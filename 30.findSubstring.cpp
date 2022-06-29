//
// Created by lossv on 2022/6/23.
//
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    vector<int> findSubstring(string s, vector<string> &words)
    {
        if (s.empty() || words.empty())
            return {};
        int listLen = words.size(), wordSize = words[0].size(), j = 0;
        if (s.size() < wordSize * listLen)
            return {};
        vector<int> res;
        unordered_map<string, int> mapWords, tmp;
        for (auto str: words)
        {
            ++mapWords[str];
        }
        string str;
        for (int i = 0; i + wordSize * listLen <= s.size(); ++i)
        {
            for (j = i; j < i + wordSize * listLen; j += wordSize)
            {
                str = s.substr(j, wordSize);
                if (mapWords.find(str) == mapWords.end())
                    break;
                ++tmp[str];
            }
            if (j == i + wordSize * listLen && tmp == mapWords)
                res.push_back(i);
            tmp.clear();
        }

        return res;
    }
};


int main()
{
    Solution solution;
    return 0;
}