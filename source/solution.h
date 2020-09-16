
#include <iostream>
#include <vector>
#include "BiTree.h"
#include <unordered_map>
#include <set>
#include <limits.h>
/////回溯算法

using namespace std;
//////////////////
class Permute_46_Solution{
public:
    vector<vector<int>> permute(vector<int>& nums);
    void DFS(vector<int> &nums, vector<int> &temp, vector<vector<int>> &res, 
       vector<int>::size_type cursize, vector<bool> &visited);
};
/////////////////
class sloveNQueue_51_Solution{
public:
    vector<vector<string>> sloveNQueue(int n);
    void DFS(vector<vector<string>> &res, vector<string> &temp, int n, int curRow, vector<int> route);
    bool valid (vector<int> route, int n);
};
/////////////
class totalNQueue_52_Solution{
public:
    int totalNQueue(int n);
    void DFS(vector<vector<int>> &res, vector<int> &temp, int n, int curRow);
    bool valid(vector<int> temp, int n);
};
////////////生成括号
class generateParenthesis_22_Solution {
public:
    vector<string> generateParenthesis(int n);
    void DFS(vector<string> &res, string &temp, int num, int n);
};
///////////////解数独
class SuDu_37_Solution{
public:
    void solveSuDu(vector<vector<char>> &board);
    void DFS(vector<vector<char>> &board, vector<vector<int>> &rows, vector<vector<int>> &cols, 
        vector<vector<int>> &cell, int i, int j, vector<vector<char>> &res);

};

/////////组合总和  每个数值可以使用多次
class combinationSum_39_Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target);
    void DFS(vector<vector<int>> &res, vector<int> &temp, vector<int> candidates, 
        int target, int sum, int posi);
};
///////组合总和  每个数值只能使用1次
class combinationSum_40_Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target);
    void DFS2(vector<vector<int>> &res, vector<int> &temp, vector<int> candidates, 
        int target, int sum, int posi);
};

///////  单词搜索 79 
class Search_79_Solution {
public:
    bool solve1(vector<vector<char>>& board1, string word1);

    bool DFS(vector<vector<char>> &board, int i, int j, string word, 
   int length, vector<vector<bool>> &used);
};
//////////子集 90

class subset_90_Solution{
public:
    vector<vector<int>> solve(vector<int> &nums);
    void DFS(vector<int> &temp, vector<vector<int>> &res, vector<int> nums, int len, int posi);
};
////栈
/////有效括号 20
class isValid_20_Solution {
public:
    bool isValid(string s);
    bool compare(char &s1, char &s2);
};

///动态规划 不同路径1  62
class uniquePaths_62_Solution {
public:
    int uniquePaths(int m, int n);
    // 动态规划
    void DFS(vector<vector<int>> &route, vector<int> &temp, vector<int> &start, vector<int> &target);
    // 回溯算法
    void BFS(int m, int n);
    // 存储路径
    vector<vector<int>> ans;
    struct route{
        vector<vector<int>> data;
    };
    
    
};

///动态规划 不同路径2  63

class uniquePathsWithObstacles_63_Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid);
    void DFS(vector<vector<int>> &route, vector<int> &temp, vector<int> &start, 
       vector<int> &target, vector<vector<int>> &obstacleGrid);
    // 动态规划
    void BFS(vector<vector<int>> &obstacleGrid);
    // 对于下面的struct,不能把括号提到上面来
    struct route
    {
        vector<vector<int>> data;
    };
    
};

///////最大子序列   LeetCode 53
class maxSubArray_53_Solution
{
public:
    int maxSubArray(vector<int> &nums);
    void DFS(vector<int> nums, vector<int> &temp, int &res);
};

////最小路径和 leetcode_64
class minPathSum_64_Solution {
public:
    int minPathSum(vector<vector<int>>& grid);
    void DFS(vector<vector<int>> grid, int &min_len, vector<vector<int>> &min_path, 
         vector<int> &route);
    void path(vector<vector<int>> grid, vector<vector<int>> min_path, vector<int> &route,
        int row, int col);
};
/// 爬楼梯 leetcode _70
class climbStair_70_Solution {
public:
    int climbStairs(int n);
    void DFS(int n, vector<vector<int>> &route, vector<int> &temp, int &count);
};

////解码方法  leetcode_91
class numDecodings_91_Solution{
public:
    int numDecoding(string s);
    void DFS(string s, vector<string> &str, string &str_temp, int &res_len);
    void print(vector<string> str);
};

///贪心算法， 跳跃游戏 , leetcode_45_and_55
class jump_45_Solution{
    public:
    bool jump(vector<int> &nums);
    void DFS(vector<int> nums, vector<int> &path, int &current, int &end, bool &res);
    int current_best_path(int current, vector<int> nums, int end);
};

///贪心算法， 买卖股票的最佳时机, leetcode_122
class maxProfit_122_Solution {
public:
    int maxProfit(vector<int>& prices);
    void DFS(int &res, vector<vector<int>> &way, vector<int> prices, int &buy, 
         int &sell, int &temp, vector<int> &temp_way);
};
///贪心算法， 加油站 leetcode_134
class canCompleteCircuit_134_Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost);
    void DFS(int start, vector<int> gas, vector<int> cost, int &res, int &res_gas);
    void actual_posi(int &posi, vector<int> &gas);
};

