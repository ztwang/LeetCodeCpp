#pragma once

#include <vector>
#include <algorithm>

namespace LeetCode {
using namespace std;
class ThreeSumClosestSolution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		if (nums.size() < 3) return{};
		std::sort(nums.begin(), nums.end());
		int size = nums.size();
		int result = nums[0] + nums[1] + nums[2];
		for (int i = 0; i < size - 2; ++i) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int* begin = &(nums[i + 1]);
			int* end = &(nums[size - 1]);
			while (begin < end) {
				int sum = *begin + *end + nums[i];
				if (sum == target) return target;
				if (abs(result - target) > abs(sum - target)) result = sum;
				if (sum < target) {
					while (*(begin) == *(++begin));
				}
				else while (*(end) == *(--end));
			}
		}
		return result;
	}
};
}