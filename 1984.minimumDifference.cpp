//
// Created by lossv on 2022/2/11.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int minimumDifference(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int ans = INT32_MAX;
        for (int i = k - 1; i < nums.size(); ++i)
        {
            ans = min(ans, nums[i] - nums[i - k + 1]);
        }
        return ans;
    }
};

int main()
{
    int num = 6;
    num &= (~(1 << 2));
    cout << num << endl;
    return 0;
}