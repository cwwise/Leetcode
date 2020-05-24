//
//  NodeHelper.swift
//  Leetcode_Swift
//
//  Created by chenwei on 2020/3/23.
//  Copyright © 2020 chenwei. All rights reserved.
//

import Foundation

// Definition for a binary tree node.
public class TreeNode {
    public var val: Int
    public var left: TreeNode?
    public var right: TreeNode?
    public init(_ val: Int) {
        self.val = val
        self.left = nil
        self.right = nil
    }
}

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
    let head: ListNode = ListNode(0)
    var cur: ListNode = head
    for i in list {
        cur.next = ListNode(i)
        cur = cur.next!
    }
    return head.next
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
