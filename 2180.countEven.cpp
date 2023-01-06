//
// Created by lossv on 2023/1/6.
//

#include <vector>
#include <map>
#include <iostream>

using namespace std;

class Solution
{
public:
    int countEven(int num)
    {
        int y = num / 10, x = num % 10;
        int res = y * 5, ySum = 0;
        while (y)
        {
            ySum += y % 10;
            y /= 10;
        }
        if (ySum % 2 == 0)
        {
            res += x / 2 + 1;
        }
        else
        {
            res += (x + 1) / 2;
        }
        return res - 1;
    }
};


int main()
{
    int a = 30;
    Solution solution;
    cout << solution.countEven(a);
    return 0;
}