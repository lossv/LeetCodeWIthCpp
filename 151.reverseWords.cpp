#include "comm.h"

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());

        int i = 0, j = 0;
        int worldCnt = 0;
        while (j < s.length())
        {
            if(s[j] != ' ')
            {
                worldCnt++;
                s[i++] = s[j++];
            }
            else
            {
                reverse(s.begin() + i - worldCnt, s.begin() + i);
                ++j;
                if(worldCnt && j < s.length())
                {
                    s[i++] = ' ';
                }
                worldCnt = 0;

            }
        }

        if(worldCnt)
        {
            reverse(s.begin() + i - worldCnt, s.begin() + i);
        }

        if(s[i - 1] == ' ')
        {
            return s.substr(0, i - 1);

        }

        return s.substr(0, i);

    }
};

int main()
{
    Solution solution;

    string s = "  hello world  ";

    cout << solution.reverseWords(s);

    return 0;
}