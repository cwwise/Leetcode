//
//  Solution123.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/12.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution123_hpp
#define Solution123_hpp

#include <stdio.h>

/**
 
 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。
 
 设计一个算法来计算你所能获取的最大利润。你最多可以完成 两笔 交易。
 
 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 
 示例 1:
 
 输入: [3,3,5,0,0,3,1,4]
 输出: 6
 解释: 在第 4 天（股票价格 = 0）的时候买入，在第 6 天（股票价格 = 3）的时候卖出，这笔交易所能获得利润 = 3-0 = 3 。
      随后，在第 7 天（股票价格 = 1）的时候买入，在第 8 天 （股票价格 = 4）的时候卖出，这笔交易所能获得利润 = 4-1 = 3 。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

class Solution123 {
public:
    int maxProfit(vector<int>& prices) {
        
        size_t n = prices.size();
        if (n < 2) {
            return 0;
        }
        
        vector<vector<int>> dp(n,vector<int>(5,0));
        
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        
        for (int i = 0; i < n; i ++) {
            dp[i][3] = INT_MIN;
        }
        
        for (int i = 1; i < n; i ++) {
            dp[i][0] = 0;
            dp[i][1] = max(dp[i-1][1], dp[i][0]-prices[i]);
            dp[i][2] = max(dp[i-1][2], dp[i][1]+prices[i]);
            dp[i][3] = max(dp[i-1][3], dp[i][2]-prices[i]);
            dp[i][4] = max(dp[i-1][4], dp[i][3]+prices[i]);
        }
        
        return max(0, max(dp[n-1][2], dp[n-1][4]));
    }
    
    int maxProfit1(vector<int>& prices) {
        size_t n = prices.size();
        if (n < 2) {
            return 0;
        }
        
        vector<int> dp(5,0);
        
        dp[0] = 0;
        dp[1] = -prices[0];
        
        dp[3] = INT_MIN;
        
        for (int i = 1; i < n; i ++) {
            dp[0] = 0;
            dp[1] = max(dp[1], dp[0]-prices[i]);
            dp[2] = max(dp[2], dp[1]+prices[i]);
            dp[3] = max(dp[3], dp[2]-prices[i]);
            dp[4] = max(dp[4], dp[3]+prices[i]);
        }
        
        return max(0, max(dp[2], dp[4]));
    }
    
    void test() {
        
    }
};


#endif /* Solution123_hpp */
