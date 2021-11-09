//
// Created by lossv on 2021/11/9.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxCount(int m, int n, vector<vector<int>> &ops)
    {
        if(ops.size() == 0)
            return m * n;
        int rangeA = m, rangeB = n;
        for (auto & op : ops)
        {
            rangeA = min(op[0], rangeA);
            rangeB = min(op[1], rangeB);
        }
        return rangeA * rangeB;
    }
};

int main()
{
    Solution solution;
    int m = 3, n = 3;
    vector<vector<int>> operations = {{2, 2},
                                      {3, 3}};
    cout << solution.maxCount(m, n, operations);
    return 0;
}