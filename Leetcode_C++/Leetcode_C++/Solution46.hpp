//
//  Solution46.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/3.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution46_hpp
#define Solution46_hpp

#include <stdio.h>
#include "Leetcode_C.h"

/**
 给定一个 没有重复 数字的序列，返回其所有可能的全排列。

 输入: [1,2,3]
 输出:
 [
   [1,2,3],
   [1,3,2],
   [2,1,3],
   [2,3,1],
   [3,1,2],
   [3,2,1]
 ]

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/permutations
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
 */

class Solution46 {
public:
    vector<vector<int>> result;
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> track;
        backtrack(nums, track);
        return result;
    }
    
    void backtrack(vector<int> nums, vector<int>& track) {
        if (track.size() == nums.size()) {
            vector<int> temp = track;
            result.push_back(temp);
            return;
        }
        
        for (int i = 0; i < nums.size(); i++) {
            if (find(track.begin(), track.end(), nums[i]) != track.end()) {
                continue;
            }
            track.push_back(nums[i]);
            backtrack(nums, track);
            track.pop_back();
        }
    }
    
    void test() {
        vector<int> demo{1, 2, 3};
        permute(demo);
        
    }
};

#endif /* Solution46_hpp */
