
#include <iostream>
#include <vector>
#include "BiTree.h"
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
    void DFS(vector<vector<int>> &route, vector<int> &temp, vector<int> &start, vector<int> &target);
    
    
};

///动态规划 不同路径2  63

class uniquePathsWithObstacles_63_Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid);
    void DFS(vector<vector<int>> &route, vector<int> &temp, vector<int> &start, 
       vector<int> &target, vector<vector<int>> &obstacleGrid);
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
    int kthSmallest(vector<vector<int>> &matrix, int k);
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