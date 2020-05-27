#include "general.h"

#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>

#include <eigen3/Eigen/Core>
#include <eigen3/Eigen/LU>
#include <eigen3/Eigen/SVD>
#include <eigen3/Eigen/Eigenvalues>

using namespace cv;
using namespace Eigen;

void FindLinearPolynomialRoots(const VectorXd& polynomial,
                               VectorXd* real,
                               VectorXd* imaginary) {
    if (real != NULL) {
        real->resize(1);
        (*real)(0) = -polynomial(1) / polynomial(0);
    }

    if (imaginary != NULL) {
        imaginary->setZero(1);
    }
}

VectorXd RemoveLeadingZeros(const VectorXd& polynomial_in) {
    int i = 0;
    while (i < (polynomial_in.size() - 1) && polynomial_in(i) == 0) {
        ++i;
    }
    return polynomial_in.tail(polynomial_in.size() - i);
}

void FindQuadraticPolynomialRoots(const VectorXd& polynomial,
                                  VectorXd* real,
                                  VectorXd* imaginary) {
    const double a = polynomial(0);
    const double b = polynomial(1);
    const double c = polynomial(2);
    const double D = b * b - 4 * a * c;
    const double sqrt_D = sqrt(fabs(D));
    if (real != NULL) {
        real->setZero(2);
    }
    if (imaginary != NULL) {
        imaginary->setZero(2);
    }

    // Real roots.
    if (D >= 0) {
        if (real != NULL) {
            // Stable quadratic roots according to BKP Horn.
            // http://people.csail.mit.edu/bkph/articles/Quadratics.pdf
            if (b >= 0) {
                (*real)(0) = (-b - sqrt_D) / (2.0 * a);
                (*real)(1) = (2.0 * c) / (-b - sqrt_D);
            } else {
                (*real)(0) = (2.0 * c) / (-b + sqrt_D);
                (*real)(1) = (-b + sqrt_D) / (2.0 * a);
            }
        }
        return;
    }

    // Use the normal quadratic formula for the complex case.
    if (real != NULL) {
        (*real)(0) = -b / (2.0 * a);
        (*real)(1) = -b / (2.0 * a);
    }
    if (imaginary != NULL) {
        (*imaginary)(0) = sqrt_D / (2.0 * a);
        (*imaginary)(1) = -sqrt_D / (2.0 * a);
    }
}

void BuildCompanionMatrix(const VectorXd& polynomial,
                          MatrixXd* companion_matrix_ptr) {
    MatrixXd& companion_matrix = *companion_matrix_ptr;

    const int degree = polynomial.size() - 1;

    companion_matrix.resize(degree, degree);
    companion_matrix.setZero();
    companion_matrix.diagonal(-1).setOnes();
    companion_matrix.col(degree - 1) = -polynomial.reverse().head(degree);
}

void BalanceCompanionMatrix(MatrixXd* companion_matrix_ptr) {
    MatrixXd& companion_matrix = *companion_matrix_ptr;
    MatrixXd companion_matrix_offdiagonal = companion_matrix;
    companion_matrix_offdiagonal.diagonal().setZero();

    const int degree = companion_matrix.rows();

    // gamma <= 1 controls how much a change in the scaling has to
    // lower the 1-norm of the companion matrix to be accepted.
    //
    // gamma = 1 seems to lead to cycles (numerical issues?), so
    // we set it slightly lower.
    const double gamma = 0.9;

    // Greedily scale row/column pairs until there is no change.
    bool scaling_has_changed;
    do {
        scaling_has_changed = false;

        for (int i = 0; i < degree; ++i) {
            const double row_norm = companion_matrix_offdiagonal.row(i).lpNorm<1>();
            const double col_norm = companion_matrix_offdiagonal.col(i).lpNorm<1>();

            // Decompose row_norm/col_norm into mantissa * 2^exponent,
            // where 0.5 <= mantissa < 1. Discard mantissa (return value
            // of frexp), as only the exponent is needed.
            int exponent = 0;
            std::frexp(row_norm / col_norm, &exponent);
            exponent /= 2;

            if (exponent != 0) {
                const double scaled_col_norm = std::ldexp(col_norm, exponent);
                const double scaled_row_norm = std::ldexp(row_norm, -exponent);
                if (scaled_col_norm + scaled_row_norm < gamma * (col_norm + row_norm)) {
                    // Accept the new scaling. (Multiplication by powers of 2 should not
                    // introduce rounding errors (ignoring non-normalized numbers and
                    // over- or underflow))
                    scaling_has_changed = true;
                    companion_matrix_offdiagonal.row(i) *= std::ldexp(1.0, -exponent);
                    companion_matrix_offdiagonal.col(i) *= std::ldexp(1.0, exponent);
                }
            }
        }
    } while (scaling_has_changed);

    companion_matrix_offdiagonal.diagonal() = companion_matrix.diagonal();
    companion_matrix = companion_matrix_offdiagonal;
}


