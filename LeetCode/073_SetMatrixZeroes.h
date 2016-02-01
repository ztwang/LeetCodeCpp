#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class SetMatrixZeroesSolution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		bool firstRowZero = false;
		for (int i = 0; i<n; ++i) {
			if (!matrix[0][i]) {
				firstRowZero = true;
				break;
			}
		}
		for (int i = 1; i<m; ++i) {
			for (int j = 0; j<n; ++j) {
				if (!matrix[i][j]) {
					matrix[0][j] = matrix[i][0] = 0;
				}
			}
		}
		for (int i = m - 1; i>0; --i) {
			if (!matrix[i][0]) {
				for (int j = n - 1; j >= 0; --j) {
					matrix[i][j] = 0;
				}
			}
		}
		for (int j = n - 1; j >= 0; --j) {
			if (!matrix[0][j]) {
				for (int i = m - 1; i>0; --i) {
					matrix[i][j] = 0;
				}
			}
		}
		if (firstRowZero) {
			for (int i = 0; i<n; ++i) matrix[0][i] = 0;
		}
	}
};
}