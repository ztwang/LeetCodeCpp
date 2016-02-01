#pragma once

#include "LinkedTree.h"

namespace LeetCode {
class PopulatingNextRightPointersInEachNodeSolution {
public:
	void connect(TreeLinkNode *root) {
		if (!root || !root->left) return;
		TreeLinkNode *pivot = root, *temp = nullptr;
		while (pivot->left) {
			temp = pivot;
			while (temp) {
				temp->left->next = temp->right;
				if (temp->next) temp->right->next = temp->next->left;
				temp = temp->next;
			}
			pivot = pivot->left;
		}
	}
};
}