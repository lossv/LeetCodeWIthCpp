//
// Created by lossv on 2022/7/27.
//

#include <string>
#include <iostream>
#include <vector>
#include <functional>

using namespace std;


class Solution
{
public:
    string fractionAddition(string expression)
    {
        if(expression[0] != '-')
            expression = '+' + expression;
        string strRes;
        int up = 0, down = 1, curIndex = 0;
        int curUP, curDown;
        while (curIndex < expression.length())
        {
            curUP = getNextValue(expression, curIndex);
            curDown = getNextValue(expression, curIndex);

            up = up * curDown + curUP * down;
            down = down * curDown;

        }
        int gcdValue = abs(__gcd(up, down));

        return to_string(up / gcdValue) + "/" + to_string(down / gcdValue);
    }

    int getNextValue(string &expression, int &curIndex)
    {
        string strValue;
        bool flag = expression[curIndex++] != '-';

        while (curIndex != expression.length() && expression[curIndex] != '+' && expression[curIndex] != '-' &&
               expression[curIndex] != '/')
        {
            strValue += expression[curIndex++];
        }

        return flag ? stoi(strValue) : -stoi(strValue);
    }

};


int main()
{
    Solution solution;
    string str = "1/3-1/2";
    cout << solution.fractionAddition(str) << endl;

    return 0;
}