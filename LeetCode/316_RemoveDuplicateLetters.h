/*
 * RemoveDuplicateLetters.h
 *
 *  Created on: Dec 15, 2015
 *      Author: zhetaow
 */

#ifndef REMOVEDUPLICATELETTERS_H_
#define REMOVEDUPLICATELETTERS_H_

#include <string>
#include <vector>

namespace LeetCode {
class RemoveDuplicateLettersSolution {
public:
	std::string RemoveDuplicateLetters(std::string s) {
		std::vector<unsigned int> count(26, 0);
		int inResult = 0;
		for (char c : s)
			count[c - 'a']++;
		std::string res = "";
		for (char c : s) {
			count[c - 'a']--;
			if (inResult & (1 << (c - 'a')))
				continue;
			if (res.empty()) {
				res.push_back(c);
				inResult |= (1 << (c - 'a'));
				continue;
			}
			while (c < res.back() && !res.empty() && count[res.back() - 'a'] > 0) {
				inResult &= ~(1 << (res.back() - 'a'));
				res.pop_back();
			}
			res.push_back(c);
			inResult |= (1 << (c - 'a'));
		}
		return res;
	}
};

}

#endif /* REMOVEDUPLICATELETTERS_H_ */