////贪心算法， leetcode_135
class candy_135_Solution {
public:
    int candy(vector<int>& ratings);
    void DFS(vector<int> ratings, vector<int> &candies);
};

///分而治之 leetcode_23
class mergeLise_23_solution{
public:
    vector<vector<int>> merge_list(vector<vector<int>> &list);
    vector<int> merge2(vector<int> list1, vector<int> list2);

};

///堆 head
//设置一个大小为K的堆，堆顶就是你所找的第K大的元素
class findKthLargest_215_solution {
public:
int findKthLargest(vector<int> &nums, int k);
int findKthLargest2(vector<int> &nums, int k);
};

///滑动窗口,Leetcode_239
class maxSlideWindow_239_solution {
public:
    void maxSlideWindow(vector<int> &nums, int k);
    void maxSlideWindow_in_heap(vector<int> &nums, int k);
};

////二分查找 leetcode_240 
class searchMatrix_240_solution {
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target);
    void DFS_rows(vector<vector<int>> &matrix, int target, int row, int &binary_row);
    void DFS_cols(vector<vector<int>> &matrix, int target, int col, int binary_row, bool &res);
};
////二分查找 leetcode_315
class countSmaller_315_solution {
public:
    vector<int> countSmaller1(vector<int> &nums);
    vector<int> countSmaller2(vector<int> &nums);
    void merge_sort(vector<pair<int, int>> &v, int n, int m, vector<int> &res);
};
///排序  归并排序
class merge_sorted {
public:
    void mergesort(vector<int> &list, int n, int m);
    void merge(vector<int> &list, int l, int mid, int r);
};
///排序 快速排序（从小到大）
class quick_sort {
public:
    void small2big(int left, int right, vector<int> &list);
    void big2small(int left, int right, vector<int> &list);
};
///前K个高频词 Leetcode_347
class topKFrequence_347_solution {
public:
    ///用哈希表统计，然后小顶堆
    vector<int> topKFrequence(vector<int> &nums, int k);
    ///用哈希表统计，然后sort
    vector<int> topKFrequence2(vector<int> &nums, int k);
};
////查找和最小的k对数字
class kSmallestPairs_373_solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int> &list1, vector<int> &list2, int k);
    vector<vector<int>> kSmallestPairs2(vector<int> &list1, vector<int> &list2, int k);
    vector<vector<int>> kSmallestPairs3(vector<int> &list1, vector<int> &list2, int k);
};

////有序矩阵中第K小的元素
class kthSmallest_378_solution {
public:
    //优先队列
    int kthSmallest(vector<vector<int>> &matrix, int k);
    //二分查找
    int kthSmallest2(vector<vector<int>> &matrix, int k);
};
///根据字符出现频率排序
class frequencySort_451_solution {
public: 
    ///排序
    string frequencySort(string s);
    ///优先队列
    string frequencySort2(string s);
};
////IPO leetcode_502
class IPO_502_solution {
public: 
    int findMaxCapital(int k, int w, vector<int> &prifit, vector<int> &Capital);
    void available_proj(int k, int w, vector<int> &Capital, vector<int> &avail,
                                    vector<int> &not_start);
    int best_proj(vector<int> &profit, vector<int> &Capital, vector<int> &avail, 
                                    vector<int> &not_start);
    ///用堆
    int findMaxCapital2(int k, int w, vector<int> &prifit, vector<int> &Capital);
};
///分割数组有连续子序列 leetcode_659
class CutWord_659_solution {
public:
    void CutWord(vector<int> &nums, vector<vector<int>> &res);
    void DeleteWord(vector<int> &target, vector<int> temp);

};

///前K个高频词，leetcode_692
class topKFrequent_692_solution {
public:
    //小顶堆
    vector<string> topKFrequent(vector<string> &words, int k);
    ///排序
    vector<string> topKFrequent2(vector<string> &words, int k);
};
///
class KthLargest_703_solution {
public:
    KthLargest_703_solution(int k, vector<int> &nums);
    int add(int val);
private:
    int kth = 0;
    vector<int> inter_nums;
};
///找出第K小的距离堆对
class smallestDistancePair_719_solution {
public:
    int smallestDistancePair(vector<int> &nums, int k);
    int smallestDistancePair2(vector<int> &nums, int k);
};

///网络延迟时间, 从某一点发出信号到所有节点都收到信号，要多长时间， leetcode_743 
class networkDelayTime_743_solution {
public:
    ///N个网络节点1->N, 当前节点为k, 
    int networkDelayTime(vector<vector<int>> &nums, int N, int k);
};
///格雷编码 leetcode_89 回溯算法
class grayCode_89_Solution {
public:
    vector<int> grayCode(int n);
    void DFS(vector<int> &res, vector<int> &temp, int n);
    void mirror(vector<int> &temp, int n);
    void Two2Ten(vector<int> &temp, vector<int> &res);
};
//复原ip地址 leetcode_93 回溯算法
class restoreIpAddresses_93_Solution {
public:
    vector<string> restoreIpAddresses(string s);
    void DFS(vector<string> &res, int n, string s, string temp);
};
///单词接龙 leetcode_126 回溯算法
class findLadders_126_Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList);
    void DFS(int &i, string endWord, vector<string>& wordList, vector<vector<string>> &res, 
                                                                        vector<string> &temp);
    bool next_string(vector<string> &temp, string condibate);
};

