#include<iostream>
#include<vector>
using namespace std;

/*
 * We can implement this approach in several ways, but you might do several bugs.
 *
 * Here is a 'safe' approach
 *
 * 1) Perform the normal reachability DFS on a matrix
 * 		Don't update the matrix. Only visited array updated
 *
 * 2) Perform a simple iterative code that check if every node is boundary or not
 * 		1) It must be visited during dfs
 * 		2) Either one of its neighbors is out of the grid
 * 		3) Or an existing neighbor that is NOT part of the CC
 */

class Solution {
private:
    typedef vector<vector<int>> GRAPH;
    // Delta for: up, right, down, left
	int dr[4] { -1, 0, 1, 0 };
	int dc[4] { 0, 1, 0, -1 };
    int ROWS, COLS, given_color;

    bool validDir(const int &nr, const int &nc){
        return 0 <= nr && nr < ROWS && 0 <= nc && nc < COLS;
    }

    bool isBorder(const GRAPH &visited, const int &r, const int &c){
        for(int d = 0; d < 4; ++d)
            if(!validDir(r + dr[d], c + dc[d]) || !visited[r+dr[d]][c+dc[d]])
                return true;

        return false;
    }

    void dfs(GRAPH &grid, GRAPH &visited, const int &nr, const int &nc){
        if(!validDir(nr,nc) || grid[nr][nc]!=given_color || visited[nr][nc])
            return;

        visited[nr][nc] = 1;

        for(int d = 0; d < 4; ++d)
            dfs(grid, visited, nr + dr[d] , nc + dc[d]);
    }
public:

    GRAPH colorBorder(GRAPH& grid, int row, int col, int color) {
        ROWS = (int)grid.size();
        COLS = (int)grid[0].size();
        given_color = grid[row][col];

        GRAPH visited(ROWS, vector<int>(COLS, 0));
        dfs(grid, visited, row, col);

        for(int r = 0; r < ROWS; ++r)
            for(int c = 0; c < COLS; ++c)
                if(visited[r][c] && isBorder(visited, r, c))
                    grid[r][c] = color;


        return grid;
    }
};

typedef vector<vector<int>> GRID;
int main(){
    GRID g1 = {{1,1},{1,2}}; // 0 0 3

    GRID g2 = {{1,2,2},{2,3,2}}; // 0 1 3

    GRID g3 = {{1,1,1},{1,1,1},{1,1,1}}; // 1 1 2

    Solution s;
    s.colorBorder(g1, 0, 0, 3);

    for(const auto vec : g1){
        for(const auto ele : vec)
            cout << ele << " ";
        cout << "\n";
    }

    return 0;
}
