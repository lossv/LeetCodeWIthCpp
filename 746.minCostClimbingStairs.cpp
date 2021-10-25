//
// Created by lossv on 2021/10/25.
//

#include <iostream>
#include <vector>

using namespace std;


class Solution
{
public:
    int minCostClimbingStairs(vector<int>& cost)
    {
        int length = cost.size();
        if(length == 0)
            return 0;
        if(length == 1)
            return cost[0];
        if(length == 2)
            return min(cost[1], cost[0]);
        for(int i = 2; i < cost.size(); ++i)
        {
            cost[i] = min(cost[i] + cost[i - 1], cost[i] + cost[i - 2]);
        }
        return min(cost[length - 2], cost[length - 1]);
    }
};


int main()
{
    Solution solution;
    vector<int> cost = {1,100};
    cout << solution.minCostClimbingStairs(cost) << endl;
    return 0;
}