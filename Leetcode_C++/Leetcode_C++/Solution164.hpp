//
//  Solution164.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/5/18.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution164_hpp
#define Solution164_hpp

#include <stdio.h>

struct DLinkedNode {
    int key, value;
    DLinkedNode* prev;
    DLinkedNode* next;
    DLinkedNode(): key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value): key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache {
    int capacity;
    int size;
    unordered_map<int, DLinkedNode *> map;
    // 头节点和尾节点
    DLinkedNode *head;
    DLinkedNode *tail;
public:
    LRUCache(int _capacity) {
        capacity = _capacity;
        size = 0;
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if (!map.count(key)) {
            return -1;
        }
        DLinkedNode *node = map[key];
        moveToHead(node);
        return node->value;
    }
    
    void put(int key, int value) {
        
        if (!map.count(key)) {
            // 如果 key 不存在，创建一个新的节点
            DLinkedNode* node = new DLinkedNode(key, value);
            map[key] = node;
            insertToHead(node);
            size ++;

            // 先判断是否超过范围
            if (size > capacity) {
                // 移除最后的
                DLinkedNode *node = removeTail();
                map.erase(node->key);
                size --;
            }
        } else {
            DLinkedNode *node = map[key];
            node->value = value;
            moveToHead(node);
        }
    }

    // 移除
    void removeNode(DLinkedNode * node) {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // 移到头部
    void moveToHead(DLinkedNode * node) {
        removeNode(node);
        insertToHead(node);
    }
    
    DLinkedNode* removeTail() {
        DLinkedNode *node = tail->prev;
        tail->prev = node->prev;
        node->prev->next = tail;
        return node;
    }
    
    // 添加头
    void insertToHead(DLinkedNode *node) {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

};

#endif /* Solution164_hpp */
