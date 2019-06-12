#include <opencv2/opencv.hpp>

#include "parse_file.h"
#include "general.h"

int main()
{
    vector<string> image_lists;

    ParseString parseString;
    parseString.ParseLine("../parse_file/images/0405_1.jpeg", image_lists);

    for (int i = 0; i < image_lists.size(); ++i)
    {
        cv::Mat image = cv::imread(image_lists[i]);
        cv::imshow("image" + to_string(i), image);
        cv::waitKey(0);
    }
}