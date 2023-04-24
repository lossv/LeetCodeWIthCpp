#include "comm.h"

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int i = 0, j = numbers.size() - 1;
        while (true)
        {
            int tmpSum = numbers[i] + numbers[j];
            if (tmpSum > target)
            {
                --j;
            }
            else if (tmpSum < target)
            {
                ++i;
            }
            else
            {
                break;
            }
        }

        return {i + 1, j + 1};
    }
};