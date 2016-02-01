#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class NumberOfIslandsSolution {
public:
	int numIslands(vector<vector<char>>& grid) {
		int count = 0;
		const int rowsize = grid.size();
		if (rowsize == 0) return 0;
		const int colsize = grid[0].size();
		for (int i = 0; i<rowsize; ++i) {
			for (int j = 0; j<colsize; ++j) {
				if (grid[i][j] == '0') continue;
				flood(grid, i, j, rowsize, colsize);
				++count;
			}
		}
		return count;
	}

	void flood(vector<vector<char>>& grid, int i, int j, const int rowsize, const int colsize) {
		if (grid[i][j] == '1') {
			grid[i][j] = '0';
			if (i > 0) flood(grid, i - 1, j, rowsize, colsize);
			if (i < rowsize - 1) flood(grid, i + 1, j, rowsize, colsize);
			if (j > 0) flood(grid, i, j - 1, rowsize, colsize);
			if (j < colsize - 1) flood(grid, i, j + 1, rowsize, colsize);
		}
	}
};
}