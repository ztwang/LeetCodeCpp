#pragma once

#include <string>

namespace LeetCode {
using namespace std;
class ValidAnagramSolution {
public:
	bool isAnagram(string s, string t) {
		if (s.size() != t.size()) return false;
		int count[26] = { 0 };
		int size = s.size();
		for (int i = 0; i<size; ++i) {
			++count[s[i] - 'a'];
			--count[t[i] - 'a'];
		}
		for (int n : count) {
			if (n) return false;
		}
		return true;
	}
};
}