//
// Created by liu on 20-1-8.
//

#include "general.h"

class example
{
public:
    example(){
        cout << "construct." << endl;
    }
    example(const example &e){
        cout << "copy." << endl;
    }
    example& operator=(const example &rhs){
        cout << "denghao." << endl;
        return *this;
    }
    example(example &&e){
        cout << "move." << endl;
    }

    ~example(){
        cout << "destroy." << endl;
    }
};

int main()
{
    std::vector<example> e_vec;
    e_vec.reserve(4);
    example e1;
//    example e2 = e1;
//    example e3(e1);
//    example e4 = std::move(e1);

    cout << endl;
    e_vec.push_back(e1);
    cout << endl;
    e_vec.emplace_back(e1);
    cout << endl;
    e_vec.emplace_back(std::move(e1));
    cout << endl;
}

