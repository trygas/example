#include "general.h"

/*
 * 主要思路首先按照位置前后进行排序, 计算出每个车在没有阻拦的情况下到达终点的时间
 * 如果比前面的车先到,那么就证明这两个车是一个车队的.
 */
struct node
{
    node(int _pos, int _speed){
        pos = _pos;
        speed = _speed;
    }

    bool operator < (const node& n) const {
        return pos > n.pos;
    }

    double pos;
    double speed;
};

int preMain()
{
    int target = 17;
    vector<int> position = {8,12,16,11,7};
    vector<int> speed = {6,9,10,9,7};
    vector<node> n;

    for(int i = 0; i < position.size(); ++i){
        n.emplace_back(node(position[i], speed[i]));
    }
    sort(n.begin(), n.end());

    int res = 0;
    for(int i = 0; i < n.size();){
        res++;
        double timeI = double(target - n[i].pos) / n[i].speed;
        for(int j = i + 1; j < position.size(); ++j){
            double timeJ = double(target - n[j].pos) / n[j].speed;
            if (timeJ <= timeI)
                i++;
            else
                break;
        }
        ++i;
        n[i].pos = n[i].speed * timeI + n[i].pos;
        for(int k = i + 1; k < n.size(); ++k){
            double posPlus = n[k].speed * timeI + n[k].pos;
            if (posPlus > n[k - 1].pos){
                n[k].pos = n[k - 1].pos;
                n[k].speed = n[k - 1].speed;
            }
            else{
                n[k].pos = posPlus;
            }
        }
    }
}

int main()
{
    int target = 17;
    vector<int> position = {8,12,16,11,7};
    vector<int> speed = {6,9,10,9,7};
    map<int, double> m;

    for(int i = 0; i < position.size(); ++i){
        m[-position[i]] = (double)(target - position[i]) / speed[i];
    }

    int res = 0;
    double cur = 0;
    for(auto it: m){
        if(it.second > cur){
            cur = it.second;
            ++res;
        }
    }
    cout << res;
}
