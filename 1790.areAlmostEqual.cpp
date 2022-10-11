//
// Created by dmlt on 2022/10/11.
//

#include <string>
#include <set>

using namespace std;

class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        if(s1.length() != s2.length())
            return false;
        set<char> set1;
        set<char> set2;
        int cnt = 0;
        for(int i = 0; i < s1.length(); ++i)
        {
            if(s1[i] != s2[i])
            {
                ++cnt;
                set1.insert(s1[i]);
                set2.insert(s2[i]);
            }
            if(cnt > 2)
                return false;
        }

        return (cnt == 2 or cnt == 0) and set1 == set2;
    }
};

class SolutionBetter {
public:
    bool areAlmostEqual(string s1, string s2) {
        int mask1 = 0, mask2 = 0, cnt = 0, n = s1.size();
        for(int i=0; i<n; ++i){
            if(s1[i]!=s2[i]){
                cnt++;
                mask1 |= 1<<(s1[i]-'a');
                mask2 |= 1<<(s2[i]-'a');
            }
        }
        return cnt==0 || (cnt==2 && (mask1==mask2));
    }
};