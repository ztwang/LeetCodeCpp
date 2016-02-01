#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class SortColorsSolution {
public:
	void sortColors(vector<int>& nums) {
		int begin = 0, end = nums.size() - 1, pivot = 0;
		while (pivot <= end) {
			if (nums[pivot] == 0) {
				swap(nums[pivot++], nums[begin++]);
			}
			else if (nums[pivot] == 2) {
				swap(nums[pivot], nums[end--]);
			}
			else ++pivot;
		}
	}
};
}