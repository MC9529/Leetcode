#pragma once
#include <limits.h>

#include <algorithm>
#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>

#include "BiTree.h"
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
  Bitnode<int> *buildTree(vector<int> &preorder, vector<int> &inorder);

  Bitnode<int> *dfs(vector<int> &preorder, vector<int> &inorder, int root,
                    int start, int end);
  void levelorder(Bitnode<int> *root);
  void DFS(Bitnode<int> *root, int n);
  vector<vector<int>> res;
  int howlen(Bitnode<int> *root);
  unordered_map<int, int> map;
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

  stack<int> s1;  // 用于存放
  stack<int> s2;  // 用于取出
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
           vector<pair<int, int>> &temp_path);

  vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
  vector<vector<pair<int, int>>> path;
};

// offer13 机器人的运动范围
class offer13 {
 public:
  int movingCount(int m, int n, int k);
  void dfs(int &row, int &col, int m, int n, int k, int &temp,
           vector<vector<bool>> &visiter);

  int longest = 0;
  vector<vector<int>> direction = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

  bool enter(int row, int col, int k);
  int sum(int num);
};

// offer14_1 割绳子
class offer14_1 {
 public:
  int cuttingRope(int n);
};

// 二进制中1的个数
class offer15 {
 public:
  int hammingWeight(int n);
};

// 数值的整数次方
class offer16 {
 public:
  double mypow(double x, int n);
};

// offer18 删除链表的节点
class offer18 {
 public:
  Node *deleteNode(Node *head, int val);
};

// offer21 调整数组顺序使得奇数位于偶数前面

class offer21 {
 public:
  vector<int> exchange(vector<int> &nums);
};

// offer24 反转链表
class offer241 {
 public:
  Node *reverseList(Node *head);
};

// 树的子结构
class offer26 {
 public:
  bool isSubstructure(Bitnode<char> *A, Bitnode<char> *B);
  void preOrder(Bitnode<char> *A, string &str_A);
  bool judge(const string &a, const string &b);  // 判断b是不是a的子串
};

// offer27 二叉树的镜像
class offer27 {
 public:
  Bitnode<char> *mirrorTree(Bitnode<char> *root);
  void mirror(Bitnode<char> *root);
};

// 对称的二叉数  offer28
class offer28 {
 public:
  bool issymmetric(Bitnode<char> *root);
  bool judge(Bitnode<char> *left, Bitnode<char> *right);
};

// offer29 顺时针的打印矩阵
class offer29 {
 public:
  vector<int> spiralOrder(vector<vector<int>> &matrix);
  void travel(vector<vector<bool>> &visited, vector<vector<int>> &matrix,
              int row, int col, int direct);

  vector<int> res;
  vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
};

// 从上到下打印二叉树  offer32_1
class offer321 {
 public:
  vector<char> levelorder(Bitnode<char> *root);
};

// 从上到下打印二叉树  offer32_2
class offer322 {
 public:
  vector<vector<char>> levelorder(Bitnode<char> *root);
};

// 从上到下打印二叉树  offer32_3
class offer323 {
 public:
  vector<vector<char>> levelorder(Bitnode<char> *root);
};

// offer34 二叉树中和为某一值的路径
class offer34 {
 public:
  vector<vector<int>> pathSum(Bitnode<char> *root, int sum);
  void dfs(Bitnode<char> *root, int sum, vector<int> &temp_res);
  vector<vector<int>> res;
  vector<int> tep_res;
};

// Search for a Range
// Given a sorted array of integers, find the starting and ending position of a
// given target value. Your algorithm’s runtime complexity must be in the order
// of O(log n). If the target is not found in the array, return [-1, -1]. For
// example, Given [5, 7, 7, 8, 8, 10] and target value 8, return [3, 4].

class searchRange_solution {
 public:
  vector<int> searchRange(vector<int> &nums, int target);
};

// offer37
class offer37 {
 public:
  string serialize(Bitnode<char> *root);
  Bitnode<char> *deserialize(string data);
  Bitnode<char> *creatNode(string data, int &n);
};

