#include<iostream>
using namespace std;

int path_sum(int grid[100][100], int rows, int cols, int r=0, int c=0){
    if(r==rows-1 && c==cols-1)
        return grid[r][c];

    int dr[]{1,0,1};
    int dc[]{0,1,1};
    int mx{INT_MIN}, best_i{}, best_j{};
    for(int i=0; i<3; ++i){
        int nr = r + dr[i];
        int nc = c + dc[i];
        if(nr<rows && nc<cols && mx<grid[nr][nc])
            mx = grid[nr][nc], best_i=nr, best_j=nc;
    }

    // cout << grid[r][c] << " ";
    return grid[r][c] + path_sum(grid, rows, cols, best_i, best_j);
}

int main(){

    int grid[][100]{ {1,7,8},
                    {2,10,11},
                    {20,5,9} };

    cout << path_sum(grid, 3,3) << endl;

    return 0;
}
