//
// Created by 觉而不绝 on 2023/3/17.
//
#include "comm.h"

using namespace std;

class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        if (k == 0)
        {
            return {};
        }

        vector<int> result;
        priority_queue<pair<int, int>> queue;
        for (int i = 0; i < k; ++i)
        {
            queue.emplace(nums[i], i);
        }

        result.emplace_back(queue.top().first);
        for (int i = k; i < nums.size(); ++i)
        {
            queue.emplace(nums[i], i);
            while (queue.top().second <= i - k)
                queue.pop();
            result.emplace_back(queue.top().first);
        }

        return result;

    }
};


int main()
{
    Solution solution;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    auto res = solution.maxSlidingWindow(nums, k);

    PrintVector(res);
    return 0;
}