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
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = { 0, 0, -1, 1};
public:
    
    void bfs(vector<vector<char>>& grid, int r, int c) {
        
        size_t nr = grid.size();
        size_t nc = grid[0].size();
        
        queue<pair<int, int>> queue;
        queue.push({r, c});
        while (!queue.empty()) {
            auto rc = queue.front();
            queue.pop();
            int row = rc.first, col = rc.second;
            grid[row][col] = '0';
            // 加入队列
            for (int i = 0; i < 4; i ++) {
                int to_x = row + dx[i];
                int to_y = col + dy[i];
                if (to_x >= 0 && to_x < nr && to_y >= 0 && to_y < nc && grid[to_x][to_y] == '1') {
                    queue.push({to_x, to_y});
                }
            }
        }
    }
    
    void dfs(vector<vector<char>>& grid, int row, int col) {
        size_t nr = grid.size();
        size_t nc = grid[0].size();
        grid[row][col] = '0';
        for (int i = 0; i < 4; i ++) {
            int to_x = row + dx[i];
            int to_y = col + dy[i];
            if (to_x >= 0 && to_x < nr && to_y >= 0 && to_y < nc && grid[to_x][to_y] == '1') {
                dfs(grid, to_x, to_y);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        size_t nr = grid.size();
        if (!nr) return 0;
        size_t nc = grid[0].size();
        
        int nums = 0;
        for (int r = 0; r < nr; r ++) {
            for (int c = 0; c < nc; c ++) {
                if (grid[r][c] == '1') {
                    nums ++;
                    dfs(grid, r, c);
                }
            }
        }
        return nums;
    }
    
    void test() {
        
        vector<char> test1 = vector<char>{'1','1','1','1','0'};
        vector<char> test2 = vector<char>{'1','1','0','1','0'};
        vector<char> test3 = vector<char>{'1','1','0','0','0'};
        vector<char> test4 = vector<char>{'1','1','0','0','0'};
        vector<char> test5 = vector<char>{'0','0','0','0','0'};
        
        vector<vector<char>> grid;
        grid.push_back(test1);
        grid.push_back(test2);
        grid.push_back(test3);
        grid.push_back(test4);
        grid.push_back(test5);
        
        cout << numIslands(grid) << endl;
    }
    
};

#endif /* Solution200_hpp */
