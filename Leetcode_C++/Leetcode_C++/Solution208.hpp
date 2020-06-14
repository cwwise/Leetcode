//
//  Solution208.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/5/31.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution208_hpp
#define Solution208_hpp

#include <stdio.h>

/**
 实现一个 Trie (前缀树)，包含 insert, search, 和 startsWith 这三个操作。
 */
struct TrieNode {
    bool isEnd;
    unordered_map<char, TrieNode*> map;
    TrieNode() : isEnd(false) {}
    
    bool containsKey(char ch) {
        return map.find(ch) != map.end();
    }
    
    TrieNode* get(char ch) {
        return map[ch];
    }
    
    void push(char ch, TrieNode *node) {
        map[ch] = node;
    }
    
    void setEnd() {
        isEnd = true;
    }
};

class Trie {
public:
    TrieNode *root;
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode *node = root;
        
        for (char ch: word) {
            if (!node->containsKey(ch)) {
                node->push(ch, new TrieNode());
            }
            node = node->get(ch);
        }
        node->setEnd();
    }
    
    /** Returns if the word is in the trie. */
    TrieNode* searchPrefix(string word) {
        TrieNode *node = root;
        for (char ch: word) {
            // 如果存在
            if (node->containsKey(ch)) {
                node = node->get(ch);
            } else {
                return NULL;
            }
        }
        return node;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode *node = searchPrefix(word);
        return node && node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode *node = searchPrefix(prefix);
        return node != NULL;
    }
};

#endif /* Solution208_hpp */
