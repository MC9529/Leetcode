
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