///分割回文串 leetcode_131 回溯算法
class partition_131_solution {
public:
    vector<vector<string>> partition(string s);
    void DFS(string s, vector<string> &temp, vector<vector<string>> &res, int &posi);
    bool IsPartition(string part);
};
//单词拆分 leetcode_140  回溯算法
class wordBreak_140_solution {
public:
    void wordBreak(string s, vector<string> &wordDict);
    void DFS(string s, vector<string> &wordDict, int &posi, vector<string> &temp_res);
    vector<vector<string>> res;
};
///添加和搜索单词 leetcode_211 回溯算法
class wordDictionary_211_solution {
public:
    void addWord(string s);
    void search(string s);
    bool equi(string s1, string s2);
    vector<string> res;
    bool bool_res = true;
};
///组合总和 leetcode_216 回溯算法
class combinationSum3_216_solution {
public:
    void combinationSum3(int k, int n);
    void DFS(int &k, int &n, vector<int> &temp_res, int &posi, vector<bool> &condibate);
    vector<vector<int>> res;
};
/// 累加数 leetcode_306 
class isAdditiveNumber_306_solution {
public:
    bool isAdditiveNumber(string num);
    void DFS(string s, bool &res, int &posi, vector<int> &temp_num, 
                                   vector<vector<int>> &temp_total);
};
//优美的排列 leetcode_526
class countArrangement_526_solution {
public:
    int count(int n);
    void DFS(vector<int> &temp, int n, vector<bool> &used);
    vector<vector<int>> res;
};
//字母大小写全排列 leetcode_784
class letterCasePermutation_784_solution {
public:
    void letterCasePermutation(string s);
    void DFS(string s, int &posi);
    vector<string> res;
};
///将数组拆分成斐波那契序列 leetcode_842
class splitIntoFibonacci_842_solution {
public:
   void splitIntoFibonacci(string s);
   void DFS(string s, vector<int> &temp, int &posi);
   vector<vector<int>> res;
};
//不同路径3 leetcode_980 
class uniquePaths3_980_solution {
public:
    void uniquePaths3(vector<vector<int>> &grid);
    void DFS(vector<vector<int>> &grid, pair<int, int> &current_point, 
            vector<vector<bool>> &used);

    void validPath(pair<int, int> point, vector<vector<int>> &grid, 
                   vector<vector<bool>> &used, vector<pair<int, int>> &validPaths);
    vector< vector<pair<int, int>> > total_res;
    vector<pair<int, int>> res;
    int obstacle_nums = 0;
};
///正方形数组的数目 leetcode_996
class numSquareFulPerms_996_solution {
public:
    void numSquareFulPerms(vector<int> &list);
    void DFS(vector<int> &res, int &posi, vector<bool> &used,
                                         vector<int> &list);
    bool IsSquareFulPerms(int val1, int val2);
    vector<vector<int>> total_res;
};
//不同的二叉搜索树2  递归
struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode(int x): val(x), left(NULL), right(NULL){}
};
class generateTrees_96_solution {
public:
    
    vector<TreeNode*> getTree(int begin, int end);
    vector<TreeNode*> generateTrees(int n);
    void print(TreeNode* root);
};

