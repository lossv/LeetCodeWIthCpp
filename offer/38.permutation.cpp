//
// Created by 觉而不绝 on 2023/3/17.
//
#include "comm.h"

using namespace std;

class Solution
{
public:

    void dfs(int index, string &curStr, string &orgStr)
    {
        if (curStr.length() == orgStr.length())
        {
            result.push_back(curStr);
            return;
        }

        for (int i = 0; i < orgStr.length(); ++i)
        {

            if (visit[i] || (i > 0 && !visit[i - 1] && orgStr[i - 1] == orgStr[i]))
            {
                continue;
            }


            visit[i] = true;
            curStr.push_back(orgStr[i]);
            dfs(index + 1, curStr, orgStr);
            visit[i] = false;
            curStr.pop_back();
        }
    }

    vector<string> permutation(string &s)
    {
        visit.resize(s.length());
        string curStr = "";
        sort(s.begin(), s.end());
        dfs(0, curStr, s);

        return result;
    }

private:
    vector<string> result;
    vector<bool> visit;
};

class Solution2
{
public:
    vector<string> result;
    vector<int> visit;

    void backtrack(const string &orgStr, string &curStr)
    {
        if (orgStr.length() == curStr.length())
        {
            result.push_back(curStr);
            return;
        }
        for (int j = 0; j < orgStr.length(); j++)
        {
            if (visit[j] || (j > 0 && !visit[j - 1] && orgStr[j - 1] == orgStr[j]))
            {
                continue;
            }

            visit[j] = true;
            curStr.push_back(orgStr[j]);
            backtrack(orgStr, curStr);
            curStr.pop_back();
            visit[j] = false;
        }
    }

    vector<string> permutation(string s)
    {
        int n = s.size();
        visit.resize(n);
        sort(s.begin(), s.end());
        string perm;
        backtrack(s, perm);
        return result;
    }
};


int main()
{
    Solution2 solution;
    string s = "suvyls";
    auto res = solution.permutation(s);
    PrintVector(res);
    return 0;
}