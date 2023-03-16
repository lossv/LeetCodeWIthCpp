//
// Created by 觉而不绝 on 2023/3/16.
//
#include "comm.h"

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int count = 0, res = -1;
        for (auto num: nums)
        {
            if (count == 0)
            {
                count = 1;
                res = num;
            }
            else
                res == num ? ++count : --count;
        }

        return res;
    }
};