///被围绕的区域，leetcode_130
class solve_130_solution {
public:
    void solve(vector<vector<char>> &board, int flag);
    //深度优先，递归
    void DFS(vector<vector<char>> &board, int i, int j);
    //深度优先， 非递归
    void DFS2(vector<vector<char>> &board, int i, int j);
    //广度优先 非递归
    void BFS3(vector<vector<char>> &board, int i, int j);
    //广度优先，递归
    void BFS4(vector<vector<char>> &board, int i, int j);
    //并差集合
    void solve_union(vector<vector<char>> &board);
    int node(int i, int j);
    int row;
    int col;
};
//岛屿的数量leetcode_200
class numIslands_200_solution {
public:
    int numIslands(vector<vector<char>> &grid, int flag);
    void DFS(vector<vector<char>> &grid, int i, int j);
    void BFS(vector<vector<char>> &gird, int i, int j);
    void Union(vector<vector<char>> &board);
    //int node(int i, int j);
    int numsIslands = 0;
    int row;
    int col;
};
//最小高度树 leetcode_310
class findMinHeightTrees_310_solution {
public:
    void findMinHeightTrees(int n, vector<vector<int>> &edges);
    void DFS(int n, vector< pair<vector<int>, bool> > &edges_bool, vector<int> &temp_res, int &hight);
    bool find_num(int n, pair<vector<int>, bool> &edges_bool, int &posi);
    vector<pair<vector<int>, int>> res;
};
//删除无效的括号 leetcode
class removeInvalidParentheses_301_solution {
public:
    void removeInvaliaParentheses(string s);
    void DFS(string s, int st, int left, int right);
    bool check(string s);
    vector<string> res;
    int count = 0;

};
//矩阵中的最长增长路径 leetcode_329
class longestIncreasingPath_329_solution {
public:
    void longestIncresingPath(vector<vector<int>> &matrix);
    void DFS(vector<int> &temp_res, int &row_posi, int &col_posi, vector<vector<int>> &matrix);
    void LonestPath(vector<vector<int>> res);
    bool NoWay(int row_posi, int col_posi, vector<int> &temp_res, vector<vector<int>> &matrix);
    vector<vector<int>> res;
    vector<int> lonestPath;
    vector<vector<int>> total_res;
    vector<pair<int, int>> direct = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

};
//矩阵中的最长增长路径 leetcode_329
class longestIncreasingPath_329_solution2 {
public:
    void longestIncresingPath2(vector<vector<int>> &matrix);
    void DFS(vector<int> &temp_res, int &posi, 
            vector<pair<pair<int, int>, int>> &vp, vector<vector<int>> &matrix);
    vector<vector<int>> res;
    bool Noway(vector<pair<pair<int, int>, int>> &vp, int posi);
};
////矩阵中的最长增长路径 leetcode_329 动态规划
//动态规划思想
/* 将matrix的排序初始值为 6, 5, 4, 3, 2, 2 1， 先从值大的开始
  path[5]= path[5] + path[6](路径最长的方向)

*/
class longestIncreasingPath_329_solution3 {
public:
    void longestIncresingPath2(vector<vector<int>> &matrix);
    void DFS(vector<vector<vector<int>>> &dp, int &posi, 
            vector<pair<pair<int, int>, int>> &vp, vector<vector<int>> &matrix);
    int rows = 0;
    int cols = 0;
    vector<pair<int, int>> direct = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    void print(vector<vector<vector<int>>> &dp);
};
//重新安排行程 leetcode_332
class findItinerary_332_solution {
public:
    void findItinerary(vector<vector<string>> &tickets);
    void DFS(vector<vector<int>> &g, int i, int N, vector<int> &path);
    bool NoWay(vector<vector<int>> &g, int i, int N);
    //vector<string> res;
    vector<vector<int>> total_path;
    vector<vector<string>> total_res;
};
///打家劫舍 leetcode_337

///太平洋大西洋水流问题 leetcode_417
class pacificAtlantic_417_solution {
public:
    void pacificAtlantic(vector<vector<int>> &matrix);
    void pacific(int &row, int &col, vector<vector<int>> &pacific_matrix, vector<vector<int>> &matrix, 
    vector<vector<bool>> &pace_used);
    void Atlantic(int &row, int &col, vector<vector<int>> &Atlantic_matrix, vector<vector<int>> &matrix,
    vector<vector<bool>> &Atlan_used);
    bool Noway(int row, int col, vector<vector<int>> &matrix, vector<vector<bool>> &used);
    bool posi_right(int row, int col);
    //vector<vector<int>> pacific_matrix;
    //vector<vector<int>> Atlantic_matrix;
    vector<vector<int>> res;
    vector<pair<int, int>> direct = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    int rows;
    int cols;
};
///the double tree
struct TreeNode_char {
        char val;
        TreeNode_char *left;
        TreeNode_char *right;
        TreeNode_char(char x): val(x), left(NULL), right(NULL){}
};
///验证二叉树 leetcode
class isValidBST_98_solution {
public:
    bool isValidBST(Bitnode<char>* root);
    bool flag = true;
};
//二叉树的层次c遍历
class levelOrder_102_solution {
public:
    //vector
    void levelOrder(Bitnode<char> *root);
    //队列
    void levelOrder2(Bitnode<char>* root);
    //递归
    void levelOrder3(Bitnode<char>* root);
    void DFS(Bitnode<char>* root, int n);
    int howlen(Bitnode<char>* root);
    vector<vector<char>> res;
};
///二叉树的锯齿型层次遍历
class zigzaglevelOrder_103_solution {
public:
    void zigzaglevelOrder(Bitnode<char>* root);
    vector<vector<char>> res;
    //flag: 0: left->right 1: right->left
    int flag = 0;
    void inverse(int &flag);
    
};
///路径总和2 leetcode_113
class pathSum_113_solution {
public:
   void pathSum(Bitnode<char>* root, int sum);
   void DFS(Bitnode<char> * root, int sum, vector<int> &temp_res);
   vector<vector<int>> res;
   void print(vector<int> &temp_res);
};
//二叉树转化为链表 leetcode_114
class flatten_114_solution {
public:
    void flatten(Bitnode<char> *root);
    void DFS(Bitnode<char> *root);
    vector<char> res;
};
///求根到叶子节点的数字之和
class sumNumbers_129_solution {
public:
    void sumNumbers(Bitnode<char>* root);
    void DFS(Bitnode<char>* root, vector<int> &temp_res);
    vector<vector<int>> res;
};
//二叉树的右视图
class rightSideView_199_solution {
public:
    void rightSideView(Bitnode<char>* root);
    void right_DFS(Bitnode<char>* root);
    vector<char> res;
};
//二叉树中的第K小的元素
class KthSmallest_230_solution {
public:
    struct comp {
        ///大顶堆
        bool operator()(const int &a, const int &b) {
            return a < b;
        } 
    };
    priority_queue<int, vector<int>, comp> queue;
    void KthSmallest(Bitnode<char>* root, int k);
    void DFS(Bitnode<char>* root, int k);

};
//二叉树的最近公共祖先 leetcode_236
class lowestCommonAncestor_236_solution {
public:
    void lowestCommonAncestor(Bitnode<char>* root, Bitnode<char>* p, Bitnode<char>* q);
    void DFS(Bitnode<char>* root, Bitnode<char>* p, Bitnode<char>* q);
    bool search_ancestor(Bitnode<char>* root, Bitnode<char>* p, Bitnode<char>* q, 
                                   bool &flag_p, bool &flag_q, bool &search_res);
    vector<char> res;
};
//找树左下角的值 leetcode_513
class findBottomLeftValue_513_solution {
public:
    void findBottomLeftValue(Bitnode<char>* root);
    vector<vector<char>> res;
};
//在每一个树行中找最大值
class largestValue_515_solution {
public:
    void largestValue(Bitnode<char>* root);
    vector<int> res;
};
//火柴拼正方形 leetcode_473 
class makesquare_473_solution {
public:
    void makesquare(vector<int> &nums);
    void DFS(int index, vector<vector<int>> &res);
    //vector<vector<int>> res;
    //vector<vector<int>> pacific_matrix(rows, vector<int>(cols, 0));
    vector<int> nums_;
    int target;
    //vector<vector<int>> res(4, vector<int>());
    bool flag = false;
    void print_vector(vector<vector<int>> &res);
    vector<vector<vector<int>>> total;
};
//最长连续序列 leetcode_128
class longestConsecutive_128_solution {
public:
    //排序
    void longestConsecutive(vector<int> &nums);
    //unordered_set
    void longestConsecutive2(vector<int> &nums);
    //并查集
    void longestConsecutive3(vector<int> &nums);
    int father(int x);
    vector<int> res;
    vector<vector<int>> total_res;
    unordered_map<int, int> uf, cnt;

};
//并查集 leetcode_547 朋友圈
class findCircleNum_547_solution {
public:
    void findCircleNum(vector<vector<int>> &nums);
};
//除法求值
class calcEquation_399_solution {
public:
    void calcEquation(vector<vector<string>> &equations, vector<double> &val, vector<vector<string>> &query);
};
///median is the middle value in an ordered list if the 
//[2, 3, 4] the median is 3
//[2, 3] the median is 2 + 3/2 =  2.5
class medianFinder {
public:
    vector<int> collector;
    medianFinder();
    void addNum(int num);
    double findMedian();
};
//合并排序数组 
class merge_1680_solution {
public:
    //直接合并后排序
    void merge(vector<int> &A, int m, vector<int> &B, int n);
    //双指针
    void merge2(vector<int> &A, int m, vector<int> &B, int n);
    //逆向指针
    void merge3(vector<int> &A, int m, vector<int> &B, int n);

};
//存在重复元素 leetcode_220
class containNearbyAlmost_220_solution {
public:
    //暴力求解
    void containNearbyAlmost(vector<int> &nums, int k, int t);
    //二叉搜索树 
    void containNearbyAlmost2(vector<int> &nums, int k, int t);
    //通排序
    void containNearbyAlmost3(vector<int> &nums, int k, int t);

