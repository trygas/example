#include "json.hpp"
#include "general.h"

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    std::ifstream input("../json_example/recon.json");
    nlohmann::json j;
    input >> j;
    std::vector<std::string> vStr = j["image"];
    vector<double > para = j["camera"];
    PrintVector(para);
    PrintVector(vStr);
    std::ofstream output("../json_example/output.json");
    output << std::setw(4) << j << std::endl;
}