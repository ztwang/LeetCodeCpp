#pragma once

#include <vector>
#include <algorithm>

namespace LeetCode {
using namespace std;
class FourSumSolution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		if (nums.size() < 4) return{};
		vector<vector<int>> result;
		sort(nums.begin(), nums.end());
		int size = nums.size();
		for (int i = 0; i<size - 3; ++i) {
			if (i>0 && nums[i] == nums[i - 1]) continue;
			if (nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) break;
			if (nums[i] + nums[size - 3] + nums[size - 2] + nums[size - 1] < target) continue;
			for (int j = i + 1; j<size - 2; ++j) {
				if (j>i + 1 && nums[j] == nums[j - 1]) continue;
				if (nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) break;
				if (nums[i] + nums[j] + nums[size - 2] + nums[size - 1] < target) continue;
				int rest = target - nums[i] - nums[j];
				int* begin = &(nums[j + 1]);
				int* end = &(nums[size - 1]);
				while (begin < end) {
					int sum = *begin + *end;
					if (sum == rest) {
						result.push_back({ nums[i], nums[j], *begin, *end });
						while (*(begin + 1) == *(begin++));
						while (*(end - 1) == *(end--));
					}
					else if (begin > end - 2) break;
					else if (sum < rest) {
						while (*(begin + 1) == *(begin++));
					}
					else {
						while (*(end - 1) == *(end--));
					}
				}
			}
		}
		return result;
};
}