    vector<pair<int, int>> res;

};
//删除排序数组中的重复项 leetcode_80
class removeDuplicate_80_solution {
public:
    void removeDuplicate(vector<int> &nums);
    void removeDuplicate2(vector<int> &nums);
};
//颜色分类 leetcode_75 
class sortColors_75_solution {
public:
     //适合多个颜色
    void sortColor(vector<int> &nums);
    ///适合3个颜色
    void sortColor2(vector<int> &nums);
};
///TODO 还没完成
//最小覆盖子串  leetcode_76
class minWindow_76_solution {
public:
    void minWindow(string s, string t);
    vector<string> res;

};
///长度最小的子数组 leetcode_209
class minSubArraylen_209_solution {
public:
     //暴力法
    int minSubArraylen(int s, vector<int> &nums);
    //建立一个nums 用来存储 前n个和，sums[2] = nums[0] + nums [1] + nums[2];
    int minSubArraylen2(int s, vector<int> &nums);
    //使用二分法
    int minSubArraylen3(int s, vector<int> &nums);
    //使用双指针
    int minSubArraylen4(int s, vector<int> &nums);

    vector<vector<int>> res; 

};
///滑动窗口最大值 leetcode_239 
class maxSlidingWindow_239_solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k);
};
///替换后的最长重复字符
class characterReplacement_424_solution {
public:
    void characterReplacement(string s, int k);
    vector<vector<char>> res;
};
//字符串的排列 leetcode_567 最大字符串是否包含最小字符串
class checkInclusion_567_solution {
public:
    bool checkInclusion(string s1, string s2);
    bool checkInclusion2(string s1, string s2);
    vector<vector<int>> container;
};
///无重复字符的最长子串 leetcode_3 滑动窗口
class lengthOfLongestSubstring_3_solution {
public:
    int lengthOfLongestSubstring(string s);

};
///最大连续1个的个数
class longestOnes_1004_solution {
public:
    int longestOnes(vector<int> &A, int k);
    int longestOnes2(vector<int> &A, int k);
    vector<pair<int, int>> res;
};
//爱生气的书店老板 leetcode_1052
class maxSatisfied_1052_solution {
public:
    int maxSatisfied(vector<int> &customers, vector<int> &grump, int x);
    int maxSatisfied2(vector<int> &customers, vector<int> &grump, int x);
    int maxSatisfied3(vector<int> &customers, vector<int> &grump, int x);
    vector< pair<pair<int, int>, int> > res;

};
///如何高效实现寻找素数
class countPrimes_solu {
public:
    void countPrimes(int n);
    vector<int> res;

};
////Dijkstra算法，求起点到终点的最短距离
typedef struct _graph
{
    vector<string> vexs; //定点集合
    int vexnum; //顶点数
    int edgenum; //边数
    vector<vector<int>> matrix; //邻接矩阵
} Graph, *Pgraph;
typedef struct _EdgeData {
    char start; //边的起点
    char end; //边的终点
    int weight;

}Edate;
/*************************************************************
 * G为图
 * vs：起点
 * prev前驱顶点数组。即，prev[i]的值是"顶点vs"到"顶点i"的最短路径所经历
 *  的全部顶点中，位于"顶点i"之前的那个顶点。
 * dist:长度数组。即，dist[i]是"顶点vs"到"顶点i"的最短路径的长度。
 * 
 * ************************************************************/
