#pragma once

#include <vector>

namespace LeetCode {
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* GenerateList(std::vector<int> list) {
	ListNode* l = new ListNode(list[0]);
	ListNode* p = l;
	for (int i = 1; i < list.size(); ++i) {
		p->next = new ListNode(list[i]);
		p = p->next;
	}
	return l;
}

void DestroyList(ListNode* l) {
	while (l != nullptr) {
		ListNode* temp = l;
		l = l->next;
		delete temp;
	}
}
}