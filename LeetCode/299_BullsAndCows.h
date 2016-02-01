#pragma once

#include <string>

namespace LeetCode {
using namespace std;
class BullsAndCowsSolution {
public:
	string getHint(string secret, string guess) {
		int A = 0, B = 0;
		int count[10] = { 0 };
		for (int i = 0; i<secret.size(); ++i) {
			if (secret[i] == guess[i]) {
				++A;
			}
			else {
				if (count[secret[i] - '0'] < 0) ++B;
				if (count[guess[i] - '0'] > 0) ++B;
				++count[secret[i] - '0'];
				--count[guess[i] - '0'];
			}
		}
		return to_string(A) + 'A' + to_string(B) + 'B';
	}
};
}