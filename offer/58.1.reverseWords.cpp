//
// Created by 觉而不绝 on 2023/3/15.
//
#include "comm.h"

using namespace std;

class Solution
{
public:
    string reverseWords(string &s)
    {
        reverse(s.begin(), s.end());
        int blankIndex = 0;
        for (int i = 0; i < s.length(); ++i)
        {
            if(blankIndex != 0)
            {
                s[blankIndex++] = ' ';
            }

            int end = i;
            while (end < s.length() && s[end] != ' ') s[blankIndex++] = s[end++];

            reverse(s.begin() + i, s.begin() + end);
            i = end;
        }

        return s;
    }
};

int main()
{
    Solution solution;
    string s = "the sky is blue";
    cout << solution.reverseWords(s);
}