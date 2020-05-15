//
//  Solution912.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/3/31.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution912_hpp
#define Solution912_hpp

#include <stdio.h>

//排序数组
class Solution912 {
public:
    
    void maxHeapify(vector<int>& nums, int i, int len) {
        for (; (i << 1) + 1 <= len;) {
            int lson = (i << 1) + 1;
            int rson = (i << 1) + 2;
            int large;
            if (lson <= len && nums[lson] > nums[i]) {
                large = lson;
            }
            else {
                large = i;
            }
            if (rson <= len && nums[rson] > nums[large]) {
                large = rson;
            }
            if (large != i) {
                swap(nums[i], nums[large]);
                i = large;
            }
            else break;
        }
    }
    
    
    vector<int> sortArray(vector<int>& nums) {
        return nums;
    }
    
    //    quickSort(vector<int>& nums) {
    //
    //    }
    //
    //    //
    //    __quickSort(vector<int>& nums, )
    
    void test() {
        vector<int> demo1 = vector<int>{1, 2, 4, 10, 8, 7, 3, 5};
        demo1 = sortArray(demo1);
        for (int i = 0; i < demo1.size(); i ++) {
            cout << demo1[i] << " ";
        }
        cout << endl;
    }
};

#endif /* Solution912_hpp */
