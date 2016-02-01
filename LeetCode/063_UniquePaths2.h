#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class UniquePaths2Solution {
public:
	int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
		if (obstacleGrid.size() == 0) return 0;
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();
		if (obstacleGrid[m - 1][n - 1] == 1) return 0;
		vector<vector<int>> path;
		path.resize(m);
		for (int i = 0; i<m; ++i) path[i].resize(n);
		path[m - 1][n - 1] = 1;
		bool blocked = false;
		for (int i = m - 2; i >= 0; --i) {
			if (blocked) {
				path[i][n - 1] = 0;
			}
			else {
				if (obstacleGrid[i][n - 1]) {
					blocked = true;
					path[i][n - 1] = 0;
				}
				else path[i][n - 1] = 1;
			}
		}
		blocked = false;
		for (int i = n - 2; i >= 0; --i) {
			if (blocked) {
				path[m - 1][i] = 0;
			}
			else {
				if (obstacleGrid[m - 1][i]) {
					blocked = true;
					path[m - 1][i] = 0;
				}
				else path[m - 1][i] = 1;
			}
		}
		for (int i = m - 2; i >= 0; --i) {
			for (int j = n - 2; j >= 0; --j) {
				if (obstacleGrid[i][j]) {
					path[i][j] = 0;
				}
				else {
					path[i][j] = path[i + 1][j] + path[i][j + 1];
				}
			}
		}
		return path[0][0];
	}
};
}