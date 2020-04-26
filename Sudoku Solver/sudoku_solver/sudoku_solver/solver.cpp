#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include "sudoku toolbox.h"
using namespace std;

//sudoku solver function using backtrack recursion
bool SudokuSolver(vector< vector<int>> & grid, string show = "no") {
	int row, col;

	if (!FindEmpty(grid, row, col))
		return true;

	for (int num = 1; num <= 9; num++) {            //options are 1-9
		if (!FindContradict(grid, row, col, num)) { //if num looks fine
			if (show.c_str() == "yes")
				cout << "(" << row << "," << col << ")" << " fill in " << num << endl;
			grid[row][col] = num;                   // try assign num
			if (SudokuSolver(grid)) return true;    //recur if succeed stop
			grid[row][col] = 0;                     //undo & try again
			if (show.c_str() == "yes")
				cout << "undo previous step!" << endl;
		}
	}
	return false;
}

//wrapper function
void Solver(vector< vector<int>> & grid) {
	string show;
	cout << "Want to show steps ('yes' or 'no') : ";
	getline(cin, show);
	while (true) {
		if (show == "yes" || show == "no")
			break;
		cout << "Invalide input, enter 'yes' or 'no' : ";
		getline(cin, show);
	}

	bool result = SudokuSolver(grid);
	string output = "not solved! ";

	if (result == 1) output = "solved! ";
	cout << "Sudoku is " << output << "See following answer :" << endl << endl;

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cout << grid[i][j] << " ";
			if (j == 8) cout << "\n";
		}
	}
	cout << endl;
}

int main()
{
	//here is an example
	vector< vector<int>> sudoku{ {0,0,0,2,6,0,7,0,1},
								 {6,8,0,0,7,0,0,9,0},
								 {1,9,0,0,0,4,5,0,0},
								 {8,2,0,1,0,0,0,4,0},
								 {0,0,4,6,0,2,9,0,0},
								 {0,5,0,0,0,3,0,2,8},
								 {0,0,9,3,0,0,0,7,4},
								 {0,4,0,0,5,0,0,3,6},
								 {7,0,3,0,1,8,0,0,0} };

	Solver(sudoku);
	
	system("pause");
	return 0;
}