// offer38 字符串的排列
class offer38 {
 public:
  vector<string> permutable(string s);
  void dfs(string s, string &track, vector<bool> &visited);
  vector<string> res;
};

// offer39 次数超过一半的数字
class offer39 {
 public:
  int majorityElement(vector<int> &nums);
};

// offer40 最小的k个数字
class offer40 {
 public:
  vector<int> getKthNumber(vector<int> &nums, int k);
};

// offer42 连续子数组的最大和
class offer42 {
 public:
  int maxSubArray(vector<int> &nums);
};

// offer43 1～n整数中1出现的次数
class offer43 {
 public:
  int countDigitone(int n);
  int calcu(int n, int previous_one);
  // vector<int> dp(n + 1, 0);
};

// offer44 数字序列中的某一位的数字
class offer44 {
 public:
  int findNthDigit(int n);
};

// 把数组排列成最小的数 offer45
class offer45 {
 public:
  string minNumber(vector<int> &nums);
};

// offer47 礼物的最大值
class offer47 {
 public:
  int maxValue(vector<vector<int>> &grid);
};

// offer48 最长不含重复字符的子字符串
class offer48 {
 public:
  int lengthOflongestSubstring(string s);
};

// 丑数
class offer49 {
 public:
  int nthUglyNumber(int n);
};

// 第一个只出现一次的字符
class offer50 {
 public:
  char firstUniqChar(string s);
};

// 数组中的逆序对
class offer51 {
 public:
  int reversePairs(vector<int> &nums);
  void dfs(int i, vector<int> &nums, vector<int> &temp);
  vector<vector<int>> res;
};

// offer53_1  在排序数组中查找数字
class offer532 {
 public:
  int search(vector<int> &nums, int target);
};

// offer533 在 0 - n-1中缺失的数字
class offer533 {
 public:
  int missingnum(vector<int> &nums);
};

// 55 二叉树的的深度
class offer55 {
 public:
  int maxdepth(Bitnode<char> *root);
};

// offer55_2 平衡二叉树
class offer552 {
 public:
  bool isblanced(Bitnode<char> *root);
  int getheight(Bitnode<char> *root);
};

// offer561 数组中数字出现的次数
class offer561 {
 public:
  vector<int> singlenumber(vector<int> &nums);
};

// offer57 和为s的两个数字
class offer57 {
 public:
  // unorder_map
  vector<int> twosum(vector<int> &nums, int target);
  // 双指针
  vector<int> twosum2(vector<int> &nums, int target);
};

// 和为s的连续正数序列
class offer572 {
 public:
  vector<vector<int>> findcontinussequence(int target);
};

// offer581 反转单词顺序
class offer581 {
 public:
  string resverseWord(string s);
};

// offer582 左旋转字符串
class offer582 {
 public:
  string resverseLeftWords(string s, int n);
};

// offer591 滑动窗口的最大值
class offer591 {
 public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k);
};

// offer60 n个赛子的点数
class offer60 {
 public:
  vector<double> twosum(int n);
};

// offer61 扑克牌中的顺子
class offer61 {
 public:
  bool isstraight(vector<int> &nums);
};

// 圆圈中最后剩下的数字 offer62

// 求 1+2....+n
class offer64 {
 public:
  int sumnums(int n);
};

// 股票的最大的利润  offer63
class offer63 {
 public:
  int maxprofit(vector<int> &prices);
};

// 不用加减乘除做加法 offer65
class offer65 {
 public:
  int add(int a, int b);
  int subtrack(int a, int b);
};

// 构建乘积数组 offer66
class offer66 {
 public:
  // 时间复杂度 o(n^2)
  vector<int> constractArr(vector<int> &a);
  // 时间复杂副  o(2n)
  vector<int> constractArr2(vector<int> &a);
};

// 将字符串转换成整数  offer67
class offer67 {
 public:
  int str2int(string str);
};

