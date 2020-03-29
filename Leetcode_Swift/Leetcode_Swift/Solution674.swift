//
//  Solution674.swift
//  Leetcode_Swift
//
//  Created by chenwei on 2020/3/29.
//  Copyright © 2020 chenwei. All rights reserved.
//

import Foundation

class Solution674 {
    func findLengthOfLCIS(_ nums: [Int]) -> Int {
        if nums.count == 0 {
            return 0
        }
        
        var ans = 1
        var count = 1
        for i in 1..<nums.count {
            
            if nums[i] > nums[i-1] {
                count += 1
            } else {
                count = 1
            }
            ans = max(ans, count)
        }
        return ans
    }
    
    func test() {
        print(findLengthOfLCIS([1,3,5,4,7]))
    }
}
