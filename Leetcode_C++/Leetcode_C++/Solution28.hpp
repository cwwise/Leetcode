//
//  Solution28.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/5/22.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution28_hpp
#define Solution28_hpp

#include <stdio.h>

class Solution28 {
public:
    
    char *strStr(char *haystack, char *needle) {
        // 模式串
        int s_len = strlen(haystack);
        // 目标串
        int p_len = strlen(needle);
        
        // 特殊判断
        if (p_len > s_len) return NULL;
        if (p_len == 0) return needle;
        unordered_map<char, int> map;
        for (int i = 0; i < p_len; i ++) {
            map[needle[i]] = p_len - i;
        }

        int index = 0;
        while (index + p_len <= s_len) {
            // haystack.substr(index, p_len) == needle
            if (isEqual(haystack, index, p_len, needle)) {
                return haystack + index;
            } else {
                if (index + p_len > s_len - 1) return NULL;
                else {
                    if (map.find(haystack[index+p_len]) != map.end()) {
                        index += map[haystack[index+p_len]];
                    } else {
                        index += p_len + 1;
                    }
                }
                
            }
        }
        return NULL;
    }
    
    bool isEqual(char *s, int start, int length, char *p) {
        int i = start;
        while (i < length+start) {
            if (s[i] != p[i-start]) {
                return false;
            }
            i ++;
        }
        return true;
    }
    
    int strStr(string haystack, string needle) {
        
        // 模式串
        int s_len = (int)haystack.length();
        // 目标串
        int p_len = (int)needle.length();
        
        // 特殊判断
        if (p_len > s_len) return -1;
        if (p_len == 0) return 0;
        unordered_map<char, int> map;
        for (int i = 0; i < p_len; i ++) {
            map[needle[i]] = p_len - i;
        }

        int index = 0;
        while (index + p_len <= s_len) {
            if (haystack.substr(index, p_len) == needle) {
                return index;
            } else {
                if (index + p_len > s_len - 1) return -1;
                else {
                    if (map.find(haystack[index+p_len]) != map.end()) {
                        index += map[haystack[index+p_len]];
                    } else {
                        index += p_len + 1;
                    }
                }
            }
        }
        return -1;
    }
    
    void test() {
        char *s = "mississippi";
        char *p = "issi";
        strStr(s, p);
        strStr("mississippi", "issi");
    }
};

#endif /* Solution28_hpp */
