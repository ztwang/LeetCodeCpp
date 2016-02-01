#pragma once

#include "BinaryTree.h"

namespace LeetCode {
class CountCompleteTreeNodesSolution {
public:
	int countNodes(TreeNode* root) {
		if (!root) return 0;
		TreeNode *temp = root->left;
		int height = 0, count = 0;
		while (temp) {
			temp = temp->left;
			++height;
		}
		temp = root;
		while (height > 0) {
			--height;
			TreeNode *left = temp->left;
			for (int i = 0; i < height; ++i) { // go to the right-most end of left branch
				left = left->right;
			}
			if (left) { // left complete, temp go to right, add 2^height to count;
				temp = temp->right;
				count += (1 << height + 1);
			}
			else { // left not complete, temp go to left, add 2^height-1 to count;
				temp = temp->left;
				count += (1 << height);
			}
		}
		if (temp) ++count;
		return count;
	}
};
}