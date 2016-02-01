#pragma once

#include "BinaryTree.h"

namespace LeetCode {
class SameTreeSolution {
public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		if (p == nullptr) return q == nullptr;
		if (q == nullptr) return false;
		return p->val == q->val && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
	}
};
}