#pragma once

#include <string>

namespace LeetCode {
using namespace std;
class ExcelSheetColumnNumberSolution {
public:
	int titleToNumber(string s) {
		int result = 0;
		for (char c : s) {
			result *= 26;
			result += c - 'A' + 1;
		}
		return result;
	}
};
}