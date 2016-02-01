#pragma once

#include <string>

namespace LeetCode {
using namespace std;
class CompareVersionNumbersSolution {
public:
	int compareVersion(string version1, string version2) {
		int n1 = 0, n2 = 0;
		int l1 = version1.size();
		int l2 = version2.size();
		int i1 = 0, i2 = 0;
		int result = 0;
		while (i1 < l1 || i2 < l2) {
			while (i1 < l1 && version1[i1] != '.') n1 = n1 * 10 + (version1[i1++] - '0');
			while (i2 < l2 && version2[i2] != '.') n2 = n2 * 10 + (version2[i2++] - '0');
			if (n1 > n2) return 1;
			if (n1 < n2) return -1;
			n1 = n2 = 0;
			++i1;
			++i2;
		}
		return 0;
	}
};
}