// 二叉树的最近公共祖先 offer681;
class offer681 {
 public:
  // 迭代版本
  Bitnode<char> *lowestcommonancester(Bitnode<char> *root, int val_p,
                                      int val_q);

  // 递归版本
  Bitnode<char> *lowestcommonancester2(Bitnode<char> *root, int val_p,
                                       int val_q);

  Bitnode<char> *travel(Bitnode<char> *root, int p_val, int q_val);
};

// 二叉树的最近公共祖先 offer682;
class offer682 {
 public:
  Bitnode<char> *lowestcommonancester(Bitnode<char> *root, int val_p,
                                      int val_q);
};

///////////// leetcode
class leetcode844 {
 public:
  bool backspaceCCompare(string t, string s);
  string getString(string str);
};

// leetcode1 两个数之和
class leetcode1 {
 public:
  vector<int> twosum(vector<int> &nums, int target);
};

// 两数相加 leetcode2
class leetcode2 {
 public:
  Node *addTwonumbers(Node *l1, Node *l2);
};

// 无重复字符的最长子串
class leetcode3 {
 public:
  int lenoflongestsubstring(string s);
  int lenoflongestsubstring2(string s);
};

// 最长回文子串  leetcode5
class leetcode5 {
 public:
  string longestPalindrome(string s);
  string longestPalindrome2(string s);
};

// 整数反转 leetcode7
class leetcode7 {
 public:
  int reverse(int x);
};

// 字符串转整数 leetcode8
class leetcode8 {
 public:
  int myatoi(string s);
};

// 回文数 leetcode9
class leetcode9 {
 public:
  bool ispalindrome(int x);
};

// 成最多水的容器 leetcode11
// 双指针法
class leetcode11 {
 public:
  int maxarea(vector<int> &height);
};

// 整数转罗马数字 leetcode12
class leetcode12 {
 public:
  string int2roman(int num);
};

// 罗马数字转数字  leetcode13

class leetcode13 {
 public:
  int roman2int(string s);
};

// leetcode14 最长公共子串
class leetcode14 {
 public:
  string longestcommonPrefix(vector<string> &strs);
  string longestcommonPrefix(const string &str1, const string &str2);
};

// 三数之和  leetcode15  二数之和 leetcode1

class leetcode15 {
 public:
  vector<vector<int>> threeSum(vector<int> &nums, int target);
};

// leetcode16 最接近的三数之和
class leetcode16 {
 public:
  int threeSumClosest(vector<int> &nums, int target);
};

// leetcode17 电话号码的字母组合
class leetcode17 {
 public:
  vector<string> letterCombinations(string digits);
  void backtrack(vector<string> &combinations,
                 const unordered_map<char, string> &phoneMap,
                 const string &digits, int index, string &combination);
};

// leetcode18 四数之和
class leetcode18 {
 public:
  vector<vector<int>> fourSum(vector<int> &nums, int target);
};

//  删除链表的第n个节点 leetcode19
class leetcode19 {
 public:
  Node *deleteNthNode(Node *head, int n);
};

// 有效括号  leetcode20
class leetcode20 {
 public:
  bool isValid(string s);
};

// 合并两个升序链表  leetcode21
class leetcode21 {
 public:
  Node *merge2Node(Node *head1, Node *head2);
};

// 括号生成器  leetcode22
class leetcode22 {
 public:
  vector<string> generaterParents(int n);
  void dfs(vector<string> &res, string path, int n, int lc, int rc);
};

// 两两交换链表中的节点  leetcode24
class leetcode24 {
 public:
  Node *swapPairs(Node *head);
};

// 删除排序数组中的重复数组  leetcode26
class leetcode26 {
 public:
  int removeDuplicates(vector<int> &nums);
};

// 移除元素 leetcode27
class leetcode27 {
 public:
  int removeelement(vector<int> &nums, int val);
};

// 实现 strStr leetcode28
class leetcode28 {
 public:
  int strStr(string haystack, string needle);
};

// 除法 leetcode29
class leetcode29 {
 public:
  int divide(int dividend, int divisor);
  int div(long a, long b);
};

