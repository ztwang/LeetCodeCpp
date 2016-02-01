#pragma once

namespace LeetCode {
class UniquePathsSolution {
public:
	int uniquePaths(int m, int n) {
		static int paths[100][100];
		if (n == 1 || m == 1) return 1;
		if (paths[m][n] > 0) return paths[m][n];
		int p = uniquePaths(m - 1, n) + uniquePaths(m, n - 1);
		paths[m][n] = p;
		return p;
	}
};
}