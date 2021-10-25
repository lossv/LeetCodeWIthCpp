//
// Created by lossv on 2021/10/25.
//

#include <iostream>

using namespace std;

class Solution
{
public:
    unsigned long long tribonacci(int n)
    {
        unsigned long long a = 0, b = 1, c = 1;
        unsigned long long tmp;
        while (n)
        {
            n--;
            tmp = a + b + c;
            a = b;
            b = c;
            c = tmp;
        }
        return a;
    }
};

int main()
{
    Solution solution;
    cout << solution.tribonacci(25) << endl;
    return 0;
}