#pragma once

#include <string>

namespace LeetCode {
using namespace std;
class MultiplyStringsSolution {
public:
	string multiply(string num1, string num2) {
		if (num1 == "0" || num2 == "0") return "0";
		if (num1 == "1") return num2;
		if (num2 == "1") return num1;
		int size1 = num1.size(), size2 = num2.size();
		string result(size1 + size2, 0);
		for (int i = size1 - 1; i >= 0; --i) {
			int n1 = num1[i];
			for (int j = size2 - 1; j >= 0; --j) {
				int product = (n1 - '0') * (num2[j] - '0');
				int index = i + j + 1;
				result[index] += product;
			}
		}
		int carry = 0;
		for (int i = size1 + size2 - 1; i > 0; --i) {
			result[i - 1] += result[i] / 10;
			result[i] = result[i] % 10 + '0';
		}
		result[0] += '0';
		if (result[0] == '0') return result.substr(1, result.size() - 1);
		return result;
	}
};
}