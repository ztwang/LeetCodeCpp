#pragma once

#include "BinaryTree.h"

namespace LeetCode {
class ValidateBinarySearchTreeSolution {
public:
	bool isValidBST(TreeNode* root) {
		return isValid(root, nullptr, nullptr);
	}

	bool isValid(TreeNode* root, TreeNode* min, TreeNode* max) {
		if (!root) return true;
		if (max && root->val >= max->val || min && root->val <= min->val) return false;
		return isValid(root->left, min, root) && isValid(root->right, root, max);
	}
};
}