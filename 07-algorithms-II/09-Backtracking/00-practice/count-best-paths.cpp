#include<bits/stdc++.h>
using namespace std;

vector<vector<char>> grid = {{'R','.','.','.','.','.','.'},
                             {'.','x','x','x','x','x','.'},
                             {'.','.','.','x','.','.','.'},
                             {'.','x','.','.','.','.','x'},
                             {'.','.','x','.','x','.','E'}};

int total_paths = 0;

int total_steps = 0;
int best_steps = 1e8;

int dr[] = {-1,0,1,0};
int dc[] = {0,1,0,-1};

bool isValid(int r, int c){
    return 0 <= r && r < grid.size() && 0 <= c && c < grid[r].size() && grid[r][c] != 'x';
}

void countPathes(int r, int c){
    if(grid[r][c] == 'E'){

        if(best_steps > total_steps){
            total_paths = 1;
            best_steps = total_steps;
        }else if(best_steps == total_steps)
            total_paths += 1;

        return;
    }

    for(int d = 0; d < 4; ++d){
        int nr = r + dr[d];
        int nc = c + dc[d];

        if(!isValid(nr,nc))
            continue;

        grid[r][c] = 'x';    // do
        total_steps += 1;

        countPathes(nr,nc); // recurse

        grid[r][c] = '.';  // undo
        total_steps -= 1;
    }
}

int main() {
    countPathes(0,0);
    cout << total_paths << " paths of " << best_steps <<  " steps\n";

    return 0;
}
