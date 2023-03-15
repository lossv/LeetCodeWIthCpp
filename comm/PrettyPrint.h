//
// Created by 觉而不绝 on 2023/3/16.
//

#ifndef LEETCODEWITHCPP_PRETTYPRINT_H
#define LEETCODEWITHCPP_PRETTYPRINT_H

#pragma once
#include "comm.h"

using std::vector;
using std::cout;
using std::endl;

template<typename T>
void PrintVector(vector<T> &data)
{
    for(auto item : data)
    {
        cout << item << " ";
    }

    cout << endl;
}

template<typename T>
void PrintVector(vector<vector<T>> &data)
{
    for(auto &items : data)
    {
        for(auto item : items)
        {
            cout << item << " ";
        }
        cout << endl;
    }

    cout << endl;
}

#endif //LEETCODEWITHCPP_PRETTYPRINT_H
