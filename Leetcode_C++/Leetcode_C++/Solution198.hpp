//
//  Solution198.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/13.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution198_hpp
#define Solution198_hpp

#include <stdio.h>

class Solution198 {
public:
    int rob(vector<int>& nums) {
        // dp[]
        int n = (int)nums.size();
        vector<int> dp(n+2, 0);
        for (int i = n-1; i >= 0; i -- ) {
            dp[i] = max(dp[i+1], dp[i+2]+nums[i]);
        }
        return dp[0];
    }
    
    int robRange(vector<int>& nums, int start, int end) {
        int n = (int)nums.size();
        vector<int> dp(n+2, 0);
        for (int i = end; i >= start; i -- ) {
            dp[i] = max(dp[i+1], dp[i+2]+nums[i]);
        }
        return dp[start];
    }
    
    int rob1(vector<int>& nums) {
        int n = (int)nums.size();
        if (n == 1) {
            return nums[0];
        }
        return max(robRange(nums, 0, n - 2), robRange(nums, 1, n - 1));
    }
    
    void test() {
        vector<int>demo{3,2,1};
        cout << rob(demo) << endl;
        cout << rob1(demo) << endl;
    }
};

#endif /* Solution198_hpp */
