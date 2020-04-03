//
//  Solution328.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/3/31.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution328_hpp
#define Solution328_hpp

#include <stdio.h>
#include "Leetcode_C.h"

/**
 给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。

 请尝试使用原地算法完成。你的算法的空间复杂度应为 O(1)，时间复杂度应为 O(nodes)，nodes 为节点总数。
 
 输入: 1->2->3->4->5->NULL
 输出: 1->3->5->2->4->NULL
  
 */
class Solution328 {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) return NULL;
        // 奇数指针
        ListNode *odd = head, *even = head->next, *evenHead = even;
        while (even != NULL && even->next != NULL) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
    
    void test() {
        
    }
};

#endif /* Solution328_hpp */
