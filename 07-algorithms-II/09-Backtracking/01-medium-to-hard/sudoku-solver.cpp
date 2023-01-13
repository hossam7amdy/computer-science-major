// https://leetcode.com/problems/sudoku-solver

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int MAX = 9;
    vector<pair<int,int>> block = {
        {3,3},{3,6},{3,9},{6,3},{6,6},{6,9},{9,3},{9,6},{9,9}
    };

    vector<vector<char>> result;
    bool solve(vector<vector<char>>& board, int cell){
        if(cell >= 81)
            return true;

        int r = cell / 9, c = cell % 9;

        if(board[r][c] != '.')
            return solve(board, cell+1);

        for(char ch = '1'; ch <= '9'; ++ch){
            if(canPlace(board, r,c, ch)){
                board[r][c] = ch;

                if(solve(board, cell+1))
                    return true;

                board[r][c] = '.';
            }
        }
        return false;
    }

    bool canPlace(vector<vector<char>>& board, int r, int c, char ch){
        int blockIdx = -1;
        for(int k = 0; k < MAX; ++k){
            if(board[r][k] == ch)
                return false;
            if(board[k][c] == ch)
                return false;
            auto p = block[k];
            if(blockIdx == -1 && p.first - 3 <= r && r < p.first && p.second - 3 <= c && c < p.second)
                blockIdx = k;
        }
        auto p = block[blockIdx];
        for(int i = p.first - 3; i < p.first; ++i)
            for(int j = p.second - 3; j < p.second; ++j)
                if(board[i][j] == ch)
                    return false;

        return true;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0);
    }
};

int main(){


    return 0;
}
