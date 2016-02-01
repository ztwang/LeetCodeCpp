#pragma once

#include <vector>
#include <stack>
#include "BinaryTree.h"

namespace LeetCode {
using namespace std;
class ConstructBinaryTreeFromInorderAndPostorderTraversalSolution {
public:
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (postorder.size() == 0) return nullptr;
		stack<TreeNode *> st;
		TreeNode *t, *r, *root;
		int i = postorder.size() - 1, j = i;
		bool f = false;
		root = new TreeNode(postorder[i--]);
		st.push(root);
		t = root;
		while (i >= 0) {
			if (!st.empty() && st.top()->val == inorder[j]) {
				t = st.top();
				st.pop();
				f = true;
				--j;
			}
			else {
				if (f) {
					f = 0;
					t->left = new TreeNode(postorder[i]);
					t = t->left;
					st.push(t);
					--i;
				}
				else {
					t->right = new TreeNode(postorder[i]);
					t = t->right;
					st.push(t);
					--i;
				}
			}
		}

		return root;
	}
};
}