#pragma once

#include <string>

namespace LeetCode {
using namespace std;
class LengthOfLastWordSolution {
public:
	int lengthOfLastWord(string s) {
		int i = s.size();
		int count = 0;
		while (i--) {
			if (s[i] != ' ') ++count;
			else if (count > 0) break;
		}
		return count;
	}
};
}