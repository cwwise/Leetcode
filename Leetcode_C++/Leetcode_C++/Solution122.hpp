//
//  Solution122.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/11.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution122_hpp
#define Solution122_hpp

#include <stdio.h>

class Solution122 {
public:
    int maxProfit(vector<int>& prices) {
        
        size_t n = prices.size();
        if (n == 0) {
            return 0;
        }
        
        //初始化row * col二维动态数组，初始化值为0
        vector<vector<int>> dp(prices.size(),vector<int>(2,0));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < n; i ++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
        }
        return dp[n-1][0];
    }
    
    int maxProfit1(vector<int>& prices) {
        
        size_t n = prices.size();
        if (n == 0) {
            return 0;
        }
        
        //初始化row * col二维动态数组，初始化值为0
        vector<int> dp_cash(n, 0);
        vector<int> dp_hold(n, 0);

        dp_cash[0] = 0;
        dp_hold[0] = -prices[0];

        for (int i = 1; i < n; i ++) {
            dp_cash[i] = max(dp_cash[i-1], dp_hold[i-1]+prices[i]);
            dp_hold[i] = max(dp_hold[i-1], dp_cash[i-1]-prices[i]);
        }
        return dp_cash[n-1];
    }
    
    void test() {
        
    }
};



#endif /* Solution122_hpp */
