//
// Created by 觉而不绝 on 2022/5/27.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution
{
public:
    int findClosest(vector<string> &words, string word1, string word2)
    {
        int index_a = -1;
        int index_b = -1;
        int min_distance = INT32_MAX;

        for(int i = 0 ; i < words.size(); ++i)
        {
            if(words[i] == word1)
            {
                index_a = i;

            }

            else if(words[i] == word2)
            {
                index_b = i;
            }

            if(index_a != -1 && index_b != -1)
            {
                min_distance = min(min_distance, abs(index_b - index_a));
            }
        }

        return min_distance;
    }
};

int main()
{
    vector<string> str_list{"I","am","a","student","from","a","university","in","a","city"};
    string words_1 = "a";
    string words_2 = "student";

    Solution solution;

    cout << solution.findClosest(str_list, words_1, words_2) << endl;

    return 0;
}