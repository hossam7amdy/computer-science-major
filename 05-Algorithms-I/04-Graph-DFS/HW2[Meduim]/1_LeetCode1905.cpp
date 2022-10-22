#include<iostream>
#include<vector>
using namespace std;

/*
 * We can implement this problem in several ways, but here is the most efficient and simplest one
 *
 * We will perform Connected Components DFS procedure in the standard way based on grid2
 * While we find a CC in grid2, we must find its cells are covered in grid1
 * If the whole CC is found in grid2 and its coverage in grid1, then we have a sub-island
 *
 * In code below, I used the grid itself to also mark the visited nodes.
 * 	This is OK, as long as no problem with changing the given arrays
 *
 * O(NM) time and memory
 */

class Solution {
private:
    typedef vector<vector<int>> GRAPH;

    // Delta for: up, right, down, left
	int dr[4] { -1, 0, 1, 0 };
	int dc[4] { 0, 1, 0, -1 };

    int ROWS, COLS;
    bool isSubIsland;

    bool validDir(const int &nr, const int &nc){
        return 0 <= nr && nr < ROWS && 0 <= nc && nc < COLS;
    }

public:
    void flooding(const GRAPH &grid1, GRAPH &grid2, int r, int c){
        if(!validDir(r, c) || !grid2[r][c])
            return;

        if(!grid1[r][c]){
            isSubIsland = false;
            return;
        }

        grid2[r][c] = 0;

        for(int d = 0; d < 4; ++d)
            flooding(grid1, grid2, dr[d] + r, dc[d] + c);
    }

    int countSubIslands(GRAPH& grid1, GRAPH& grid2) {
        ROWS = (int)grid1.size();
        COLS = (int)grid1[0].size();

        int cnt = 0;
        for(int i = 0; i < ROWS; ++i){
            for(int j = 0; j < COLS; ++j){
                isSubIsland = true;
                if(grid2[i][j] == 1){
                    flooding(grid1, grid2, i, j);
                    cnt += isSubIsland;
                }
            }
        }

        return cnt;
    }
};


typedef vector<vector<int>> GRAPH1;

int main(){
    GRAPH1 grid1 = {{1,1,1,0,0},{0,1,1,1,1},{0,0,0,0,0},{1,0,0,0,0},{1,1,0,1,1}};
    GRAPH1 grid2 = {{1,1,1,0,0},{0,0,1,1,1},{0,1,0,0,0},{1,0,1,1,0},{0,1,0,1,0}};

    GRAPH1 g1 = {{1,0,1,0,1},{1,1,1,1,1},{0,0,0,0,0},{1,1,1,1,1},{1,0,1,0,1}};
    GRAPH1 g2 = {{0,0,0,0,0},{1,1,1,1,1},{0,1,0,1,0},{0,1,0,1,0},{1,0,0,0,1}};

    Solution s;
    cout << s.countSubIslands(grid1, grid2) << endl;
    cout << s.countSubIslands(g1, g2) << endl;



    return 0;
}
