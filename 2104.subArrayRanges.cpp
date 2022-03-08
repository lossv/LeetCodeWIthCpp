//
// Created by lossv on 2022/3/4.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    long long subArrayRanges(vector<int> &nums)
    {
        int n = nums.size();
        long long ret = 0;
        for (int i = 0; i < n; i++)
        {
            int minVal = INT32_MAX, maxVal = INT32_MIN;
            for (int j = i; j < n; j++)
            {
                minVal = min(minVal, nums[j]);
                maxVal = max(maxVal, nums[j]);
                ret += maxVal - minVal;
            }
        }
        return ret;
    }
};

int main()
{
    Solution solution;
    vector<int> nums = {1, 2, 3, 3, 5};
    cout << solution.subArrayRanges(nums) << endl;
    return 0;
}