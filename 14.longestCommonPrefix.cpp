#include "comm.h"

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int cnt = 0;
        int size = strs.size();
        if(size == 1)
        {
            return strs[0];
        }

        int flag = true;
        while (true)
        {
            for(int i = 0; i < size - 1; ++i)
            {
                if(cnt == strs[i].length() || cnt == strs[i + 1].length())
                {
                    flag = false;
                    break;
                }

                if(strs[i][cnt] != strs[i + 1][cnt])
                {
                    flag = false;
                    break;
                }
            }

            if(!flag)
            {
                break;
            }

            ++cnt;
        }

        return strs[0].substr(0, cnt);
    }
};