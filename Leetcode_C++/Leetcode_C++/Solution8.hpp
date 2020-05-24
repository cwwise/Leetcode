//
//  Solution8.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/4/3.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution8_hpp
#define Solution8_hpp

/*
 请你来实现一个 atoi 函数，使其能将字符串转换成整数。
 
 首先，该函数会根据需要丢弃无用的开头空格字符，直到寻找到第一个非空格的字符为止。接下来的转化规则如下：
 
 如果第一个非空字符为正或者负号时，则将该符号与之后面尽可能多的连续数字字符组合起来，形成一个有符号整数。
 假如第一个非空字符是数字，则直接将其与之后连续的数字字符组合起来，形成一个整数。
 该字符串在有效的整数部分之后也可能会存在多余的字符，那么这些字符可以被忽略，它们对函数不应该造成影响。
 注意：假如该字符串中的第一个非空格字符不是一个有效整数字符、字符串为空或字符串仅包含空白字符时，则你的函数不需要进行转换，即无法进行有效转换。
 
 在任何情况下，若函数不能进行有效的转换时，请返回 0 。
 
 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/string-to-integer-atoi
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

#include <stdio.h>

class Solution8 {
public:
    int myAtoi1(string str) {
        long sum = 0;
        int flag = 1;
        // 先跳过空格
        int i = 0;
        while (i < str.length()) {
            if (str[i] == ' ') {
                i++;
            } else {
                if (str[i] == '-') {
                    flag = -1;
                } else if (str[i] == '+') {
                } else if (str[i] < '0' || str[i] > '9') {
                    return 0;
                }
                i++;
                break;
            }
        }
        
        for (; i < str.length(); i ++) {
            int c = str[i] - '0';
            sum = sum * 10 + c;
            if (sum > (INT_MAX - c) / 10) {
                return (flag == 1) ? INT_MAX : INT_MIN;
            }
        }
        return int(sum*flag);
    }
    
    int myAtoi(string str) {
        int length = str.length();
        if (length == 0) return 0;
        
        int res = 0;
        // 符号位
        int flag = true;
        // 到第一个非空格
        int i = 0;
        while (i < length && str[i] == ' ') {
            i ++;
        }
        
        // 判断第一位是否为符号位
        if (str[i] == '+') {
            i ++;
        } else if (str[i] == '-') {
            flag = false;
            i ++;
        }
        // 在范围并且指为数字
        while (i < length) {
            char c = str[i];
            if (c >= '0' && c <= '9') {
                int a = c - '0';
                if (res > (INT_MAX - a) / 10) {
                    return flag ? INT_MAX : INT_MIN;
                } else {
                    res = res*10 + a;
                }
            } else {
                break;
            }
            i ++;
        }
        return flag ? res : -res;
    }
    
    // "-91283472332"
    void test() {
        cout << INT_MAX << endl;
        
        cout << myAtoi("   -11aa") << endl;
        cout << myAtoi("a") << endl;
        cout << myAtoi("---") << endl;
        cout << myAtoi("-1111") << endl;
        cout << myAtoi("-91283472332") << endl;
        
    }
};



#endif /* Solution8_hpp */
