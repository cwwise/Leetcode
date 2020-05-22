//
//  Solution151.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/5/22.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution151_hpp
#define Solution151_hpp

// 翻转字符串里的单词
// 给定一个字符串，逐个翻转字符串中的每个单词。
// 输入: "the sky is blue"
// 输出: "blue is sky the"
#include <stdio.h>

class Solution151 {
public:
    string reverseWords(string s) {
        int n = s.length();
        // 特判
        if (n == 0) return s;
        int j = n - 1;
        // 去掉尾部空格
        while (s[j] == ' ' && j > 0) {
            j --;
        }
        
        int i = j;
        string res;
        while (i >= 0) {
            while (i >= 0 && s[i] != ' ') i--;
            res += s.substr(i+1, j-i);
            res += " ";
            while (i >= 0 && s[i] == ' ') i--;
            j = i;
        }
        // 去掉最后空格
        res.pop_back();
        return res;
    }
};

#endif /* Solution151_hpp */
