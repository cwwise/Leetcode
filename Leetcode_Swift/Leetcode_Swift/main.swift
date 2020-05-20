//
//  main.swift
//  Leetcode_Swift
//
//  Created by chenwei on 2020/3/23.
//  Copyright © 2020 chenwei. All rights reserved.
//

import Foundation

Solution2().test()
Solution121().test()


// Definition for a binary tree node.
 public class TreeNode {
     public var val: Int
     public var left: TreeNode?
     public var right: TreeNode?
     public init(_ val: Int) {
         self.val = val
         self.left = nil
         self.right = nil
     }
 }

class Solution {
    func hasPathSum(_ root: TreeNode?, _ sum: Int) -> Bool {
        if (root == nil) {
            return false;
        }
        let temp = sum - root!.val;
        if (root?.left == nil && root?.right == nil) {
            return (temp == 0);
        }
        return hasPathSum(root?.left, temp) || hasPathSum(root?.right, temp);
    }
}
