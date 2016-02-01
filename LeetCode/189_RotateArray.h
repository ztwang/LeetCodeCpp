#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class RotateArraySolution {
public:
	void rotate(vector<int>& nums, int k) {
		k %= nums.size();
		if (k > 0 && nums.size() > 1) {
			reverse(nums.begin(), nums.end() - k);
			reverse(nums.end() - k, nums.end());
			reverse(nums.begin(), nums.end());
		}
	}
};
}