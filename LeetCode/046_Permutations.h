#pragma once

#include <vector>
#include <algorithm>

namespace LeetCode {
class PermutationsSolution {
public:
	std::vector<std::vector<int>> permute(std::vector<int>& nums) {
		std::vector<std::vector<int>> results;
		std::vector<int> result;
		std::vector<bool> used(nums.size());
		std::generate(used.begin(), used.end(), []() {return false; });
		GeneratePermutations(nums, 0, used, result, results);
		return results;
	}

	void GeneratePermutations(std::vector<int>& nums, int count, std::vector<bool>& used, std::vector<int>& result, std::vector<std::vector<int>>& results) {
		if (nums.size() == count) {
			results.push_back(result); return;
		}
		for (int i = 0; i < nums.size(); ++i) {
			if (!used[i]) {
				result.push_back(nums[i]);
				used[i] = true;
				GeneratePermutations(nums, count + 1, used, result, results);
				result.pop_back();
				used[i] = false;
			}
		}
	}
};
}