//
//  Solution289.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/2.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution289_hpp
#define Solution289_hpp

#include <stdio.h>

class Solution289 {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int neighbors[3] = {0, 1, -1};
        
        size_t rows = board.size();
        size_t cols = board[0].size();
        
        // 创建复制数组 copyBoard
        vector<vector<int>>copyBoard(rows, vector<int>(cols, 0));
        
        // 从原数组复制一份到 copyBoard 中
        for (int row = 0; row < rows; row++) {
            for (int col = 0; col < cols; col++) {
                copyBoard[row][col] = board[row][col];
            }
        }
        
        
        for (int row = 0; row < rows; row ++) {
            for (int col = 0; col < cols; col ++) {
                
                // 对于每一个细胞统计其八个相邻位置里的活细胞数量
                int liveNeighbors = 0;
                
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        
                        if (!(neighbors[i] == 0 && neighbors[j] == 0)) {
                            int r = (row + neighbors[i]);
                            int c = (col + neighbors[j]);
                            
                            // 查看相邻的细胞是否是活细胞
                            if ((r < rows && r >= 0) && (c < cols && c >= 0) && (copyBoard[r][c] == 1)) {
                                liveNeighbors += 1;
                            }
                        }
                    }
                }
                
                
                // 规则 1 或规则 3
                if ((copyBoard[row][col] == 1) && (liveNeighbors < 2 || liveNeighbors > 3)) {
                    board[row][col] = 0;
                }
                // 规则 4
                if (copyBoard[row][col] == 0 && liveNeighbors == 3) {
                    board[row][col] = 1;
                }                
            }
        }
    }
    
    void test() {
        
    }
};


#endif /* Solution289_hpp */
