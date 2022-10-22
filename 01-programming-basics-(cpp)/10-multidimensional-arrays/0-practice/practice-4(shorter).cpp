#include <iostream>
using namespace std;

/*
Practice: Greedy Robot
● Read integers N, M, then Read matrix NxM. All values are distinct.
● A robot starts at cell (0, 0).
● Take the value in the current cell and moves.
● It can move only one step to either: Right, Bottom or the diagonal.
● It always selects the cell that has maximum value.
● Print the total values the robot collects
● Input: 3 4
    ○ 8 1 9 52
    ○ 3 15 27 6
    ○ 14 28 2 10
*/

int main(){
    int const ROW{100};
    int const COL{100};
    int matrix[ROW][COL];
    int row,col;
    cin >> row >> col;

    //-8 -1 -9 -52 -3 -15 -27 -6 -14 -28 -2 -10
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++)
            cin >> matrix[i][j];
    }

    int i=0,j=0, sum = matrix[i][j];
    int di[]{0,1,1};
    int dj[]{1,0,1};

    while(!(i==row-1 && j==col-1)){
        int ni, nj, mx, d=0;
        int best_i,best_j;
        bool st_time = true;
        while(d<3){
            ni = i + di[d];
            nj = j + dj[d];

            if(ni<row && nj<col){
                if(st_time || mx<matrix[ni][nj])
                    mx = matrix[ni][nj] ,best_i = ni, best_j=nj, st_time = false;
            }
            d++;
        }
        //cout << mx << " ";
        i = best_i;
        j = best_j;
        sum += mx;
    }

    cout << sum;


    return 0;
}
