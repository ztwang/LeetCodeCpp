#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class RotateImageSolution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int len = matrix.size();
		int layer = 0;
		for (int l = len; l > 1; l -= 2, ++layer) {
			for (int i = 0; i < l - 1; ++i) {
				int temp = matrix[layer][layer + i];
				matrix[layer][layer + i] = matrix[len - 1 - layer - i][layer];
				matrix[len - 1 - layer - i][layer] = matrix[len - 1 - layer][len - 1 - layer - i];
				matrix[len - 1 - layer][len - 1 - layer - i] = matrix[layer + i][len - 1 - layer];
				matrix[layer + i][len - 1 - layer] = temp;
			}
		}
	}
};
}