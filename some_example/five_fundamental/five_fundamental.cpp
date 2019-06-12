#include <iostream>
#include <opencv2/nonfree/nonfree.hpp>
#include <opencv2/features2d/features2d.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "general.h"

void PrintMat(cv::Mat mat)
{
    for (int i = 0; i < mat.rows; ++i)
    {
        for (int j = 0; j < mat.cols; ++j)
        {
            std::cout << mat.at<float>(i, j) << " ";
        }

        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void Mat2Array(cv::Mat mat, std::vector<float>& array)
{
    for (int i = 0; i < mat.cols; ++i)
    {
        array.push_back(mat.at<float>(0, i));
    }
}

void WarpHomographyPoint(cv::Point2d& point1, cv::Point2d& point2, cv::Mat homography)
{
    const double h11 = homography.at<float>(0, 0);
    const double h12 = homography.at<float>(0, 1);
    const double h13 = homography.at<float>(0, 2);
    const double h21 = homography.at<float>(1, 0);
    const double h22 = homography.at<float>(1, 1);
    const double h23 = homography.at<float>(1, 2);
    const double h31 = homography.at<float>(2, 0);
    const double h32 = homography.at<float>(2, 1);
    const double h33 = homography.at<float>(2, 2);

    const double u1 = point1.x;
    const double v1 = point1.y;

    double x1 = h11 * u1 + h12 * v1 + h13;
    double y1 = h21 * u1 + h22 * v1 + h23;
    double z1 = h31 * u1 + h32 * v1 + h33;

    point2.x = x1 / z1;
    point2.y = y1 / z1;
}

int main()
{
    cv::Mat image1 = cv::imread("../five_fundamental/1.png");
    cv::Mat image2 = cv::imread("../five_fundamental/2.png");
    cv::Mat outImage;

    cv::SiftFeatureDetector siftFeatureDetector;
    cv::SiftDescriptorExtractor siftDescriptorExtractor;
    cv::Mat description1, description2;
    std::vector<cv::KeyPoint> keypoint1, keypoint2;
    std::vector<cv::DMatch> matches12, matches21, matches;

    siftFeatureDetector.detect(image1, keypoint1);
    siftFeatureDetector.detect(image2, keypoint2);

    siftDescriptorExtractor.compute(image1, keypoint1, description1);
    siftDescriptorExtractor.compute(image2, keypoint2, description2);

    cv::FlannBasedMatcher matcher;
    matcher.match(description1, description2, matches12);
    matcher.match(description2, description1, matches21);

    for(auto m:matches12)
    {
        if(matches21[m.trainIdx].trainIdx == m.queryIdx)
            matches.push_back(m);
    }

    cv::Mat A(6, 9, CV_32F);
    for (int i = 0; i < 3; ++i)
    {
        const cv::KeyPoint point1 = keypoint1[matches[i].trainIdx];
        const cv::KeyPoint point2 = keypoint2[matches[i].queryIdx];

        const double u1 = point1.pt.x;
        const double v1 = point1.pt.y;
        const double u2 = point2.pt.x;
        const double v2 = point2.pt.y;

        A.at<float>(2*i,0) = 0.0;
        A.at<float>(2*i,1) = 0.0;
        A.at<float>(2*i,2) = 0.0;
        A.at<float>(2*i,3) = -u1;
        A.at<float>(2*i,4) = -v1;
        A.at<float>(2*i,5) = -1;
        A.at<float>(2*i,6) = v2*u1;
        A.at<float>(2*i,7) = v2*v1;
        A.at<float>(2*i,8) = v2;

        A.at<float>(2*i+1,0) = u1;
        A.at<float>(2*i+1,1) = v1;
        A.at<float>(2*i+1,2) = 1;
        A.at<float>(2*i+1,3) = 0.0;
        A.at<float>(2*i+1,4) = 0.0;
        A.at<float>(2*i+1,5) = 0.0;
        A.at<float>(2*i+1,6) = -u2*u1;
        A.at<float>(2*i+1,7) = -u2*v1;
        A.at<float>(2*i+1,8) = -u2;
    }
    const cv::KeyPoint point1 = keypoint1[matches[1].trainIdx];
    const cv::KeyPoint point2 = keypoint2[matches[1].queryIdx];

    double scale1 = point1.response;
    double scale2 = point2.response;
    double cosangle1 = std::cos(point1.angle * 3.1415926 / 360);
    double cosangle2 = std::cos(point2.angle * 3.1415926 / 360);
    const double u1 = point1.pt.x;
    const double v1 = point1.pt.y;
    const double u2 = point2.pt.x;
    const double v2 = point2.pt.y;

    cv::Mat u,w,vt;
    cv::SVDecomp(A,w,u,vt,cv::SVD::MODIFY_A | cv::SVD::FULL_UV);

    cv::Mat b, c, d;
    std::vector<float> B, C, D;

    b = vt.row(6);
    c = vt.row(7);
    d = vt.row(8);

    Mat2Array(b, B);
    Mat2Array(c, C);
    Mat2Array(d, D);

    double bCoefficient, cCoefficient, dCoefficient = 1;

    bCoefficient =
        (
            - cosangle2 * C[0] * D[6] * v2 * scale1 + cosangle2 * C[3] * D[6] * u1 * scale1
            + cosangle2 * C[6] * D[0] * v2 * scale1 - cosangle2 * C[6] * D[3] * u1 * scale1
            - cosangle2 * cosangle1 * C[3] * D[6] * v1 + cosangle2 * cosangle1 * C[3] * D[6] * v2
            + cosangle2 * cosangle1 * C[6] * D[3] * v1 - cosangle2 * cosangle1 * C[6] * D[3] * v2
            - C[0] * D[6] * u1 * scale2 * scale1 + C[0] * D[6] * u2 * scale2 * scale1
            + C[6] * D[0] * u1 * scale2 * scale1 - C[6] * D[0] * u2 * scale2 * scale1
            + cosangle1 * C[0] * D[6] * v1 * scale2 - cosangle1 * C[3] * D[6] * u2 * scale2
            - cosangle1 * C[6] * D[0] * v1 * scale2 + cosangle1 * C[6] * D[3] * u2 * scale2
            + cosangle2 * C[0] * D[3] * scale1 - cosangle2 * C[3] * D[1] * scale1
            - cosangle1 * C[0] * D[3] * scale2 + cosangle1 * C[3] * D[0] * scale2
            ) /
        (
            + cosangle2 * B[0] * C[6] * v2 * scale1 + cosangle2 * B[3] * C[6] * u1 * scale1
            + cosangle2 * B[6] * C[0] * v2 * scale1 - cosangle2 * B[6] * C[3] * u1 * scale1
            - cosangle2 * cosangle1 * B[3] * C[6] * v1 + cosangle2 * cosangle1 * B[3] * C[6] * v2
            + cosangle2 * cosangle1 * B[6] * C[3] * v1 - cosangle2 * cosangle1 * B[6] * C[3] * v2
            - B[0] * C[6] * u1 * scale2 * scale1 + B[0] * C[6] * u2 * scale2 * scale1
            + B[6] * C[0] * u1 * scale2 * scale1 - B[6] * C[0] * u2 * scale2 * scale1
            + cosangle1 * B[0] * C[6] * v1 * scale2 - cosangle1 * B[3] * C[6] * u2 * scale2
            - cosangle1 * B[6] * C[0] * v1 * scale2 + cosangle1 * B[6] * C[3] * u2 * scale2
            + cosangle2 * B[0] * C[3] * scale1 - cosangle2 * B[3] * C[1] * scale1
            - cosangle1 * B[0] * C[3] * scale2 + cosangle1 * B[3] * C[0] * scale2
            );

    cCoefficient = -
        (
            - cosangle2 * B[0] * D[6] * v2 * scale1 + cosangle2 * B[3] * D[6] * u1 * scale1
            + cosangle2 * B[6] * D[0] * v2 * scale1 - cosangle2 * B[6] * D[3] * u1 * scale1
            - cosangle2 * cosangle1 * B[3] * D[6] * v1 + cosangle2 * cosangle1 * B[3] * D[6] * v2
            + cosangle2 * cosangle1 * B[6] * D[3] * v1 - cosangle2 * cosangle1 * B[6] * D[3] * v2
            - B[0] * D[6] * u1 * scale2 * scale1 + B[0] * D[6] * u2 * scale2 * scale1
            + B[6] * D[0] * u1 * scale2 * scale1 - B[6] * D[0] * u2 * scale2 * scale1
            + cosangle1 * B[0] * D[6] * v1 * scale2 - cosangle1 * B[3] * D[6] * u2 * scale2
            - cosangle1 * B[6] * D[0] * v1 * scale2 + cosangle1 * B[6] * D[3] * u2 * scale2
            + cosangle2 * B[0] * D[3] * scale1 - cosangle2 * B[3] * D[1] * scale1
            - cosangle1 * B[0] * D[3] * scale2 + cosangle1 * B[3] * D[0] * scale2
        ) /
        (
            - cosangle2 * B[0] * C[6] * v2 * scale1 + cosangle2 * B[3] * C[6] * u1 * scale1
            + cosangle2 * B[6] * C[0] * v2 * scale1 - cosangle2 * B[6] * C[3] * u1 * scale1
            - cosangle2 * cosangle1 * B[3] * C[6] * v1 + cosangle2 * cosangle1 * B[3] * C[6] * v2
            + cosangle2 * cosangle1 * B[6] * C[3] * v1 - cosangle2 * cosangle1 * B[6] * C[3] * v2
            - B[0] * C[6] * u1 * scale2 * scale1 + B[0] * C[6] * u2 * scale2 * scale1
            + B[6] * C[0] * u1 * scale2 * scale1 - B[6] * C[0] * u2 * scale2 * scale1
            + cosangle1 * B[0] * C[6] * v1 * scale2 - cosangle1 * B[3] * C[6] * u2 * scale2
            - cosangle1 * B[6] * C[0] * v1 * scale2 + cosangle1 * B[6] * C[3] * u2 * scale2
            + cosangle2 * B[0] * C[3] * scale1 - cosangle2 * B[3] * C[1] * scale1
            - cosangle1 * B[0] * C[3] * scale2 + cosangle1 * B[3] * C[0] * scale2
        );

    cv::Mat homography = bCoefficient * b.reshape(0, 3) + cCoefficient * c.reshape(0, 3) + dCoefficient * d.reshape(0, 3);
    PrintMat(homography);

    int pointIndex = 6;
    cv::KeyPoint point3 = keypoint1[pointIndex];
    cv::KeyPoint point4 = keypoint2[pointIndex];

    cv::Point2d pt1 = point3.pt;
    cv::Point2d pt2(0.0, 0.0);
    WarpHomographyPoint(pt1, pt2, homography);
    std::cout << point4.pt.x << " " << point4.pt.y << std::endl;
    std::cout << pt2.x << " " << pt2.y << std::endl;

    {
        cv::Mat A(7,9,CV_32F);
        std::vector<cv::Point2d> hallucinatedPoint(5);
        std::vector<cv::Point2d> anotherPoint(5);
        for(int i = 0; i < hallucinatedPoint.size(); ++i)
        {
            hallucinatedPoint[i].x = RandomNumber(i * 0.2 * image1.rows, (i+1) * 0.2 * image1.rows);
            hallucinatedPoint[i].y = RandomNumber(0, image1.cols);

            WarpHomographyPoint(hallucinatedPoint[i], anotherPoint[i], homography);

            const double u1 = hallucinatedPoint[i].x;
            const double v1 = hallucinatedPoint[i].y;
            const double u2 = anotherPoint[i].x;
            const double v2 = anotherPoint[i].y;

            A.at<float>(i,0) = u2*u1;
            A.at<float>(i,1) = u2*v1;
            A.at<float>(i,2) = u2;
            A.at<float>(i,3) = v2*u1;
            A.at<float>(i,4) = v2*v1;
            A.at<float>(i,5) = v2;
            A.at<float>(i,6) = u1;
            A.at<float>(i,7) = v1;
            A.at<float>(i,8) = 1;
        }

        for (int i = 5; i < 7; ++i)
        {
            const cv::KeyPoint point1 = keypoint1[matches[i].trainIdx];
            const cv::KeyPoint point2 = keypoint2[matches[i].queryIdx];

            const double u1 = point1.pt.x;
            const double v1 = point1.pt.y;
            const double u2 = point2.pt.x;
            const double v2 = point2.pt.y;

            A.at<float>(i,0) = u2*u1;
            A.at<float>(i,1) = u2*v1;
            A.at<float>(i,2) = u2;
            A.at<float>(i,3) = v2*u1;
            A.at<float>(i,4) = v2*v1;
            A.at<float>(i,5) = v2;
            A.at<float>(i,6) = u1;
            A.at<float>(i,7) = v1;
            A.at<float>(i,8) = 1;
        }

        cv::Mat u,w,vt;
        cv::SVDecomp(A,w,u,vt,cv::SVD::MODIFY_A | cv::SVD::FULL_UV);

        cv::Mat b, c, bMinusc;
        std::vector<float> B, C, BMinusC;
        double bCoefficient, cCoefficient;

        b = vt.row(7);
        c = vt.row(8);
        bMinusc = b - c;
        Mat2Array(b, B);
        Mat2Array(c, C);
        Mat2Array(bMinusc, BMinusC);

        double cubicA = BMinusC[0]*BMinusC[4]*BMinusC[8] + BMinusC[1]*BMinusC[5]*BMinusC[6]
            + BMinusC[3]*BMinusC[7]*BMinusC[2] - BMinusC[2]*BMinusC[4]*BMinusC[6]
            - BMinusC[0]*BMinusC[7]*BMinusC[5] - BMinusC[1]*BMinusC[3]*BMinusC[8];
        double cubicB = BMinusC[0]*BMinusC[4]*C[8] + BMinusC[0]*C[4]*BMinusC[8] + C[0]*BMinusC[4]*BMinusC[8]
            + BMinusC[1]*BMinusC[5]*C[6] + BMinusC[1]*C[5]*BMinusC[6] + C[1]*BMinusC[5]*BMinusC[6]
            + BMinusC[3]*BMinusC[7]*C[2] + BMinusC[3]*C[7]*BMinusC[2] + C[3]*BMinusC[7]*BMinusC[2]
            - BMinusC[2]*BMinusC[4]*C[6] - BMinusC[2]*C[4]*BMinusC[6] - C[2]*BMinusC[4]*BMinusC[6]
            - BMinusC[0]*BMinusC[7]*C[5] - BMinusC[0]*C[7]*BMinusC[5] - C[0]*BMinusC[7]*BMinusC[5]
            - BMinusC[1]*BMinusC[3]*C[8] - BMinusC[1]*C[3]*BMinusC[8] - C[1]*BMinusC[3]*BMinusC[8];
        double cubicC = BMinusC[0]*C[4]*C[8] + C[0]*C[4]*BMinusC[8] + C[0]*BMinusC[4]*C[8]
            + BMinusC[1]*C[5]*C[6] + C[1]*C[5]*BMinusC[6] + C[1]*BMinusC[5]*C[6]
            + BMinusC[3]*C[7]*C[2] + C[3]*C[7]*BMinusC[2] + C[3]*BMinusC[7]*C[2]
            - BMinusC[2]*C[4]*C[6] - C[2]*C[4]*BMinusC[6] - C[2]*BMinusC[4]*C[6]
            - BMinusC[0]*C[7]*C[5] - C[0]*C[7]*BMinusC[5] - C[0]*BMinusC[7]*C[5]
            - BMinusC[1]*C[3]*C[8] - C[1]*C[3]*BMinusC[8] - C[1]*BMinusC[3]*C[8];
        double cubicD = C[0]*C[4]*C[8] + C[1]*C[5]*C[6]
            + C[3]*C[7]*C[2] - C[2]*C[4]*C[6]
            - C[0]*C[7]*C[5] - C[1]*C[3]*C[8];

        double as = cubicB*cubicB - 3*cubicA*cubicC;
        double bs = cubicB*cubicC - 9*cubicA*cubicD;
        double t = (2*as*cubicB-3*cubicA*bs)/(2*sqrt(as*as*as));
        double si = acos(t);

        std::cout << cubicA << std::endl;
        std::cout << cubicB << std::endl;
        std::cout << cubicC << std::endl;
        std::cout << cubicD << std::endl;
        std::cout << std::endl;

        std::cout << as << std::endl;
        std::cout << bs << std::endl;
        std::cout << t  << std::endl;
        std::cout << si << std::endl;
        std::cout << std::endl;

        double x1 = (-cubicB-2*sqrt(as)*cos(si/3))/(3*cubicA);
        double x2 = (-cubicB+sqrt(as)*(cos(si/3)+sqrt(3)*sin(si/3)))/(3*cubicA);
        double x3 = (-cubicB+sqrt(as)*(cos(si/3)-sqrt(3)*sin(si/3)))/(3*cubicA);

        std::cout << x1 << std::endl;
        std::cout << x2 << std::endl;
        std::cout << x3 << std::endl;

        cv::Mat fundamental = b * x1 + c * (1 - x1);
        fundamental = fundamental.reshape(0, 3);
        PrintMat(fundamental);
    }
}