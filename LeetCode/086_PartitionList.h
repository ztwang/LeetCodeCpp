#pragma once

#include "LinkedList.h"

namespace LeetCode {
class PartitionListSolution {
public:
	ListNode* partition(ListNode* head, int x) {
		ListNode larger(0), smaller(0);
		ListNode *l = &larger, *s = &smaller;

		while (head) {
			ListNode* & temp = head->val < x ? s : l;
			temp->next = head;
			temp = temp->next;
			head = head->next;
		}
		s->next = larger.next;
		l->next = nullptr;
		return smaller.next;
	}
};
}