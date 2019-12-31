
#include <iostream>
#include <vector>
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