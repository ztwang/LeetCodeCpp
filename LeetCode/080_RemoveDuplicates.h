#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class RemoveDuplicatesSolution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.size() < 3)  return nums.size();
		int current = 2, size = nums.size();
		for (int i = 2; i < size; ++i) {
			if (nums[i] != nums[current - 1] || nums[i] != nums[current - 2]) {
				nums[current++] = nums[i];
			}
		}
		return current;
	}
};
}