#pragma once

#include "LinkedList.h"

namespace LeetCode {
class SwapNodesInPairsSolution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode *p = head;
		if (head && head->next) {
			p = head->next;
			head->next = swapPairs(p->next);
			p->next = head;
		}
		return p;
	}
};
}