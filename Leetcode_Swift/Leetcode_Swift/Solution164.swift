//
//  Solution164.swift
//  Leetcode_Swift
//
//  Created by chenwei on 2020/5/18.
//  Copyright © 2020 chenwei. All rights reserved.
//

import Foundation

class DoubleLinkList<K, V> where K : Equatable {
    
    class Node: Equatable {
        static func == (lhs: DoubleLinkList<K, V>.Node, rhs: DoubleLinkList<K, V>.Node) -> Bool {
            return lhs.key == rhs.key
        }
        
        weak var pre: Node?
        var next: Node?
        var key: K
        var value: V
        init(key: K, value: V) {
            self.value = value
            self.key = key
        }
        
    }
    
    var head: Node?
    var tail: Node?
    var size: Int = 0
    // 在链表头部添加节点 x，时间 O(1)
    public func addFirst(node: Node) {
        // 如果没有头节点
        guard let head = self.head else {
            self.head = node
            return
        }
        node.next = head
        head.pre = node
        self.head = node
    }
    
    public func remove(node: Node) {
        
        let prev = node.pre
        let next = node.next
        
        if let prev = prev {
          prev.next = next
        } else {
          head = next
        }

        // 如果下一个节点
        if let nextNode = next {
            nextNode.pre = prev
        } else {
            tail = prev
        }
        
        node.pre = nil
        node.next = nil
    }
    
    public func removeLast() {
        if let node = tail {
            remove(node: node)
        }
    }
    
    public func printList() {
        var res = [K]()
        var node = head
        while let next = node {
            res.append(next.key)
            node = node?.next
        }
        print(res.map{ return "\($0)" }.joined(separator: "->"))
    }
}

class LRUCache {
    
    var cache: DoubleLinkList<Int, Int>    
    init(_ capacity: Int) {
        cache = DoubleLinkList()
    }
    
    func get(_ key: Int) -> Int {
        return 0
    }
    
    func put(_ key: Int, _ value: Int) {
        
    }
}
