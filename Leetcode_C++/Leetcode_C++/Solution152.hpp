//
//  Solution152.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/11.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution152_hpp
#define Solution152_hpp

#include <stdio.h>
#include "Leetcode_C.h"

class Solution152 {
public:
    int maxProduct(vector<int>& nums) {
        size_t n = nums.size();
        if (n == 0) {
            return 0;
        }
        vector<int> dpMin(n, 0);
        vector<int> dpMax(n, 0);
        dpMin[0] = dpMax[0] = nums[0];
        int res = nums[0];
        for (int i = 1; i < n; i ++) {
            dpMax[i] = max(max(dpMax[i-1] * nums[i], dpMin[i-1] * nums[i]), nums[i]);
            dpMin[i] = min(min(dpMax[i-1] * nums[i], dpMin[i-1] * nums[i]), nums[i]);
            res = max(dpMax[i], res);
        }
        return res;
    }
    
    //
    int maxProduct1(vector<int>& nums) {
        size_t n = nums.size();
        if (n == 0) {
            return 0;
        }
        int dpMax = nums[0];
        int dpMin = nums[0];
        int res = nums[0];
        
        for (int i = 1; i < n; i ++) {
            int preMax = dpMax;
            dpMax = max(max(dpMax * nums[i], dpMin * nums[i]), nums[i]);
            dpMin = min(min(preMax * nums[i], dpMin * nums[i]), nums[i]);
            res = max(dpMax, res);
        }
        return res;
    }
    
    void test() {
        vector<int> demo1{-2,0,-1,2,3};
        cout << maxProduct1(demo1) << endl;
    }
    
};

#endif /* Solution152_hpp */