class Dijkstra_solu {
public:
    void dijkstra(Graph G, int vs);
};
///Floyd算法找最短路径
class Floyd_solution {
public:
    void Floyd(vector<vector<int>> &nums, int k);
};
///最长上升子序列  
class lengthofLis_300_solution {
public:
     //动态规划
    int lengthofLis(vector<int> &nums);
    //动态规划
    int lengthofLis2(vector<int> &nums);
     // 贪心+二分查找
    int lengthofLis3(vector<int> &nums);
    //贪心+二分查找方法2
    int lengthofLis4(vector<int> &nums);
    void print(vector<int> &d);
};
//搜索二维矩阵 leetcode_74
class searchMatrix_74_solution {
public:
    //二分查找
    void searchMatrix(vector<vector<int>> &matrix, int target);
    //先定范围，再定位置
    void searchMatrix2(vector<vector<int>> &matrix, int target);
    vector<pair<int, int>> res;
};
//寻找山脉峰值 峰值：nums[i] > nums[i + 1] and nums[i] < nums[i - 1]
class findPeakElement_162_solution {
public:
    //迭代
    int findPeakElement(vector<int> &nums);
    //递归
    int findPeakElement2(vector<int> &nums);
    int findPeakElementHelper(vector<int> &nums, int start, int end);
};
//区间和的个数 给定一个整数数组 nums，
//返回区间和在 [lower, upper] 之间的个数，
//包含 lower 和 upper。
class countRangeSum_327_solution {
public:
    int countRangeSum(vector<int> &nums, int lower, int upper);
    int search(vector<int> nums, int low, int high);
    vector<pair<int, int>> ans;
    //hash
    int countRangeSum2(vector<int> &nums, int lower, int upper);
};
///统计优美子数组 leetcode_1248
//连续数组中有k个奇数
class numberofSubarrays_1248_solution {
public:
    //二分法
    void numberofSubarrays(vector<int> &nums, int k);
    int search(vector<int> &helper, int lower, int k);
    vector<pair<int, int>> ans;
    //hash
    void numberofSubarrays2(vector<int> &nums, int k);
    //
    int numberofSubarrays3(vector<int> &nums, int k);
};
///四个数相加 leetcode_454
class foursumcout_454_solution {
public:
   int foursumcout(vector<int> &A, vector<int> &B, vector<int> &C, vector<int> &D);
   vector<vector<int>> res;
};
// 找到K个最接近的元素
class findclosestelement_658_solution {
public:
    void findclosestelement(vector<int> &nums, int k, int x);
    vector<int> res;
};
// 乘法表中第K小的数 leetcode_668
class findKthnumber_668_solution {
public:
    //  二分法
    int findKthnumber(int m, int n, int k);
    int binary_search(vector<int> &container, int k);
};
// 最长重复子数组 leetcode_718
class findLength_718_solution {
public:
    int findLength(vector<int> &A, vector<int> &B);
};

// 最短编辑距离，对一个string s进行编辑，使得s变成string t,要求操作次数最短
class ShortEditLen_solution {
public:
    // 动态规划
    void ShortEditLen(string &A, string &B);
};
// 如何去除有序数组的重复元素
// labuladong 算法小抄
class removeDuplicate_solu {
public:
    // 有序 快慢指针
    void removeDuplicate(vector<int> &nums);
    // 无序 set
    void removeDuplicate2(vector<int> &nums);
    
};
// 如何寻找最长回文子串
class longestPalindrome_solu {
public:
    void longestPalindrome(string &s);
    string find(string &s, int left, int right);
    vector<pair<string, string>> ans;

};

// leetcode_45 跳格子
class jump_45_solution {
public:
   // 动态规划
   int jump(vector<int> &nums);
   int calcu_steps(int posi, vector<int> &nums, vector<int> &dp);
   // 贪心算法
   int jump2(vector<int> &nums);
};

