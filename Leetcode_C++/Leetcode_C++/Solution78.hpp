//
//  Solution77.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/5/12.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution78_hpp
#define Solution78_hpp

#include <stdio.h>

class Solution78 {
public:
    vector<vector<int>> res;
    vector<vector<int>> subsets(vector<int>& nums) {

        if (nums.size() == 0) {
            return res;
        }
        
        vector<int> track;
        backtrack(nums, 1, track);
        return res;
    }
    
    void backtrack(vector<int>& nums, int begin, vector<int> &track) {
        res.push_back(track);
        for (int i = begin; i < nums.size(); i ++) {
            track.push_back(i);
            backtrack(nums, i + 1, track);
            track.pop_back();
        }
    }
    
    void test() {
        
    }
    
};

#endif /* Solution77_hpp */
