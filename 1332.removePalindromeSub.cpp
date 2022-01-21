//
// Created by 觉而不绝 on 2022/1/22.
//

#include <iostream>

using namespace std;

class Solution
{
public:
    int removePalindromeSub(string s)
    {
        if (s.length() == 0)
            return 0;
        if (check(s))
            return 1;

        return 2;
    }

    bool check(string s)
    {
        for (int i = 0; i < s.length() / 2; ++i)
        {
            if (s[i] != s[s.length() - i - 1])
                return false;
        }
        return true;
    }
};

int main()
{
    Solution solution;
    string str = "";
    cout << solution.removePalindromeSub(str) << endl;
    cout << solution.check("abbbab") << endl;
    return 0;
}