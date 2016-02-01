#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class CombinationsSolution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> results;
		vector<int> result;
		combinations(results, result, 0, k, n);
		return results;
	}

	void combinations(vector<vector<int>>& results, vector<int>& result, int i, int k, const int n) {
		if (k == 0) {
			results.push_back(result);
		}
		else {
			for (; i<n; ++i) {
				result.push_back(i + 1);
				combinations(results, result, i + 1, k - 1, n);
				result.pop_back();
			}
		}
	}
};
}