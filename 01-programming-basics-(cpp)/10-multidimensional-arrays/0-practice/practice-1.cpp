#include <iostream>
using namespace std;

/*
Practice: Max value
● Read 2 integers for the rows and columns of a matrix ( <= 100). Then read
rows x cols integer value. Find the position of maximum value in the array. If
there are several ones, find the last occurance
● Input:
    ○ 3 4
    ○ 1 5 1 10
    ○ 2 10 3 4
    ○ 1 10 10 7
● Output
    ○ Max value at position 2 2 with value = 10
*/

int main(){
    int const ROW{100};
    int const COL{100};
    int matrix[ROW][COL];
    int r,c;
    cin >> r >> c;
    //1 5 1 10 2 10 3 4 1 10 10 7
    int mx=0, row,col;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> matrix[i][j];
            if(mx<=matrix[i][j]){
                mx = matrix[i][j];
                row = i;
                col = j;
            }
        }
    }

    cout << "Max value at position " << row << " " << col << " with value = " << mx;



    return 0;
}
