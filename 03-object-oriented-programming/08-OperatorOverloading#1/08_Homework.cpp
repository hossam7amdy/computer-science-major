/// Homework 8: Chessboard
/*
● We wanna build chessboard class
    ○ 2d board of integers
● Change this class to allow these operators
    ○ 2 ways of set and get
*/

#include<iostream>
#include<vector>
using namespace std;

class ChessBoard {
private:
	int rows;
	int colums;
	vector< vector<int> > board;

public:
	ChessBoard(int rows, int colums) :
			rows(rows), colums(colums)
    {
        board = vector< vector<int>>(rows, vector<int>(colums));
    }

    /*
	 * There is no double subscript operator [][]
	 * overload operator[] to return an object that also overloads operator[]. This will enable [][].
	 *
	 * If we used internally 2D vector
	 * and returned row for []
	 * then return allows all operations on a single vector!
	 */

    vector<int>& operator[](const int &row)
    {
        // using board[row][col]
		// then become row[col]
        return board[row];
    }

    int& operator()(const int &row, const int &col)
    {
        return board[row][col];
    }
};

int main() {
	ChessBoard board(2, 3);	// 2x3 grid

	board(0, 0) = 10;
	board[0][1] = 20;

	cout << board[0][0] << " " << board(0, 1);

	return 0;
}
