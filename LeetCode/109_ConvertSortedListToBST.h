#pragma once

#include "LinkedList.h"
#include "BinaryTree.h"

namespace LeetCode {
class ConvertSortedListToBSTSolution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		ListNode* pivot = head;
		while (pivot && pivot->next) {
			pivot = pivot->next;
		}
		return build(head, pivot);
	}

	TreeNode* build(ListNode* head, ListNode* end) {
		if (!head) return nullptr;
		if (head == end) return new TreeNode(head->val);
		ListNode* slow = head, *fast = head;
		while (fast->next && fast->next->next && fast->next != end && fast->next->next != end) {
			slow = slow->next;
			fast = fast->next->next;
		}
		TreeNode* node = new TreeNode(slow->next->val);
		node->left = build(head, slow);
		if (slow->next != end) // if there is a right branch;
			node->right = build(slow->next->next, end);
		return node;
	}
};
}