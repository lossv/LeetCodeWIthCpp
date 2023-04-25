#include "comm.h"

using namespace std;

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int i = 0, j = height.size() - 1;
        int result = 0;
        while (i < j)
        {
            result = max(min(height[i], height[j]) * (j - i), result);
            if (height[i] > height[j])
            {
                --j;
            }
            else
            {
                ++i;
            }
        }


        return result;
    }
};