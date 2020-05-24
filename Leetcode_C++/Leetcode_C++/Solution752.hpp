//
//  Solution752.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/5/23.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution752_hpp
#define Solution752_hpp

#include <stdio.h>

class Solution752 {
public:
    
    string plusOne(string str, int i) {
        if (str[i] == '9') {
            str[i] = '0';
        } else {
            str[i] += 1;
        }
        return str;
    }
    
    string minusOne(string str, int i) {
        if (str[i] == '0') {
            str[i] = '9';
        } else {
            str[i] -= 1;
        }
        return str;
    }
    
    int openLock(vector<string>& deadends, string target) {
        
        queue<string> queue;
        queue.push("0000");
        set<string> visit;
        visit.insert("0000");

        int step = 1;
        while (!queue.empty()) {
            int n = queue.size();
            for (int i = 0; i < n; i ++) {
                string item = queue.front();
                queue.pop();
                
                // 判断
                if (find(deadends.begin(), deadends.end(), item) != deadends.end()) {
                    continue;
                }
                
                if (item == target) {
                    return step;
                }
                
                for (int j = 0; j < 4; j ++) {
                    string up = plusOne(item, j);
                    string down = minusOne(item, j);
                    if (visit.count(up) == 0) {
                        queue.push(up);
                        visit.insert(up);
                    }
                    if (visit.count(down) == 0) {
                        queue.push(down);
                        visit.insert(down);
                    }
                }
            }
            step ++;
        }
        return step;
    }
    
    void test() {
        
    }
};

#endif /* Solution752_hpp */
