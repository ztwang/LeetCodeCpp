#pragma once

#include "LinkedList.h"

namespace LeetCode {
class ReverseLinkedListSolution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (m == n) return head;
		ListNode dumb(0);
		dumb.next = head;
		ListNode* pm = &dumb;
		while (--m) {
			--n;
			pm = pm->next;
		}
		ListNode* cur = pm->next, *next;
		while (--n) {
			next = cur->next;
			cur->next = cur->next->next;
			next->next = pm->next;
			pm->next = next;
		}

		return dumb.next;
	}
};
}