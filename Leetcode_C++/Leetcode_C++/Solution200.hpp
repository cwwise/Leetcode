//
//  Solution200.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/3/23.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution200_hpp
#define Solution200_hpp

#include "Leetcode_C.h"
#include <stdio.h>

class Solution200 {
    int d_x[4] = {-1, 0, 1, 0};
    int d_y[4] = {-1, 0, 1, 0};
public:
    int numIslands(vector<vector<char>>& grid) {
      size_t nr = grid.size();
      if (!nr) return 0;
      size_t nc = grid[0].size();
        
      int nums = 0;
      for (int r = 0; r < nr; r ++) {
        for (int c = 0; c < nc; c ++) {
          if (grid[r][c] == '1') {
            nums ++;
            grid[r][c] = '0';

            queue<pair<int, int>> queue;
            queue.push({r, c});

            while (!queue.empty()) {
              auto rc = queue.front();
              queue.pop();
              int row = rc.first, col = rc.second;
              

            } 

          }

        } 
      }
            
      return nums;  
    }
    
    
};

#endif /* Solution200_hpp */
