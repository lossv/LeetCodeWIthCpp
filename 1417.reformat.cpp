//
// Created by lossv on 2022/8/11.
//


#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    string reformat(string s)
    {
        string number;
        string alpha;
        string res;
        for (auto &item: s)
        {
            if ('9' < item)
            {
                alpha += item;
            }
            else
            {
                number += item;
            }
        }

        if (abs(int(number.length() - alpha.length())) > 1)
        {
            return "";
        }

        for (int i = 0; i < s.length() / 2; ++i)
        {
            res += number[i];
            res += alpha[i];
        }

        if(s.length() % 2 != 0)
        {
            if(number.length() > alpha.length())
                res += number[number.length() - 1];
            else
                res = alpha[alpha.length() - 1] + res;
        }

        return res;
    }
};

int main()
{
    Solution solution;
    string test = "covid2019";
    cout << solution.reformat(test);
    return 0;
}