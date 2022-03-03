//
// Created by lossv on 2022/3/3.
//

#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class Solution
{
public:
    int addDigits(int num)
    {
        while (num >= 10)
        {
            int sum = 0;
            while (num > 0)
            {
                sum += num % 10;
                num /= 10;
            }
            num = sum;
        }
        return num;
    }

    int addDigits1(int num)
    {
        return (num - 1) % 9 + 1;
    }
};

int main()
{
    Solution solution;
    cout << solution.addDigits(100) << endl;
    return 0;
}