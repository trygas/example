#include "general.h"

/*
 * 禁止离自己最近的敌对方的权利, 一直循环到一方没有投票权力了, 剩下的一方则为获胜方
 */
int main()
{
    string senate = "RDDRRDRDRD";

    int rcnt = 0, dcnt = 0;
    for(int i = 0; i < senate.size(); ++i){
        if(senate[i] == 'R'){
            if(rcnt >= 0)
                dcnt--;
            rcnt++;
        }
        else{
            if(dcnt >= 0)
                rcnt--;
            dcnt++;
        }
    }

    if(rcnt == dcnt)
        cout << ((senate[0] == 'D') ? "Dire" : "Radiant");
    cout << ((rcnt > dcnt) ? "Radiant" : "Dire");
}