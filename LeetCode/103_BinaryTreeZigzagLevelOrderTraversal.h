#pragma once

#include <vector>
#include "BinaryTree.h"

namespace LeetCode {
using namespace std;
class BinaryTreeZigzagLevelOrderTraversalSolution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> result;
		travel(result, root, 0);
		return result;
	}

	void travel(vector<vector<int>>& result, TreeNode* node, int level) {
		if (!node) return;
		if (level >= result.size()) result.push_back(vector<int>{});
		if (level & 1) {
			result[level].insert(result[level].begin(), node->val);
		}
		else result[level].push_back(node->val);
		travel(result, node->left, ++level);
		travel(result, node->right, level);
	}
};
}