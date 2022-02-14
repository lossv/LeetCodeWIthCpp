//
// Created by lossv on 2022/2/14.
//
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int singleNonDuplicate(vector<int> &nums)
    {
        int result = 0;
        for (auto item: nums)
        {
            result = result xor item;
        }

        return result;
    }
};


int main()
{
    vector<int> nums = {1, 1, 2, 3, 3, 4, 4, 8, 8};
    Solution solution;
    cout << solution.singleNonDuplicate(nums);
    return 0;
}