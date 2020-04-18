//
//  Solution117.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/16.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution117_hpp
#define Solution117_hpp

#include <stdio.h>

class Solution117 {
    
    class Node {
    public:
        int val;
        Node* left;
        Node* right;
        Node* next;

        Node() : val(0), left(NULL), right(NULL), next(NULL) {}

        Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

        Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
    };
    
public:
    Node* connect(Node* root) {
        
        // 队列
        if (root == nullptr) {
            return root;
        }
        
        queue<Node *> queue;
        queue.push(root);
        
        while (!queue.empty()) {
            int size = queue.size();
            for (int i = 0; i < size; i ++) {
                Node *node = queue.front();
                queue.pop();
                
                if (i < size - 1) {
                    node->next = queue.front();
                }
                
                if (node->left) {
                    queue.push(node->left);
                }
                
                if (node->right) {
                    queue.push(node->right);
                }
            }
        }
        
        return root;
    }
    
    void test() {
        
    }
};

#endif /* Solution117_hpp */
