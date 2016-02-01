#pragma once

#include <vector>
#include "BinaryTree.h"

namespace LeetCode {
using namespace std;
class BinaryTreeLevelOrderTraversal2Solution {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		vector<vector<int>> result;
		travel(result, root, 0);
		reverse(result.begin(), result.end());
		return result;
	}

	void travel(vector<vector<int>>& result, TreeNode* node, int level) {
		if (!node) return;
		if (level >= result.size()) result.push_back(vector<int>{});
		result[level].push_back(node->val);
		travel(result, node->left, level + 1);
		travel(result, node->right, level + 1);
	}
};
}