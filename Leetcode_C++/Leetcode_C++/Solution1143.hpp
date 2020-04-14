//
//  Solution1143.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/13.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution1143_hpp
#define Solution1143_hpp

#include <stdio.h>

class Solution1143 {
public:
    int longestCommonSubsequence(string text1, string text2) {

        size_t m = text1.length(), n = text2.length();
        
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for (int i = 1; i < m + 1; i ++) {
            for (int j = 1; j < n + 1; j ++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i-1][j-1];
                } else {
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                }
            }
        }
        return dp[m][n];
    }
};

#endif /* Solution1143_hpp */
