#pragma once

#include <string>

namespace LeetCode {
using namespace std;
class TrieNode {
public:
	bool end;
	TrieNode* next[26]{ nullptr };
	// Initialize your data structure here.
	TrieNode() {
		end = false;
	}
};

class WordDictionary {
private:
	TrieNode* data;
public:
	WordDictionary() {
		data = new TrieNode();
	}

	// Adds a word into the data structure.
	void addWord(string word) {
		TrieNode* pivot = data;
		for (char c : word) {
			if (pivot->next[c - 'a'] == nullptr) {
				pivot->next[c - 'a'] = new TrieNode();
			}
			pivot = pivot->next[c - 'a'];
		}
		pivot->end = true;
	}

	// Returns if the word is in the data structure. A word could
	// contain the dot character '.' to represent any one letter.
	bool search(string word) {
		//if (word.size() == 0) return data->end;
		return searchAll(data, word, 0);
	}

	bool searchAll(TrieNode* node, const string& word, int idx) {
		if (idx == word.size()) return node != nullptr && node->end;
		if (word[idx] == '.') {
			if (node == nullptr) return false;
			++idx;
			for (TrieNode* n : node->next) {
				if (searchAll(n, word, idx)) return true;
			}
			return false;
		}
		return node != nullptr && searchAll(node->next[word[idx] - 'a'], word, idx + 1);
	}
};
}