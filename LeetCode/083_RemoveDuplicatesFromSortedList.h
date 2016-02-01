#pragma once

#include "LinkedList.h"

namespace LeetCode {
class RemoveDuplicatesFromSortedListSolution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* pivot = head;
		while (pivot != nullptr && pivot->next != nullptr) {
			int v = pivot->val;
			while (pivot->next != nullptr && pivot->next->val == v) {
				pivot->next = pivot->next->next;
			}
			pivot = pivot->next;
		}
		return head;
	}
};
}