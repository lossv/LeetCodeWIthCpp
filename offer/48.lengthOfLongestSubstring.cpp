//
// Created by 觉而不绝 on 2023/3/15.
//
#include "comm.h"

using namespace std;


class Solution
{
public:
    int lengthOfLongestSubstring(string &s)
    {
        unordered_map<char, int> mapIndex;

        int leftIndex = 0;
        int maxSubStr = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            char c = s[i];
            if (mapIndex.count(c) > 0)
            {
                if (mapIndex[c] >= leftIndex)
                {
                    // 右移一步
                    leftIndex = mapIndex[c] + 1;
                }
                mapIndex[c] = i;
            }
            else
            {
                mapIndex[c] = i;
            }

            maxSubStr = max(maxSubStr, i - leftIndex + 1);
        }

        return maxSubStr;
    }
};

int main()
{
    Solution solution;
    string s = "abcabcbb";
    cout << solution.lengthOfLongestSubstring(s);

    return 0;
}