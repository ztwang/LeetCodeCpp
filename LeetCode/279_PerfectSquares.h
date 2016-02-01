#pragma once

#include <vector>
#include <algorithm>

namespace LeetCode {
using namespace std;
class PerfectSquaresSolution {
	int numSquares(int n) {
		static vector<int> counts({0});
		while (counts.size() <= n) {
			int size = counts.size();
			int count = INT_MAX;
			for (int i = 1; i*i <= size; ++i) {
				count = min(count, counts[size - i*i] + 1);
			}
			counts.push_back(count);
		}
		return counts[n];
	}
};
}