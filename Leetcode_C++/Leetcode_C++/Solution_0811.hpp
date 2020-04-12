//
//  Solution_0811.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/12.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution_0811_hpp
#define Solution_0811_hpp

#include <stdio.h>

/**
 
 硬币。给定数量不限的硬币，币值为25分、10分、5分和1分，编写代码计算n分有几种表示法。(结果可能会很大，你需要将结果模上1000000007)

 示例1:

  输入: n = 5
  输出：2
  解释: 有两种方式可以凑成总金额:
 5=5
 5=1+1+1+1+1

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/coin-lcci
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

class Solution_0811 {
public:
    int waysToChange(int n) {
        vector<int> coins{1, 5, 10, 25};
        //
        vector<vector<int>> dp(4, vector<int>(n+1, 0));
        
        for (int i = 0; i <= n; i ++) {
            dp[0][i] = 1;
        }

        for (int i = 0; i < 4; i ++) {
            dp[i][0] = 1;
        }
        
        for (int i = 1; i < 4; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (j >= coins[i]) {
                    dp[i][j]=(dp[i-1][j]+dp[i][j-coins[i]])%1000000007;
                } else {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        
        return dp[3][n];
    }
    
    int waysToChange1(int n) {
        vector<int> coins{1, 5, 10, 25};
        //
        vector<int> dp(n+1, n+1);
        dp[0] = 0;
        for (int i = 1; i < dp.size(); i ++) {
            for (int coin: coins) {
                if (i - coin < 0) continue;
                if (i - coin == 0) {
                    cout << "1->" << i << endl;
                }
                dp[i] = min(dp[i], dp[i-coin] + 1);
            }
        }
        
        return dp[n];
    }
    
    void test() {
        cout << waysToChange(10) << endl;
    }
};

#endif /* Solution_0811_hpp */
