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
        vector<int> copyNums(nums);
        if(length == 0)
            return 0;
        if(length == 1)
            return nums[0];
        if(length == 2)
            return max(nums[0], nums[1]);
        if(length == 3)
            return max(max(nums[0], nums[1]), nums[2]);
        if(length == 4)
            return max(nums[0] + nums[2], nums[1] + nums[3]);
        nums[2] += nums[0];
        for(int i = 3; i < length - 1; ++i)
                nums[i] = max(nums[i] + nums[i - 2], nums[i] + nums[i - 3]);
        copyNums[3] += copyNums[1];
        for(int i = 4; i < length; ++i)
            copyNums[i] = max(copyNums[i] + copyNums[i - 2], copyNums[i] + copyNums[i - 3]);

        return max(max(nums[length - 3], nums[length - 2]), max(copyNums[length - 1], copyNums[length - 2]));
    }
};


int main()
{
    Solution solution;
    vector<int> nums = {6,3,10,8,2,10,3,5,10,5,3};
    cout << solution.rob(nums) << endl;
    return 0;
}