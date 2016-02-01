#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class SearchInsertPositionSolution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int i = 0;
		int size = nums.size();
		for (; i<size; ++i) {
			if (nums[i] >= target) return i;
		}
		return i;
	}
};
}