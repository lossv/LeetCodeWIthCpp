//
// Created by lossv on 2021/11/9.
//
#include <iostream>
#include <string>
#include <cstring>
#include <unordered_map>

using namespace std;


class Solution
{
public:
    int findMinStep(string& board, string& hand)
    {
        unordered_map<char, int> boardMap;
        unordered_map<char, int> handMap;
        int BoardIndexMap[board.length()];
        memset(BoardIndexMap, 0, sizeof BoardIndexMap);
        for(char & i : hand)
            handMap[i]++;
        for(int i = 0; i < board.length(); ++i)
        {
            if(boardMap.find(board[i]) != boardMap.end())
                BoardIndexMap[i] = boardMap[board[i]];
            else
                BoardIndexMap[i] = - 1;
            boardMap[board[i]] = i;
        }
        cout << " ";
        return -1;
    }
};

int main()
{
    string board = "WWRRBBWW";
    string hand = "WRBRW";
    Solution solution;
    cout << solution.findMinStep(board, hand);
    return 0;
}