/*
 * Main.cpp
 *
 *  Created on: Dec 15, 2015
 *      Author: zhetaow
 */

#include <iostream>
#include <vector>
#include "290_WordPattern.h"

using namespace LeetCode;

int main() {
	WordPatternSolution s;
	/*ListNode* l = new ListNode(1);
	l->next = new ListNode(1);
	l->next->next = new ListNode(1);
	l->next->next->next = new ListNode(2);
	l->next->next->next->next = new ListNode(3);*/
	//vector<int> result{-1,0,0,3,3,3,0,0,0};
	//vector<int> b{1,2,2};
	//s.reverseBits(1);
	auto result = s.wordPattern("abba","dog cat cat dog");
	std::cout << result << std::endl;
	/*for (auto r : result) {
		cout << r << ' ';
		/*for (auto s : r) {
			cout << s << ' ';
		}
		cout << endl;
	}*/
	/*ListNode* t = result;
	while (t != nullptr) {
		std::cout << t->val << ' ';
		t = t->next;
	}*/
	std::cout << ("25" < "256") << std::endl;
	return 0;
}
