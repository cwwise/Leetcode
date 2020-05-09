//
//  Solution76.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/5/2.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution76_hpp
#define Solution76_hpp

#include <stdio.h>
#include "Leetcode_C.h"

class Solution76 {
public:
    string minWindow(string s, string t) {
        
        int start = 0, minLen = INT_MAX;
        int left = 0, right = 0;
        string res = s;
        
        unordered_map<char, int> windows;
        unordered_map<char, int> needs;
        
        for (char c: t) needs[c] ++;
        // 记录符合字符的要求
        int match = 0;
        
        while (right < s.size()) {
            char c1 = s[right];
            if (needs.count(c1)) {
                windows[c1] ++;
                if (windows[c1] == needs[c1]) {
                    match ++;
                }
            }
            right ++;
            
            while (match == needs.size()) {
                // 更新最小串
                if (right - left < minLen) {
                    start = left;
                    minLen = right - left;
                }
                char c2 = s[left];
                if (needs.count(c2)) {
                    windows[c2] --;
                    if (windows[c2] == needs[c2]) {
                        match --;
                    }
                }
                left ++;
            }
        }
        
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
    
    void test() {
        
    }
};

#endif /* Solution76_hpp */
