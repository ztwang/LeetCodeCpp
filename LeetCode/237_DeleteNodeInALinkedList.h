#pragma once

#include "LinkedList.h"

namespace LeetCode {
class DeleteNodeInALinkedListSolution {
public:
	void deleteNode(ListNode* node) {
		ListNode* temp = node->next;
		*node = *temp;
		delete temp;
	}
};
}