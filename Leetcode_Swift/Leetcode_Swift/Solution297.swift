//
//  Solution297.swift
//  Leetcode_Swift
//
//  Created by chenwei on 2020/5/22.
//  Copyright © 2020 chenwei. All rights reserved.
//

import Foundation

class Codec {
    func reserialize(_ root: TreeNode?, str: String) -> String {
        var value = str
        guard let node = root else {
            value += "null,"
            return value
        }
        value += "\(node.val)" + ","
        value = reserialize(node.left, str: value)
        value = reserialize(node.right, str: value)
        return value
    }
    
    func serialize(_ root: TreeNode?) -> String {
        return reserialize(root, str: "");
    }
    
    func rdeserialize(_ list: inout [String]) -> TreeNode? {
        if list.first == "null" {
            list.remove(at: 0)
            return nil
        }
        let item = list.first ?? ""
        let root = TreeNode(Int(item) ?? 0);
        list.remove(at: 0)
        root.left = rdeserialize(&list);
        root.right = rdeserialize(&list);
        return root
    }
    
    func deserialize(_ data: String) -> TreeNode? {
        var list = data.components(separatedBy: ",")
        return rdeserialize(&list)
    }
    
    
}