bool FindPolynomialRootsCompanionMatrix(const Eigen::VectorXd& polynomial_in,
                                        Eigen::VectorXd* real,
                                        Eigen::VectorXd* imaginary) {
    if (polynomial_in.size() == 0) {
        cerr << "Invalid polynomial of size 0 passed to FindPolynomialRoots";
        return false;
    }

    VectorXd polynomial = RemoveLeadingZeros(polynomial_in);
    const int degree = polynomial.size() - 1;

    // Is the polynomial constant?
    if (degree == 0) {
        cout << "Trying to extract roots from a constant "
                     << "polynomial in FindPolynomialRootsCompanionMatrix";
        // We return true with no roots, not false, as if the polynomial is constant
        // it is correct that there are no roots. It is not the case that they were
        // there, but that we have failed to extract them.
        return true;
    }

    // Linear
    if (degree == 1) {
        FindLinearPolynomialRoots(polynomial, real, imaginary);
        return true;
    }

    // Quadratic
    if (degree == 2) {
        FindQuadraticPolynomialRoots(polynomial, real, imaginary);
        return true;
    }

    // The degree is now known to be at least 3. For cubic or higher
    // roots we use the method of companion matrices.

    // Divide by leading term
    const double leading_term = polynomial(0);
    polynomial /= leading_term;

    // Build and balance the companion matrix to the polynomial.
    MatrixXd companion_matrix(degree, degree);
    BuildCompanionMatrix(polynomial, &companion_matrix);
    BalanceCompanionMatrix(&companion_matrix);

    // Find its (complex) eigenvalues.
    Eigen::EigenSolver<MatrixXd> solver(companion_matrix, false);
    if (solver.info() != Eigen::Success) {
        cerr << "Failed to extract eigenvalues from companion matrix.";
        return false;
    }

    // Output roots
    if (real != NULL) {
        *real = solver.eigenvalues().real();
    } else {
        cout << "NULL pointer passed as real argument to "
                     << "FindPolynomialRoots. Real parts of the roots will not "
                     << "be returned.";
    }
    if (imaginary != NULL) {
        *imaginary = solver.eigenvalues().imag();
    }
    return true;
}


bool FindPolynomialRoots(const VectorXd& polynomial,
                         VectorXd* real,
                         VectorXd* imaginary) {
    return FindPolynomialRootsCompanionMatrix(polynomial, real, imaginary);
}

