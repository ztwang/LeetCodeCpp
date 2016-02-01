#pragma once

#include "LinkedList.h"

namespace LeetCode {
class MergeTwoSortedListsSolution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (l1 == nullptr) return l2;
		if (l2 == nullptr) return l1;
		ListNode *newList = nullptr;
		if (l1->val < l2->val) {
			newList = l1;
			l1 = l1->next;
		}
		else {
			newList = l2;
			l2 = l2->next;
		}
		ListNode *p = newList;
		while (l1 != nullptr && l2 != nullptr) {
			if (l1->val < l2->val) {
				p->next = l1;
				l1 = l1->next;
			}
			else {
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
		if (l1 == nullptr) p->next = l2;
		else p->next = l1;
		return newList;
	}
};
}