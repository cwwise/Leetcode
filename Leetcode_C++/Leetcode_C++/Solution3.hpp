//
//  Solution3.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/5/2.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution3_hpp
#define Solution3_hpp

#include <stdio.h>
#include "Leetcode_C.h"

class Solution3 {
public:
    int lengthOfLongestSubstring1(string s) {
        int n = (int)s.length();
        
        // 哈希集合，记录每个字符是否出现过
        unordered_set<char> occ;
        int rk = -1, ans = 0;
        
        for (int i = 0; i < n; i ++) {
            if (i != 0) {
                occ.erase(s[i-1]);
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                occ.insert(s[rk + 1]);
                rk ++;
            }
            ans = max(ans, rk - i + 1);
        }
        return ans;
    }
    
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_set<char> lookup;
        int maxStr = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            while (lookup.find(s[i]) != lookup.end()){
                lookup.erase(s[left]);
                left ++;
            }
            maxStr = max(maxStr,i-left+1);
            lookup.insert(s[i]);
        }
        return maxStr;
    }
    
    int lengthOfLongestSubstring2(string s) {
        int left = 0, right = 0;
        unordered_map<char, int> window;
        int res = 0;
        
        while (right < s.size()) {
            char c1 = s[right];
            window[c1] ++;
            right ++;
            
            while (window[c1] > 1) {
                char c2 = s[left];
                window[c2] --;
                left ++;
            }
            res = max(res, right - left);
        }
        return res;
    }
    
    void test() {
        cout << lengthOfLongestSubstring("abcabcbb") << endl;
    }
};

#endif /* Solution3_hpp */
