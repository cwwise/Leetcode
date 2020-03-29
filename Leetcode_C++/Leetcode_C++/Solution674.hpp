//
//  Solution674.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/3/29.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution674_hpp
#define Solution674_hpp

#include <stdio.h>
#include "Leetcode_C.h"

/*
 给定一个未经排序的整数数组，找到最长且连续的的递增序列。
 
 输入: [1,3,5,4,7]
 输出: 3
 解释: 最长连续递增序列是 [1,3,5], 长度为3。
 尽管 [1,3,5,7] 也是升序的子序列, 但它不是连续的，因为5和7在原数组里被4隔开。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/longest-continuous-increasing-subsequence
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
class Solution674 {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        /*
         如果知道 L[i]的值 求L[i+1]
         L[i+1] = (a[i+1] > a[i]) ? L[i] + 1 : L[i]
         L[0] = 1
         */
        //
        if (nums.size() == 0) {
            return 0;
        }
        int ans = 1;
        // 当前值
        int count = 1;
        for (int i = 1; i < nums.size(); i ++) {
            if (nums[i] > nums[i-1]) {
                count += 1;
            } else {
                count = 1;
            }
            ans = max(ans, count);
        }
        return ans;
    }
    
    void test() {
        vector<int> nums1 = vector<int>{1,3,5,4,7};
        cout << findLengthOfLCIS(nums1) << endl;
    }
};

#endif /* Solution674_hpp */
