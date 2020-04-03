//
//  Solution203.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/3/31.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution203_hpp
#define Solution203_hpp

#include <stdio.h>
#include "Leetcode_C.h"

/**
 删除链表中等于给定值 val 的所有节点。

 输入: 1->2->6->3->4->5->6, val = 6
 输出: 1->2->3->4->5

 */
class Solution203 {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *ans = new ListNode(0);
        ans->next = head;
        
        ListNode *pre = ans;
        ListNode *cur = head;
        while (cur != NULL) {
            // 找到节点
            if (cur->val == val) {
                pre->next = cur->next;
            } else {
                pre = cur;
            }
            cur = cur->next;
        }
        return ans->next;
    }
    
    void test() {
        ListNode *p1 = NodeTestHelper::createNode(vector<int>{1, 2, 2, 3});
        NodeTestHelper::printNodeList(removeElements(p1, 2));
    }
};


#endif /* Solution203_hpp */
