//
// Created by 觉而不绝 on 2023/2/28.
//
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution
{
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>> &items1, vector<vector<int>> &items2)
    {
        map<int, int> m_map;
        for(auto &item : items1)
            m_map[item[0]] += item[1];

        for(auto &item : items2)
            m_map[item[0]] += item[1];


        vector<vector<int>> res;
        for(auto &[value, weight] : m_map)
        {
            res.push_back({value, weight});
        }

        return res;
    }
};


int main()
{

    return 0;
}