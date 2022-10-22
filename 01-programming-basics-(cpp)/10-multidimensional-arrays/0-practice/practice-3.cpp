#include <iostream>
using namespace std;

/*
Practice: Swap 2 columns
● Read integers N, M, then Read matrix NxM. Then read 2 indices of columns.
Swap the 2 columns together. Print the new matrix.
● Input: 3 4
    ○ 8 16 9 52
    ○ 3 15 27 6
    ○ 14 25 2 10
    ○ 0 3
● Output
    ○ 52 16 9 8
    ○ 6 15 27 3
    ○ 10 25 2 14
*/

int main(){
    int const ROW{100};
    int const COL{100};
    int matrix[ROW][COL];
    int row,col;
    cin >> row >> col;

    //8 16 9 52 3 15 27 6 14 25 2 10
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++)
            cin >> matrix[i][j];
    }

    int c1,c2;
    cin >> c1 >> c2;
    for(int i=0; i<row; i++){
        int temp = matrix[i][c1];
        matrix[i][c1] = matrix[i][c2];
        matrix[i][c2] = temp;
    }

    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++)
            cout << matrix[i][j] << " ";
        cout << '\n';
    }


    return 0;
}