// 搜索排序数组  leetcode 33
class leetcode33 {
 public:
  int search(vector<int> &nums, int target);
};

// 在排序数组中查找元素的第一个和最后一个位置 时间复杂度O(log(n))
// leetcode34
class leetcode34 {
 public:
  vector<int> searchRange(vector<int> &nums, int target);
  // int lower_bound(vector<int> &nums, int target);
  // int upper_bound(vector<int> &nums, int target);
};

// 搜索插入位置  leetcode35
class leetcode35 {
 public:
  int searchInsert(vector<int> &nums, int target);
};

// 排序  快速排序
class quickSort {
 public:
  void quicksort(vector<int> &nums, int l, int r);
};

// 排序  归并排序
class mergeSort {
 public:
  void mergesort(vector<int> &nums, int low, int high);
  void merge(vector<int> &nums, int low, int mid, int high);
};

// leetcode36 有效数独
class leetcode36 {
 public:
  bool isvalidsuduku(vector<vector<char>> &board);
};

// leetcode39 组合总和
class leetcode39 {
 public:
  // 元素可以无数次引用
  vector<vector<int>> commbinationsum(vector<int> &nums, int target);
  // 可以重复利用
  void dfs(vector<int> &nums, vector<int> &temp, int target, int sum, int posi);
  // 不可以重复利用
  void dfs1(vector<int> &nums, vector<int> &temp, int target, int sum,
            int posi);

  vector<vector<int>> res;
};

class leetcode40 {
 public:
  vector<vector<int>> commbinationsum(vector<int> &nums, int target);
  // 不可以重复利用
  vector<vector<int>> res;
  void dfs1(vector<int> &nums, vector<int> &temp, int target, int sum,
            int posi);
};

// 接雨水
class leetcode42 {
 public:
  int trap(vector<int> &height);
};

// 全排列 leetcode46
class leetcode46 {
 public:
  vector<vector<int>> permut(vector<int> &nums);
  void dfs(vector<bool> &visited, vector<int> &temp, vector<int> &nums,
           int &posi);
  vector<vector<int>> ans;
};

//  全排列2 leetcode47
class leetcode47 {
 public:
  vector<vector<int>> permut(vector<int> &nums);
  void dfs(vector<bool> &visited, vector<int> &temp, vector<int> &nums,
           int &posi);
  vector<vector<int>> ans;
};

// Pow(x, n) leetcode50
class leetcode50 {
 public:
  // 一步一步 迭代 0(n)
  double myPow(double x, int n);
  // O(log(N))
  double myPow2(double x, int n);
};

// N 皇后 leetcode51
class leetcode51 {
 public:
  vector<vector<string>> SolveNQueens(int n);
  void dp(int n, int row, vector<string> &temp);
  bool valid(int row, int col, vector<string> &temp, int n);
  vector<vector<string>> ans;
};

// leetcode53 最大子序列和
class leetcode53 {
 public:
  int maxSubarray(vector<int> &nums);
};

//  leetcode54   旋转矩阵

class leetcode54 {
 public:
  vector<int> spiralOrer(vector<vector<int>> &nums);
};
// leetcode 55 跳跃游戏
class leetcode55 {
 public:
  // 贪心算法
  bool canjump3(vector<int> &nums);
  // 回溯算法
  bool canjump2(vector<int> &nums);
  bool dfs(int cur_level, int &most_step, vector<int> &temp_step,
           vector<int> &nums);
  vector<vector<int>> path;
};

// leetcode56 合并区间
class leetcode56 {
 public:
  void merge(vector<vector<int>> &nums, vector<pair<int, int>> &ans);
};

// 螺旋矩阵 leetcode59
class leetcode59 {
 public:
  vector<vector<int>> generatematrix(int n);
};

// leetcode 61 旋转列表
class leetcode61 {
 public:
  Node *rotateRight(Node *head, int k);
};

