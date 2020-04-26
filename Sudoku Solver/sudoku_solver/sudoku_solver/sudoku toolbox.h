#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//find the empty spot
bool FindEmpty(vector< vector<int>> & grid, int &row, int &col) {
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			if (grid[i][j] == 0) {
				row = i; //assign row position
				col = j; //assign column position
				return true;
			}
		}
	}
	return false;
}

//find any contradiction based on previously filled location
bool FindContradict(vector< vector<int>> & grid, int &row, int &col, int &num) {
	vector<int> row_range, col_range;

	//find small grid 9x9
	if (0 <= row && row <= 2) {
		row_range.push_back(0); row_range.push_back(2);
		if (0 <= col && col <= 2) {
			col_range.push_back(0); col_range.push_back(2);
		}
		else if (3 <= col && col <= 5) {
			col_range.push_back(3); col_range.push_back(5);
		}
		else {
			col_range.push_back(6); col_range.push_back(8);
		}
	}
	else if (3 <= row && row <= 5) {
		row_range.push_back(3); row_range.push_back(5);
		if (0 <= col && col <= 2) {
			col_range.push_back(0); col_range.push_back(2);
		}
		else if (3 <= col && col <= 5) {
			col_range.push_back(3); col_range.push_back(5);
		}
		else {
			col_range.push_back(6); col_range.push_back(8);
		}
	}
	else {
		row_range.push_back(6); row_range.push_back(8);
		if (0 <= col && col <= 2) {
			col_range.push_back(0); col_range.push_back(2);
		}
		else if (3 <= col && col <= 5) {
			col_range.push_back(3); col_range.push_back(5);
		}
		else {
			col_range.push_back(6); col_range.push_back(8);
		}
	}

	//find contradiction in small grid 9x9
	for (int i = row_range[0]; i <= row_range[1]; i++) {
		for (int j = col_range[0]; j <= col_range[1]; j++)
			if (grid[i][j] == num) return true;
	}

	//find contradiction in row 1x9
	if (count(grid[row].begin(), grid[row].end(), num)) return true;

	//find contradiction in column 9x1
	for (int i = 0; i < 9; i++)
		if (grid[i][col] == num) return true;

	return false; //find no contradiction
}

