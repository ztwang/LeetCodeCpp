#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class RomanToIntegerSolution {
public:
	int romanToInt(string s) {
		int r = 0;
		int size = s.size();
		int cur = getNum(s[0]);
		int prev;
		for (int i = 1; i<size; ++i) {
			prev = cur;
			cur = getNum(s[i]);
			r += (prev >= cur) ? prev : -prev;
		}
		return r + getNum(s[size - 1]);
	}
	int getNum(char c) {
		switch (c) {
		case 'I': return 1;
		case 'V': return 5;
		case 'X': return 10;
		case 'L': return 50;
		case 'C': return 100;
		case 'D': return 500;
		case 'M': return 1000;
		}
	}
};
}