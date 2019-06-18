#include <iostream>
#include <cmath>
using namespace std;

#include <eigen3/Eigen/Core>
// Eigen 几何模块
#include <eigen3/Eigen/Geometry>


int main ( int argc, char** argv )
{
    Eigen::Matrix3d q = Eigen::Matrix3d::Identity();
    Eigen::AngleAxisd v(M_PI/4,Eigen::Vector3d(0,0,1));//沿z轴旋转了45度
    auto out=Eigen::AngleAxisd(q);
    cout << out.axis() << endl << endl;
    cout << v.axis() << endl << endl;
    return 0;
}