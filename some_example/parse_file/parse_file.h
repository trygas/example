

#ifndef SOME_PROJECT_PARSE_FILE_H
#define SOME_PROJECT_PARSE_FILE_H

#include <iostream>
#include <fstream>
#include <istream>
#include <vector>

using namespace std;

class ParseString
{
public:
    ParseString(){}
    ~ParseString(){}

    inline void ParseLine(const string image_file, vector<string> &image_lists)
    {
        const std::string::size_type i1 = image_file.rfind('.');

        if (i1 == std::string::npos)
            return;

        std::string suffix_name = image_file.substr(i1 + 1);

        if (suffix_name == "txt")
            ParseFile(image_file, image_lists);
        else
            image_lists.push_back(image_file);
    }

    inline void ParseFile(const string image_file, vector<string> &image_lists)
    {
        string::size_type i1 = image_file.rfind('/');
        string directory_name = image_file.substr(0, i1 + 1);
        ifstream file(image_file);

        string s;
        while (getline(file, s))
        {
            string::size_type i2 = s.find_first_of(',');
            string file_name = directory_name + s.substr(0, i2);
            image_lists.push_back(file_name);
        }
    }
};

#endif //SOME_PROJECT_PARSE_FILE_H
