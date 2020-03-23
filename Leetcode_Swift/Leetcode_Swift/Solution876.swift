//
//  Solution876.swift
//  Leetcode_Swift
//
//  Created by chenwei on 2020/3/23.
//  Copyright © 2020 chenwei. All rights reserved.
//

import Foundation

class Solution876 {
    func middleNode(_ head: ListNode?) -> ListNode? {
        var slow = head
        var fast = head
        while fast != nil && fast?.next != nil {
            fast = fast?.next?.next
            slow = slow?.next
        }
        return slow
    }
}
