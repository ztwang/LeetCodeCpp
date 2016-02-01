#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class SudokuSolverSolution {
private:
	int blkcheck[9]{ 0,0,0,0,0,0,0,0,0 };
	int rowcheck[9]{ 0,0,0,0,0,0,0,0,0 };
	int colcheck[9]{ 0,0,0,0,0,0,0,0,0 };
public:
	void solveSudoku(vector<vector<char>>& board) {
		init(board);
		solve(board, 0, 0);
	}

	void init(vector<vector<char>>& board) {
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] != '.') {
					int pos = 1 << (board[i][j] - '1');
					rowcheck[i] |= pos;
					colcheck[j] |= pos;
					blkcheck[i / 3 * 3 + j / 3] |= pos;
				}
			}
		}
	}

	bool solve(vector<vector<char>>& board, int i, int j) {
		if (i > 7 && j > 8) return true;
		if (j > 8) {
			j = 0; ++i;
		}
		int blkId = i / 3 * 3 + j / 3;
		if (board[i][j] != '.') {
			return solve(board, i, j + 1);
		}
		int valid = getValid(i, j);
		if (valid == 511) {
			return false;
		}
		int row = rowcheck[i];
		int col = colcheck[j];
		int blk = blkcheck[blkId];
		for (int k = 0; k < 9; ++k) {
			int pos = 1 << k;
			if (!(valid & pos)) {
				board[i][j] = '1' + k;
				rowcheck[i] |= pos;
				colcheck[j] |= pos;
				blkcheck[blkId] |= pos;
				if(solve(board, i, j + 1)) return true;
				board[i][j] = '.';
				rowcheck[i] = row;
				colcheck[j] = col;
				blkcheck[blkId] = blk;
			}
		}
		return false;
	}

	int getValid(int i, int j) {
		return (rowcheck[i] | colcheck[j] | blkcheck[i / 3 * 3 + j / 3]);
	}
};
}