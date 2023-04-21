#include "comm.h"

using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int maxValue = *max_element(candies.begin(), candies.end());
        vector<bool> result;

        for(auto item : candies)
        {
            if(item + extraCandies >= maxValue)
            {
                result.emplace_back(true);
            }
            else
            {
                result.emplace_back(false);
            }
        }

        return result;

    }
};