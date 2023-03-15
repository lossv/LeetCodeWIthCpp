//
// Created by 觉而不绝 on 2023/3/15.
//
#include "comm.h"

using namespace std;


class Solution
{
public:

    Solution()
    {
        flag = false;
    }

    bool exist(vector<vector<char>> &board, string &word)
    {
        visit = new int *[board.size()];
        for (int i = 0; i < board.size(); ++i)
        {
            visit[i] = new int[board[0].size()];
            memset(visit[i], 0, sizeof(int) * board[0].size());
        }

        for (int i = 0; i < board.size(); ++i)
        {
            for (int j = 0; j < board[0].size(); ++j)
            {
                dfs(i, j, board.size(), board[0].size(), "", word, board);
                if(flag)
                {
                    return flag;
                }
            }
        }
        return flag;
    }

    void dfs(int x, int y, int n, int m, string curWord, string &target, vector<vector<char>> &board)
    {
        if (x >= n || y >= m || x < 0 || y < 0 || flag || visit[x][y] == 1 || curWord.size() >= target.size()) return;

        if(board[x][y] != target[curWord.size()])
        {
            return;
        }

        curWord += board[x][y];

        if(curWord == target)
        {
            flag = true;
            return;
        }

        visit[x][y] = 1;
        dfs(x + 1, y, n, m, curWord, target, board);
        dfs(x, y + 1, n, m, curWord, target, board);
        dfs(x - 1, y, n, m, curWord, target, board);
        dfs(x, y - 1, n, m, curWord, target, board);
        visit[x][y] = 0;

    }

private:
    bool flag;
    int **visit;
};

int main()
{
    Solution solution;
    vector<vector<char>> board
            {{'A', 'A', 'A', 'A', 'A', 'A'},
             {'A', 'A', 'A', 'A', 'A', 'A'},
             {'A', 'A', 'A', 'A', 'A', 'A'},
             {'A', 'A', 'A', 'A', 'A', 'A'},
             {'A', 'A', 'A', 'A', 'A', 'A'},
             {'A', 'A', 'A', 'A', 'A', 'B'}};

    string target = "AAAAAAAAAAAAAAB";

    cout << solution.exist(board, target);
    return 0;
}