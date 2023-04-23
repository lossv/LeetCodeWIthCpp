//
// Created by 觉而不绝 on 2023/4/22.
//

#include "comm.h"

using namespace std;

class Solution
{
public:
    int jump(vector<int> &nums)
    {
        vector<int> dp(nums.size(), INT32_MAX);
        dp[0] = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = 1; j <= nums[i] && j + i < nums.size(); ++j)
            {
                if(dp[i + j] == INT32_MAX)
                {
                    dp[i + j] = dp[i] + 1;
                }
                else
                {
                    dp[i + j] = min(dp[i] + 1, dp[i + j]);
                }
            }
        }

        return dp[nums.size() - 1];
    }
};

int main()
{
    Solution solution;
    vector<int> nums{2,3,1,1,4, 0};

    cout << solution.jump(nums);

    return 0;
}