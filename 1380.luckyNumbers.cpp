//
// Created by lossv on 2022/2/15.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int n = matrix.size();
        for (int i = 0; i < n; ++i)
        {
            auto minIndex = min_element(matrix[i].begin(), matrix[i].end());
            bool flag = true;
            for (int j = 0; j < n; ++j)
            {
                if (matrix[j][minIndex - matrix[i].begin()] > (*minIndex))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                ans.emplace_back(*minIndex);
            }
        }
        return ans;
    }
};

int main()
{

    return 0;
}