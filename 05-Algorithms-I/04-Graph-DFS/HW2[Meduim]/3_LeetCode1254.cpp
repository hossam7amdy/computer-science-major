#include<iostream>
#include<vector>
using namespace std;

/*
 * A simple observation will make this problem just a standard code!
 *
 * What REALLY makes a connected component closed?
 * 	Simply, it doesn't touch any grid boundary at all (first/last row - first/last column)
 *
 * So do the normal CC counting on DFS for the zero values
 * 		Any CC that touches the boundary shouldn't be counted
 *
 * For educational purposes only, instead of building visited matrix
 * I build CC matrix, which assigns the same ID for all CC elements
 * 		Start from id=1 to differentiate which cells NOT visited
 */

class Solution {
private:
    typedef vector<vector<int>> GRAPH;
    // Delta for: up, right, down, left
	int dr[4] { -1, 0, 1, 0 };
	int dc[4] { 0, 1, 0, -1 };
    int ROWS, COLS;
    bool isClosedIsland;

    bool validDir(const int &nr, const int &nc){
        return 0 <= nr && nr < ROWS && 0 <= nc && nc < COLS;
    }

    void dfs(GRAPH &grid, bool &isClosedIsland, const int &nr, const int &nc){
        if(!validDir(nr, nc)){
            isClosedIsland = false;
            return;
        }

        if(grid[nr][nc])
            return;

        grid[nr][nc] = 2;

        for(int d = 0; d < 4; ++d)
            dfs(grid, isClosedIsland, nr+dr[d], nc+dc[d]);
    }

public:

    int closedIsland(GRAPH& grid) {
        ROWS = (int)grid.size();
        COLS = (int)grid[0].size();

        int cnt = 0;
        for(int i = 0; i < ROWS; ++i){
            for(int j = 0; j < COLS; ++j){
                isClosedIsland = true;
                if(!grid[i][j]){
                    dfs(grid, isClosedIsland, i, j);
                    cnt += (isClosedIsland);
                }
            }
        }

        return cnt;
    }
};

int main(){


    return 0;
}
