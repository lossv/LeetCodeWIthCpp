//
// Created by lossv on 2022/3/2.
//

#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution
{
public:
    vector<long> getCandidates(const string &n)
    {
        int len = n.size();
        vector<long> candidate = {
                (long) pow(10, len - 1) - 1,
                (long) pow(10, len) + 1
        };

        long prefix = stol(n.substr(0, (len + 1) / 2));
        for (auto item: {prefix - 1, prefix, prefix + 1})
        {
            auto tmp = to_string(item);
            auto tmpCandidate = tmp + string(tmp.rbegin() + (len & 1), tmp.rend());
            candidate.emplace_back(stol(tmpCandidate));
        }

        return candidate;
    }

    string nearestPalindromic(string &n)
    {
        long selfNumber = stol(n), ans = -1;
        auto candidates = getCandidates(n);
        for (auto &candidate: candidates)
        {
            if (candidate != selfNumber)
            {
                if (ans == -1 ||
                    abs(candidate - selfNumber) < abs(ans - selfNumber) ||
                    abs(candidate - selfNumber) == abs(ans - selfNumber) && candidate < ans)
                {
                    ans = candidate;
                }
            }
        }
        return to_string(ans);
    }


};

int main()
{
    Solution solution;
    string str = "10";
    cout << solution.nearestPalindromic(str) << endl;
    return 0;
}