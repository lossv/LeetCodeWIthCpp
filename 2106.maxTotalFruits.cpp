#include "comm.h"

using namespace std;

class Solution
{
public:

    int maxTotalFruits(vector<vector<int>> &fruits, int startPos, int k)
    {
        int n = fruits.size(), ans = 0, sum = 0;
        for (int l = 0, r = 0; r < n; r++)
        {
            sum += fruits[r][1];
            while (l <= r &&
                   (fruits[r][0] - fruits[l][0] + min(abs(startPos - fruits[l][0]), abs(startPos - fruits[r][0]))) > k)
            {
                sum -= fruits[l][1];
                l++;
            }
            ans = max(ans, sum);
        }
        return ans;
    }
};


int main()
{
    Solution solution;
    vector<vector<int>> fruits{{0,  9},
                               {4,  1},
                               {5,  7},
                               {6,  2},
                               {7,  4},
                               {10, 9}};

    int startPos = 5, k = 4;

    cout << solution.maxTotalFruits(fruits, startPos, k);

    return 0;
}