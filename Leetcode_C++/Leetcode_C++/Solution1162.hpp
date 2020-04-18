//
//  Solution1162.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/15.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution1162_hpp
#define Solution1162_hpp

/**
 
 你现在手里有一份大小为 N x N 的「地图」（网格） grid，上面的每个「区域」（单元格）都用 0 和 1 标记好了。其中 0 代表海洋，1 代表陆地，请你找出一个海洋区域，这个海洋区域到离它最近的陆地区域的距离是最大的。
 
 我们这里说的距离是「曼哈顿距离」（ Manhattan Distance）：(x0, y0) 和 (x1, y1) 这两个区域之间的距离是 |x0 - x1| + |y0 - y1| 。
 
 如果我们的地图上只有陆地或者海洋，请返回 -1。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/as-far-from-land-as-possible
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include <stdio.h>
#include "Leetcode_C.h"

class Solution1162 {
public:
    

    
    
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        
        queue<pair<int, int>> queue;
        vector<vector<int>> seen(n, vector<int>(n));
        // 将所有的陆地格子加入队列
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    queue.push(pair<int, int>(i, j));
                    seen[i][j] = 1;
                }
            }
        }
        // 如果我们的地图上只有陆地或者海洋，请返回 -1。
        if (queue.empty() || queue.size() == n * n) {
            return -1;
        }
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
        
        int dis = -1;
        while (!queue.empty()) {
            dis += 1;
            int size = queue.size();
            for (int i = 0; i < size; i ++) {
                auto [x, y] = queue.front();
                queue.pop();
                
                for (int i = 0; i < 4; i ++) {
                    int to_x = dirs[i][0] + x;
                    int to_y = dirs[i][1] + y;
                    if (to_x >= 0 && to_x < n && to_y >= 0 && to_y < n && seen[to_x][to_y] != 1) {
                        seen[to_x][to_y] = 1;
                        queue.push(pair<int, int>(to_x, to_y));
                    }
                }
            }
        }
        return dis;
    }
};

#endif /* Solution1162_hpp */
