#pragma once

#include <vector>
#include <algorithm>

namespace LeetCode {
using namespace std;
class ThreeSumSolution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		if (nums.size() < 3) return {};
		std::sort(nums.begin(), nums.end());
		int size = nums.size();
		vector<vector<int>> result;
		for (int i = 0; i < size-2; ++i) {
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			int target = 0 - nums[i];
			int* begin = &(nums[i+1]);
			int* end = &(nums[size-1]);
			while (begin < end) {
				int sum = *begin + *end;
				if (sum == target) {
					result.push_back({ nums[i], *begin, *end });
					while (*(begin + 1) == *(begin++));
					while (*(end - 1) == *(end--));
				}
				else if (begin > end - 2) break;
				else if (sum < target) {
					while (*(begin + 1) == *(begin++));
				}
				else {
					while (*(end - 1) == *(end--));
				}
			}
		}
		return result;
	}
};
}