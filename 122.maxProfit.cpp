//
// Created by 觉而不绝 on 2023/4/22.
//

#include "comm.h"

using namespace std;

class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int result = 0;
        int preValue = INT32_MAX;
        for (auto price: prices)
        {
            if (preValue < price)
            {
                result += price - preValue;
            }

            preValue = price;
        }

        return result;
    }
};


int main()
{
    Solution solution;

    vector<int> prices{7, 1, 5, 3, 6, 4};
    cout << solution.maxProfit(prices);

    return 0;
}