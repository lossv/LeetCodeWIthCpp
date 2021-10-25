//
// Created by lossv on 2021/10/21.
//

#include <iostream>

using namespace std;

class Solution
{
public:
    int fib(int n)
    {
        int a = 0, b = 1;
        while (n)
        {
            n--;
            int tmp = a + b;
            a = b;
            b = tmp;
        }
        return a;
    }
};

int main()
{
    Solution solution;
    cout << solution.fib(4) << endl;
    return 0;
}