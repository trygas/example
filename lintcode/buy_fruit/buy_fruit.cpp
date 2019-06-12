#include "general.h"

int main()
{
    vector<int > fruitBuy{16};
    vector<int > fruitSell{19};

    int ownMoney = 15;

    vector<pair<int, int> > buyAndGet;
    for (int i = 0; i < fruitBuy.size(); ++i)
    {
        buyAndGet.push_back(pair<int, int>(fruitBuy[i], fruitSell[i]));
    }

    sort(buyAndGet.begin(), buyAndGet.end(), [](pair<int, int> &a, pair<int, int> &b){
        return a.first < b.first;
    });

    int lastMoney = ownMoney;

    for (int i = 0; i < fruitBuy.size(); ++i)
    {
        if (lastMoney >= buyAndGet[i].first && buyAndGet[i].second - buyAndGet[i].first >= 0)
            lastMoney += ( - buyAndGet[i].first + buyAndGet[i].second);
    }

    cout << lastMoney;
}