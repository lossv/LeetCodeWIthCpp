//
// Created by 觉而不绝 on 2022/8/14.
//

#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    int maxScore(string s)
    {
        int cnt1 = 0;
        int maxScore = 0;
        int cnt0 = 0;
        for (auto &c: s)
            if (c == '1')
                cnt1++;
        if(cnt1 == 0 || cnt1 == s.length())
            return s.length() - 1;
        for (int i = 0; i < s.length() - 1; ++i)
        {
            if (s[i] == '0')
                cnt0++;
            else
                cnt1--;
            maxScore = max(maxScore, cnt1 + cnt0);
        }

        return maxScore;
    }
};


int main()
{
    string s = "0001011100010010111000000001001001000110010000000000";
    Solution solution;
    cout << solution.maxScore(s);
    return 0;
}