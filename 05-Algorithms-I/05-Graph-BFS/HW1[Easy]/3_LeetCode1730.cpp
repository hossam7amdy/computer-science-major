#include<iostream>
#include<vector>
#include<queue>
using namespace std;

typedef vector<vector<char>> GRAPH;

class Solution{
private:
    // helpers
    int dr[4] { -1, 0, 1, 0 };
    int dc[4] { 0, 1, 0, -1 };
    int COLS, ROWS;
    char me = '*', food = '#', free = 'O', obstacle = 'X';

    bool validDir(const int &r, const int &c){
        return 0 <= r && r < ROWS && 0 <= c && c < COLS;
    }

    int shortestPath(GRAPH &matrix, int sr, int sc){
        queue<pair<int,int>> dirs;

        dirs.push({sr, sc});
        matrix[sr][sc] = obstacle;

        int steps = 0;
        while(!dirs.empty()){
            int sz = (int)dirs.size();

            ++steps; // new level
            while(sz--){
                auto cur = dirs.front();
                dirs.pop();


                sr = cur.first, sc = cur.second;
                for(int d = 0; d < 4; ++d){
                    int nr = sr + dr[d];
                    int nc = sc + dc[d];

                    if(!validDir(nr, nc) || matrix[nr][nc] == obstacle)
                        continue;

                    if(matrix[nr][nc] == food)
                        return steps;

                    dirs.push({nr, nc});
                    matrix[nr][nc] = obstacle;
                }
            }
        }

        // Tip: we can use the matrix itself to mark visited by setting matrix[nr][nc] = 'X';
        // This is good for competitions, but not industry / interviews
        return -1;
    }

public:
    int getFood(vector<vector<char>> matrix){
        ROWS = (int)matrix.size();
        COLS = (int)matrix[0].size();

        for(int r = 0; r < ROWS; ++r)
            for(int c = 0; c < COLS; ++c)
                if(matrix[r][c] == me)
                    return shortestPath(matrix, r, c);

        return -1; // redundant
    }
};

int main(){

    Solution s;
    GRAPH g1 = {{'X','X','X','X','X','X'},
                {'X','*','O','O','O','X'},
                {'X','O','O','#','O','X'},
                {'X','X','X','X','X','X'}};
    cout << s.getFood(g1) << "\n"; // 3

    GRAPH g2 = {{'X','X','X','X','X'},
                {'X','*','X','O','X'},
                {'X','O','X','#','X'},
                {'X','X','X','X','X'}};
    cout << s.getFood(g2) << "\n"; // -1

    GRAPH g3 = {{'X','X','X','X','X','X','X','X'},
                {'X','*','O','X','O','#','O','X'},
                {'X','O','O','X','O','O','X','X'},
                {'X','O','O','O','O','#','O','X'},
                {'X','X','X','X','X','X','X','X'}};
    cout << s.getFood(g3) << "\n"; // 6

    return 0;
}
