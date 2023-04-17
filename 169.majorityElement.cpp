//
// Created by 觉而不绝 on 2023/4/17.
//
#include "comm.h"

using namespace std;

class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int iValue = nums[0];
        int iCount = 1;
        for(int i = 1; i < nums.size(); ++i)
        {
            if(iValue == nums[i])
            {
                ++iCount;
            }
            else
            {
                if(--iCount == 0)
                {
                    iValue = nums[i];
                    iCount = 1;
                }
            }

        }

        return iValue;
    }
};

int main()
{
    vector<int> nums{3, 2, 3};
    Solution solution;
    cout << solution.majorityElement(nums);
    return 0;
}