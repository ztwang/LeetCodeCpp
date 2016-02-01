#pragma once

#include "LinkedList.h"

namespace LeetCode {
class AddTwoNumbersSolution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* l1Pivot = l1;
		ListNode* l2Pivot = l2;
		ListNode* result = new ListNode((l1Pivot->val + l2Pivot->val) % 10);
		ListNode* rPivot = result;
		int tens = (l1Pivot->val + l2Pivot->val) / 10;
		int sum = 0;
		l1Pivot = l1Pivot->next;
		l2Pivot = l2Pivot->next;
		while (l1Pivot || l2Pivot) {
			int sum = tens;
			if (l1Pivot != nullptr) {
				sum += l1Pivot->val;
				l1Pivot = l1Pivot->next;
			}
			if (l2Pivot != nullptr) {
				sum += l2Pivot->val;
				l2Pivot = l2Pivot->next;
			}
			rPivot->next = new ListNode(sum % 10);
			tens = sum / 10;
			rPivot = rPivot->next;
		}
		if (tens) rPivot->next = new ListNode(1);
		return result;
	}
};
}