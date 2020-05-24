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
#include "Leetcode_C.h"

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
    
    int findKthLargest2(vector<int>& nums, int k) {
        int n = nums.size();
        return quickselect(nums, 0, n - 1, n - k);
    }
    
    int partition(vector<int>& nums, int left, int right) {
        // 标定点left
        
        int pivot = nums[left];
        int i = left + 1;
        int j = right;
        while (true) {
            while (i <= j && nums[i] < pivot) i++;
            while (i <= j && nums[j] > pivot) j++;
            if (i > j) break;
            swap(nums[i++], nums[j--]);
        }
        swap(nums[left], nums[j]);
        return j;
    }
    
    int quickselect(vector<int>& nums, int left, int right, int k_smallest) {
        // 只有一个数字
        if (left >= right) {
            return nums[left];
        }
        
        int pivot_index = partition(nums, left, right);
        if (pivot_index == k_smallest) {
            return nums[pivot_index];
        }
        else if (pivot_index > k_smallest) {
            return quickselect(nums, left, pivot_index - 1, k_smallest);
        } else {
            return quickselect(nums, pivot_index - 1, right, k_smallest);
        }
    }
    
    
    void test() {
        vector<int> demo{1, 2, 3, 4, 5};
        cout << findKthLargest(demo, 5) << endl;
    }
};

#endif /* Solution215_hpp */
