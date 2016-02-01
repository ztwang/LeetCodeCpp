#pragma once

#include "BinaryTree.h"

namespace LeetCode {
class FlattenBinaryTreeToLinkedListSolution {
public:
	void flatten(TreeNode* root) {
		if (!root || !root->left && !root->right) return;
		flatten(root->left);
		flatten(root->right);
		if (root->left) {
			TreeNode* t = root->left;
			while (t->right) t = t->right;
			t->right = root->right;
			root->right = root->left;
			root->left = nullptr;
		}
	}
};
}