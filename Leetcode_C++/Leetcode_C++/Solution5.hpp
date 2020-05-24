//
//  Solution5.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/12.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution5_hpp
#define Solution5_hpp

#include <stdio.h>

/**
 给定一个字符串 s，找到 s 中最长的回文子串。你可以假设 s 的最大长度为 1000。
 
 示例 1：
 
 输入: "babad"
 输出: "bab"
 注意: "aba" 也是一个有效答案。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/longest-palindromic-substring
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

class Solution5 {
public:
    string longestPalindrome(string s) {
        size_t len = s.length();
        if (len < 2) {
            return s;
        }
        vector<vector<bool>> dp(len, vector<bool>(len, false));
        int maxLen = 1;
        int start = 0;
        for (int j = 1; j < len; j ++) {
            for (int i = 0; i < j; i ++) {
                if (s[i] == s[j]) {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                } else {
                    dp[i][j] = false;
                }
                
                if (dp[i][j]) {
                    int curLen = j - i + 1;
                    if (curLen > maxLen) {
                        maxLen = curLen;
                        start = i;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
    
    string longestPalindrome2(string s) {
        int n = s.size();
        if (n <= 1) return s;
        int start = 0;
        int max_len = 0;
        
        // 中心扩散法
        for (int i = 0; i < n; i ++) {
            int len1 = isPalindromic(s, i, i);
            int len2 = isPalindromic(s, i, i+1);
            int len = max(len1, len2);
            
            if (len > max_len) {
                start = i - (len-1)/2;
                max_len = len;
            }
        }
        return s.substr(start, max_len);
    }
    
    int isPalindromic(string s, int left, int right) {
        int l = left;
        int r = right;
        while (l >= 0 && r < s.size() && s[l] == s[r]) {
            l --;
            r ++;
        }
        return r - l - 1;
    }
    
    string longestPalindrome1(string s) {
        // 表示包含i位置 最长回文字符
        // dp[i] = dp[i-1]
        // 从i到j 最长回文字符
        // dp[i][j]。
        // dp[i-1][j+1]
        string ans = "";
        size_t max_l = 0;
        size_t len = s.length();
        
        for (int i = 0; i < len; i ++) {
            
            for (int j = 1; j <= len-i; j ++) {
                string subS = s.substr(i, j);
                if (subS.length() > max_l && isPalindromic(subS)) {
                    ans = s.substr(i, j);
                    max_l = ans.length();
                }
            }
        }
        return ans;
    }
    
    bool isPalindromic(string s) {
        size_t len = s.length();
        for (int i = 0; i < len / 2; i ++) {
            if (s[i] != s[len-1-i]) {
                return false;
            }
        }
        return true;
    }
    
    void test() {
        cout << longestPalindrome2("babad") << endl;
    }
};

#endif /* Solution5_hpp */
