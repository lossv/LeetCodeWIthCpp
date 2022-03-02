//
// Created by lossv on 2022/2/28.
//

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    int ret;
    int cnt = 0;
    vector<int> mask;

    int maximumRequests(int n, vector<vector<int>> &requests)
    {
        ret = 0;
        mask.resize(n);
        backtracking(requests, 0);
        return ret;
    }

    void backtracking(vector<vector<int>> &requests, int pos)
    {
        if (pos == requests.size())
        {
            // 只有mask内元素全为0，才是合理的方案
            for (auto &n: mask)
            {
                if (n > 0)
                    return;
            }
            ret = max(ret, cnt);
            return;
        }
        // 不选pos
        backtracking(requests, pos + 1);
        // 选
        int out = requests[pos][0], in = requests[pos][1];
        mask[out] -= 1;
        mask[in] += 1;
        cnt++;
        backtracking(requests, pos + 1);
        // 回溯
        mask[out] += 1;
        mask[in] -= 1;
        cnt--;
    }
};

int main()
{
    return 0;
}