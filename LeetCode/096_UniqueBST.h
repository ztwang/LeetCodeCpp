#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class UniqueBSTSolution {
public:
	int numTrees(int n) {
		vector<int> counts(n + 1, 0);
		counts[0] = counts[1] = 1;
		for (int i = 2; i <= n; ++i) {
			for (int j = 1; j <= i; ++j) {
				counts[i] += counts[j - 1] * counts[i - j];
			}
		}
		return counts[n];
	}
};
}