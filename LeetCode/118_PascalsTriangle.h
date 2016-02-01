#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class PascalsTriangleSolution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> results;
		for (int i = 0; i<numRows; ++i) {
			results.push_back(vector<int>{});
			for (int j = 0; j <= i; ++j) {
				if (!j || j == i) results[i].push_back(1);
				else results[i].push_back(results[i - 1][j] + results[i - 1][j - 1]);
			}
		}
		return results;
	}
};
}