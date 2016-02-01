#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class JumpGameSolution {
public:
	bool canJump(vector<int>& nums) {
		int horizon = 0;
		int size = nums.size();
		for (int i = 0; i<size; ++i) {
			if (horizon < i) return false;
			if (horizon >= size) return true;
			int n = nums[i] + i;
			if (n > horizon) horizon = n;
		}
		return true;
	}
};
}