#pragma once

#include <vector>
#include <algorithm>

namespace LeetCode {
using namespace std;
class NextPermutationSolution {
public:
	void nextPermutation(vector<int>& nums) {
		int pivot = nums.size() - 2;
		while (pivot >= 0 && nums[pivot] >= nums[pivot + 1]) --pivot;
		reverse(nums.begin() + pivot + 1, nums.end());
		if (pivot >= 0) {
			int pos = pivot + 1;
			while (nums[pivot] >= nums[pos]) ++pos;
			swap(nums[pivot], nums[pos]);
		}
	}
};
}