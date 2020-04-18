//
//  Solution106.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/16.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution106_hpp
#define Solution106_hpp

#include <stdio.h>

/**
 106. 从中序与后序遍历序列构造二叉树
 根据一棵树的中序遍历与后序遍历构造二叉树。
 
 注意:
 你可以假设树中没有重复的元素。
 
 例如，给出
 
 中序遍历 inorder = [9,3,15,20,7]
 后序遍历 postorder = [9,15,7,20,3]
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
class Solution106 {
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int inLen = inorder.size();
        int postLen = postorder.size();
        return build(inorder, 0, inLen-1, postorder, 0, postLen-1);
    }
    
    TreeNode* build(vector<int>& inorder, int inLeft, int inRight,
                    vector<int>& postorder, int postLeft, int postRight) {
        if (inLeft > inRight || postLeft > postRight) {
            return NULL;
        }
        
        // 根节点
        int pivot = postorder[postRight];
        int pivotIndex = inLeft;
        
        // 注意这里如果编写不当，有数组下标越界的风险
        while (inorder[pivotIndex] != pivot) {
            pivotIndex++;
        }
        
        TreeNode *root = new TreeNode(pivot);
        root->left = build(inorder, inLeft, pivotIndex-1,
                           postorder, postLeft, postRight - inRight + pivotIndex - 1);
        
        root->right = build(inorder, pivotIndex+1, inRight,
                            postorder, postRight - inRight + pivotIndex, postRight-1);
               
        return root;
    }
    
    void test() {
        
    }
};

#endif /* Solution106_hpp */
