//
//  Solution2.swift
//  Leetcode_Swift
//
//  Created by chenwei on 2020/3/23.
//  Copyright © 2020 chenwei. All rights reserved.
//

import Foundation

/*
 给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。
 如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。
 您可以假设除了数字 0 之外，这两个数都不会以 0 开头。

 输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
 输出：7 -> 0 -> 8
 原因：342 + 465 = 807
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/add-two-numbers
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

// 243
// 564
// 807
class Solution2 {
    func addTwoNumbers(_ l1: ListNode?, _ l2: ListNode?) -> ListNode? {
        // 头节点
        let pre = ListNode(0)
        var p = l1
        var q = l2
        var cur = pre
        
        var flag = 0
        while p != nil || q != nil {
            
            let a = p?.val ?? 0
            let b = q?.val ?? 0
            
            let sum = a + b + flag
            flag = sum/10
            cur.next = ListNode(sum % 10)
            cur = cur.next!
            
            if p != nil {
                p = p?.next
            }
            
            if q != nil {
                q = q?.next
            }
        }
        
        if flag > 0 {
            cur.next = ListNode(flag)
        }
        
        return pre.next;
    }
    
    func test() {
        let head1 = createNode([1, 8])
        let head2 = createNode([0])
        printNode(head1)
        printNode(head2)

        printNode(addTwoNumbers(head1, head2))
    }
}
