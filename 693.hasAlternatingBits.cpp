//
// Created by lossv on 2022/3/28.
//

#include <iostream>

using namespace std;

class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        long a = n ^ (n >> 1);
        return (a & (a + 1)) == 0;
    }
};


int main()
{
    return 0;
}