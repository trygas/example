#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>

#include "general.h"

using namespace std;
using namespace cv;

int main()
{
    vector<KeyPoint> vecKeyPt;
    Mat des;
    Mat image = cv::imread("../sift/DJI_0011.jpg");
    cv::resize(image, image, Size(1000, 750));
    Ptr<Feature2D> sift = xfeatures2d::SIFT::create(1000);
    Ptr<Feature2D> akaze = AKAZE::create();

    double totaltime;
    clock_t start, finish;
    start = clock();
    sift->detect(image, vecKeyPt);
    sift->compute(image, vecKeyPt, des);
//    akaze->detect(image, vecKeyPt);
//    akaze->compute(image, vecKeyPt, des);
    finish = clock();
    totaltime = (double)(finish - start)/CLOCKS_PER_SEC;
    cout << totaltime;
}