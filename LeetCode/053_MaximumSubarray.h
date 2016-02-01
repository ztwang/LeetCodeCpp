#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class MaximumSubarraySolution {
public:
	int maxSubArray(vector<int>& nums) {
		int size = nums.size();
		int max = nums[0], left = nums[0];
		for (int i = 1; i<size; ++i) {
			if (left < 0) left = nums[i];
			else left += nums[i];
			max = max < left ? left : max;
		}
		return max;
	}
};
}