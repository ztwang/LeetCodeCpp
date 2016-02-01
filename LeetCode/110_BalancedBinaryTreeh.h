#pragma once

#include "BinaryTree.h"

namespace LeetCode {
class BalancedBinaryTreeSolution {
public:
	bool isBalanced(TreeNode* root) {
		if (!root || !root->left && !root->right) return true;
		int l = height(root->left), r = height(root->right);
		if (l > r + 1 || l < r - 1) return false;
		return isBalanced(root->left) && isBalanced(root->right);
	}

	int height(TreeNode* node) {
		if (!node) return 0;
		return max(height(node->left), height(node->right)) + 1;
	}
};
}