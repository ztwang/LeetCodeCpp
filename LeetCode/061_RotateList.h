#pragma once

#include "LinkedList.h"

namespace LeetCode {
class RotateListSolution {
public:
	ListNode* rotateRight(ListNode* head, int k) {
		if (k == 0 || head == nullptr || head->next == nullptr) return head;
		int count = 1;
		ListNode* oldEnd = head;
		while (oldEnd->next != nullptr) ++count, oldEnd = oldEnd->next;
		int index = count - k % count;
		if (index == count) return head;
		ListNode* newEnd = nullptr;
		ListNode* newStart = nullptr;
		for (count = 0, newStart = head; count < index; ++count, newEnd = newStart, newStart = newStart->next);
		newEnd->next = nullptr;
		oldEnd->next = head;
		return newStart;
	}
};
}