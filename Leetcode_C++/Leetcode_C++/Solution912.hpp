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
