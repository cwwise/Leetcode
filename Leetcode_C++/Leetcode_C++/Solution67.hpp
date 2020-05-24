//
//  Solution67.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/5/23.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution67_hpp
#define Solution67_hpp

#include <stdio.h>

class Solution67 {
public:
    string addBinary(string a, string b) {
        int a_n = a.length();
        int b_n = b.length();
        
        int count = max(a_n, b_n)+1;
        vector<int> res(count, 0);
        // 补零
        int i = count - a_n;
        while (i > 0) {
            a = "0" + a;
            i --;
        }
        
        i = count - b_n;
        while (i > 0) {
            b = "0" + b;
            i --;
        }
        
        for (int j = count - 1; j >= 1; j --) {
            int p = a[j] + b[j] - 2 * '0' + res[j];
            res[j] = p % 2;
            res[j-1] = p / 2;
        }
        
        // 去掉头部的零
        i = 0;
        while (i < res.size() && res[i] == 0) {
            i ++;
        }
        string ans;
        while (i < res.size()) {
            ans += res[i] + '0';
            i ++;
        }
        return ans.length() == 0 ? "" : ans;
    }
    
    void test() {
        addBinary("0", "0");
    }
};

#endif /* Solution67_hpp */
