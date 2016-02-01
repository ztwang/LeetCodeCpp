#pragma once

#include "BinaryTree.h"

namespace LeetCode {
class SymmetricTreeSolution {
public:
	bool isSymmetric(TreeNode* root) {
		return root == nullptr || symmetric(root->left, root->right);
	}

	bool symmetric(TreeNode* a, TreeNode* b) {
		if (a == nullptr) return b == nullptr;
		if (b == nullptr) return false;
		return a->val == b->val && symmetric(a->left, b->right) && symmetric(a->right, b->left);
	}
};
}