//
// Created by 觉而不绝 on 2023/4/22.
//

#include "comm.h"

using namespace std;

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int can_reach = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (i > can_reach) return false;
            can_reach = max(can_reach, i + nums[i]);
        }
        return true;
    }
};

int main()
{
    Solution solution;
    vector<int> nums{3, 2, 1, 0, 4};

    cout << solution.canJump(nums);

    return 0;
}


