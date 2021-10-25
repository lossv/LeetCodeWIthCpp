//
// Created by lossv on 2021/10/21.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        bool flag = false;

        for (int i = digits.size() - 1; i >= 0; --i)
        {
            int tmp = 0;
            if (i == digits.size() - 1)
                tmp = digits[i] + 1;
            else
                tmp += digits[i] + (flag ? 1 : 0);

            digits[i] = tmp % 10;
            if (tmp >= 10)
                flag = true;
            else
            {
                flag = false;
                break;
            }
        }
        if (flag)
            digits.insert(digits.begin(), 1);
        return digits;
    }
};

int main()
{
    vector<int> digits = {1, 9, 9};
    Solution solution;
    solution.plusOne(digits);
    for (auto i: digits)
        cout << i << " ";
    return 0;
}
