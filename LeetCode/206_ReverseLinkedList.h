#pragma once

#include "LinkedList.h"

namespace LeetCode {
class ReverseLinkedListSolution {
public:
    ListNode* reverseList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* prev = nullptr;
        ListNode* cur = head;
        ListNode* next = head;
        while(next) {
            next = next->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }
};
}