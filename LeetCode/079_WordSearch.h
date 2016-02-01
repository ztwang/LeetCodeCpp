#pragma once

#include <vector>

namespace LeetCode {
using namespace std;
class WordSearchSolution {
public:
	bool exist(vector<vector<char>>& board, string word) {
		int m = board.size();
		int n = board[0].size();
		for (int i = 0; i<m; ++i) {
			for (int j = 0; j<n; ++j) {
				if (search(board, word, i, j, 0, m, n)) {
					return true;
				}
			}
		}
		return false;
	}

	bool search(vector<vector<char>>& board, string& word, int i, int j, int pos, const int m, const int n) {
		if (pos == word.size()) return true;
		if (word[pos] != board[i][j]) return false;
		if (pos == word.size() - 1 && word[pos] == board[i][j]) return true;

		char c = board[i][j];
		board[i][j] = 0;
		if (i > 0 && search(board, word, i - 1, j, pos + 1, m, n)) {
			board[i][j] = c;
			return true;
		}
		else if (i < m - 1 && search(board, word, i + 1, j, pos + 1, m, n)) {
			board[i][j] = c;
			return true;
		}
		else if (j > 0 && search(board, word, i, j - 1, pos + 1, m, n)) {
			board[i][j] = c;
			return true;
		}
		else if (j < n - 1 && search(board, word, i, j + 1, pos + 1, m, n)) {
			board[i][j] = c;
			return true;
		}
		else {
			board[i][j] = c;
			return false;
		}
	}
};
}