// labuladong算法小抄 
// 最长递增序列（序列可以不连续，但是串必须连续）
class lengthOfLIS_solu {
public:
    // 动态规划 dp[i]:以该位置结尾的最长递增序列 dp[i] = min(dp[0.....i-1]) + 1
    void lengthOfLis(vector<int> &nums);
    // 维护一个数组tail，当出现的数大于这个数组直接append，否则替换掉数组中大于等于这个数的最小值。
    // 最后tail的长度就是最长上升子序列的长度
    // 而tail数组是一个有序数组，使用二分查找复杂度为O（log n）
    // 贪心算法，二分查找，要使最长，则最顶部的元素要尽可能小
    void lengthOfLis2(vector<int> &nums);
};
// labuladong算法小抄 
// 0-1背包问题
class knapsack_solu {
public:
    void knapsack(int N, int W, vector<int> &weight, vector<int> &value);
};
// labuladong算法小抄
// 高楼掉鸡蛋 
class superEggDrop_solu {
public:
    void superEggDrop(int K, int N);
};
// labuladong算法小抄
// 最长公共子序列
class longestCommonSubsequence_solution {
public:
    void longestCommonSubsequence(string str1, string str2);
};
// // labuladong算法小抄
// 最长回文子序列
class longestPalindromeSubseq_solution {
public:
    void longestPalindromeSubseq(string str1);
};
// labuladong算法小抄
// 动态规划之博弈
/*你和你的朋友面前有一排石头堆，用一个数组 piles 表示，
  piles[i] 表示第 i 堆石子有多少个。你们轮流拿石头，
  一次拿一堆，但是只能拿走最左边或者最右边的石头堆。
  所有石头被拿完后，谁拥有的石头多，谁获胜。
*/
/*
请你设计一个算法，返回先手和后手的最后得分（石头总数）之差。
比如上面那个例子，先手能获得 4 分，后手会获得 100 分，
你的算法应该返回 -96。
*/
class stoneGame_solu {
public:
    void stoneGame(vector<int> &stone);
};

// 贪心算法之区间调度问题
/*
在区间集合 intvs 中选择一个区间 x，这个 x 是在当前所有区间中结束最早的（end 最小）。
把所有与 x 区间相交的区间从区间集合 intvs 中删除。
重复步骤 1 和 2，直到 intvs 为空为止。之前选出的那些 x 就是最大不相交子集。
*/
class intervalSchedule_solu {
public:
    void intervalSchedule(vector<vector<int>> &nums);
};
// leetcode_435 无重叠区间
// 给定一个区间，找出最少需要去除的子区间，使得剩下的区间不重复
// 转化问题， 就是找一个最长的不重叠区间 
class eraseOverlapIntervals_435_solu {
public:
    void eraseOverlapIntervals(vector<vector<int>> &nums);
};
// 股票买卖问题 最多允许进行一次买和卖
class Solution_121_solution {
public:
    void maxProfit(vector<int>& prices);
};

// 股票买卖问题，允许进行多次买和卖
class Solution_122_solution {
public:
    void maxProfit(vector<int>& prices);
};

// 股票买卖问题，允许进行2次操作（买和卖加起来算一次）
class Solution_123_solution {
public:
    void maxProfit(vector<int>& prices);
};

// 股票买卖问题，允许进行k次操作（买和卖加起来算一次）
// #TODO
class Solution_188_solution {
public:
    void maxProfit(vector<int>& prices, int k);
};

// labuladong算法小抄
// 实现计算器
class calculator_solution {
public:
    void pre_process(string s);
    void calculator(queue<char> &s, stack<int> &stk, char &sign_out);

};
// labuladong算法小抄
/*
对于比较小的数字，做运算可以直接使用编程语言提供的运算符，但是如果相乘的两个因数非常大，
语言提供的数据类型可能就会溢出。一种替代方案就是，运算数以字符串的形式输入，
然后模仿我们小学学习的乘法算术过程计算出结果，并且也用字符串表示。
*/
class multiply_string_solution {
public:
    void multiply_string(string s1, string s2);
    void get_ten_one_posi(int temp1, int temp2, int &ten_posi, int &one_posi);

};

// 给出一个区间的集合，请合并所有重叠的区间
// leetcode_56
class merge_56_solution {
public:
    void merge(vector<vector<int>> &nums, vector<pair<int, int>> &ans);
};
// 给出两个区间，请输出两个区间的重叠部分
// leetcode_986
class intervalIntersection_986_solution {
public:
    void intervalIntersection(vector<vector<int>> &nums1, vector<vector<int>> &nums2);
};
// labuladong算法小抄
// 俄罗斯套娃，信封问题
class envelops_solution {
public:
    void envelops(vector<vector<int>> &nums);
};
// labuladong算法小抄
// 颜色填充问题 
class FloodFill_solution {
public:
    void floodfill(vector<vector<int>> &nums, int sr, int sc, int newcolor);
};
// labuladong算法小抄
// 二分查找高效判断子序列
class isSubsequence_solu {
public:
    void isSubsequence(string s1, string s2);
    void isSubsequence2(string s1, string s2);
};
// 脑筋急转弯
/*
如果我能赢，那么最后轮到我取石子的时候必须要剩下 1~3 颗石子，这样我才能一把拿完。
如何营造这样的一个局面呢？显然，如果对手拿的时候只剩 4 颗石子，那么无论他怎么拿，
总会剩下 1~3 颗石子，我就能赢。如何逼迫对手面对 4 颗石子呢？要想办法，
让我选择的时候还有 5~7 颗石子，这样的话我就有把握让对方不得不面对 4 颗石子。
如何营造 5~7 颗石子的局面呢？让对手面对 8 颗石子，无论他怎么拿，
都会给我剩下 5~7 颗，我就能赢。这样一直循环下去，我们发现只要踩到 4 的倍数，
就落入了圈套，永远逃不出 4 的倍数，而且一定会输。所以这道题的解法非常简单：
*/
class canWinNim_solu {
public:
    void canWinNim(int n);
};
// 三数之和
// 在一个数组中找3个数使得他们的和等于0
// leetcode_15
class ThreeSum_15_solution {
public:
    void ThreeSum(vector<int> &nums);
    void ThreeSum2(vector<int> &nums, int sum);
};
// 四数之和
// 在一个数组中找4个数使得他们的和等于target
class FourSum_18_solution {
public:
    void FourSum(vector<int> &nums, int sum);
};

