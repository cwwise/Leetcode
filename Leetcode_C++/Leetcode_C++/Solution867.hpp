//
//  Solution867.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/3/23.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution867_hpp
#define Solution867_hpp

#include <stdio.h>
#include "Leetcode_C.h"

/*
 给定一个带有头结点 head 的非空单链表，返回链表的中间结点。
 如果有两个中间结点，则返回第二个中间结点。
 */
class Solution867 {
public:
    // 普通方法，先计算出链表的长度，然后再次找到n/2处的节点
    ListNode* middleNode(ListNode* head) {
        int n = 0;
        ListNode *cur = head;
        while (cur != NULL) {
            n ++;
            cur = cur->next;
        }
        
        int k = 0;
        cur = head;
        while (k < n /2) {
            k ++;
            cur = cur->next;
        }
        return cur;
    }
    
    //
    ListNode* middleNode_1(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    void test() {
        ListNode *head = NodeTestHelper::createNode(vector<int>{1, 2, 3, 4, 5, 6});
        NodeTestHelper::printNodeList("链表1", head);
        cout << middleNode_1(head)->val << endl;
        
        head = NodeTestHelper::createNode(vector<int>{1, 2, 3, 4, 5});
        NodeTestHelper::printNodeList("链表2", head);
        cout << middleNode_1(head)->val << endl;
    }
    
};


#endif /* Solution867_hpp */
