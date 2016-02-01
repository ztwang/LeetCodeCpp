#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int count = 0;
		int size = nums.size();
		int p = 0;
		for (int i = 0; i<size; ++i) {
			if (i == size - count) break;
			if (!nums[i]) continue;
			nums[p] = nums[i];
			++p;
		}
		for (; p<size; ++p) {
			nums[p] = 0;
		}
	}
};
}