//
// Created by 觉而不绝 on 2023/3/15.
//
#include "comm.h"

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int cnt = 0;

        int left = 0, right = nums.size() - 1;

        int mid = -1;
        bool flag = false;
        while (left <= right)
        {
            mid = (left + right) / 2;
            if (nums[mid] == target)
            {
                flag = true;
                break;
            }
            if (target > nums[mid])
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
        }

        if (!flag)
            return 0;

        cnt++;
        int tmp = mid - 1;
        while (tmp >= 0 && nums[tmp] == target)
        {
            cnt++;
            tmp--;
        }

        tmp = mid + 1;
        while (tmp < nums.size() && nums[tmp] == target)
        {
            cnt++;
            tmp++;
        }

        return cnt;
    }
};

int main()
{
    vector<int> nums = {1, 3};
    int target = 1;
    Solution solution;
    cout << solution.search(nums, target);
    return 0;
}