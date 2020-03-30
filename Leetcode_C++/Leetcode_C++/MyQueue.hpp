//
//  MyQueue.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/3/29.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef MyQueue_hpp
#define MyQueue_hpp

#include <stdio.h>
#include <stack>

class MyQueue {
public:
    //
    stack<int> left;
    stack<int> right;
    /** Initialize your data structure here. */
    MyQueue() {

    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        right.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        //
        int value = peek();
        left.pop();
        return value;
    }
    
    /** Get the front element. */
    int peek() {
        while (!right.empty()) {
             left.push(right.top());
             right.pop();
        }
        return 1;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return left.empty() & right.empty();
    }
};

#endif /* MyQueue_hpp */
