#pragma once

#include <vector>
#include "BinaryTree.h"

namespace LeetCode {
using namespace std;
class BinaryTreeLevelOrderTraversalSolution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> result;
		travel(result, root, 0);
		return result;
	}

	void travel(vector<vector<int>>& result, TreeNode* node, int level) {
		if (node == nullptr) return;
		if (result.size() <= level) {
			result.push_back(vector<int>{});
		}
		result[level].push_back(node->val);
		travel(result, node->left, ++level);
		travel(result, node->right, level);
	}
};
}