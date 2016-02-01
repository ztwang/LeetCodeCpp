#pragma once

#include <string>

namespace LeetCode {
using namespace std;
class ZigZagConversionSolution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1) return s;
		int halfperiod = numRows - 1;
		int period = halfperiod << 1;
		int size = s.size();
		string res = "";
		int i = 0;
		for (i = 0; i < size; i += period)
			res.push_back(s[i]);
		for (i = 1; i < numRows - 1; ++i) {
			for (int j = 0; j < size; j += period) {
				int idx = j + i;
				if (idx < size)res.push_back(s[idx]);
				idx = j + period - i;
				if (idx < size) res.push_back(s[idx]);
			}
		}
		for (int i = halfperiod; i < size; i += period)
			res.push_back(s[i]);
		return res;
	}
};
}