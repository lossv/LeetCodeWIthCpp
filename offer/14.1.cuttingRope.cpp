//
// Created by 觉而不绝 on 2023/3/17.
//
#include "comm.h"

using namespace std;

class Solution
{
public:
    int cuttingRope(int n)
    {
        if (n == 1)
            return 1;
        maxValue = 0;
        dfs(0, 1, 0, n);
        return maxValue;
    }

    void dfs(int n, int curValue, int splitCnt, int totalLen)
    {
        if (n == totalLen && splitCnt > 1)
        {
            maxValue = max(maxValue, curValue);
            return;
        }

        for (int i = 1; n + i <= totalLen; ++i)
        {
            dfs(n + i, i * curValue, splitCnt + 1, totalLen);
        }
    }


private:
    int maxValue;
};

class Solution2
{
public:
    int cuttingRope(int n)
    {
        vector<int> dp(n + 1);
        for (int i = 2; i <= n; i++)
        {
            int curMax = 0;
            for (int j = 1; j < i; j++)
            {
                curMax = max(curMax, max(j * (i - j), j * dp[i - j]));
            }
            dp[i] = curMax;
        }
        return dp[n];
    }
};


int main()
{
    Solution2 solution;

    int n = 29;
    cout << solution.cuttingRope(n);
    return 0;
}