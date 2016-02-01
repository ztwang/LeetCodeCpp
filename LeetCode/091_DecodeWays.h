#pragma once

#include <string>

namespace LeetCode {
using namespace std;
class DecodeWaysSolution {
public:
	int numDecodings(string s) {
		if (s.empty() || s[0] == '0') return 0;
		int size = s.size();
		if (size == 1) return 1;
		int c1 = 1, c2 = 1;
		for (int i = 1; i<size; ++i) {
			int t = c1;
			if (one(s[i])) {
				if (two(s[i - 1], s[i])) {
					c1 = c1 + c2;
				}
			}
			else {
				if (two(s[i - 1], s[i])) {
					c1 = c2;
				}
				else return 0;
			}
			c2 = t;
		}
		return c1;
	}

	bool one(char c) {
		return c != '0';
	}

	bool two(char c1, char c2) {
		return c1 == '1' || c1 == '2' && c2 < '7';
	}
};
}