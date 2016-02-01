#pragma once

#include "BinaryTree.h"
#include <vector>
#include <string>

namespace LeetCode {
using namespace std;
class BinaryTreePathsSolution {
public:
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> result;
		if (!root) return result;
		string s = to_string(root->val);
		if (!root->left && !root->right) {
			result.push_back(s);
			return result;
		}
		if (root->left) {
			travel(result, s, root->left);
		}
		if (root->right) {
			travel(result, s, root->right);
		}
		return result;
	}

	void travel(vector<string>& result, string s, TreeNode* root) {
		if (!root) return;
		s += "->" + to_string(root->val);
		if (!root->left && !root->right) {
			result.push_back(s);
			return;
		}
		if (root->left) {
			travel(result, s, root->left);
		}
		if (root->right) {
			travel(result, s, root->right);
		}
	}
};
}