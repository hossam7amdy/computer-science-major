#include <iostream>
using namespace std;

/*
Practice: Special print
● Read 2 integers for the rows and columns of a matrix ( <= 100). Then read
rows x cols integer value.
● Print the following 4 values
    ○ The sum of the left diagonal & The sum of the right diagonal
    ○ The sum of the last row & The sum of the last column
● Input: 3 4
    ○ 8 16 9 52
    ○ 3 15 27 6
    ○ 14 25 2 10
● Output
    ○ 25 104
    ○ 51 68
*/

int main(){
    int const ROW{100};
    int const COL{100};
    int matrix[ROW][COL];
    int r,c;
    cin >> r >> c;

    //8 16 9 52 3 15 27 6 14 25 2 10
    int ldiag, rdiag, lrow, lcol;
    ldiag = rdiag = lrow = lcol = 0;
    int jc = c-1, ir = 0;
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            cin >> matrix[i][j];

            if(i==j) //left diagonal
                ldiag += matrix[i][j];

            if(i == ir && j == jc){ //right diagonal
                rdiag += matrix[i][j];
                jc--;
                ir++;
            }

            if(i==r-1) //last row
                lrow += matrix[i][j];

            if(j==c-1) //last column
                lcol += matrix[i][j];


        }
    }

    cout << "Left Diagonal = " << ldiag << " " << " right diagonal = " << rdiag << " "
        << "Last row = " << lrow << " " << "Last column = " << lcol;



    return 0;
}
