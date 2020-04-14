//
//  Solution51.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/13.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution51_hpp
#define Solution51_hpp

#include <stdio.h>

/**
 n 皇后问题研究的是如何将 n 个皇后放置在 n×n 的棋盘上，并且使皇后彼此之间不能相互攻击。
 
 给定一个整数 n，返回所有不同的 n 皇后问题的解决方案。

 每一种解法包含一个明确的 n 皇后问题的棋子放置方案，该方案中 'Q' 和 '.' 分别代表了皇后和空位。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/n-queens
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

class Solution51 {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return res;
    }
        
    void backtrack(vector<string> &borad, int row) {
        if (row == borad.size()) {
            res.push_back(borad);
        }
        
    }
    
    //
    bool isValid(vector<string> &borad, int row, int col) {
        int n = (int)borad.size();
        // 检查列
        for (int i = 0; i < n; i++) {
            if (borad[i][col] == 'Q') {
                return false;
            }
        }
        
        //
        for (int i = row - 1, j = col + 1; i >= 0 && j < n ; i --, j++) {
            if (borad[i][j] == 'Q') {
                return false;
            }
        }
        
        return true;
    }
    
    void test() {
        
    }
};

#endif /* Solution51_hpp */
