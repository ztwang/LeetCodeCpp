#pragma once

#include "BinaryTree.h"

namespace LeetCode {
class InvertBinaryTreeSolution {
public:
	TreeNode* invertTree(TreeNode* root) {
		if (!root || !root->left && !root->right) return root;
		invertTree(root->left);
		invertTree(root->right);
		TreeNode* temp = root->left;
		root->left = root->right;
		root->right = temp;
		return root;
	}
};
}