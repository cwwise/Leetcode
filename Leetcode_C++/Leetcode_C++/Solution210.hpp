//
//  Solution210.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/5/17.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution210_hpp
#define Solution210_hpp

#include <stdio.h>

/**
 现在你总共有 n 门课需要选，记为 0 到 n-1。

 在选修某些课程之前需要一些先修课程。 例如，想要学习课程 0 ，你需要先完成课程 1 ，我们用一个匹配来表示他们: [0,1]

 给定课程总量以及它们的先决条件，返回你为了学完所有课程所安排的学习顺序。

 可能会有多个正确的顺序，你只要返回一种就可以了。如果不可能完成所有课程，返回一个空数组。

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/course-schedule-ii
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
class Solution210 {
private:
    // 存储有向图
    vector<vector<int>> edges;
    // 标记每个节点的状态：0=未搜索，1=搜索中，2=已完成
    vector<int> visited;
    // 用数组来模拟栈，下标 0 为栈底，n-1 为栈顶
    vector<int> result;
    // 判断有向图中是否有环
    bool invalid;
public:
    void dfs(int u) {
        visited[u] = 1;
        // 搜索其相邻节点
        // 只要发现有环，立刻停止搜索
        for (int v: edges[u]) {
            if (visited[v] == 0) {
                dfs(v);
                if (invalid) {
                    return;
                }
            }
            // 如果「搜索中」说明找到了环
            else if (visited[v] == 1) {
                invalid = true;
            }
        }
        visited[u] = 2;
        result.push_back(u);
    }
    
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        edges.resize(numCourses);
        visited.resize(numCourses);
        

        for (auto info: prerequisites) {
            edges[info[1]].push_back(info[0]);
        }
        
        // 每次挑选一个「未搜索」的节点，开始进行深度优先搜索
        for (int i = 0; i < numCourses && !invalid; ++i) {
            if (!visited[i]) {
                dfs(i);
            }
        }
        if (invalid) {
            return {};
        }
        
        // 如果没有环，那么就有拓扑排序
        // 注意下标 0 为栈底，因此需要将数组反序输出
        reverse(result.begin(), result.end());
        return result;
    }
};

#endif /* Solution210_hpp */
