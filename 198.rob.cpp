//
// Created by lossv on 2021/10/25.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int rob(vector<int>& nums)
    {
        int length = nums.size();
        if(length == 0)
            return 0;
        if(length == 1)
            return nums[0];
        if(length == 2)
            return max(nums[0], nums[1]);
        if(length == 3)
            return max(nums[0] + nums[2], nums[1]);
        nums[2] += nums[0];
        for(int i = 3; i < length; ++i)
            nums[i] = max(nums[i] + nums[i - 2], nums[i] + nums[i - 3]);

        return max(nums[length - 1], nums[length - 2]);
    }
};


int main()
{
    Solution solution;
    vector<int> nums = {2,7,9,3,1};
    cout << solution.rob(nums) << endl;
    return 0;
}