//
// Created by 觉而不绝 on 2023/3/14.
//
#include "comm.h"

using namespace std;

class Solution
{
public:
    int maxValue(vector<vector<int>> &grid)
    {

        int n = grid.size();
        int m = grid[0].size();

        for (int i = 1; i < n; ++i)
        {
            grid[i][0] += grid[i - 1][0];
        }

        for (int i = 1; i < m; ++i)
        {
            grid[0][i] += grid[0][i - 1];
        }

        for (int i = 1; i < n; ++i)
        {
            for (int j = 1; j < m; ++j)
            {
                grid[i][j] = max(grid[i - 1][j], grid[i][j - 1]) + grid[i][j];
            }
        }

        return grid[n - 1][m - 1];
    }
};

int main()
{
    Solution solution;

    vector<vector<int> > grid{
            {1, 3, 1},
            {1, 5, 1},
            {4, 2, 1}
    };

    cout << solution.maxValue(grid) << endl;

    return 0;
}