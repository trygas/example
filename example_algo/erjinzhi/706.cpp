#include "general.h"

vector<string> binaryTime(int num)
{
    // Write your code here
    map<int, vector<int> > hours;
    map<int, vector<int> > minutes;

    for(int i = 0; i < 12; ++i){
        int index = 0;
        int num = i;
        while(num){
            if(num & 1)
                index++;
            num /= 2;
        }
        hours[index].push_back(i);
    }
    for(int i = 0; i < 60; ++i){
        int index = 0;
        int num = i;
        while(num){
            if(num & 1)
                index++;
            num /= 2;
        }
        minutes[index].push_back(i);
    }

    vector<string> res;
    for(int i = 0; i <= num; ++i){
        vector<int> hour = hours[i];
        vector<int> minute = minutes[num - i];

        if(!hour.empty() && !minute.empty()){
            for(int j = 0; j < hour.size(); ++j){
                for(int k = 0; k < minute.size(); ++k){
                    string midRes = to_string(hour[j]) + ":";

                    if(minute[k] < 10)
                        midRes += "0" + to_string(minute[k]);
                    else
                        midRes += to_string(minute[k]);

                    res.push_back(midRes);
                }
            }
        }
    }

    return res;
}

int main()
{
    PrintVector(binaryTime(1));
}