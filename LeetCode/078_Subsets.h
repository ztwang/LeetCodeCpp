#pragma once

#include <vector>
#include <algorithm>

namespace LeetCode {
using namespace std;
class SubsetsSolution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> results;
		vector<int> result;
		sort(nums.begin(), nums.end());
		getSubsets(results, result, nums, 0);
		return results;
	}

	void getSubsets(vector<vector<int>>& results, vector<int>& result, vector<int>& nums, int i) {
		results.push_back(result);
		for (; i<nums.size(); ++i) {
			result.push_back(nums[i]);
			getSubsets(results, result, nums, i + 1);
			result.pop_back();
		}
	}
};
}