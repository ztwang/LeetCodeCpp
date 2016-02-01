#pragma once

namespace LeetCode {
class ReverseIntegerSolution {
public:
	int reverse(int x) {
		long long ux = std::abs(x);
		long long r = 0;
		while (ux > 0) {
			r = r * 10 + ux % 10;
			ux /= 10;
		}
		if (r > INT_MAX) return 0;
		return x > 0 ? r : -r;
	}
};
}