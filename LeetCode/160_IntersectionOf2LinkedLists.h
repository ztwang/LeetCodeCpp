#pragma once

#include "LinkedList.h"

namespace LeetCode {
class IntersectionOf2LinkedListsSolution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode* a = headA, *b = headB;
		while (a && b) {
			if (a == b) return a;
			a = a->next;
			b = b->next;
			if (!a && !b) return nullptr;
			if (!a) a = headB;
			if (!b) b = headA;
		}
		return nullptr;
	}
};
}