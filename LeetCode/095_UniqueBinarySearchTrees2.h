#pragma once

#include <vector>
#include "BinaryTree.h"

namespace LeetCode {
using namespace std;
class UniqueBinarySearchTrees2Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		if (n < 1) return{};
		vector<TreeNode*> result{ nullptr };
		int m = 1;
		while (n >= m) {
			int size = result.size();
			for (int i = 0; i<size; ++i) {
				TreeNode* newRoot = new TreeNode(m);
				newRoot->left = result[i];
				result[i] = newRoot;
			}
			for (int i = 0; i<size; ++i) {
				if (result[i]->left) {
					TreeNode* root = result[i]->left;
					int step = 1;
					TreeNode* pivot = root;
					while (pivot) {
						TreeNode * c = copy(result[i]->left);
						TreeNode * temp = c;
						int count = 0;
						while (++count < step) {
							temp = temp->right;
						}
						TreeNode* r = temp->right;
						temp->right = new TreeNode(m);
						temp->right->left = r;
						result.push_back(c);
						pivot = pivot->right;
						++step;
					}
				}
			}
			++m;
		}
		return result;
	}

	TreeNode* copy(TreeNode* node) {
		if (!node) return nullptr;
		TreeNode* c = new TreeNode(node->val);
		if (node->left) c->left = copy(node->left);
		if (node->right) c->right = copy(node->right);
		return c;
	}
};
}