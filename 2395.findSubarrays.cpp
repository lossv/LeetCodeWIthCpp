//
// Created by 觉而不绝 on 2023/3/26.
//

#include "comm.h"

using namespace std;

class Solution
{
public:
    bool findSubarrays(vector<int> &nums)
    {
        unordered_set<uint64_t> setRecord;

        for (int i = 0; i < nums.size() - 1; ++i)
        {
            uint64_t tmp = nums[i] + nums[i + 1];
            if (setRecord.count(tmp))
            {
                return true;
            }
            setRecord.insert(tmp);
        }

        return false;
    }
};

int main()
{
    Solution solution;
    vector<int> nums{1, 2, 3, 4, 5};
    cout << solution.findSubarrays(nums);
    return 0;
}