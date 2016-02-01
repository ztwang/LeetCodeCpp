#pragma once

#include <string>

namespace LeetCode {
class LongestSubstringWithoutRepeatingCharactersSolution {
public:
	int lengthOfLongestSubstring(std::string s) {
		int max = 0;
		int characters[256]{0};
		int count = 0;
		int start = 0;
		for (int i = 0; i < s.size(); ++i) {
			char c = s.at(i);
			if (characters[c]) {
				count = i - start;
				if (count > max) max = count;
				for (int j = start; j < characters[c]-1; ++j) {
					characters[s.at(j)] = 0;
				}
				start = characters[c];
			}
			characters[c] = i+1;
		}
		count = s.size() - start;
		if (count > max) return count;
		return max;
	}
};
}