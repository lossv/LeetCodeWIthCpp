#include "comm.h"

using namespace std;

class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int left = 0, right = nums.size();
        while (left < right)
        {
            if(nums[left] == val)
            {
                std::swap(nums[left], nums[--right]);
            }
            else
            {
                ++left;
            }

        }

        return left;
    }
};

int main()
{

    return 0;
}