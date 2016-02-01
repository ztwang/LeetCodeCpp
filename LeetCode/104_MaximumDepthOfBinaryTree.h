#pragma once

#include "BinaryTree.h"
#include <algorithm>

namespace LeetCode {
using namespace std;
class MaximumDepthOfBinaryTreeSolution {
public:
	int maxDepth(TreeNode* root) {
		if (!root) return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}
};
}