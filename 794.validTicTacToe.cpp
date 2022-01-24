//
// Created by lossv on 2021/12/9.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    bool validTicTacToe(vector<string> &board)
    {
        int cnt = 0, w[128]{};
        for (auto &&s: board) for (char c: s) cnt += c == 'O' ? -1 : c == 'X';
        for (int i = 0; i < 3; ++i)
        {
            ++w[board[i][0] | board[i][1] | board[i][2]];
            ++w[board[0][i] | board[1][i] | board[2][i]];
        }
        ++w[board[0][0] | board[1][1] | board[2][2]];
        ++w[board[0][2] | board[1][1] | board[2][0]];
        return cnt == 1 && !w['O'] || cnt == 0 && !w['X'];
    }
};

int main()
{
//    Solution solution;
//    vector<string> board = {
//            "XOX", "O O", "XOX"
//    };
//    cout << solution.validTicTacToe(board) << endl;


    return 0;
}