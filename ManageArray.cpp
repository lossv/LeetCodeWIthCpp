//
// Created by lossv on 2021/11/8.
//

#include "ManageArray.h"
#include <iostream>

using namespace std;

int GetKey(S stTmp)
{
    return stTmp.key;
}

int main()
{
    S s[10];
    int iCnt = 10;
    for(int i = 0; i < iCnt; ++i)
    {
       s[i].key = i;
       s[i].value = i * i;
    }
    s[3].key = 2;
//    auto fun = [](S stTmp) -> int{
//        return stTmp.key;
//    };
    ManageArray<S, int> manageArray(iCnt, s, GetKey);

    manageArray.DeleteKey(7);
    manageArray.DeleteKey(9);

    manageArray.DeleteAllKey(2);

    for(int i = 0; i < iCnt; ++i)
    {
        cout << s[i].key << " " << s[i].value << endl;
    }
    return 0;
}