#pragma once

#include <vector>
#include <algorithm>

namespace LeetCode {
using namespace std;
class Solution {
public:
	int rob(vector<int>& nums) {
		int a = 0, b = 0, size = nums.size();
		for (int i = 0; i<size; ++i) {
			if (i % 2) b = max(a, b + nums[i]);
			else a = max(a + nums[i], b);
		}
		return max(a, b);
	}
};
}