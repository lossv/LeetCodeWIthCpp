//
// Created by 觉而不绝 on 2023/4/22.
//

#include "comm.h"

using namespace std;

class Solution
{
public:
    int longestArithSeqLength(vector<int> &nums)
    {
        int ans = 0, n = nums.size();
        vector<vector<int>> dp(n, vector<int>(1001, 1));
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                int d = nums[i] - nums[j] + 500;
                dp[i][d] = max(dp[i][d], dp[j][d] + 1);
                ans = max(ans, dp[i][d]);
            }
        }
        return ans;
    }
};

