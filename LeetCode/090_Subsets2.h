#pragma once

#include <vector>
#include <algorithm>

namespace LeetCode {
using namespace std;
class Subsets2Solution {
public:
	vector<vector<int>> subsetsWithDup(vector<int>& nums) {
		int size = nums.size();
		vector<vector<int>> results;
		if (!size) return results;
		vector<int> result;
		sort(nums.begin(), nums.end());
		generate(results, result, nums, 0);
		return results;
	}

	void generate(vector<vector<int>>& results, vector<int>& result, vector<int>& nums, int i) {
		results.push_back(result);
		for (int j = i; j < nums.size(); ++j) {
			if (j == i || nums[j] != nums[j - 1]) {
				result.push_back(nums[j]);
				generate(results, result, nums, j + 1);
				result.pop_back();
			}
		}
	}
};
}