int main()
{
    vector<KeyPoint> keypoint1, keypoint2;
    vector<Point2d> points1, points2;
    cv::Mat descriptor1, descriptor2;
    cv::Mat image1 = cv::imread("../self_calibration/DJI_0010.JPG");
    cv::Mat image2 = cv::imread("../self_calibration/DJI_0011.JPG");

//    cv::resize(image1, image1, cv::Size(1000, 750));
//    cv::resize(image2, image2, cv::Size(1000, 750));

    cv::Ptr<Feature2D> f2d = xfeatures2d::SIFT::create(1000);
    f2d->detect(image1, keypoint1);
    f2d->detect(image2, keypoint2);

    f2d->compute(image1, keypoint1, descriptor1);
    f2d->compute(image2, keypoint2, descriptor2);

    vector<DMatch> matches;
    FlannBasedMatcher flannBasedMatcher;
    flannBasedMatcher.match(descriptor1, descriptor2, matches);

    for (int i = 0; i < matches.size(); ++i)
    {
        points1.push_back(keypoint1[matches[i].queryIdx].pt);
        points2.push_back(keypoint2[matches[i].trainIdx].pt);
    }

    cv::Mat fundamental = cv::findFundamentalMat(points1, points2);
    cout << fundamental << endl;

    double fund[9];
    for (int i = 0; i < fundamental.rows; ++i)
    {
        for (int j = 0; j < fundamental.cols; ++j)
        {
            fund[i * 3 + j] = fundamental.at<double>(i, j);
        }
    }

    double focal_length1, focal_length2;
    Map<const Matrix3d> fundamental_matrix(fund);
    const Vector3d epipole1 = fundamental_matrix.jacobiSvd(ComputeFullV).matrixV().rightCols<1>();
    const Vector3d epipole2 = fundamental_matrix.transpose().jacobiSvd(ComputeFullV).matrixV().rightCols<1>();
    cout << epipole1.x() << endl;
    cout << epipole2.x() << endl;

    const double theta1 = atan2(-epipole1(1), epipole1(0));
    const double theta2 = atan2(-epipole2(1), epipole2(0));

    Matrix3d rotation1, rotation2;
    rotation1 <<
              cos(theta1), -sin(theta1), 0,
              sin(theta1), cos(theta1), 0,
              0, 0, 1;
    rotation2 <<
              cos(theta2), -sin(theta2), 0,
              sin(theta2), cos(theta2), 0,
              0, 0, 1;

    const Matrix3d rotated_fmatrix =
        rotation2 * fundamental_matrix * rotation1.transpose();
    // With the normalized epipoles, the fundamental matrix is now of the form:
    // F = [ e'_2   0    0   ] [ a b a ] [ e_2   0     0  ]
    //     [ 0      1    0   ] [ c d c ] [ 0     1     0  ]
    //     [ 0      0  -e'_1 ] [ a b a ] [ 0     0   -e_1 ]
    const Vector3d rotated_epipole1 = rotation1 * epipole1;
    const Vector3d rotated_epipole2 = rotation2 * epipole2;

    Matrix3d factorized_matrix =
        DiagonalMatrix<double, 3>(rotated_epipole2(2), 1, -rotated_epipole2(0))
            .inverse() *
        rotated_fmatrix *
        DiagonalMatrix<double, 3>(rotated_epipole1(2), 1, -rotated_epipole1(0))
            .inverse();

    // For convenience, as defined above.
    const double a = factorized_matrix(0, 0);
    const double b = factorized_matrix(0, 1);
    const double c = factorized_matrix(1, 0);
    const double d = factorized_matrix(1, 1);

    const double focal_length1_sq =
        (-a * c * rotated_epipole1(0) * rotated_epipole1(0)) /
        (a * c * rotated_epipole1(2) * rotated_epipole1(2) + b * d);
    const double focal_length2_sq =
        (-a * b * rotated_epipole2(0) * rotated_epipole2(0)) /
        (a * b * rotated_epipole2(2) * rotated_epipole2(2) + c * d);

    cout << "focal_length_sq: " << focal_length1_sq << endl;
    cout << "focal_length_sq: " << focal_length2_sq << endl;

    if (focal_length1_sq < 0 || focal_length2_sq < 0) {
        return false;
    }

    focal_length1 = sqrt(focal_length1_sq);
    focal_length2 = sqrt(focal_length2_sq);
    cout << focal_length1 << endl;
    cout << focal_length2 << endl;

//    double focal_length;
//    Map<const Matrix3d> G(fund);
//    Eigen::JacobiSVD<Eigen::Matrix3d> svd(
//        G, Eigen::ComputeFullU | Eigen::ComputeFullV);
//    const Eigen::Matrix3d& U = svd.matrixU();
//    const Eigen::Matrix3d& V = svd.matrixV();
//    const double a = svd.singularValues()(0);
//    const double b = svd.singularValues()(1);
//
//    // Construct the quadratic equation that reveals the focal length.
//    const double U20 = U(2, 0);
//    const double U21 = U(2, 1);
//    const double V20 = V(2, 0);
//    const double V21 = V(2, 1);
//    const double U20_sq = U20 * U20;
//    const double U21_sq = U21 * U21;
//    const double V20_sq = V20 * V20;
//    const double V21_sq = V21 * V21;
//    Eigen::VectorXd coeffs(3);
//    coeffs(0) = a * a * (1.0 - U20_sq) * (1.0 - V20_sq) -
//                b * b * (1.0 - U21_sq) * (1.0 - V21_sq);
//    coeffs(1) = a * a * (U20_sq + V20_sq - 2.0 * U20_sq * V20_sq) -
//                b * b * (U21_sq + V21_sq - 2.0 * U21_sq * V21_sq);
//    coeffs(2) = a * a * U20_sq * V20_sq - b * b * U21_sq * V21_sq;
//
//    // Solve the quadratic equation. The roots provide the square of the focal
//    // length.
//    Eigen::VectorXd real_roots, imaginary_roots;
//    if (!FindPolynomialRoots(coeffs, &real_roots, &imaginary_roots)) {
//        return false;
//    }
//
//    // If niether root is positive then no valid solution exists. If one of the
//    // roots is negative then it leads to an imaginary value for the focal length
//    // so we can immediately return the other value as the solution.
//    if (real_roots(0) < 0 && real_roots(1) < 0) {
//        return false;
//    } else if (real_roots(0) < 0) {
//        focal_length = std::sqrt(real_roots(1));
//    } else if (real_roots(1) < 0) {
//        focal_length = std::sqrt(real_roots(0));
//    } else {
//        // If we reach this point then the roots are both positive and so we
//        // disambiguate the roots by selecting the root that best satisfies the
//        // linear constraint.
//        const double c1 =
//            a * U20 * U21 * (1.0 - V20_sq) + b * V20 * V21 * (1.0 - U21_sq);
//        const double c2 = U21 * V20 * (a * U20 * V20 + b * U21 * V21);
//        const double root1_val = c1 * real_roots(0) + c2;
//        const double root2_val = c1 * real_roots(1) + c2;
//        if (std::abs(root1_val) < std::abs(root2_val)) {
//            focal_length = std::sqrt(real_roots(0));
//        } else {
//            focal_length = std::sqrt(real_roots(1));
//        }
//    }
//
//    cout << focal_length;
}