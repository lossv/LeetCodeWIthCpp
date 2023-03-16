//
// Created by 觉而不绝 on 2023/3/16.
//
#include "comm.h"

using namespace std;

class Solution
{
public:
    int countSubarrays(vector<int> &nums, int k)
    {
        int diff = 0;
        unordered_map<int, int> mapRecord;
        mapRecord[0] = 1;
        bool find = false;
        int ans = 0;
        for(auto num: nums)
        {
            if(num > k)
            {
                ++diff;
            }
            else if(num < k)
            {
                --diff;
            }
            else
            {
                find = true;
            }

            if(find)
            {
                ans += mapRecord[diff];
                ans += mapRecord[diff - 1];
            }
            else
            {
                mapRecord[diff] = 1;
            }
        }

        return ans;
    }
};