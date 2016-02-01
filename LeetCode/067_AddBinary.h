#pragma once

#include <string>

namespace LeetCode {
using namespace std;
class AddBinarySolution {
public:
	string addBinary(string a, string b) {
		if (a == "0") return b;
		if (b == "0") return a;
		int asize = a.size() - 1;
		int bsize = b.size() - 1;
		int carry = 0;
		string result;
		while (asize >= 0 && bsize >= 0) {
			int r = a[asize--] - '0' + b[bsize--] - '0' + carry;
			carry = r / 2;
			result = (char)(r % 2 + '0') + result;
		}
		while (asize >= 0) {
			int r = a[asize--] - '0' + carry;
			carry = r / 2;
			result = (char)(r % 2 + '0') + result;
		}
		while (bsize >= 0) {
			int r = b[bsize--] - '0' + carry;
			carry = r / 2;
			result = (char)(r % 2 + '0') + result;
		}
		if (carry) {
			result = '1' + result;
		}
		return result;
	}
};
}