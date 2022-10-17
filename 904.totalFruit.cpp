//
// Created by lossv on 2022/10/17.
//

#include <vector>
#include <map>
#include <iostream>


using std::cout;
using std::map;
using std::vector;

class Solution
{
public:
    int totalFruit(vector<int> &fruits)
    {
        int left = 0, right = 0, ans = 0;
        int ln = fruits[left], rn = fruits[right];
        while (right < fruits.size())
        {
            if (fruits[right] == rn || fruits[right] == ln)
            {
                ans = std::max(ans, right + 1 - left);
                right++;
            }
            else
            {
                left = right - 1;
                ln = fruits[left];
                while (left >= 1 && fruits[left - 1] == ln) left--;
                rn = fruits[right];
                ans = std::max(ans, right + 1 - left);
            }
        }
        return ans;
    }
};

int main()
{
    vector<int> fruits = {1, 0, 1, 4, 1, 4, 1, 2, 3};
    Solution solution;
    cout << solution.totalFruit(fruits);
    return 0;
}