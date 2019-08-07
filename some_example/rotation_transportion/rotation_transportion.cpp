#include <iostream>
#include <cmath>
using namespace std;

#include <eigen3/Eigen/Core>
// Eigen 几何模块
#include <eigen3/Eigen/Geometry>


int main ( int argc, char** argv )
{
//    Eigen::Quaterniond fourNum(0.5, -0.5, 0.5, -0.5);
    Eigen::Matrix3d q = Eigen::Matrix3d::Identity();
//    Eigen::Matrix3d fourNumMat =z43z3 Eigen::Matrix3d(fourNum);
    auto out=Eigen::AngleAxisd(q);
    cout << q << endl << endl;
    cout << out.axis() << endl << endl;
//    auto fourNumMat = Eigen::AngleAxisd(fourNum);
//        cout << fourNumMat.axis() << endl << endl;
    return 0;
}