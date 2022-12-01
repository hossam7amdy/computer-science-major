#include <bits/stdc++.h>
using namespace std;

/*
     The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

     APPROACH:
        - a valid board implies each row,col,diagonal have exactly one queen
        - so backtrack from first row and try all possible combinations till no queens left

    COMPLEXITY:
        - Time: O(n!) n * n-1 * n-2 * n-3 ...
        - Space: O(s * n^2) solutions * board

*/

const int MAX = 9;
bool columns[MAX];
bool diagonal[2 * MAX];
bool anti_diag[2 * MAX];

int n;
vector<string> curBoard;
vector<vector<string>> result;

void backtrack(int r){
    if(r == n){
        result.push_back(curBoard);
        return;
    }

    for(int c = 0; c < n; ++c){
        if(columns[c] || diagonal[r+c] || anti_diag[r-c+n])
            continue;

        curBoard[r][c] = 'Q';
        columns[c] = diagonal[r+c] = anti_diag[r-c+n] = 1;

        backtrack(r + 1);

        columns[c] = diagonal[r+c] = anti_diag[r-c+n] = 0;
        curBoard[r][c] = '.';
    }
};

vector<vector<string>> solveNQueens(int n_) {
    n = n_;
    curBoard = vector<string>(n,string(n, '.'));

    memset(columns, 0, sizeof(columns));
    memset(diagonal, 0, sizeof(diagonal));
    memset(anti_diag, 0, sizeof(anti_diag));

    backtrack(0);
    return result;
}

int main(){

    solveNQueens(1);

    return 0;
}
