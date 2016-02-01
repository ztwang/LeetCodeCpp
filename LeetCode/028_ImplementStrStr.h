#pragma once

#include <string>

namespace LeetCode {
using namespace std;
class ImplementStrStrSolution {
public:
	int strStr(string haystack, string needle) {
		int head = -1;
		int size = haystack.size() - needle.size();
		for (int i = 0; i <= size; ++i) {
			int j = 0;
			bool found = true;
			while (j < needle.size()) {
				if (haystack[i + j] != needle[j++]) {
					found = false;
					break;
				}
			}
			if (found) return i;
		}
		return -1;
	}
};
}