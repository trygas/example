#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

void BilinearInterpolation(cv::Mat& in_image, cv::Mat& out_image, double scale)
{
    cv::Mat image;
    in_image.copyTo(image);

    int row = image.rows * scale;
    int col = image.cols * scale;

    image.create(row, col, in_image.type());

    uchar* data = image.data;

    for (int i = 0; i < image.rows; ++i)
    {
        for (int j = 0; j < image.cols; ++j)
        {
            Point2d init_point((double)j / scale, (double)i / scale);
            Point2i tl(init_point.x < 0 ? 0 : (int)init_point.x, init_point.y < 0 ? 0 : (int)init_point.y);
            Point2i tr(init_point.x > image.cols ? image.cols : (int)init_point.x + 1, init_point.y < 0 ? 0 : (int)init_point.y);
            Point2i bl(init_point.x < 0 ? 0 : (int)init_point.x, init_point.x > image.rows ? image.rows : (int)init_point.y + 1);
            Point2i br(init_point.x > image.cols ? image.cols : (int)init_point.x + 1, init_point.x > image.rows ? image.rows : (int)init_point.y + 1);

            double inter_x1 = (tr.x - init_point.x) * in_image.at<uchar>(tl) + (init_point.x - tl.x) * in_image.at<uchar>(tr);
            double inter_x2 = (br.x - init_point.x) * in_image.at<uchar>(bl) + (init_point.x - bl.x) * in_image.at<uchar>(br);

            double inter = (br.y - init_point.y) * inter_x1 + (init_point.y - tr.y) * inter_x2;

            *data = inter;
            ++data;
        }
    }

    image.copyTo(out_image);
}

int main()
{
    Mat image = imread("../bilinear_interpolation/img1.png");
    cvtColor(image, image, CV_RGB2GRAY);
    BilinearInterpolation(image, image, 1.5);
    imshow("image", image);
    cvWaitKey();
}