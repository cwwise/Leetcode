//
//  Solution72.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/12.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution72_hpp
#define Solution72_hpp

#include <stdio.h>

/**
 给你两个单词 word1 和 word2，请你计算出将 word1 转换成 word2 所使用的最少操作数 。

 你可以对一个单词进行如下三种操作：

 插入一个字符
 删除一个字符
 替换一个字符
  

 示例 1：

 输入：word1 = "horse", word2 = "ros"
 输出：3
 解释：
 horse -> rorse (将 'h' 替换为 'r')
 rorse -> rose (删除 'r')
 rose -> ros (删除 'e')

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/edit-distance
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

class Solution72 {
public:
    int minDistance(string word1, string word2) {
        size_t m = word1.length(), n = word2.length();
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));
        
        for (int i = 0; i <= m; i ++) {
            dp[i][0] = i;
        }
        
        for (int j = 0; j <= n; j ++) {
            dp[0][j] = j;
        }
        
        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (word1[i-1] == word2[j-1]) {
                    dp[i][j] = dp[i-1][j-1];
                } else {
                    dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                }
            }
        }
        return dp[m][n];
    }
    
    void test() {
        cout << minDistance("abc", "abde") << endl;
    }
};

#endif /* Solution72_hpp */
