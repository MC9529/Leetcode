#pragma once
#include <iostream>
#include <vector>
#include "BiTree.h"
#include <unordered_map>
#include <set>
#include <limits.h>
#include "LinkList.h"



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

// offer06 从尾到头打印链表

class offer06 {
public:
    void reverseprint(Node *head);
};


// offer 24 反转链表
class offer24 {
public:
    void reverselist(Node *head);
};

// offer07 重建二叉树
class offer07 {
public:
   Bitnode<int>* buildTree(vector<int> &preorder, vector<int> &inorder);
    
   Bitnode<int>* dfs(vector<int> &preorder, vector<int> &inorder, 
                     int root, int start, int end);
   void levelorder(Bitnode<int>* root);
   void DFS(Bitnode<int>* root, int n);
   vector<vector<int>> res;
   int howlen(Bitnode<int>* root);
   unordered_map <int, int> map;
};

// 用队列实现栈 offer_09
class queue2stack {
public:
    void push(int x);
    int pop();
    int top();
    bool empty();
    queue<int> queue1;
    int top_element;
    int count = 0;

};

class stack2queue {
public:
    void push(int x);
    int pop();
    int front();
    bool empty();

    int top_element;
    int count = 0;

    stack<int> s1; // 用于存放
    stack<int> s2; // 用于取出

};

// offer_10 费伯纳起数列
class offer10 {
public:
    long long fib(int n);
    vector<long long> dp = {0, 1};
};

// offer10_2 青蛙跳台
class offer10_2 {
public:
    int numWays(int n);
};

// 旋转数组的最小值  二分法
class offer11 {
public:
   int minArray(vector<int> &nums);
};

// offer12 矩阵中的路径
class offer12 {
public:
    bool exit(vector<vector<char>> &board, string word);

    vector<vector<char>> board_;
    string word_;
    void dfs(int i, int j, int &cur_posi, bool &ans,
              vector<pair<int, int> > &temp_path);

    vector<vector<int>> direction = { {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vector<vector<pair<int, int> > > path;

};

// offer13 机器人的运动范围
class offer13 {
public:
    int movingCount(int m, int n, int k);
    void dfs(int &row, int &col, int m,
             int n, int k, int &temp,
             vector<vector<bool>> &visiter);

    int longest = 0;
    vector<vector<int>> direction =
        {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    
    bool enter(int row, int col, int k);
    int sum(int num);
};

