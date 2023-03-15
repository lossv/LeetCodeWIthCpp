//
// Created by 觉而不绝 on 2023/3/16.
//
#include "comm.h"

using namespace std;


class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        int left = 0, right = nums.size() - 1;
        while (left < right)
        {
            if (nums[right] > target)
            {
                --right;
                continue;
            }

            int value = nums[left] + nums[right];
            if (value > target)
            {
                --right;
            }
            else if (value < target)
            {
                ++left;
            }
            else
            {
                return {nums[left], nums[right]};
            }
        }

        return {};
    }
};


int main()
{

    vector<int> nums = {10,26,30,31,47,60};
    int target = 40;

    Solution solution;

    auto res = solution.twoSum(nums, target);

    PrintVector(res);

    return 0;
}