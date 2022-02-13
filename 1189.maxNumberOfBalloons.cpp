//
// Created by 觉而不绝 on 2022/2/13.
//

#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    int maxNumberOfBalloons(string text)
    {
        sort(text.begin(), text.end());
        int num_a = 0, num_b = 0, num_l = 0, num_n = 0, num_o = 0;
        for(auto c : text)
        {
            if(c == 'a')
                ++num_a;
            else if(c == 'b')
                ++num_b;
            else if(c == 'l')
                ++num_l;
            else if(c == 'n')
                ++num_n;
            else if(c == 'o')
                ++num_o;
        }

        return min({num_a, num_b, num_l / 2, num_n, num_o / 2});
    }
};

int main()
{
    string text = "leetcode";

    Solution solution;
    cout << solution.maxNumberOfBalloons(text) << endl;

    return 0;
}