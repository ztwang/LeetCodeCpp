#pragma once

namespace LeetCode {
class DivideTwoIntegersSolution {
public:
	int divide(int dividend, int divisor) {
		if (divisor == 0) return INT_MAX;
		if (dividend == 0) return 0;
		if (divisor == 1) return dividend;
		if (divisor == -1) return (dividend == INT_MIN) ? INT_MAX : -dividend;
		unsigned int result = 0;
		unsigned int udividend = std::abs(dividend), udivisor = std::abs(divisor);
		while (udividend >= udivisor) {
			int i = 0;
			long long temp = udivisor;
			for (; temp <= udividend; ++i)
				temp <<= 1;
			result += 1 << --i;
			udividend -= udivisor << i;
		}
		return (divisor > 0 ^ dividend > 0) ? -(long)result : (result > INT_MAX ? INT_MAX : result);
	}
};
}