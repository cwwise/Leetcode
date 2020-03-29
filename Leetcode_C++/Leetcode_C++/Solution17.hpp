//
//  Solution17.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/3/25.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution17_hpp
#define Solution17_hpp

#include <stdio.h>
#include "Leetcode_C.h"

/*
 一个有名的按摩师会收到源源不断的预约请求，每个预约都可以选择接或不接。在每次预约服务之间要有休息时间，因此她不能接受相邻的预约。给定一个预约请求序列，替按摩师找到最优的预约集合（总预约时间最长），返回总的分钟数。
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/the-masseuse-lcci
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
class Solution17 {
public:
    int massage(vector<int>& nums) {
        size_t n = nums.size();
        if (n == 0) {
            return 0;
        }
        // dp[i][0] = max(dp[i-1][0], dp[i-1][1])
        // dp[i][1] = dp[i-1][0] + nums
        int dp0 = 0, dp1 = nums[0];
        for (int i = 1; i < n; i ++) {
            int tdp0 = max(dp0, dp1);
            int tdp1 = dp0 + nums[i];
            dp0 = tdp0;
            dp1 = tdp1;
        }
        return max(dp0, dp1);
    }
};

#endif /* Solution17_hpp */
