//
// Created by lossv on 2021/10/18.
//
#include <iostream>
#include <cstring>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int mMap[256];
        int preIndex = 0;
        int maxCount = 0;
        memset(mMap, -1, sizeof mMap);
        for(int i = 0; i < s.length(); ++i)
        {
            int ANSCIndex = int(s[i]);
            int tmpIndex = 0;
            if(mMap[ANSCIndex] == -1)
            {
                mMap[ANSCIndex] = i;
            }
            else
            {
                tmpIndex = mMap[ANSCIndex];
                if(tmpIndex >= preIndex)
                {
                    preIndex = tmpIndex + 1;
                }
                mMap[ANSCIndex] = i;
            }
            maxCount = max(maxCount, i - preIndex + 1);
        }
        return maxCount;
    }
};