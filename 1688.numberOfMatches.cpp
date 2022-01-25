//
// Created by lossv on 2022/1/25.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfMatches(int n)
    {
        return n - 1;
    }
};

int main()
{
    Solution solution;
    cout << solution.numberOfMatches(7) << endl;
    return 0;
}