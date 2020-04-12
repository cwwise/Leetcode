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

/**
 
 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。

 设计一个算法来计算你所能获取的最大利润。你可以尽可能地完成更多的交易（多次买卖一支股票）。

 注意：你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

  

 示例 1:

 输入: [7,1,5,3,6,4]
 输出: 7
 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 3 天（股票价格 = 5）的时候卖出, 这笔交易所能获得利润 = 5-1 = 4 。
      随后，在第 4 天（股票价格 = 3）的时候买入，在第 5 天（股票价格 = 6）的时候卖出, 这笔交易所能获得利润 = 6-3 = 3 。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

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
