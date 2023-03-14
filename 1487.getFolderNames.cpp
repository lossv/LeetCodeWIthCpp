//
// Created by 觉而不绝 on 2023/3/3.
//

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<string> getFolderNames(vector<string> &names)
    {
        unordered_map<string, int> m_map;
        vector<string> res;

        for (auto &item: names)
        {
            if(m_map[item] == 0)
            {
                res.emplace_back(item);
            }

        }
    }
};


int main()
{

    return 0;
}