#pragma once

#include <vector>
#include <algorithm>

namespace LeetCode {
using namespace std;
class Permutations2Solution {
public:
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		vector<vector<int>> results;
		vector<int> result;
		vector<bool> used(nums.size(), false);
		sort(nums.begin(), nums.end());
		permute(results, result, used, nums, 0);
		return results;
	}

	void permute(vector<vector<int>>& results, vector<int>& result, vector<bool>& used, vector<int>& nums, int pos) {
		if (pos == nums.size()) {
			results.push_back(result);
			return;
		}
		for (int i = 0; i < nums.size(); ++i) {
			if (used[i]) continue;
			used[i] = true;
			result.push_back(nums[i]);
			permute(results, result, used, nums, pos + 1);
			result.pop_back();
			used[i] = false;
			while (i < nums.size()-1 && nums[i] == nums[i+1]) ++i;
		}
	}
};
}