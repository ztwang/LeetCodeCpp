#pragma once

#include "BinaryTree.h"

namespace LeetCode {
class PathSumSolution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		//if(sum < 0) return false;
		if (!root) return false;
		if (!root->left && !root->right) return sum == root->val;
		sum -= root->val;
		if (!root->left) return hasPathSum(root->right, sum);
		if (!root->right) return hasPathSum(root->left, sum);
		return hasPathSum(root->left, sum) || hasPathSum(root->right, sum);
	}
};
}