// leetcode62 不同路径
class leetcode62 {
 public:
  // 回溯算法
  int uniquePath(int m, int n);
  void dfs(vector<pair<int, int>> &path, int &row, int &col, int m, int n);
  vector<vector<pair<int, int>>> ans;
  vector<vector<int>> directions = {{1, 0}, {0, 1}};
  // 动态规划
  int uniquePath2(int m, int n);
};

// leetcode63  不同路径 障碍物
class leetcode63 {
 public:
  int uniquePathwithobs(vector<vector<int>> &obsgrid);

  void dfs(vector<pair<int, int>> &path, int &row, int &col, int m, int n);
  vector<vector<pair<int, int>>> ans;
  vector<vector<int>> directions = {{1, 0}, {0, 1}};
  vector<vector<int>> obsgrid_;
  // 动态规划
  int uniquePath2(vector<vector<int>> &obsgrid);
};

// leetcode64  最小路径和
class leetcode64 {
 public:
  int minPathsum(vector<vector<int>> &grid);
};

// leetcode67 二进制求和
class leetcode67 {
 public:
  string addBinary(string a, string b);
};

// leetcode69  x的平方根
class leetcode69 {
 public:
  int mysqrt(int x);
};

//  leetcode70 爬楼梯
class leetcode70 {
 public:
  int climbStairs(int n);
};

// leetcode74 搜索二维矩阵
class leetcode74 {
 public:
  bool searchMatrix(vector<vector<int>> &matrix, int target);
};

// leetcode75 颜色分类
class leetcode75 {
 public:
  // 单指针
  void sortColor(vector<int> &nums);
  // 双指针
  void sortColor2(vector<int> &nums);
};

// 组合 leetcode77
class leetcode77 {
 public:
  vector<vector<int>> combine(int n, int k);
  void dfs(vector<int> &temp, int cur_posi, int n, int k);
  vector<vector<int>> ans;
};

// 子集 leetcode78
class leetcode78 {
 public:
  vector<vector<int>> subsets(vector<int> &nums);
  void dfs(int cur_posi, vector<int> nums);
  vector<vector<int>> ans;
  vector<int> temp;
};

// leetcode80

class leetcode80 {
 public:
  int removeDuplicates(vector<int> &nums);
};

// leetcode81  搜索旋转矩阵
class leetcode81 {
 public:
  bool search(vector<int> &nums, int target);
};

// leetcode84 柱状图中的最大柱形图
class leetcode84 {
 public:
  // 暴力法
  int largeRectangleArea(vector<int> &nums);

  int largeRectangleArea1(vector<int> &nums);
};

// leetcode90 子集
class leetcode90 {
 public:
  vector<vector<int>> subsetwithDup(vector<int> &nums);
  vector<vector<int>> ans;
  void dfs(vector<int> &nums, vector<int> &temp, int posi, vector<bool> &used);
};

// leetcode92 反转链表2
class leetcode92 {
 public:
  Node *reverseBetween(Node *head, int m, int n);
  // 递归实现

  Node *reverseBetween2(Node *head, int m, int n);
  Node *reverseN(Node *head_m, int n);
  Node *successor = nullptr;
};
// leetcode94 二叉树的中序遍历
class leetcode94 {
 public:
  //  Bitnode<char>* lowestcommonancester(
  // Bitnode<char> * root, int val_p, int val_q);
  void inorder(Bitnode<char> *root, vector<char> &res);
  void inorderTravel(Bitnode<char> *root);
};

// leetcode120 最小路径和
class leetcode120 {
 public:
  int minisumTotal(vector<vector<int>> &triangle);
};

// leetcode121 买卖股票的最佳时机
class leetcode121 {
 public:
  int maxProfit(vector<int> &prices);
};

// leetcode122 买卖股票的最佳时机2
class leetcode122 {
 public:
  int maxProfit(vector<int> &profit);
};

// leetcode123 买卖股票的最佳时机3

class leetcode123 {
 public:
  int maxprofit(vector<int> &prices);
};

