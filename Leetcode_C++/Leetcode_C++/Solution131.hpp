//
//  Solution131.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/5/21.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution131_hpp
#define Solution131_hpp

#include <stdio.h>

/**
 给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。

 返回 s 所有可能的分割方案。

 示例:
 */
class Solution131 {
public:
    vector<vector<string>> res;
    vector<vector<string>> partition(string s) {
        if (s.size() == 0) return res;
        vector<string> path;
        backtrack(0, s, path);
        return res;
    }

    void backtrack(int start, string s, vector<string> &path) {
        int n = s.size();
        if (start == n) {
            res.push_back(path);
            return;
        }

        for (int i = start; i < n; i ++) {
            if (!isValid(s, start, i)) {
                continue;
            }
            path.push_back(s.substr(start, i - start + 1));
            backtrack(i+1, s, path);
            path.pop_back();
        }
    }

    bool isValid(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end]) return false;
            start ++;
            end --;
        }
        return true;
    }
    
    void test() {
        partition("aab");
    }
};
#endif /* Solution131_hpp */
