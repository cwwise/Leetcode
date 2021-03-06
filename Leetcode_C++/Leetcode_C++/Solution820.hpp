//
//  Solution820.hpp
//  Leetcode_C++
//
//  Created by chenwei on 2020/5/31.
//  Copyright © 2020 chenwei. All rights reserved.
//

#ifndef Solution820_hpp
#define Solution820_hpp

#include <stdio.h>

/**
 给定一个单词列表，我们将这个列表编码成一个索引字符串 S 与一个索引列表 A。

 例如，如果这个列表是 ["time", "me", "bell"]，我们就可以将其表示为 S = "time#bell#" 和 indexes = [0, 2, 5]。
 
 对于每一个索引，我们可以通过从字符串 S 中索引的位置开始读取字符串，直到 "#" 结束，来恢复我们之前的单词列表。

 那么成功对给定单词列表进行编码的最小字符串长度是多少呢？

 来源：力扣（LeetCode）
 链接：https://leetcode-cn.com/problems/short-encoding-of-words
 著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */

bool myfunction2 (string str1, string str2) { return str1.length() < str2.length(); }

struct cmp1 {
    bool operator()(const string& __x, const string& __y) const {return __x < __y;}
    
//    bool operator() (string str1, string str2) {
//        return str1.length() < str2.length();
//    }
};

class Solution820 {
public:
    int minimumLengthEncoding(vector<string>& words) {
        sort(words.begin(), words.end(), myfunction2);
        return 0;
    }
};

#endif /* Solution820_hpp */
