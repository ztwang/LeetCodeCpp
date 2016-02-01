#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class LetterCombinationsOfAPhoneNumberSolution {
public:
	string chars[10]{ "", "","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
	vector<string> letterCombinations(string digits) {
		vector<string> result;
		GetCombinations(digits, 0, result, "");
		return result;
	}

	void GetCombinations(string& digits, int idx, vector<string>& result, string combo) {
		if (idx == digits.size()) {
			result.push_back(combo);
			return;
		}
		string characters = chars[digits[idx] - '0'];
		for (char c : characters) {
			GetCombinations(digits, idx + 1, result, combo + c);
		}
	}
};
}