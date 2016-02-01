#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class NumArray {
	vector<int> sums;
public:
	NumArray(vector<int> &nums) {
		if (!nums.size()) return;
		sums.push_back(nums[0]);
		for (int i = 1; i<nums.size(); ++i) {
			sums.push_back(sums[i - 1] + nums[i]);
		}
	}

	int sumRange(int i, int j) {
		if (!sums.size()) return 0;
		if (!i) return sums[j];
		return sums[j] - sums[i - 1];
	}
};

}