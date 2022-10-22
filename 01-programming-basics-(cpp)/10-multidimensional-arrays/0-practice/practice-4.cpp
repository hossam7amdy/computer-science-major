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
    ○ 3 15 29 16
    ○ 14 28 2 10
*/

int main(){
    int const ROW{100};
    int const COL{100};
    int matrix[ROW][COL];
    int row,col;
    cin >> row >> col;

    //8 1 9 52 3 15 29 16 14 28 2 10
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++)
            cin >> matrix[i][j];
    }

    int i=0,j=0, sum = matrix[i][j];
    while(!(i==row-1 && j==col-1)){//break when reaches last position (NAND)
        int mx = -1;  //if negative values (BUG)
        int best_i, best_j;
        if(i+1<row){//is down ok
            if(mx<matrix[i+1][j])
                mx = matrix[i+1][j], best_i = i+1, best_j = j;
        }
        if(j+1<col){ //is right ok
            if(mx<matrix[i][j+1])
                mx = matrix[i][j+1], best_i = i, best_j = j+1;
        }
        if((i+1<row) && (j+1<col)){ //is diagonal ok
            if(mx<matrix[i+1][j+1])
                mx = matrix[i+1][j+1], best_i = i+1, best_j = j+1;
        }

        sum += mx;
        i = best_i;
        j = best_j;
    }

    cout << sum;


    return 0;
}
