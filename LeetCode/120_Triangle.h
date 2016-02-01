#pragma once

#include <vector>
#include <algorithm>

namespace LeetCode {
using namespace std;
class TriangleSolution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int level = triangle.size() - 1;
		vector<int> sums(triangle[level]);
		int count = sums.size() - 1;
		while (level-- >= 0) {
			for (int i = 0; i<count; ++i) {
				sums[i] = min(sums[i], sums[i + 1]) + triangle[level][i];
			}
			--count;
		}
		return sums[0];
	}
};
}