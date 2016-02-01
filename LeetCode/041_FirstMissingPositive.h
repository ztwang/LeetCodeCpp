#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class FirstMissingPositiveSolution {
public:
	int firstMissingPositive(vector<int>& nums) {
		int size = nums.size();
		int i = 0;
		while (i < size) {
			if (nums[i] > 0 && nums[i] <= size) {// can swap
				if (nums[i] != i + 1 && nums[i] == nums[nums[i] - 1]) {//not self and not the right
					nums[nums[i] - 1] = 0;
				}
				swap(nums[i], nums[nums[i] - 1]);
			}
			else {
				nums[i] = 0;
			}
			if (nums[i] == 0 || nums[i] == i + 1) {
				++i;
			}
		}
		for (i = 0; i < size && nums[i] != 0; ++i);
		return i + 1;
	}
};
}