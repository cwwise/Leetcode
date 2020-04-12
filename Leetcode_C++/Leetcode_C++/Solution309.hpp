//
//  Solution309.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/13.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution309_hpp
#define Solution309_hpp

#include <stdio.h>

/**
 给定一个整数数组，其中第 i 个元素代表了第 i 天的股票价格 。
 
 设计一个算法计算出最大利润。在满足以下约束条件下，你可以尽可能地完成更多的交易（多次买卖一支股票）:
 
 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。
 卖出股票后，你无法在第二天买入股票 (即冷冻期为 1 天)。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

class Solution309 {
public:
    int maxProfit(vector<int>& prices) {
        
        size_t n = prices.size();
        if (n == 0) {
            return 0;
        }
        
        //初始化row * col二维动态数组，初始化值为0
        vector<vector<int>> dp(prices.size(),vector<int>(2,0));
        // 不持股
        dp[0][0] = 0;
        // 持股
        dp[0][1] = -prices[0];

        for (int i = 1; i < n; i ++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]);
            dp[i][1] = max(dp[i-1][1], dp[i-1][1]-prices[i]);
        }
        return dp[n - 1][0];
    }
    
    void test() {
        
    }
};

#endif /* Solution309_hpp */
