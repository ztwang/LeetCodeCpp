#pragma once

#include <string>

namespace LeetCode {
using namespace std;
class RegularExpressionMatchingSolution {
public:
	bool isMatch(string s, string p) {
		int sp = 0, pp = 0;
		int ssize = s.size(), psize = p.size();
		while (sp < ssize && pp < psize) {
			if (p[pp] == '.') {
				++sp;
				++pp;
			}
			else if (p[pp] == '*') {
				++pp;
				int lastc = p.find_last_of(p[pp], sp);
			}
		}
	}
};
}