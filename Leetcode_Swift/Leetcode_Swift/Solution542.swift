//
//  Solution542.swift
//  Leetcode_Swift
//
//  Created by chenwei on 2020/4/15.
//  Copyright © 2020 chenwei. All rights reserved.
//

import Foundation

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
    func updateMatrix(_ matrix: [[Int]]) -> [[Int]] {
        
        let m = matrix.count, n = matrix[0].count;
        var dis = [[Int]](repeating: [Int](repeating: 0, count: n), count: m)
        var seen = [[Bool]](repeating: [Bool](repeating: false, count: n), count: m)
        
        var queue = [(Int, Int)]();
        for i in 0..<m {
            for j in 0..<n {
                if matrix[i][j] == 0 {
                    queue.append((i, j))
                    seen[i][j] = true
                }
            }
        }
        
        let dis_x = [0, 1, 0, -1]
        let dis_y = [-1, 0, 1, 0]
        
        // 不为空
        while !queue.isEmpty {
            let item = queue.removeFirst()
            for i in 0..<4 {
                let to_x = item.0 + dis_x[i]
                let to_y = item.1 + dis_y[i]
                // 判断边界
                if to_x >= 0 && to_x < m && to_y >= 0 && to_y < n && !seen[to_x][to_y] {
                    seen[to_x][to_y] = true
                    queue.append((to_x, to_y))
                    dis[to_x][to_y] = dis[item.0][item.1] + 1
                }
            }
        }
        
        return dis
    }
    
    func updateMatrix1(_ matrix: [[Int]]) -> [[Int]] {
        let m = matrix.count, n = matrix[0].count;
        var dist = [[Int]](repeating: [Int](repeating: LONG_MAX, count: n), count: m)
        
        for i in 0..<m {
            for j in 0..<n {
                if matrix[i][j] == 0 {
                    dist[i][j] = 0
                }
            }
        }
        
        for i in 0..<m {
            for j in 0..<n {
                if (i - 1 >= 0) {
                    dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                }
                if (j - 1 >= 0) {
                    dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }
        
        return dist
    }
    
}
