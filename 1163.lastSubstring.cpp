#include "comm.h"

using namespace std;


class Solution
{
public:
    string lastSubstring(string s)
    {
        int startIndex = 0;
        int compareStartIndex = 0;
        int compareCnt = 0;
        int compareFlag = false;
        // cacacacacacacac

        for (int i = 0; i < s.length(); ++i)
        {
            if(s[i] > s[startIndex])
            {
                startIndex = i;
                continue;
            }
            else if(s[i] == s[startIndex] && !compareFlag && i != 0)
            {
                compareFlag = true;
                compareStartIndex = i;
                compareCnt = 1;
            }
            else
            {
                if(compareFlag)
                {
                    ++compareCnt;
                    char startIndexChar = s[startIndex + compareCnt - 1];
                    char compareStartIndexChar = s[compareStartIndex + compareCnt - 1];

//                    string startIndexStr = s.substr(startIndex, compareCnt);
//                    string compareStartIndexStr = s.substr(compareStartIndex, compareCnt);


                    if(startIndexChar < compareStartIndexChar)
                    {
                        startIndex = compareStartIndex;
                        i = startIndex;
                        compareFlag = false;
                        compareCnt = 0;
                    }
                    else if(startIndexChar > compareStartIndexChar)
                    {
                        compareFlag = false;
                        compareCnt = 0;
                    }
                }
            }
        }

        return s.substr(startIndex);
    }
};

int main()
{
    Solution solution;

    string s="jlidhumidloagrlvvxdqscegbeaybfhhyaeilzxdpyvvxixrjytdalknkospradmumysbkizziltzjwsxkteykblcvkfivzmtvnsyrfgvojhyzkouscymixrdfmehiwijntzqptqaxgalygtzvwxnsgcnygbjzeqmbactgmckvssvkentpxcnznrbbnkttnzpvlzfmdvvsozaiycumzlizbfxvyucyagclrifczcvzvrkiqiajindjjyxgxflnjcgckruujsbppxtwgwvrrxgniqplynvboqyvrsxnmbjhgoybqophbxmjhhrznezstujjuucvrrvofktxldxfaioyijoayggmvjmgzjflzxmkwxmxnyizampdcfntdfkxxprgfxjduiwrmgdfuprpljgnbzbedqbzhqsbmohbhlszvdzcgbimfurmkwqaignxbeevevonmdgupugcjxvqglqkwqzrlqequliwmfrvidtpprodcbhgkt";

    cout << solution.lastSubstring(s);


    return 0;
}