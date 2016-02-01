#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class GrayCodeSolution {
public:
	vector<int> grayCode(int n) {
		vector<int> result{ 0 };
		int t = 1;
		while (n--) {
			for (int i = result.size() - 1; i >= 0; --i) {
				result.push_back(result[i] ^ t);
			}
			t <<= 1;
		}
		return result;
	}
};
}