#include "comm.h"

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        int left = 0, right = 0;
        int n = height.size();
        int maxValueIndex = 0;
        for (int i = 0; i < n; ++i)
        {
            if (height[maxValueIndex] < height[i])
            {
                maxValueIndex = i;
            }
        }

        int pre = -1;
        int result = 0;

        for (int i = 0; i <= maxValueIndex; ++i)
        {
            if (height[i] > pre)
            {
                pre = height[i];
                continue;
            }

            result += pre - height[i];
        }

        pre = -1;
        for (int i = n - 1; i >= maxValueIndex; --i)
        {
            if (height[i] >= pre)
            {
                pre = height[i];
                continue;
            }

            result += pre - height[i];
        }

        return result;
    }
};

int main()
{
    Solution solution;
    vector<int> nums{4,2,0,3,2,5};

    cout << solution.trap(nums);

    return 0;
}