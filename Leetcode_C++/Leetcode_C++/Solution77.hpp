//
//  Solution77.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/5/12.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution77_hpp
#define Solution77_hpp

#include <stdio.h>

class Solution77 {
public:
    vector<vector<int>> res;
    vector<vector<int>> combine(int n, int k) {
        
        if (n <= 0 || k <= 0 || n < k) {
            return res;
        }
        vector<int> track;
        backtrack(n, k, 1, track);
        return res;
    }
    
    void backtrack(int n, int k, int begin, vector<int> &track) {
        // 结束
        if (track.size() == k) {
            res.push_back(track);
            return;
        }
        
        for (int i = begin; i <= n; i ++) {
            track.push_back(i);
            backtrack(n, k, i + 1, track);
            track.pop_back();
        }
    }
    
    void test() {
        combine(4, 2);
    }
    
};

#endif /* Solution77_hpp */
