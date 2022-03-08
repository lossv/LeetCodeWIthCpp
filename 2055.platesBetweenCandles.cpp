//
// Created by lossv on 2022/3/8.
//

#include <iostream>
#include <vector>
#include <string>

using namespace std;


class Solution
{
public:
    vector<int> platesBetweenCandles(string &s, vector<vector<int>> &queries)
    {
        int n = s.length();
        vector<int> preSum(n), left(n), right(n);

        int sum = 0;
        for(int i = 0; i < n; ++i)
        {
            if(s[i] == '*')
                ++sum;
            preSum[i] = sum;
        }

        for(int i = 0, value = -1; i < n; ++i)
        {
            if(s[i] == '|')
                value = i;
            left[i] = value;
        }

        for(int i = n - 1, value = -1; i >= 0; --i)
        {
            if(s[i] == '|')
                value = i;
            right[i] = value;
        }

        vector<int> res;

        for (auto &query: queries)
        {
            int x = right[query[0]], y = left[query[1]];
            res.push_back(x == -1 || y == -1 || x >= y ? 0 : preSum[y] - preSum[x]);
        }

        return res;
    }
};


int main()
{
    Solution solution;
    string str = "**|**|***|";
    vector<vector<int>> queries = {{2, 5},
                                   {5, 9}};

    auto res = solution.platesBetweenCandles(str, queries);

    for (auto item: res)
        cout << item << " ";

    return 0;
}