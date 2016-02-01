#pragma once

namespace LeetCode {
class PalindromNumberSolution {
public:
	bool isPalindrome(int x) {
		if (x < 0 || x > 0 && x % 10 == 0) return false;
		if (x < 10) return true;
		int res = 0;
		while (x > res) {
			res = res * 10 + x % 10;
			if (res == x) return true;
			x = x / 10;
		}
		return x == res;
	}
};
}