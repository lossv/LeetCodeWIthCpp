//
// Created by lossv on 2022/8/12.
//
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int>> groupThePeople(vector<int> &groupSizes)
    {
        unordered_map<int, vector<int>> mMap;
        vector<vector<int>> result;
        for (int i = 0; i < groupSizes.size(); ++i)
        {
            mMap[groupSizes[i]].emplace_back(i);
        }

        for (auto [key, valueList]: mMap)
        {
            for (int i = 0; i < valueList.size(); i += key)
            {
                vector<int> tmp;
                tmp.insert(tmp.begin(), valueList.begin(), valueList.begin() + key);
                result.emplace_back(tmp);
            }
        }

        return result;
    }
};


int main()
{

    return 0;
}