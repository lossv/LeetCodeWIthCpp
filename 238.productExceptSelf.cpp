#include "comm.h"

using namespace std;

class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> values(nums.size(), 1);
        int curValue = 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            values[i] = curValue;
            curValue *= nums[i];
        }

        curValue = 1;
        for (int i = nums.size() - 1; i >= 0; --i)
        {
            values[i] *= curValue;
            curValue *= nums[i];
        }

        return values;
    }
};


int main()
{
    Solution solution;
    vector<int> nums{-1,1,0,-3,3};

    auto res = solution.productExceptSelf(nums);
    PrintVector(res);

    return 0;
}