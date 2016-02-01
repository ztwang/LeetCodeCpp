#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class SearchForARangeSolution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		int begin = -1;
		int end = -1;
		int s = -1, e = nums.size();
		// find the start
		while (s < e - 1) {
			int mid = (s + e) / 2;
			if (nums[mid] >= target) {
				e = mid;
			}
			else {
				s = mid;
			}
		}
		begin = e;
		if (nums[begin] != target) return{ -1,-1 };
		// find the end
		s = begin, e = nums.size();
		while (s < e - 1) {
			int mid = (s + e) / 2;
			if (nums[mid] == target) {
				s = mid;
			}
			else {
				e = mid;
			}
		}
		end = s;
		return{ begin, end };
	}
};
}