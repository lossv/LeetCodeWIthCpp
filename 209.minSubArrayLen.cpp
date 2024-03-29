#include "comm.h"

using namespace std;

class Solution
{
public:
    int minSubArrayLen(int s, vector<int> &nums)
    {
        int n = nums.size();
        if (n == 0)
        {
            return 0;
        }
        int ans = INT_MAX;
        int start = 0, end = 0;
        int sum = 0;
        while (end < n)
        {
            sum += nums[end];
            while (sum >= s)
            {
                ans = min(ans, end - start + 1);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};


int main()
{
    Solution solution;
    int target = 6;
    vector<int> nums = {10, 2, 3};

    cout << solution.minSubArrayLen(target, nums);

    return 0;
}