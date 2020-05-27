#include <iostream>
#include <string>
#include <fstream>
#include <memory>
#include <vector>

#include "json.hpp"

class CreateJSON
{
public:
    static std::shared_ptr<CreateJSON> GetInstance()
    {
        static std::shared_ptr<CreateJSON> globalJSON(new CreateJSON);
        return globalJSON;
    }

    bool insertJsonPath(std::string &_jsonPath)
    {
        jsonPath = _jsonPath;
        std::fstream fs(jsonPath.c_str(), std::ios::in | std::ios::out | std::ios::binary | std::ios::ate | std::ios::trunc);
        fs << "{" << std::endl;
        return true;
    }

    bool insertString(std::string &key, std::string& value)
    {
        if (jsonPath.empty())
            return false;
        std::fstream fs(jsonPath.c_str(), std::ios::in | std::ios::out | std::ios::binary | std::ios::ate);
        fs << "  \"" << key << "\":" << "\"" << value << "\"," << std::endl;

        return true;
    }

    bool insertVectorDouble(std::string& key, std::vector<double>& value)
    {
        if (jsonPath.empty())
            return false;
        std::fstream fs(jsonPath.c_str(), std::ios::in | std::ios::out | std::ios::binary | std::ios::ate);
        fs << "  \"" << key << "\":[";
        for (int i = 0; i < value.size(); ++i)
        {
            if (i != value.size() - 1)
                fs << value[i] << ",";
            else
                fs << value[i];
        }
        fs << "]," << std::endl;

        return true;
    }

    ~CreateJSON()
    {
        std::fstream fs(jsonPath.c_str(), std::ios::in | std::ios::out | std::ios::binary | std::ios::ate);
        fs.seekg(-2, std::ios::cur);
        fs << std::endl << "}";
    }
private:
    CreateJSON(){};
    std::string jsonPath;
};

int main()
{
    std::ofstream file("../CreateJSON/result.json");
    file << "haha";
}
