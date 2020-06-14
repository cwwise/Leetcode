//
//  Solution460.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/5/31.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution460_hpp
#define Solution460_hpp

#include <stdio.h>

// 缓存的节点信息
struct Node {
    int cnt;
    int time;
    int key, value;
    Node(int _cnt, int _time, int _key, int _value):cnt(_cnt), time(_time), key(_key), value(_value){}

    bool operator< (Node node) const {
        // 如果次数相同 比较时间
        return cnt == node.cnt ? time < node.time : cnt < node.cnt;
    }
};

class LFUCache {
    int capacity, time;
    unordered_map<int, Node> key_table;
    set<Node> set;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        time = 0;
        key_table.clear();
        set.clear();
    }
    
    int get(int key) {
        // 先判断
        auto it = key_table.find(key);
        // 如果没有找到
        if (it == key_table.end()) return -1;
        
        // 如果存在
        Node node = it->second;
        set.erase(node);
        
        // 更新节点
        node.time = ++time;
        node.cnt ++;
        set.insert(node);
        it->second = node;
        
        return node.value;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        
        auto it = key_table.find(key);
        if (it == key_table.end()) {
            // 先移除
            if (key_table.size() == capacity) {
                key_table.erase(set.begin()->key);
                set.erase(set.begin());
            }
            Node cache = Node(1, ++time, key, value);
            set.insert(cache);
            key_table.insert(make_pair(key, cache));
        } else {
            Node cache = it->second;
            set.erase(cache);
            // 更新节点
            cache.time = ++time;
            cache.cnt ++;
            cache.value = value;
            set.insert(cache);
            it->second = cache;
        }
    }
};

//class LFUCache1 {
//public:
//    LFUCache(int capacity) {
//
//    }
//
//    int get(int key) {
//
//    }
//
//    void put(int key, int value) {
//
//    }
//};

#endif /* Solution460_hpp */
