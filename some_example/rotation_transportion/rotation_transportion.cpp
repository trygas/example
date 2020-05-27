#include <iostream>
#include <cmath>
#include "general.h"
using namespace std;

#include <eigen3/Eigen/Core>
// Eigen 几何模块
#include <eigen3/Eigen/Geometry>

#include <ceres/rotation.h>

int main ( int argc, char** argv )
{
//    Eigen::Vector3d angle(3.07417, -0.589253, -0.018623);
//    Eigen::Vector3d angleinv = -angle;
//    Eigen::Vector4d quadR, quadRinv;
//
//    ceres::AngleAxisToQuaternion(angle.data(), quadR.data());
//    ceres::AngleAxisToQuaternion(angleinv.data(), quadRinv.data());
//
//    cout << quadR << endl;
//    cout << quadRinv << endl;

//    Eigen::Vector4d quadR(1.33974e-08, -1, 1.33974e-08, -1.94289e-16);
//    Eigen::Vector3d angle;
//    ceres::QuaternionToAngleAxis(quadR.data(), angle.data());
//    cout << angle;
//    return 0;

    vector<int> a = {1, 2, 3};
    sort(a.begin(), a.end(), [](int a, int b){
        return a > b;
    });

    PrintVector(a);
}