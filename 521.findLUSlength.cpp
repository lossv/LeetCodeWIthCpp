//
// Created by 觉而不绝 on 2022/3/5.
//

#include <iostream>
#include <cstring>

using namespace std;

class Solution
{
public:
    int findLUSlength(string a, string b)
    {
        if(a == b)
            return -1;
        return max(a.length(), b.length());
    }
};

int main()
{
    Solution solution;
    string a = "abc";
    string b = "bcd";
    cout << solution.findLUSlength(a, b) << endl;

    return 0;
}