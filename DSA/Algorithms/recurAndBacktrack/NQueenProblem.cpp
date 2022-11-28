#include <iostream>

using std::cout;
using std::endl;

// - Algorithm:
// 	1) Start in the leftmost column
// 	2) If all queens are placed then return true
// 	3) Try all rows in the current column. 
// 		Do following for every tried row.
// 			a) If the queen can be placed safely in this row then mark 
// 			this [row, column] as part of the solution and recursively 
// 			check if placing queen here leads to a solution.
// 			b) If placing the queen in [row, column] leads to a solution 
// 			then return true.
// 			c) If placing queen doesn't lead to a solution then unmark 
// 			this [row, column] (Backtrack) and go to step (a) to try other rows.
// 	4) If all rows have been tried and nothing worked, return false to trigger backtracking.
//
// - Time Complexity: O(N!)
// - Auxiliary Space: O(N2)


/* This function solves the N Queen problem using
   Backtracking. It mainly uses solveNQUtil() to
   solve the problem. It returns false if queens
   cannot be placed, otherwise, return true and
   prints placement of queens in the form of 1s.
   Please note that there may be more than one
   solutions, this function prints one  of the
   feasible solutions.*/
bool solveNQ();

/* A recursive utility function to solve N
   Queen problem */
bool solveNQUtil(int board[][8], int col);

/* A utility function to check if a queen can
   be placed on board[row][col]. Note that this
   function is called when "col" queens are
   already placed in columns from 0 to col -1.
   So we need to check only left side for
   attacking queens */
bool isSafe(int board[][8], int row, int col);

void printSolution(int board[][8]);

int main() {
	solveNQ();

	cout << endl;
	return 0;
}

bool solveNQ() {
	int board[8][8] = { 0 };

	if (!solveNQUtil(board, 0)) {
		cout << "\nSolution is not exist\n";
		return false;
	}

	printSolution(board);

	return true;
}

bool solveNQUtil(int board[][8], int col) {
	// base case: if all queens are placed then return true
	if (col >= 8) {
		return true;
	}

	for (int i = 0; i < 8; i++) {
		if (isSafe(board, i, col)) {
			board[i][col] = 1;

			if (solveNQUtil(board, col + 1)) {
				return true;
			}

			board[i][col] = 0;
		}
	}

	return false;
}

bool isSafe(int board[][8], int row, int col) {
	for (int j = 0; j < col; j++) {
		if (board[row][j] == 1) {
			return false;
		}
	}

	for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
		if (board[i][j] == 1) {
			return false;
		}
	}

	for (int i = row, j = col; i < 8 && j >= 0; i++, j--) {
		if (board[i][j] == 1) {
			return false;
		}
	}

	return true;
}

void printSolution(int board[][8]) {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			cout << board[i][j] << " ";
		}
		cout << endl;
	}
}
