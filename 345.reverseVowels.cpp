#include "comm.h"

using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        int i = 0, j = s.size() - 1;
        string tool = "aoeiuAOEIU";
        while (i < j)
        {
            while (tool.find(s[i]) == -1 && i < j)
                ++i;
            while (tool.find(s[j]) == -1 && i < j)
                --j;
            if (i < j)
                swap(s[i++], s[j--]);
        }
        return s;
    }
};


int main()
{
    Solution solution;

    string s = "leetcode";

    cout << solution.reverseVowels(s);

    return 0;
}