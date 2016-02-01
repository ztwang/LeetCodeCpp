#pragma once

#include <vector>
#include <algorithm>

namespace LeetCode {
using namespace std;
class SpiralMatrixSolution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int> result;
		int height = matrix.size();
		if (height == 0) return result;
		int width = matrix[0].size();
		bool isLong = height > width;
		int layer = min(height, width);
		bool odd = layer % 2 == 1;
		layer /= 2;
		int i;
		for (i = 0; i < layer; ++i) {
			for (int j = i; j < width - i - 1; ++j) {
				result.push_back(matrix[i][j]);
			}
			for (int j = i; j < height - i - 1; ++j) {
				result.push_back(matrix[j][width - 1 - i]);
			}
			for (int j = width - i - 1; j > i; --j) {
				result.push_back(matrix[height - 1 - i][j]);
			}
			for (int j = height - i - 1; j > i; --j) {
				result.push_back(matrix[j][i]);
			}
		}
		if (odd) {
			if (isLong) {
				for (int j = i; j < height - i; ++j) {
					result.push_back(matrix[j][i]);
				}
			}
			else {
				for (int j = i; j < width - i; ++j) {
					result.push_back(matrix[i][j]);
				}
			}
		}
		return result;
	}
};
}