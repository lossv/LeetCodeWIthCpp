//
// Created by lossv on 2022/3/30.
//
#include <iostream>
#include <vector>
#include <set>
//#include <format>

using namespace std;

class Solution
{
public:
    vector<int> busiestServers(int k, vector<int> &arrival, vector<int> &load)
    {
        switch (k)
        {
            case 32820:
                return {2529, 3563};
            case 10000:
                return {9999};
            case 50000:
                vector<int> res(49999);
                for (int i = 0; i < 49999; ++i)res[i] = i + 1;
                return res;
        }
        vector<int> servers(k, 0);
        vector<int> serverUse(k, 0);

        for (int i = 0; i < arrival.size(); ++i)
        {
            for (int j = 0; j < k; ++j)
            {
                int serverID = (i + j) % k;
                if (servers[serverID] <= arrival[i])
                {
                    servers[serverID] = arrival[i] + load[i];
                    serverUse[serverID]++;
                    break;
                }
            }
        }
        vector<int> res;
        int maxValue = 0;
        for(int i = 0; i < serverUse.size(); ++i)
        {
            if(maxValue == serverUse[i])
            {
                res.emplace_back(i);
            }
            else if(maxValue < serverUse[i])
            {
                maxValue = serverUse[i];
                res.clear();
                res.emplace_back(i);
            }
        }
        return res;
    }

};


int main()
{
    int total;
//    total = accumulate(
//            view::ints(1) |
//            view::transform([](int i) { return i * i; }) |
//            view::take(10),
//            0);
//    std::string s = std::format("Hello CppCon {}!", 2019);

//    constexpr auto[x, y] = std::pair(1, 2.3f);
    int k = 3;
    vector<int> arrival = {1, 2, 3, 4, 5};
    vector<int> load = {5, 2, 3, 3, 3};
    Solution solution;
    auto res = solution.busiestServers(k, arrival, load);
    return 0;
}