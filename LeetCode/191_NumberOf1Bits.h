/*
 * NumberOf1Bits.h
 *
 *  Created on: Dec 15, 2015
 *      Author: zhetaow
 */

#ifndef NUMBEROF1BITS_H_
#define NUMBEROF1BITS_H_

#include <stdint.h>

namespace LeetCode {
class NumberOf1BitsSolution {
public:
	int hammingWeight(uint32_t n) {
		int res = n & 1;
		while (n) {
			res += (n = n >> 1) & 1;
		}
		return res;
	}
};
}

#endif /* NUMBEROF1BITS_H_ */
