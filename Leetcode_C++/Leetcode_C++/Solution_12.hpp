//
//  Solution_12.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/5/22.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution_12_hpp
#define Solution_12_hpp

/**
 
 请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有字符的路径。路径可以从矩阵中的任意一格开始，每一步可以在矩阵中向左、右、上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入该格子。例如，在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字母用加粗标出）。

 [["a","b","c","e"],
 ["s","f","c","s"],
 ["a","d","e","e"]]

 但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/ju-zhen-zhong-de-lu-jing-lcof
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <stdio.h>

class Solution_12 {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.size() == 0 || board[0].size() == 0) return false;

        int m = board.size();
        int n = board[0].size();
        
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (!visit[i][j] && word[0] == board[i][j]) {
                    if (dfs(board, word, i, j, 0, visit)) return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>> board, string word, int i, int j, int k, vector<vector<bool>> &visit) {
        int m = board.size();
        int n = board[0].size();
        // 判断
        if (i < 0 || i >= m || j < 0 || j >= n || visit[i][j] || word[k] != board[i][j]) return false;
        if (k == word.length() - 1) return true;

        visit[i][j] = true;
        bool result = dfs(board, word, i + 1, j, k + 1, visit) || dfs(board, word, i - 1, j, k + 1, visit) ||
                      dfs(board, word, i, j + 1, k + 1, visit) || dfs(board, word, i, j - 1, k + 1, visit);
        visit[i][j] = false;
        return result;
    }
    
    void test() {
        
    }
};

#endif /* Solution_12_hpp */
