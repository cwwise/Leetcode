//
//  Solution542.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/15.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution542_hpp
#define Solution542_hpp

#include <stdio.h>

/**
 
 给定一个由 0 和 1 组成的矩阵，找出每个元素到最近的 0 的距离。

 两个相邻元素间的距离为 1 。

 示例 1:
 输入:

 0 0 0
 0 1 0
 0 0 0
 输出:

 0 0 0
 0 1 0
 0 0 0

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/01-matrix
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

class Solution542 {
public:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        //
        queue<pair<int, int>> q;
        vector<vector<int>> seen(m, vector<int>(n));
        vector<vector<int>> dist(m, vector<int>(n));
        
        // 将所有的 0 添加进初始队列中
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == 0) {
                    q.push(pair<int, int>(i, j));
                    seen[i][j] = 1;
                }
            }
        }
        
        // 广度优先搜索
        while (!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int d = 0; d < 4; ++d) {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && !seen[ni][nj]) {
                    dist[ni][nj] = dist[i][j] + 1;
                    q.push(pair<int, int>(ni, nj));
                    seen[ni][nj] = 1;
                }
            }
        }
        return dist;
    }
    
    void test() {
        
    }
};

#endif /* Solution542_hpp */
