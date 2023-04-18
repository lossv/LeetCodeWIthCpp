#include "comm.h"

using namespace std;


class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int i = 0;
        for (int n: nums)
            if (i < 2 || n != nums[i - 2])
                nums[i++] = n;
        return i;
    }
};


int main()
{
    vector<int> nums{0, 0, 1, 1, 1, 1, 2, 3, 3};
    Solution solution;
    auto res = solution.removeDuplicates(nums);
    PrintVector(nums);
    return 0;
}