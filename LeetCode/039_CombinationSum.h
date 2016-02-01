#pragma once

#include <vector>
#include <algorithm>

namespace LeetCode {
using namespace std;
class CombinationSumSolution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> results;
		vector<int> result;
		sort(candidates.begin(), candidates.end());
		getCombinations(results, result, candidates, target, 0);
		return results;
	}

	void getCombinations(vector<vector<int>>& results, vector<int>& result, vector<int>& candidates, int target, int i) {
		if (target == 0) {
			results.push_back(result);
			return;
		}
		for (; candidates[i] <= target && i < candidates.size(); ++i) {
			result.push_back(candidates[i]);
			getCombinations(results, result, candidates, target - candidates[i], i);
			result.pop_back();
		}
	}
};
}