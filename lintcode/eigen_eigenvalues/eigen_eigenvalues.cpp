#include <iostream>
#include <opencv2/opencv.hpp>
#include <Eigen/Dense>

using namespace std;
using namespace Eigen;

int main()
{
//    MatrixXd matrix = MatrixXd::Zero(4, 2);
//
//    matrix(0, 0) = 6;
//    matrix(0, 1) = 6;
//    matrix(1, 0) = 0;
//    matrix(1, 1) = 1;
//    matrix(2, 0) = 4;
//    matrix(2, 1) = 0;
//    matrix(3, 0) = 0;
//    matrix(3, 1) = 6;
//
//    EigenSolver<MatrixXd> es(matrix);
//    cout << es.eigenvalues() << endl;
//    cout << es.eigenvectors() << endl;

    cv::Mat A(4, 2, CV_32F);

    A.at<double>(0, 0) = 6;
    A.at<double>(0, 1) = 6;
    A.at<double>(1, 0) = 0;
    A.at<double>(1, 1) = 1;
    A.at<double>(2, 0) = 4;
    A.at<double>(2, 1) = 0;
    A.at<double>(3, 0) = 0;
    A.at<double>(3, 1) = 6;

    cv::Mat u, w, vt;
    cv::SVDecomp(A, w, u, vt, cv::SVD::MODIFY_A | cv::SVD::FULL_UV);

    cout << w << endl;
}