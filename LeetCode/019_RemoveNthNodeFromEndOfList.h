#pragma once

#include "LinkedList.h"

namespace LeetCode {
class RemoveNthNodeFromEndOfListSolution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* targetPrev = nullptr;
		ListNode* target = head;
		ListNode* pivot = head;
		while (--n > 0) {
			pivot = pivot->next;
		}
		while (pivot->next != nullptr) {
			targetPrev = target;
			target = target->next;
			pivot = pivot->next;
		}
		if (targetPrev == nullptr) {
			return target->next;
		}
		targetPrev->next = target->next;
		return head;
	}
};
}