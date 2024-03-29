//
// Created by 觉而不绝 on 2023/4/18.
//
#include "comm.h"

using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        k = k % nums.size();
        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};


int main()
{
    Solution solution;

    vector<int> nums{1, 2, 3, 4, 5, 6, 7};
    int n = 3;

    solution.rotate(nums, n);
    PrintVector(nums);
    return 0;
}