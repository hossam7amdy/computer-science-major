#include<iostream>
#include<vector>
#include<queue>
using namespace std;

/*
 * The problem is asking for the longest path.
 * 		We learned before, the longest path is efficiently solvable in DAG
 *
 * We also, know the matrix can be represented as a graph?
 *
 * Let's analyze it 2 neighbor cells
 * values (3, 5): first is connected to 2nd
 * values (5, 3): second is connected to first
 * values (5, 5): no edge
 *
 * Clearly, the matris is a DAG!
 *
 * So all what we need to do, is to apply level-by-level topological sort the same as parallel-courses
 * 	Just on a matrix rather than a graph
 *
 */

class Solution {
    typedef vector<vector<int>> GRAPH;

    int ROWS, COLS;
    struct node{ int r, c; };

    bool validDir(const int &r, const int &c){
        return 0 <= r && r < ROWS && 0 <= c && c < COLS;
    }

    pair<int, vector<node>> neighbors(int r, int c, const GRAPH &matrix){
        int dr[4] = {1,0,-1,0};
        int dc[4] = {0,1,0,-1};

        vector<node> edges;
        int indegree = 0;
        for(int d = 0; d < 4; ++d){
            int nr = r + dr[d], nc = c + dc[d];
            if(!validDir(nr, nc))
                continue;
            if(matrix[r][c] < matrix[nr][nc])
                edges.push_back({nr, nc}); // out-going
            else if(matrix[r][c] > matrix[nr][nc])
                ++indegree;                // in-going
            // == => No edges
        }
        return {indegree, edges};
    }

public:
    int longestIncreasingPath(GRAPH& matrix) {
        ROWS = (int)matrix.size();
        COLS = (int)matrix[0].size();

        GRAPH indegree(ROWS, vector<int>(COLS, 0));
        for(int r = 0; r < ROWS; ++r)
            for(int c = 0; c < COLS; ++c)
                indegree[r][c] = neighbors(r, c, matrix).first;


        queue<node> ready;
        for(int r = 0; r < ROWS; ++r)
            for(int c = 0; c < COLS; ++c)
                if(!indegree[r][c])
                    ready.push({r,c});

        int level = 0;
        for(int sz = (int)ready.size(); !ready.empty(); sz = (int)ready.size(), ++level){
            while(sz--){
                node n = ready.front();
                ready.pop();

                vector<node> edges = neighbors(n.r, n.c, matrix).second;
                for(node &p : edges)
                    if(--indegree[p.r][p.c] == 0)
                        ready.push({p.r, p.c});
            }
        }
        return level;
    }
};

int main(){

    return 0;
}
