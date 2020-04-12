//
//  Solution121.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/11.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution121_hpp
#define Solution121_hpp

#include <stdio.h>
#include "Leetcode_C.h"
/**
 给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
 
 如果你最多只允许完成一笔交易（即买入和卖出一支股票一次），设计一个算法来计算你所能获取的最大利润。
 
 注意：你不能在买入股票前卖出股票。
 
 示例 1:
 
 输入: [7,1,5,3,6,4]
 输出: 5
 解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
 注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格；同时，你不能在买入前卖出股票。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */

class Solution121 {
public:
    int maxProfit(vector<int>& prices) {
        
        size_t n = prices.size();
        if (n == 0) return 0; // 边界条件
        int minprice = prices[0];
        vector<int> dp (n, 0);
        
        for (int i = 1; i < n; i++){
            minprice = min(minprice, prices[i]);
            dp[i] = max(dp[i - 1], prices[i] - minprice);
        }
        return dp[n - 1];
    }
    
    void test() {
        vector<int> demo1{1,5,4};
        cout << maxProfit(demo1) << endl;
    }
};

#endif /* Solution121_hpp */
