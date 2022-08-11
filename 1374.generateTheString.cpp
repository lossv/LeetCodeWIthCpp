//
// Created by lossv on 2022/8/1.
//

#include <string>

using namespace std;

class Solution
{
public:
    string generateTheString(int n)
    {
        string resulttStr;
        for(int i = 0; i < n - 1; ++i)
        {
            resulttStr += 'a';
        }
        if(n % 2 == 0)
        {
            resulttStr += 'b';
        }
        else
        {
            resulttStr += 'a';
        }

        return resulttStr;
    }
};


int main()
{

}