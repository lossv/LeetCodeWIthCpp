//
// Created by lossv on 2022/6/29.
//
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

class Solution
{
private:
    unordered_map<string, string> m_database;
public:

    static string strTiny;

    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        auto index = longUrl.find_last_of('/', longUrl.length() - 1);
        auto result = Solution::strTiny + longUrl.substr(index, longUrl.length() - index);
        m_database[result] = longUrl;
        return result;
    }

    // Decodes a shortened URL to its original URL.
    string decode(const string &shortUrl)
    {
        return m_database[shortUrl];
    }
};

string Solution::strTiny = "http://tinyurl.com";

int main()
{
    Solution solution;
    cout << solution.encode("https://leetcode.com/problems/design-tinyurl") << endl;
    return 0;
}