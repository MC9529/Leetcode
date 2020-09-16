#include <iostream>
#include <vector>
#include "BiTree.h"
#include <unordered_map>
#include <set>
#include <limits.h>

// offer 03 数组中重复的数字
class offer03 {
public:
    void findRepeatNum(vector<int> &nums);

};

// offer 53_1 统计一个数字在数组中出现的次数
class offer53_1 {
public:
     // unorder_map
    void search(vector<int> &nums, int target);
    // 二分查找
    void search2(vector<int> &nums, int target);

};

// offer05 替换空格
class offer05 {
public:
     // 需要额外的空间
    void replaceSpace(string s);
    // 不需要额外的空间
    void replaceSpace2(string s);

};