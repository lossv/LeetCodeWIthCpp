//
// Created by 觉而不绝 on 2022/4/5.
//

#include <iostream>

class Solution
{
public:
    int countPrimeSetBits(int left, int right)
    {
        int ans = 0;
        for (int x = left; x <= right; ++x)
        {
            if ((1 << __builtin_popcount(x)) & 665772)
            {
                ++ans;
            }
        }
        return ans;
    }
};


int main()
{
    int left = 10, right = 20;
    Solution solutionl;
    std::cout << solutionl.countPrimeSetBits(left, right);
    return 0;
}