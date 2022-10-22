#include<bits/stdc++.h>
using namespace std;

const int MAX = 100 + 1;
int memory[MAX][MAX];

int n,m;
vector<vector<int>> grid;

int minPathSum(int r, int c){
    if(0 > c || c >= m)
        return 1e9;

    if(r == n - 1)
        return grid[r][c];

    auto &ret = memory[r][c];
    if(ret != -1)
        return ret;

    int p1 = minPathSum(r + 1, c);
    int p2 = minPathSum(r + 1, c - 1);
    int p3 = minPathSum(r + 1, c + 1);

    return ret = grid[r][c] + min(p1, min(p2, p3));
}

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        grid = matrix;
        n = (int)grid.size(), m = (int)grid[0].size();

        memset(memory, -1, sizeof(memory));

        int ans = 1e9;
        for(int c = 0; c < m; ++c)
            ans = min(ans, minPathSum(0, c));

        return ans;
    }
};

int main(){

    return 0;
}
