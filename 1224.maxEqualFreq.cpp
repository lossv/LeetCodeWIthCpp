//
// Created by lossv on 2022/8/18.
//

#include <vector>
#include <iostream>
#include <unordered_map>
#include <set>
#include <numeric>

using namespace std;

class Solution
{
public:
    int maxEqualFreq(vector<int> &nums)
    {
        unordered_map<int, int> freq, count;
        int res = 0, maxFreq = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (count[nums[i]] > 0)
            {
                freq[count[nums[i]]]--;
            }
            count[nums[i]]++;
            maxFreq = max(maxFreq, count[nums[i]]);
            freq[count[nums[i]]]++;
            bool ok = maxFreq == 1 ||
                      freq[maxFreq] * maxFreq + freq[maxFreq - 1] * (maxFreq - 1) == i + 1 && freq[maxFreq] == 1 ||
                      freq[maxFreq] * maxFreq + 1 == i + 1 && freq[1] == 1;
            if (ok)
            {
                res = max(res, i + 1);
            }
        }
        return res;
    }
};

int main()
{
//    auto nums = {1, 1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 4, 5};
//    auto nums = {2, 2, 1, 1, 5, 3, 3, 5};
    auto nums = {1, 1, 2, 3, 4, 4, 4};
//    auto nums = {1, 1, 1, 2, 2, 2};
    Solution solution;
    cout << solution.maxEqualFreq(nums) << endl;
    return 0;
}