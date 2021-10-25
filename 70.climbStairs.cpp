//
// Created by lossv on 2021/10/25.
//

#include <iostream>

using namespace std;


class Solution
{
public:
    int climbStairs(int n)
    {
        if(n == 0)
            return 0;
        if(n == 1)
            return 1;
        if(n == 2)
            return 2;
        int a = 1;
        int b = 2;
        int tmp;
        while (n > 2)
        {
            n--;
            tmp = a + b;
            a = b;
            b = tmp;
        }
        return b;
    }
};

int main()
{
    Solution solution;
    cout << solution.climbStairs(3) << endl;
    return 0;
}