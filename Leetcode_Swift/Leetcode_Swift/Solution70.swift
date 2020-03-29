//
//  Solution70.swift
//  Leetcode_Swift
//
//  Created by chenwei on 2020/3/29.
//  Copyright © 2020 chenwei. All rights reserved.
//

import Foundation

/*
 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

 注意：给定 n 是一个正整数。

 示例 1：

 输入： 2
 输出： 2
 解释： 有两种方法可以爬到楼顶。
 1.  1 阶 + 1 阶
 2.  2 阶

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/climbing-stairs
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

class Solution70 {
    func climbStairs(_ n: Int) -> Int {
        // a[i] =
        // a[1] = 1
        // a[2] = 2
        // a[3] = a[3-1] + a[3-2]
        
        if n <= 2 {
            return n
        }
        // 1 2 3 5
        var pre = 1
        var cur = 2
        for _ in 3...n {
            let sum = pre + cur
            pre = cur
            cur = sum
        }
        return cur
    }
    
    func test() {
        print(climbStairs(4))
        print(climbStairs(5))
    }
}
