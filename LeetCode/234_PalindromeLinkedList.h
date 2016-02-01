#pragma once

#include "LinkedList.h"

namespace LeetCode {
class PalindromeLinkedListSolution {
public:
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next) return true;
		ListNode* fast = head, *slow = head;
		while (fast->next && fast->next->next) {
			fast = fast->next->next;
			slow = slow->next;
		}
		slow->next = reverse(slow->next);
		slow = slow->next;
		while (slow) {
			if (head->val != slow->val) return false;
			head = head->next;
			slow = slow->next;
		}
		return true;
	}

	ListNode* reverse(ListNode* head) {
		ListNode* prev = nullptr, *next = nullptr;
		while (head) {
			next = head->next;
			head->next = prev;
			prev = head;
			head = next;
		}
		return prev;
	}
};
}