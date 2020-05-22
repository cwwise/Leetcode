//
//  Solution148.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/5/20.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution148_hpp
#define Solution148_hpp

#include <stdio.h>
#include "Leetcode_C.h"

/**
 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

 示例 1:

 输入: 4->2->1->3
 输出: 1->2->3->4
 https://leetcode-cn.com/problems/sort-list/
 */
class Solution148 {
public:
    ListNode* sortList(ListNode* head) {
        // 条件判断
        if (!head || !head->next) return head;
        
        
        ListNode *slow = head;
        ListNode *fast = head->next;
        
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *temp = slow->next;
        slow->next = nullptr;
        
        // 递归排序
        ListNode *left = sortList(head);
        ListNode *right = sortList(temp);

        // 归并
        ListNode *res = new ListNode(0);
        ListNode *h = res;
        
        while (left != nullptr && right != nullptr) {
            if (left->val < right->val) {
                h->next = left;
                left = left->next;
            } else {
                h->next = right;
                right = right->next;
            }
            h = h->next;
        }
        h->next = left != nullptr ? left : right;
        return res->next;
    }
    
    
};

#endif /* Solution148_hpp */
