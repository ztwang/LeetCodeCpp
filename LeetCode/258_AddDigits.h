#pragma once

namespace LeetCode {
class AddDigitsSolution {
public:
	int addDigits(int num) {
		if (!num) return 0;
		if (!(num % 9)) return 9;
		return num % 9;
	}
};
}