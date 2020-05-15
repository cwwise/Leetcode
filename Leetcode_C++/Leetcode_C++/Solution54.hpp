//
//  Solution54.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/5/9.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution54_hpp
#define Solution54_hpp

#include <stdio.h>

class Solution54 {
public:
    vector<int> spiralOrder1(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) return {};
        vector<int> res;
        int R = (int)matrix.size();
        int C = (int)matrix[0].size();
        vector<vector<bool>> seen(R, vector<bool>(C, false));

        int dr[4] = {0, 1, 0, -1};
        int dc[4] = {1, 0, -1, 0};
        int r = 0, c = 0, di = 0;
    
        return res;
    }
    
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0) {
            return {};
        }
        vector<int> res;
        int r = (int)matrix.size();
        int c = (int)matrix[0].size();
        
        
        return res;
    }
};

#endif /* Solution54_hpp */