// leetcode130 被围绕的区域
class leetcode130 {
 public:
  void solve(vector<vector<char>> &board);
  void dfs(vector<vector<char>> &board, int x, int y);
};

// leetcode131 分割回文串
class leetcode131 {
 public:
  vector<vector<string>> partition(string s);
  bool ispalindrome(const string &s, int start, int end);
  void backtracking(const string &s, int startIdex);
  vector<vector<string>> res;
  vector<string> path;
};

// leetcode132 分割回文串2

class leetcode132 {
 public:
  vector<vector<string>> partition(string s);
  bool ispalindrome(const string &s, int start, int end);
  void backtracking(const string &s, int startIdex);
  vector<vector<string>> res;
  vector<string> path;
};

// leetcode134 加油站

class leetcode134 {
 public:
  int canCompletecircuit(vector<int> &gas, vector<int> &cost);
};

// leetcode136 只出现一次的数字

class leetcode136 {
 public:
  int singleNumber(vector<int> &nums);
  int singleNumber2(vector<int> &nums);
};

// leetcode137 只出现一次的数字2
class leetcode137 {
 public:
  int singlenum(vector<int> &nums);
};

// leetcode141 环形链表
class leetcode141 {
 public:
  bool hasCycle(Node *head);
};

// leetcode1081 不同字符的最小子序列

class leetcode1081 {
 public:
  string smallestSubsequence(string s);
};

/****************************************************************************
 * 贪心算法
 * **************************************************************************/
class leetcode455 {
 public:
  int findContentChildren(vector<int> &g, vector<int> &s);
  int findContentChildren2(vector<int> &g, vector<int> &s);
};

// leetcode135

class leetcode135 {
 public:
  int candy(vector<int> &ratings);
};

// leetcode435
class leetcode435 {
 public:
  int eraseOverlapIntervals(vector<vector<int>> &nums);
};

// leetcode605
class leetcode605 {
 public:
  bool canPlaceFlower(vector<int> &flowered, int n);
};

class leetcode452 {
 public:
  int findminArrowShot(vector<vector<int>> &points);
};
// leetcode122
class leetcode122_1 {
 public:
  // 贪心算法
  int maxProfit(vector<int> &prices);
  // 动态规划
  int maxProfit2(vector<int> &prices);
};

// leetcode121
class leetcode121_1 {
 public:
  int maxprofit(vector<int> &prices);
};

// leetcode406

class leetcode406 {
 public:
  vector<vector<int>> ReConstructQueue(vector<vector<int>> peoples);
};

// leetcode167

/**********************************************************************
 * 双指针
 ***********************************************************************/
class leetcode167 {
 public:
  vector<int> Twosum(vector<int> nums, int target);
};

class leetcode15_1 {
 public:
  vector<vector<int>> Threesum(vector<int> nums, int target);
  vector<vector<int>> Threesum2(vector<int> nums, int target);
};

// 四个数之和
class leetcode18_1 {
 public:
  vector<vector<int>> Foursum(vector<int> &nums, int target);
};

// leetcode16 三个数最接近的和
class leetcode16_1 {
 public:
  int threeSumClosest(vector<int> &nums, int target);
};
// leetcode88 归并两个有序的数组

class leetcode88_1 {
 public:
  void merge(vector<int> &nums1, int m, vector<int> &nums2, int n);
};

// 快慢指针 leetcode142

class leetcode142 {
 public:
  Node *detectCycle(Node *head);
};

// leetcode141
class leetcode141_1 {
 public:
  bool hascycle(Node *head);
};

/*************************************************
 * 滑动窗口
 *
 * ********************************************/
// leetcode3
class leetcode3_1 {
 public:
  int lengthOfLongestSubstring(string s);
};

// leetcode239 滑动窗口最大值

class leetcode239 {
 public:
  vector<int> maxSlidingWindow(vector<int> &nums, int k);
};

// leetcode76 最小覆盖子串
class leetcode76 {
 public:
  string minWindow(string s, string t);
};

/***********************************************
 * 二分查找
 *
 * **********************************************/

