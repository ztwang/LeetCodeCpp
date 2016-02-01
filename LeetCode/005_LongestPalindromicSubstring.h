#pragma once

#include <string>

namespace LeetCode {
class LongestPalindromicSubstringSolution {
public:
	std::string longestPalindrome(std::string s) {
		int i, a, b, start=0, size = s.size(), max = 0;
		for (i = 0; i < size && max < 2 * (size - i);) {
			a = b = i;
			for (; b + 1 < size && s[b] == s[b + 1]; ++b);
			i = b + 1;
			for (; a > 0 && b + 1 < size && s[a - 1] == s[b + 1]; --a, ++b);
			int count = b - a + 1;
			if (count > max) start = a, max = count;
		}
		return s.substr(start, max);
	}
};
}