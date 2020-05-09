//
//  Solution239.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/5/2.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution239_hpp
#define Solution239_hpp

#include <stdio.h>

class Solution239 {
public:
    
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        if (k == 0) return res;
        deque<size_t> window;
        /*Init K integers in the list*/
        for (size_t i = 0; i < k; i++) {
            while (!window.empty() && nums[i] > nums[window.back()]) {
                window.pop_back();
            }
            window.push_back(i);
        }
        res.push_back(nums[window.front()]);
        
        /*End of initialization*/
        for (size_t i = k; i < nums.size(); i++) {
            if (!window.empty() && window.front() <= i - k) {
                window.pop_front();
            }
            while (!window.empty() && nums[i] > nums[window.back()]) {
                window.pop_back();
            }
            window.push_back(i);
            res.push_back(nums[window.front()]);
        }
        
        return res;
    }
    
    void test() {
        vector<int> nums{1,3,-1,-3,5,3,6,7};
        maxSlidingWindow(nums, 3);
    }
};

#endif /* Solution239_hpp */
