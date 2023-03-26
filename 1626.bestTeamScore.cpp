//
// Created by 觉而不绝 on 2023/3/22.
//
#include "comm.h"

using namespace std;

class Solution
{
public:
    int bestTeamScore(vector<int> &scores, vector<int> &ages)
    {
        int n = scores.size();
        vector<pair<int, int>> people;
        for (int i = 0; i < n; ++i)
        {
            people.emplace_back(scores[i], ages[i]);
        }
        sort(people.begin(), people.end());
        vector<int> dp(n, 0);
        int res = 0;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (people[i].second >= people[j].second)
                {
                    dp[i] = max(dp[i], dp[j]);
                }
            }
            dp[i] += people[i].first;
            res = max(res, dp[i]);
        }
        return res;
    }
};


int main()
{
    Solution solution;
    vector<int> scores{1, 1, 1, 2};
    vector<int> ages{2, 2, 2, 1};

    cout << solution.bestTeamScore(scores, ages);
    return 0;
}