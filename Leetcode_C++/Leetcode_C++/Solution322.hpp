//
//  Solution322.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/12.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution322_hpp
#define Solution322_hpp

#include <stdio.h>

class Solution322 {
public:
    int coinChange(vector<int>& coins, int amount) {
        // dp[n] = dp[n-coin] + 1
        size_t n = coins.size();
        if (n == 0) {
            return 0;
        }
        
        // dp[n] = dp[n-coin] + 1
        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;
        for (int i = 1; i < dp.size(); i ++) {
            for (int coin: coins) {
                if (i - coin < 0) {
                    continue;
                }
                dp[i] = min(dp[i], dp[i-coin] + 1);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
    
    int ans = INT_MAX;
    void dfs(vector<int>& coins,int index,int amount,int cnt){

        if (index < 0) {
            return;
        }
        
        for (int c = amount/coins[index]; c >= 0; c --) {
            int na = amount - c*coins[index];
            int ncnt = cnt+c;
            
            if (na == 0) {
                ans = min(ans, ncnt);
                break;
            }
            
            if (ncnt + 1 >= ans) {
                break;
            }
            
            dfs(coins, index-1, na, ncnt);
        }
        
    }
    
    
    void test() {
        
    }
};

#endif /* Solution322_hpp */
