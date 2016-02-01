#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class SearchA2DMatrixSolution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0 || target < matrix[0][0]) return false;
		int m = matrix.size();
		int n = matrix[0].size();
		if (target > matrix[m - 1][n - 1]) return false;
		int begin = 0, end = m - 1, i;
		if (target == matrix[m - 1][0]) return true;
		else if (target > matrix[m - 1][0]) i = m - 1;
		else {
			while (begin < end - 1) {
				int mid = (begin + end) / 2;
				int num = matrix[mid][0];
				if (num == target) return true;
				if (num > target) end = mid;
				else begin = mid;
			}
			i = begin;
		}
		if (matrix[i][0] == target || matrix[i][n - 1] == target) return true;
		if (matrix[i][n - 1] < target) return false;
		begin = 0, end = n - 1;
		while (begin < end - 1) {
			int mid = (begin + end) / 2;
			int num = matrix[i][mid];
			if (num == target) return true;
			if (num > target) end = mid;
			else begin = mid;
		}
		return matrix[i][begin] == target;
	}
};
}