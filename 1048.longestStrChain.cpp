#include "comm.h"

using namespace std;

class Solution
{
public:
    int longestStrChain(vector<string> &words)
    {
        sort(words.begin(), words.end(), [](string &a, string &b) -> bool
            {
                return a.length() < b.length();
            });

        unordered_map<string, int> mapWord;
        for (auto &s: words)
        {
            mapWord[s] = 1;
        }


        int result = 1;
        for (auto &s: words)
        {
            for (int i = 0; i < s.length(); ++i)
            {
                auto tmpStr = s.substr(0, i) + s.substr(i + 1);
                if (mapWord.count(tmpStr))
                {
                    mapWord[s] = max(mapWord[s], mapWord[tmpStr] + 1);
                }
            }

            result = max(mapWord[s], result);
        }

        return result;
    }

};


int main()
{
    Solution solution;

    vector<string> words{"a", "b", "ba", "bca", "bda", "bdca"};

    cout << solution.longestStrChain(words);

    return 0;
}