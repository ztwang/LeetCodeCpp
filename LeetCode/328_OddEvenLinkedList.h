#pragma once

#include "LinkedList.h"

namespace LeetCode {
class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		ListNode o(0), e(0);
		ListNode* odd = &o, *even = &e;
		bool flag = true;
		while (head) {
			if (flag) {
				odd->next = head;
				head = head->next;
				odd = odd->next;
				flag = false;
			}
			else {
				even->next = head;
				head = head->next;
				even = even->next;
				flag = true;
			}
		}
		odd->next = e.next;
		even->next = nullptr;
		return o.next;
	}
};
}