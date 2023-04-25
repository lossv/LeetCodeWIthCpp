#include "comm.h"

using namespace std;


class Solution
{
public:
    vector<string> sortPeople(vector<string> &names, vector<int> &heights)
    {
        map<int, string> hash;
        vector<string> ans;
        for (int i = 0; i < names.size(); ++i) hash[heights[i]] = names[i];
        for (auto &i: hash) ans.push_back(i.second);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};