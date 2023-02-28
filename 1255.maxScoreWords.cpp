//
// Created by 觉而不绝 on 2023/2/26.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int maxScoreWords(vector<string> &words, vector<char> &letters, vector<int> &score)
    {
        int n = words.size();
        int res = 0;
        vector<int> count(26);

        for (auto c: letters)
        {
            count[c - 'a']++;
        }


        for (int i = 0; i < (1 << n); ++i)
        {
            vector<int> worldCount(26);
            for (int k = 0; k < n; ++k)
            {
                if (((i & (1 << k)) == 0))
                {
                    continue;
                }

                for (auto c: words[k])
                {
                    worldCount[c - 'a']++;
                }
            }

            bool ok = true;
            int sum = 0;
            for(int j = 0; j < score.size(); ++j)
            {
                sum += score[j] * worldCount[j];
                ok = ok && (worldCount[j] <= count[j]);
            }

            if(ok)
            {
                res = max(res, sum);
            }
        }

        return res;
    }
};


int main()
{
    vector<string> words = {"dog","cat","dad","good"};
    vector<char> letters = {'a','a','c','d','d','d','g','o','o'};
    vector<int> socre = {1,0,9,5,0,0,3,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0};
    Solution solution;
    cout << solution.maxScoreWords(words, letters, socre) << endl;
    return 0;
}