//
//  NodeHelper.swift
//  Leetcode_Swift
//
//  Created by chenwei on 2020/3/23.
//  Copyright © 2020 chenwei. All rights reserved.
//

import Foundation

// Definition for singly-linked list.
public class ListNode {
    public var val: Int
    public var next: ListNode?
    public init(_ val: Int) {
        self.val = val
        self.next = nil
    }
}

func createNode(_ list: [Int]) -> ListNode? {
    var head: ListNode?
    var cur: ListNode?
    for i in list {
        let p = ListNode(i)
        if head == nil {
            head = p
        } else {
            cur?.next = p
        }
        cur = p
    }
    return head
}

func printNode(_ head: ListNode?) {
    var p = head
    var result = [String]()
    while p != nil {
        result.append("\(p!.val)")
        p = p!.next
    }
    print(result.joined(separator: " -> "))
}
