#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

/*
 The same treatment as walls-and-gates problem

 From the cell perspective: it is like 1-1 relation
 From the ocean perspective: it is 1-M relationship

 This motivates reverse thinking: start from ocean

 The problem is actually 2 parts:
 Is cell reachable from the first row and first column (Pacific)?
 Is cell reachable from the last row and the last column (Atlantic)?

 We solve each one independently, then
 if pacificReachable[i][j] && atlanticReachable[i][j] ==> then consider (i, j) location

 As we have several starting points, this is just  multi-source BFS

 Tip: as we reversed the problem: then cell go to another if src <= targetk
 */

class Solution {
private:
    struct cell{
        int r, c;
        cell(const int &r, const int &c):
            r(r), c(c){
          }
    };

    typedef vector<vector<int>> GRAPH;

    vector<vector<cell>> vis;
    int dr[4] = {-1,0,1,0};
    int dc[4] = {0,-1,0,1};
    int ROWS, COLS;

    bool validDir(const int &r, const int &c){
        return 0 <= r && r < ROWS && 0 <= c && c < COLS;
    }

    void bfs_pacific(const GRAPH &heights){
        queue<cell> q;
        for(int i = 0; i < ROWS; ++i)
            q.push(cell(i, 0)), vis[i][0].r = 1;
        for(int j = 1; j < COLS; ++j)
            q.push(cell(0, j)), vis[0][j].r = 1;

        while(!q.empty()){
            cell cur = q.front();
            q.pop();

            for(int d = 0; d < 4; ++d){
                int nr = cur.r + dr[d];
                int nc = cur.c + dc[d];

                if(!validDir(nr, nc) || heights[cur.r][cur.c] > heights[nr][nc] || vis[nr][nc].r)
                    continue;

                q.push(cell(nr,nc));
                vis[nr][nc].r = 1;
            }
        }
    }

    void bfs_atlantic(const GRAPH &heights){
        queue<cell> q;
        for(int r = ROWS-1; r >= 0; --r)
            q.push(cell(r, COLS-1)), vis[r][COLS-1].c = 1;
        for(int c = COLS-1; c >= 0; --c)
            q.push(cell(ROWS-1, c)), vis[ROWS-1][c].c = 1;

        while(!q.empty()){
            cell cur = q.front();
            q.pop();

            for(int d = 0; d < 4; ++d){
                int nr = cur.r + dr[d];
                int nc = cur.c + dc[d];

                if(!validDir(nr, nc) || heights[cur.r][cur.c] > heights[nr][nc] || vis[nr][nc].c)
                    continue;

                q.push(cell(nr,nc));
                vis[nr][nc].c = 1;
            }
        }

    }

public:
    vector<vector<int>> pacificAtlantic(GRAPH& heights) {
        ROWS = heights.size();
        COLS = heights[0].size();
        vis.resize(ROWS, vector<cell>(COLS, cell(0,0)));

        bfs_atlantic(heights);
        bfs_pacific(heights);

        GRAPH result;
        for(int r = 0; r < ROWS; ++r)
            for(int c = 0; c < COLS; ++c)
                if(vis[r][c].r && vis[r][c].c)
                    result.push_back({r,c});

        sort(result.begin(), result.end());
        return result;
    }
};

typedef vector<vector<int>> GRAPH;

void test1(){
    GRAPH heights = {{1,2,2,3,5},{3,2,3,4,4},{2,4,5,3,1},{6,7,1,4,5},{5,1,1,2,4}};

    Solution s;
    GRAPH ans = s.pacificAtlantic(heights);

    for(int i = 0; i < (int)ans.size(); ++i)
        cout << "(" << ans[i][0] << ", " << ans[i][1] << ") ";
}

int main(){
    test1();

    return 0;
}
