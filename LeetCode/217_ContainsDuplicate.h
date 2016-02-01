#pragma once

#include <vector>
#include <algorithm>

namespace LeetCode {
using namespace std;
class ContainsDuplicateSolution {
public:
	bool containsDuplicate(vector<int>& nums) {
		int size = nums.size();
		if (size < 2) return false;
		sort(nums.begin(), nums.end());
		for (int i = 1; i<size; ++i) if (nums[i] == nums[i - 1]) return true;
		return false;
	}
};
}