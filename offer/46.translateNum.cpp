//
// Created by 觉而不绝 on 2023/3/14.
//
#include "comm.h"

using namespace std;

class Solution
{
public:
    int translateNum(int num)
    {
        auto str = to_string(num);
        vector<int> dp(str.length() + 1);
        dp[0] = 1;
        dp[1] = 1;
        for(int i = 2; i <= str.length(); ++i)
        {
            auto subStr = str.substr(i - 2, 2);
            if("10" <= subStr && subStr <= "25")
            {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            else
            {
                dp[i] = dp[i - 1];
            }
        }

        return dp[dp.size() - 1];
    }
};


int main()
{
    Solution solution;
    cout << solution.translateNum(12258);
    return 0;
}