#pragma once

#include "LinkedList.h"

namespace LeetCode {
class RemoveDuplicatesFromSortedList2Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* pivot = head;
		ListNode* prev = nullptr;
		while (pivot != nullptr && pivot->next != nullptr) {
			if (pivot->val != pivot->next->val) {
				prev = pivot;
				pivot = pivot->next;
			}
			else {
				int v = pivot->val;
				pivot = pivot->next;
				while (pivot != nullptr && pivot->val == v) {
					pivot = pivot->next;
				}
				if (prev == nullptr) {
					head = pivot;
				}
				else prev->next = pivot;
			}
		}
		return head;
	}
};
}