// 最接近的三个数之和
// 
class ThreeSumClosest_16_solution {
public:
    void ThreeSumClosest(vector<int> &nums, int target);
};
// 盛最多水的容器
// leetcode_11
class maxArea_11_solution {
public:
    // 暴力法
    void maxArea(vector<int> &nums);
    // 备忘录法
    void maxArea2(vector<int> &nums);
    // 双指针法
    void maxArea3(vector<int> &nums);
};
// labuladong算法小抄
// 用栈实现队列，用双栈实现队列
class Stack_2_queue_solution {
public:
    // 将一个元素添加到队尾
    void push(int x);
    // 删除队头元素并返回
    int pop();
    // 返回队头元素
    int peek();
    // 判断元素是否为空
    bool empty();
    // 用于存放场景
    stack<int> s1;
    // 用于取出场景
    stack<int> s2;
};
// // labuladong算法小抄
// 用队列实现栈，用队列实现栈
class Queue_2_stack_solution {
public:
    void push(int x);
    int pop();
    int top();
    bool empty();
    queue<int> queue1;
    int top_element;
};
// 最长回文子串 leetcode_5
class longestPalindrome_5_solution {
public:
    void longestPalindrome(string s);
    void longestPalindrome2(string s);
    // 二维降低为一维
    void longestPalindrome3(string s);

};

// 正则表达式 leetcode_10
class isMatch_10_solution {
public:
    // 动态规划
    bool isMatch(string &s, string &p);
};

// 搜索旋转排序数组 leetcode_33
class search_33_solution {
public:
    int search(vector<int> &nums, int target);

};
// 搜索旋转数组 leetcode_81

class search_81_solution {
public:
    bool search(const vector<int> &nums, const int target);
};

// 字符相乘 leetcode_43
class multiply_43_solution {
public:
    void multiply(string num1, string nums2);
    void get_ten_one_posi(int temp1, int temp2, 
                          int &ten_posi, int &one_posi);
};

// 螺旋矩阵 leetcode_54
class spiralOrder_54_solution {
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix);
};
// 螺旋矩阵2 leetcode_59
class generateMatrix_59_solution {
public:
    vector<vector<int>> generateMatrix(int n);
};
// 插入区间，leetcode_57
class insert_57_solution {
public:
    vector<vector<int>> insert(vector<vector<int>> &matrix, vector<int> &new_matrix);
    bool cover(vector<int> &matrix1, vector<int> &matrix2, vector<int> &ans);
    void PrintMatrix(vector<int> &matrix);
};
// 第k个排列 leetcode_60
class getPermutation_60_solution {
public:
    string gerPermutation(int n, int k);
    bool Is_k_valide(int n, int k);

    void DFS(vector<int> &nums, vector<int> &temp, vector<vector<int>> &res, 
             vector<int>::size_type cursize, vector<bool> &visited);

};
// 
// 矩阵置0 leetcode_73
class setZero_73_solution {
public:
    void setZero(vector<vector<int>> &matrix);
};

// 组合 leetcode_77
class combine_77_solution {
public:
    // 从1到n, k个数的组合，不需要顺序
    vector<vector<int>> combine(int n, int k);
    void DFS(int &cur_posi, int n, int k, vector<int> &temp, 
        vector<bool> &used, vector<vector<int>> &ans);
    /// way_2
    vector<vector<int>> combine2(int n, int k);
    void trackback(int i, vector<bool> &vis, int n, int k, int len);
private:
    vector<int> temp;
    vector<vector<int>> ans;
};

// 子集 leetcode_78
class subsets_78_solution {
public:
    vector<vector<int>> subsets(vector<int> &nums);
    void DFS(int start, vector<int> &temp, const vector<int> &nums);
private:
    vector<vector<int>> ans;
    vector<int> temp;

};
// 排列 
class permute_solution {
public:
    vector<vector< pair<int, int> >> permute(vector<int> &nums);
    void DFS(vector<int> &nums, vector<bool> &used);
private:
    vector<vector< pair<int, int> >> ans;
    vector<pair<int, int>> temp;
};

// 三角形最小路径和 leetcode_120
class minimumTotal_120_solution {
public:
    vector<int> minimumTotal(vector<vector<int>> &triangle);
};

// leetcode_85 最大矩形
class maximalRectangle_85_solution {
public:
    int maxmalRectangle(vector<vector<int>> &matrix);
};