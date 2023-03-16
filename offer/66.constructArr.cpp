//
// Created by 觉而不绝 on 2023/3/17.
//

#include "comm.h"

using namespace std;

class Solution
{
public:
    vector<int> constructArr(vector<int> &a)
    {
        vector<int> values(a.size(), 0);

        int curValue = 1;
        for(int i = 0; i < a.size(); ++i)
        {
            values[i] = curValue;
            curValue *= a[i];
        }

        curValue = 1;
        for(int i = a.size() - 1; i >= 0; --i)
        {
            values[i] *= curValue;
            curValue *= a[i];
        }

        return values;
    }
};