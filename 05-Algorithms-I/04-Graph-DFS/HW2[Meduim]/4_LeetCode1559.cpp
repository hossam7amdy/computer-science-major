#include<iostream>
#include<vector>
using namespace std;

/*
 * With a simple observation, we can reduce the code to connected components counting problem.
 *
 * When we are at node (r, c) and move to a neighbor, e.g, (r+1, c)
 * 	This neighbor tries to go back to (r, c) creating a trivial cycle
 * 	Or move to a visited node
 *
 * 	To handle this 2 cases, we used the visited array to avoid them
 *
 * 	Now, we want to figure out if there is a cycle.
 * 	The cycle happens if you visited a place you visited before
 * 	BUT, this shouldn't be the node we just come from it (our parent node)
 *
 * 	To handle the code, we just add 2 new parameters: par_r, par_c which is the parent node generated the edge
 * 	When iterating on the neighbors, don't go back to the node's parent
 *
 * 	Now, if a node is visited it must come from a cycle!
 */

class Solution {
    typedef vector<vector<bool>> GRAPH;
    // Delta for: up, right, down, left
	int dr[4] { -1, 0, 1, 0 };
	int dc[4] { 0, 1, 0, -1 };
    int ROWS, COLS;
    bool isCycle;

    bool validDir(const int &nr, const int &nc){
        return 0 <= nr && nr < ROWS && 0 <= nc && nc < COLS;
    }

    void dfs(const vector<vector<char>>& grid, GRAPH &visited, int r, int c, const char &curColor, int old_r = -1, int old_c = -1){
        if(!validDir(r, c) || grid[r][c]!=curColor)
            return;

        if(visited[r][c]){
            isCycle = true;
            return;
        }

        visited[r][c] = 1;

        for(int d = 0; d < 4; ++d){
            int nr = r + dr[d];
            int nc = c + dc[d];
            if(nr==old_r && nc==old_c)
                continue;
            dfs(grid, visited, nr, nc, curColor, r, c);
        }
    }
public:
    bool containsCycle(vector<vector<char>>& grid) {
        ROWS = (int)grid.size();
        COLS = (int)grid[0].size();
        GRAPH visited(ROWS, vector<bool>(COLS, 0));

        for(int r = 0; r < ROWS; ++r){
            for(int c = 0; c < COLS; ++c){
                if(!visited[r][c]){
                    isCycle = false;
                    dfs(grid, visited, r, c, grid[r][c]);
                    if(isCycle)
                        return true;
                }
            }
        }

        return false;
    }
};

int main(){
    vector<vector<char>> g1 = {{'a','a','a','a'}, {'a','b','b','a'}, {'a','b','b','a'}, {'a','a','a','a'}};

    Solution s;
    cout << s.containsCycle(g1) << endl;

    return 0;
}
