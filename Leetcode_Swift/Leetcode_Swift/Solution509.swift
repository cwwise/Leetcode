//
//  Solution509.swift
//  Leetcode_Swift
//
//  Created by chenwei on 2020/3/29.
//  Copyright © 2020 chenwei. All rights reserved.
//

import Foundation

class Solution509 {
    func fib(_ N: Int) -> Int {
        
        if N <= 1 {
            return N
        }
        
        var pre = 0
        var cur = 1
        for _ in 2...N {
            let sum = cur + pre
            pre = cur
            cur = sum
        }
        return cur
    }
    
    func fib1(_ N: Int) -> Int {
        if N <= 1 {
            return N
        }
        
        var dp = Array(repeating: 0, count: N+1)
        dp[0] = 0
        dp[1] = 1
        for i in 2...N {
            dp[i] = dp[i-1] + dp[i-2]
        }
        return dp[N]
    }
    
    // 数学表达式
    func fib2(_ N: Int) -> Int {
        let powN = Double(N)
        let value = (pow((1 + sqrt(5))/2, powN) - pow((1 - sqrt(5))/2, powN))/sqrt(5)
        return Int(value)
    }
    
    func test() {
        for i in 1..<10 {
            print(fib(i))
        }
    }
}
