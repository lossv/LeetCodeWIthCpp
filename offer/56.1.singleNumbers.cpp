#include "comm.h"

using namespace std;

class Solution
{
public:
    vector<int> singleNumbers(vector<int> &nums)
    {
        int value = 0;
        for (auto num: nums)
        {
            value ^= num;
        }

        int div = 1;
        while ((value & div) == 0)
            div <<= 1;

        int a = 0, b = 0;
        for (auto num: nums)
        {
            if (num & div)
            {
                a ^= num;
            }
            else
            {
                b ^= num;
            }
        }

        return {a, b};
    }
};

int main()
{
    Solution solution;
    vector<int> a{1, 1, 2, 2, 4, 5};
    auto res = solution.singleNumbers(a);
    PrintVector(res);
}