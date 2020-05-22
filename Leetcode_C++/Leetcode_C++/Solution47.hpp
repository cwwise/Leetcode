//
//  Solution47.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/5/21.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution47_hpp
#define Solution47_hpp

#include <stdio.h>

class Solution47 {
public:

    vector<vector<int>> res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return res;
        
        sort(nums.begin(), nums.end());
        vector<int> used(n, false);
        vector<int> path;
        backtrack(nums, 0, used, path);
        return res;
    }

    void backtrack(vector<int> nums, int start,
                   vector<int> &used, vector<int> &path) {
        if (start == nums.size()) {
            vector<int> temp = path;
            res.push_back(temp);
            return;
        }

        for (int i = 0; i < nums.size(); i ++) {
            // 判断条件
            if (used[i]) continue;
            if (i > 0 && nums[i] == nums[i-1] && !used[i - 1]) continue;

            path.push_back(nums[i]);
            used[i] = true;
            backtrack(nums, start + 1, used, path);
            used[i] = false;
            path.pop_back();
        }
    }
    
    void test() {
        vector<int> demo{1, 1, 3};
        permuteUnique(demo);
    }
};

#endif /* Solution47_hpp */
