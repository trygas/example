#include "general.h"

vector<int> diffWaysToCompute(string &input) {
    // write your code here
    vector<int> res;

    for(int i = 0; i < input.size(); ++i){
        if(input[i] == '+' || input[i] == '-' || input[i] == '*'){
            string left = input.substr(0, i);
            string right = input.substr(i + 1);
            vector<int> leftRes = diffWaysToCompute(left);
            vector<int> rightRes = diffWaysToCompute(right);

            for(int j = 0; j < leftRes.size(); ++j){
                for (int k = 0; k < rightRes.size(); ++k)
                {
                    switch (input[i]){
                        case '+':{
                            res.push_back(leftRes[j] + leftRes[k]);
                            break;
                        }
                        case '-':{
                            res.push_back(leftRes[j] - rightRes[k]);
                            break;
                        }
                        case '*':{
                            res.push_back(leftRes[j] * rightRes[k]);
                            break;
                        }
                    }
                }
            }
        }
    }

    if(res.empty())
        res.push_back(stoi(input.c_str()));
    return res;
}

int main()
{
    string input = "2-1-1";

    PrintVector(diffWaysToCompute(input));
}