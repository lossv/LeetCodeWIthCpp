//
// Created by lossv on 2021/10/20.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:

    int minMoves(vector<int>& nums)
    {
        int small = nums[0];
        int ans = 0;
        for(auto value: nums)
            small = min(small, value);
        for(auto value: nums)
            ans += value - small;
        return ans;
    }
};


int main()
{
    vector<int> nums = {1, 2, 3};
    Solution solution;
    cout << solution.minMoves(nums) << endl;
    return 0;
}