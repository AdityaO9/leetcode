#include <bits/stdc++.h>
using namespace std;

// Trie Node Structure
struct Node {
    Node* links[26] = {NULL}; // Stores 26 lowercase letters
    bool end = false;         // Marks the end of a word
    
    bool contain(char ch) { return links[ch - 'a'] != NULL; }
    Node* get(char ch) { return links[ch - 'a']; }
    void put(Node* node, char ch) { links[ch - 'a'] = node; }
    void setEnd() { end = true; }
    bool isEnd() { return end; }
};

// Trie Class for Fast Word Lookup
class Trie {
public:
    Node* root;
    Trie() { root = new Node(); }

    void insert(const string& s) {
        Node* node = root;
        for (char c : s) {
            if (!node->contain(c)) {
                node->put(new Node(), c);
            }
            node = node->get(c);
        }
        node->setEnd();
    }
};

class Solution {
public:
    Trie trie;
    unordered_map<int, vector<string>> memo; // Memoization

    vector<string> wordBreakHelper(string& s, int start) {
        // If already computed, return stored result
        if (memo.count(start)) return memo[start];
        if (start == s.size()) return {""};  // Reached the end of the string

        vector<string> sentences;
        Node* cur = trie.root;
        
        for (int i = start; i < s.size(); i++) {
            if (!cur->contain(s[i])) break; // No valid word continues
            
            cur = cur->get(s[i]);
            if (cur->isEnd()) { // Found a valid word
                string word = s.substr(start, i - start + 1);
                vector<string> restSentences = wordBreakHelper(s, i + 1);
                
                for (const string& rest : restSentences) {
                    sentences.push_back(rest.empty() ? word : word + " " + rest);
                }
            }
        }
        
        return memo[start] = sentences;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        // Insert words into Trie for fast lookup
        for (const string& word : wordDict) {
            trie.insert(word);
        }
        return wordBreakHelper(s, 0);
    }
};