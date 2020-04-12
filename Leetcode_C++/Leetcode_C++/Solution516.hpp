//
//  Solution516.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/12.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution516_hpp
#define Solution516_hpp

#include <stdio.h>

class Solution516 {
public:
    int longestPalindromeSubseq(string s) {
        int n = int(s.length());
        if (n < 2) {
            return 1;
        }
        
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i ++) {
            dp[i][i] = 1;
        }
        
        for (int i = n - 1; i >= 0; i --) {
            for (int j = i + 1; j < n; j ++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i+1][j-1] + 2;
                } else {
                    dp[i][j] = max(dp[i+1][j], dp[i][j-1]);
                }
            }
        }
        
        return dp[0][n-1];
    }
    
    void test() {
        cout << longestPalindromeSubseq("bbbab") << endl;
    }
};

#endif /* Solution516_hpp */
