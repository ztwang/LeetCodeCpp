#pragma once

#include "BinaryTree.h"
#include <vector>

namespace LeetCode {
using namespace std;
class PathSum2Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> results;
		if (!root) return results;
		vector<int> result;
		find(results, result, root, sum);
		return results;
	}

	void find(vector<vector<int>>& results, vector<int>& result, TreeNode* node, int sum) {
		if (!node) return;
		if (!node->left && !node->right) {
			if (sum == node->val) {
				result.push_back(node->val);
				results.push_back(result);
				result.pop_back();
			}
			return;
		}
		result.push_back(node->val);
		find(results, result, node->left, sum - node->val);
		find(results, result, node->right, sum - node->val);
		result.pop_back();
	}
};
}