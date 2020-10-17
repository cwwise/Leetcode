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
    // 列
    unordered_set<int> column;
    // 副对角线
    unordered_set<int> sub;
    // 主对角线
    unordered_set<int> main;
    // 结果
    vector<vector<string>> result;
    
    vector<vector<string>> solveNQueens(int n) {
        if (n == 0) {
            return result;
        }
        vector<int> path;
        dfs(0, n, path);
        return result;
    }

    void dfs(int row, int n, vector<int> & path) {
        if (row == n) {
            // 转化
            vector<string> item = convert2board(n, path);
            result.push_back(item);
            return;
        }

        // 从每列放
        for (int i = 0; i < n; i ++) {
            // 主对角线 row+column 为固定值
            // 副对角线 row-column 为固定值
            if (column.count(i) || main.count(row+i) || sub.count(row-i)) {
                continue;
            }

            path.push_back(i);
            column.insert(i);
            main.insert(row+i);
            sub.insert(row-i);

            dfs(row+1, n, path);

            column.erase(i);
            main.erase(row+i);
            sub.erase(row-i);
            path.pop_back();
        }

    }

    vector<string> convert2board(int n, vector<int> path) {
        vector<string> res;
        for (int i = 0; i < n; i ++) {
            string str(n, '.');
            str[path[i]] = 'Q';
            res.push_back(str);
        }
        return res;
    }
    
    void test() {
        vector<vector<string>> result = solveNQueens(4);
        for (vector<string> item: result) {
            for (string str: item) {
                cout << str << endl;
            }
            cout << endl;
        }
    }
};

#endif /* Solution51_hpp */
