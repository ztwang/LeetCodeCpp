#pragma once

#include <string>

namespace LeetCode {
using namespace std;
class ExcelSheetColumnTitleSolution {
public:
	string convertToTitle(int n) {
		string s;
		while (n) {
			s.insert(s.begin(), (--n) % 26 + 'A');
			n /= 26;
		}
		return s;
	}
};
}