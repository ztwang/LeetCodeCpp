#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class SearchInRotatedSorteArraySolution {
public:
	bool search(vector<int>& nums, int target) {
		int begin = 0, end = nums.size() - 1;
		while (begin <= end) {
			int mid = begin + (end - begin) / 2;
			if (nums[begin] == target || nums[end] == target || nums[mid] == target) return true;
			if (nums[begin] == nums[mid] && nums[end] == nums[mid]) {
				++begin;
				--end;
			}
			else if (nums[begin] <= nums[mid]) {
				if (nums[begin] <= target && nums[mid] > target) end = mid - 1;
				else begin = mid + 1;
			}
			else {
				if (nums[end] >= target && nums[mid] < target) begin = mid + 1;
				else end = mid - 1;
			}
		}
		return false;
	}
};
}