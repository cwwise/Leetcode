//
//  Solution70.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/3/29.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution70_hpp
#define Solution70_hpp

#include <stdio.h>
#include "Leetcode_C.h"

/*
 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
 注意：给定 n 是一个正整数。
 
 */

class Solution70 {
public:
    int climbStairs(int n) {
        if (n <= 2) {
            return n;
        }
        vector<int>dp(n,0);
        dp[0] = 1;
        dp[1] = 2;
        for(int i = 2; i < n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n-1];
    }
    
    void test() {
        for (int i = 1; i < 10; i ++) {
            cout << climbStairs(i) << endl;
        }
    }
};

#endif /* Solution70_hpp */
