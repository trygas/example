#include <iostream>
#include <iomanip>

#include "general.h"
#include "TinyEXIF.h"
#include "tinyxml2.h"

using namespace std;

bool exportEle(GSLAM::Svar& var,tinyxml2::XMLElement* ele,string parentName="")
{
    if(!ele) return false;
    if(ele->Attribute("value"))
        var.insert((parentName.empty()?string():parentName+".")+ele->Name(),ele->Attribute("value"));

    tinyxml2::XMLElement* child=ele->FirstChildElement();
    while(child)
    {
        exportEle(var,child,(parentName.empty()?string():parentName+".")+ele->Name());
        child=child->NextSiblingElement();
    }

    return true;
}

int main()
{
    TinyEXIF::EXIF exif;
    GSLAM::Svar var;
    exif.parseFile("../Read_EXIF/DJI_0011.jpg", var);
    std::string dataTime=var.GetString("DateTime","");
    double Timestamp=var.GetDouble("Timestamp",0);
    cout << dataTime << endl;
    cout << Timestamp << endl;

    vector<double> gpsInfo;
    std::vector<std::string> extraParams;

    gpsInfo.reserve(14);
    if(var.d.exist("Longitude") && var.d.exist("Latitude")&&var.d.exist("Altitude"))
    {
        gpsInfo.push_back(var.d["Longitude"]);
        gpsInfo.push_back(var.d["Latitude"]);
        gpsInfo.push_back(var.d["Altitude"]);
        gpsInfo.push_back(var.GetDouble("LongitudeSigma",5));
        gpsInfo.push_back(var.GetDouble("LatitudeSigma",5));
        gpsInfo.push_back(var.GetDouble("AltitudeSigma",10));
    }
    if(var.d.exist("RelativeAltitude"))
    {
        gpsInfo.push_back(var.d["RelativeAltitude"]);
        gpsInfo.push_back(var.GetDouble("RelativeAltitudeSigma",10));
    }
    if(var.d.exist("CameraPitch")&&var.d.exist("CameraYaw")&&var.d.exist("CameraRoll"))
    {
        gpsInfo.push_back(var.d["CameraPitch"]);
        gpsInfo.push_back(var.d["CameraYaw"]);
        gpsInfo.push_back(var.d["CameraRoll"]);
        gpsInfo.push_back(var.GetDouble("CameraPitchSigma",1));
        gpsInfo.push_back(var.GetDouble("CameraYawSigma",10));
        gpsInfo.push_back(var.GetDouble("CameraRollSigma",1));
    }
    cout.precision(10);
    PrintVector(gpsInfo);

    return 0;
}