#include "comm.h"

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        vector<vector<int>> result;
        int size = nums.size();
        for (int i = 0; i < size - 2; ++i)
        {
            int value = nums[i];
            int left = i + 1, right = size - 1;
            if(i && nums[i - 1] == nums[i])
            {
                continue;
            }

            while (left < right)
            {
                if (right + 1 < size && nums[right] == nums[right + 1])
                {
                    --right;
                    continue;
                }

                if (left - 1 > i && nums[left] == nums[left - 1])
                {
                    ++left;
                    continue;
                }

                if (nums[left] + nums[right] == -value)
                {
                    result.push_back({value, nums[left], nums[right]});
                    --right;
                    continue;
                }

                if (nums[left] + nums[right] > -value)
                {
                    --right;
                }
                else
                {
                    ++left;
                }
            }
        }

        return result;
    }
};


int main()
{
    Solution solution;

    vector<int> nums = {0,1,1};
    auto res = solution.threeSum(nums);
    PrintVector(res);


    return 0;
}