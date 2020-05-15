//
//  Solution18.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/5/15.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution18_hpp
#define Solution18_hpp

#include <stdio.h>

class Solution18 {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        int n = (int)nums.size();
        // 判断
        if (n < 4) return res;
        find(nums.begin(), nums.end(), <#const _Tp &__value_#>)
        // 排序
        sort(nums.begin(), nums.end());
        // i j (l, r)
        for (int i = 0; i < n - 3; i ++) {
            // 先过滤重复
            if (i > 0 && nums[i] == nums[i-1]) continue;
            
            for (int j = i + 1; j < n - 2; j ++) {
                // 跳过重复
                if (j > i + 1 && nums[j] == nums[j-1]) continue;
                int l = j + 1;
                int r = n - 1;
                while (l < r) {
                    int sum = nums[i] + nums[j] + nums[l] + nums[r];
                    if (sum == target) {
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
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
        }        
        return res;
    }
    
    void test() {
        vector<int> a{-3,-1,0,2,4,5};
        fourSum(a, 2);
    }
};

#endif /* Solution18_hpp */
