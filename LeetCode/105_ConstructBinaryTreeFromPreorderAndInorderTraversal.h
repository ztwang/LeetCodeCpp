#pragma once

#include <vector>
#include <stack>
#include "BinaryTree.h"

namespace LeetCode {
using namespace std;
class ConstructBinaryTreeFromPreorderAndInorderTraversalSolution {
public:
	TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
		if (preorder.size() == 0) return nullptr;
		stack<TreeNode *> st;
		TreeNode *t, *r, *root;
		int i = 1, j = 0;
		bool f = false;
		root = new TreeNode(preorder[0]);
		st.push(root);
		t = root;
		while (i < preorder.size()) {
			if (!st.empty() && st.top()->val == inorder[j]) {
				t = st.top();
				st.pop();
				f = true;
				++j;
			}
			else {
				if (f) {
					f = 0;
					t->right = new TreeNode(preorder[i]);
					t = t->right;
					st.push(t);
					++i;
				}
				else {
					t->left = new TreeNode(preorder[i]);
					t = t->left;
					st.push(t);
					++i;
				}
			}
		}

		return root;
	}
};
}