// leetcode69 x的平方根

class leetcode69_1 {
 public:
  int mySqrt(int x);
};

// leetcode34 查找区间
class leetcode34_1 {
 public:
  vector<int> searchRange(vector<int> &nums, int target);
  vector<int> searchRange2(vector<int> &nums, int target);
  int low_bound(vector<int> &nums, int target);
  int upp_bound(vector<int> &nums, int target);
};

// leetcode81  旋转数组查找数字

class leetcode81_1 {
 public:
  bool search(vector<int> &nums, int target);
};

// leetcode540  有序数组中的单一元素

class leetcode540 {
 public:
  int singleNonDuplicate(vector<int> &nums);
};

/******************************************
 * 排序
 *
 * ****************************************/

// 快速排序

class quickSort_1 {
 public:
  void QuickSort(vector<int> &nums, int l, int r);
};

// 归并排序
class MergeSort_1 {
 public:
  void mergesort(vector<int> &nums, int low, int high);
  void merge(vector<int> &nums, int low, int mid, int high);
};

// 冒泡排序
class bubblesort {
 public:
  void Bubblesort(vector<int> &nums);
};

class leetcode215 {
 public:
  void findKthlargest(vector<int> &nums, int k);
  // 优先队列
  void findKthlargest2(vector<int> &nums, int k);
};

/***************************************************
 * 搜索
 *
 * ************************************************/
// 深度优先
class leetcode695 {
 public:
  int maxAreaOfIsland(vector<vector<int>> &grid);
  int dfs(vector<vector<int>> &grid, int cur_i, int cur_j);
};

// 深度优先  leetcode547

class leetcode547 {
 public:
  // 深度优先搜索
  int findCircleNum(vector<vector<int>> &friends);
  void dfs(vector<vector<int>> &friends, int i, vector<bool> &visited);
  // 广度优先搜索
  int findCircleNum2(vector<vector<int>> &friends);
};

// leetcode417 水流入太平洋和大西洋

class leetcode417 {
 public:
  vector<int> direct = {-1, 0, 1, 0, -1};
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &matrix);
  void dfs(vector<vector<int>> &matix, vector<vector<bool>> &can_reach, int i,
           int j);
};

/****************************************
 * 回溯算法
 *
 * *************************************/
class leetcode46_1 {
 public:
  vector<vector<int>> permutation(vector<int> nums);
  void dfs(vector<int> &ans, vector<int> &nums, vector<bool> &visited);

  //
  vector<vector<int>> permutation2(vector<int> nums);
  void dfs2(vector<int> &temp_ans, vector<int> &nums, int i);

 private:
  vector<vector<int>> ans;
};

class leetcode77_1 {
 public:
  vector<vector<int>> combine(int n, int k);
  void dfs(vector<int> &temp_ans, int n, int k, vector<bool> &visited,
           int cur_posi);

 private:
  vector<vector<int>> ans;
};

// leetcode51
class leetcode51_1 {
 public:
  vector<vector<string>> solveNqueue(int n);
  void dfs(vector<string> &temp_ans, int n, int r);
  bool valid(int row, int col, vector<string> &temp, int n);

 private:
  vector<vector<string>> ans;
};

// leetcode130

class leetcode130_1 {
 public:
  void solve(vector<vector<char>> &board);
  void dfs(vector<vector<char>> &board, int row, int col);
};

// leetcode47
class leetcode47_1 {
 public:
  vector<vector<int>> permuteUnique(vector<int> &nums);
  void dfs(vector<int> &temp_ans, vector<bool> &visited, int n,
           vector<int> &nums);

 private:
  vector<vector<int>> ans;
};

// leetcode40
class leetcode40_1 {
 public:
  vector<vector<int>> combinationSum2(vector<int> &nums, int target);
  void dfs(vector<int> &nums, vector<int> &temp_ans, int target, int &cur_sum,
           vector<bool> &visited, int &cur_posi);

 private:
  vector<vector<int>> ans;
};