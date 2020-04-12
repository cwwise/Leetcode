//
//  Solution120.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/11.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution120_hpp
#define Solution120_hpp

#include <stdio.h>
#include "Leetcode_C.h"

/*
 给定一个三角形，找出自顶向下的最小路径和。每一步只能移动到下一行中相邻的结点上。

 例如，给定三角形：

 [
      [2],
     [3,4],
    [6,5,7],
   [4,1,8,3]
 ]
 自顶向下的最小路径和为 11（即，2 + 3 + 5 + 1 = 11）。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/triangle
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

class Solution120 {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> mini = triangle[triangle.size() - 1];
        for (size_t i = triangle.size() - 2; i >= 0; i --) {
            for (int j = 0; j < triangle[i].size(); j ++) {
                mini[j] = triangle[i][j] + min(mini[j], mini[j+1]);
            }
        }
        return mini[0];
    }
    
    void test() {

    }
};

#endif /* Solution120_hpp */
