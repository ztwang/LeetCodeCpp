#pragma once

#include <vector>
#include "BinaryTree.h"

namespace LeetCode {
using namespace std;
class BinaryTreeInorderTraversalSolution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		traversal(result, root);
		return result;
	}

	void traversal(vector<int>& result, TreeNode* node) {
		if (!node) return;
		if (node->left) traversal(result, node->left);
		result.push_back(node->val);
		if (node->right) traversal(result, node->right);
	}
};
}