//
//  Solution215.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/20.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution215_hpp
#define Solution215_hpp

#include <stdio.h>

/*
 215. 数组中的第K个最大元素
 在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
 */

class Solution215 {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int,vector<int>,greater<int> > queue;
        for (int i = 0; i < k; i ++) {
            queue.push(nums[i]);
        }
        
        for (int i = k; i < (int)nums.size(); i ++) {
            if (queue.top() > nums[i]) {
                queue.pop();
                queue.push(nums[i]);
            }
        }
        return queue.top();
    }
    
    int findKthLargest1(vector<int>& nums, int k) {
        priority_queue <int> queue;
        int n = (int)nums.size();
        for (int i = 0; i < n; i ++) {
            queue.push(nums[i]);
        }
        
        for (int i = 0; i < k - 1; i ++) {
            queue.pop();
        }
        return queue.top();
    }
    
    void test() {
        vector<int> demo{1, 2, 3, 4, 5};
        cout << findKthLargest(demo, 5) << endl;
    }
};

#endif /* Solution215_hpp */
