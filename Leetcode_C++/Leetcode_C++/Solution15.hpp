//
//  Solution15.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/5/15.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution15_hpp
#define Solution15_hpp

#include <stdio.h>

class Solution15 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        int n = (int)nums.size();
        // 判断
        if (n < 3) return res;
        // 排序
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i ++) {
            if (nums[i] > 0) break;
            // 跳过重复
            if (i > 0 && nums[i] == nums[i-1]) continue;
            int l = i + 1;
            int r = n - 1;
            while (l < r) {
                int sum = nums[i] + nums[l] + nums[r];
                if (sum == 0) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    while (l < r && nums[l] == nums[l + 1]) l ++;
                    while (l < r && nums[r] == nums[r - 1]) r --;
                    l ++;
                    r --;
                } else if (sum < 0) {
                    l ++;
                } else {
                    r --;
                }
            }
        }
        return res;
    }
    
    void test() {
        vector<int> a{-1,0,1,2,-1,-4};
        threeSum(a);
    }
};


#endif /* Solution15_hpp */
