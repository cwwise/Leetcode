//
//  Solution714.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/13.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution714_hpp
#define Solution714_hpp

#include <stdio.h>

2147483646
2147483647
2147483646
/**
 
 给定一个整数数组 prices，其中第 i 个元素代表了第 i 天的股票价格 ；非负整数 fee 代表了交易股票的手续费用。

 你可以无限次地完成交易，但是你每次交易都需要付手续费。如果你已经购买了一个股票，在卖出它之前你就不能再继续购买股票了。

 返回获得利润的最大值。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
class Solution714 {
public:
    int maxProfit(vector<int>& prices, int fee) {
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
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]+prices[i]-fee);
            dp[i][1] = max(dp[i-1][1], dp[i-1][0]-prices[i]);
        }
        return dp[n - 1][0];
    }
    
    void test() {
        vector<int> demo{1, 3, 2, 8, 4, 9};
        cout << maxProfit(demo, 2) << endl;
    }
};

#endif /* Solution714_hpp */
