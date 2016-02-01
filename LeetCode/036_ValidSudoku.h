#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class ValidSudokuSolution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int blkcheck[9]{ 0,0,0,0,0,0,0,0,0 };
		int rowcheck[9]{ 0,0,0,0,0,0,0,0,0 };
		int colcheck[9]{ 0,0,0,0,0,0,0,0,0 };
		for (int i = 0; i < 9; ++i) {
			for (int j = 0; j < 9; ++j) {
				if (board[i][j] != '.') {
					// check block
					int blockIdx = j / 3 + i / 3 * 3;
					int pos = 1 << (board[i][j] - '1');
					if (blkcheck[blockIdx] & pos) {
						return false;
					}
					blkcheck[blockIdx] |= pos;

					// check row
					if (rowcheck[i] & pos) {
						return false;
					}
					rowcheck[i] |= pos;

					// check column
					if (colcheck[j] & pos) {
						return false;
					}
					colcheck[j] |= pos;
				}
			}
		}
		return true;
	}
};
}