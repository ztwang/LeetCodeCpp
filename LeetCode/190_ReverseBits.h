#pragma once

#include <cstdint>

namespace LeetCode {
using namespace std;
class ReverseBitsSolution {
public:
	uint32_t reverseBits(uint32_t n) {
		uint32_t result = 0;
		short i = 32;
		while (i--) {
			result = result << 1;
			result += n & 1;
			n = n >> 1;
		}
		return result;
	}
};
}