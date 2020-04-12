//
//  Solution188.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/12.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution188_hpp
#define Solution188_hpp

#include <stdio.h>

/**
 
 给定一个数组，它的第 i 个元素是一支给定的股票在第 i 天的价格。

 设计一个算法来计算你所能获取的最大利润。你最多可以完成 k 笔交易。

 注意: 你不能同时参与多笔交易（你必须在再次购买前出售掉之前的股票）。

 示例 1:

 输入: [2,4,1], k = 2
 输出: 2
 解释: 在第 1 天 (股票价格 = 2) 的时候买入，在第 2 天 (股票价格 = 4) 的时候卖出，这笔交易所能获得利润 = 4-2 = 2 。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iv
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

class Solution188 {
public:
    int maxProfit(int k, vector<int>& prices) {

        size_t n = prices.size();
        if (n < 2) {
            return 0;
        }
        
        if (k < 1) {
            return 0;
        }
        
        vector<vector<int>> dp(n, vector<int>(k*2+1, INT_MIN));
        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < n; i ++) {
            dp[i][0] = 0;
            for (int j = 1; j <= k; j ++) {
                int temp_k = 2*(j-1) + 1;
                // 买入
                dp[i][temp_k] = max(dp[i-1][temp_k], dp[i][temp_k-1] - prices[i]);
                dp[i][temp_k+1] = max(dp[i-1][temp_k+1], dp[i][temp_k] + prices[i]);
            }
        }
        
        // 所有卖出时候的最大值
        int res = 0;
        for (int i = 0; i < k*2+1; i += 2) {
            res = max(res, dp[n-1][i]);
        }
        return res;
    }
    
    int maxProfit1(int k, vector<int>& prices) {

        size_t n = prices.size();
        if (n < 2 || k < 1) {
            return 0;
        }
        
        if (k >= n / 2) {
            return greedy(prices);
        }
        
        vector<int> dp(k*2+1, INT_MIN);
        dp[0] = 0;
        dp[1] = -prices[0];

        for (int i = 1; i < n; i ++) {
            for (int j = 1; j <= k; j ++) {
                int temp_k = 2*(j-1) + 1;
                // 买入
                dp[temp_k] = max(dp[temp_k], dp[temp_k-1] - prices[i]);
                dp[temp_k+1] = max(dp[temp_k+1], dp[temp_k] + prices[i]);
            }
        }
        
        // 所有卖出时候的最大值
        int res = 0;
        for (int i = 0; i < k*2+1; i += 2) {
            res = max(res, dp[i]);
        }
        return res;
    }
    
    int greedy(vector<int>& prices) {
        
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
        // 2 5 2
        vector<int> demo1{5,7,2,7,3,3,5,3,0};
        cout << maxProfit1(1000000000, demo1) << endl;
    }
};

#endif /* Solution188_hpp */
