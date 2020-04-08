#include "solution.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <functional>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <cstring>
#include <stdlib.h>
#include <limits.h>
using namespace std;

///回溯算法
/////////////////////////////////////////////////////////////////////////////////
//// permute_46
vector<vector<int>> Permute_46_Solution::permute(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> temp;
        vector<vector<int>> res;
        vector<bool> visited(n, false);
        DFS(nums, temp, res, 0, visited );
        return res;
        
}
void Permute_46_Solution::DFS(vector<int> &nums, vector<int> &temp, vector<vector<int>> &res, vector<int>::size_type cursize, vector<bool> &visited)
{
    if(cursize == nums.size())
    {
        res.push_back(temp);
        return;
    }
    for(vector<int>::size_type i = 0; i< nums.size(); i++)
    {
        if(!visited[i]){
            temp.push_back(nums[i]);
            visited[i] = true;
            DFS(nums, temp, res, cursize+1, visited);
            temp.pop_back();
            visited[i] = false;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////
////  NQueue_51

vector<vector<string>> sloveNQueue_51_Solution::sloveNQueue(int n){
    vector<vector<string>> res;
    vector<string> temp;
    vector<int> route;
    string temp_char;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            temp_char.push_back('.');
        }
        temp.push_back(temp_char);
    }
    for(int i =0; i< n; i++){
        for(int j= 0; j<n; j++){
            std::cout << temp[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    DFS(res, temp, n, 0, route);
    return res;
}

void sloveNQueue_51_Solution::DFS(vector<vector<string>> &res, vector<string> &temp, 
    int n, int curRow, vector<int> route){
    if((int)route.size() == n){
        for (int i =0; i<n; i++){
            for(int j=0; j< n; j++){
            std::cout << temp[i][j];
            }
            std::cout << std::endl;
        }
        res.push_back(temp);
        //temp.clear();
        for(vector<int>::size_type i =0; i<route.size(); i++){
            std::cout << route[i];
        }
        std::cout << std::endl;
        route.clear();
        return;
    }
    for(int i =0; i< n; i++){
        if(valid(route, i)){
            route.push_back(i);
            temp[curRow][i] = 'Q';
            DFS(res, temp, n, curRow + 1, route);
            route.pop_back();
            temp[curRow][i] = '.';
        }
    }

}
bool sloveNQueue_51_Solution::valid(vector<int> route, int n){
    if(route.size() < 1) return true;
    int row = route.size();
    //int col = route.back();
    for(int i =0; i < row; i++){
        int c = route[i];
        if(c == n||abs(c-n)==abs(i-row)){
            return false;
        }
    }
    return true;
}
////////////////
/////totalNQueue_52
int totalNQueue_52_Solution::totalNQueue(int n)
{
    vector<vector<int>> res;
    vector<int> temp;
    DFS(res, temp, n, 0);

    return (int)res.size();
}

void totalNQueue_52_Solution::DFS(vector<vector<int>> &res, vector<int> &temp, int n, int curRow){
    if((int)temp.size() == n){
        res.push_back(temp);
        //temp.clear();
        return;
    }
    for(int i = 0; i < n; i++){
        if(valid(temp, i)){
            temp.push_back(i);
            DFS(res, temp, n, curRow + 1);
            temp.pop_back();
        }
    }

}
bool totalNQueue_52_Solution::valid(vector<int> temp, int n){
    int row = temp.size();
    if(row < 1) return true;
    for(int j = 0; j < row; j++){
        int c = temp[j];
        if(c == n||abs(c - n) == abs(j - row)){
            return false;
        }
    }
    return true;
}

//////////

vector<string> generateParenthesis_22_Solution::generateParenthesis(int n){
    vector<string> res;
    string temp;
    //string s="()";
    DFS(res, temp, 0, n);

    return res;
}

void generateParenthesis_22_Solution::DFS(vector<string> &res, string &temp, 
        int num, int n){
    if((int)temp.size() == 2 *n && num == 0){
        res.push_back(temp);
        return ;
    }
    if((int)num < 0||((int)temp.size() == 2*n && num != 0)){
        return ;
    }
    int v1 = num + 1;
    int v2 = num - 1;
    temp.push_back('(');
    string temp1 = temp;
    temp.pop_back();
    temp.push_back(')');
    string temp2 = temp;
    DFS(res, temp1, v1, n);
    DFS(res, temp2, v2, n);
}
/////////////////解数独
void SuDu_37_Solution::solveSuDu(vector<vector<char>> &board)
{
    const int N = 10;
    vector<vector<int>> rows(N, vector<int>(N, 0));
    vector<vector<int>> cols(N, vector<int>(N, 0));
    vector<vector<int>> cell(N, vector<int>(N, 0));
    for(int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            if(board[i][j]=='.') continue;
            int n = board[i][j]-'0';
            int k = i / 3 * 3 + j / 3;
            cell[k][n] = 1;
            rows[i][n] = 1;
            cols[j][n] = 1;
        }
    }
    vector<vector<char>> res(board);
    DFS(board, rows, cols, cell, 0, 0, res);
    swap(res, board);
    
}

void SuDu_37_Solution::DFS(vector<vector<char>> &board, vector<vector<int>> &rows, vector<vector<int>> &cols, 
        vector<vector<int>> &cell, int i, int j, vector<vector<char>> &res){
    if(i * 9 + j == 81){
        res = board;
        return;
    }
    int k = i / 3 * 3 + j / 3;  ///第几个cell
    int t = i * 9 + j + 1;   //下一个
    int r = t / 9;    //下一个在第几行
    int c = t % 9;   //下一个在第几列
    if(board[i][j] != '.'){  ////有数
        DFS(board, rows, cols, cell, r, c, res); //下一个
        return;
    }
    for(int num = 1; num <= 9; num++){
        if(rows[i][num] != 1 && cols[j][num] != 1 && cell[k][num] != 1){ ///行列块都满足。
            rows[i][num] = cols[j][num] = cell[k][num] = 1;
            board[i][j] = num + '0';
            DFS(board, rows, cols, cell, r, c, res);
            rows[i][num] = cols[j][num] = cell[k][num] = 0;
            board[i][j] = '.';
        }
    }
}


////////组合总和  每个数值可以使用多次

vector<vector<int>> combinationSum_39_Solution::combinationSum(vector<int>& candidates, 
         int target){
    int sum = target;
    vector<vector<int>> res;
    vector<int> temp;
    //sort(candidates.begin(), candidates.end());
    DFS(res, temp, candidates, target, sum, 0);
    return res;
}
void combinationSum_39_Solution::DFS(vector<vector<int>> &res, vector<int> &temp, 
         vector<int> candidates, int target, int sum, int posi){
    if(accumulate(temp.begin(),temp.end(),0) == sum){
        res.push_back(temp);
        return;
    }
    for(int i = posi ; i< (int)candidates.size(); i++){
        if(target>0){
            target = target - candidates[i];
            temp.push_back(candidates[i]);
            //DFS(res, temp, candidates, target, sum, i + 1);
            DFS(res, temp, candidates, target, sum, i); ///又从相同位置出发
            target = target + candidates[i];
            temp.pop_back();
        }
    }
}

////////组合总和  每个数值只能使用1次

vector<vector<int>> combinationSum_40_Solution::combinationSum2(vector<int>& candidates, 
         int target){
    int sum = target;
    vector<vector<int>> res;
    vector<int> temp;
    sort(candidates.begin(), candidates.end());
    //vector<int> used((int)candidates.size(), 0); //标记是否用过
    DFS2(res, temp, candidates, target, sum, 0);
    ///v.erase(unique(v.begin(), v.end()), v.end());
    //res.erase(unique(res.begin(), res.end(), res.end()));

    return res;
}
void combinationSum_40_Solution::DFS2(vector<vector<int>> &res, vector<int> &temp, 
         vector<int> candidates, int target, int sum, int posi){
    if(accumulate(temp.begin(),temp.end(),0) == sum){
        res.push_back(temp);
        //used((int)candidates.size(), 0);
        return;
    }
    for(int i = posi ; i< (int)candidates.size(); i++){
        /*if(used[i]== 1){
            DFS2(res, temp, candidates, target, sum, i + 1);
            continue;
        }*/
        if(i > posi && candidates[i]==candidates[i-1]) continue; ///如果当前这个数和上一个数相等， 则跳过
        if(target > 0){
            target = target - candidates[i];
            temp.push_back(candidates[i]);
            //used[i] = 1;
            DFS2(res, temp, candidates, target, sum, i + 1); //从下一个位置出发
            //DFS2(res, temp, candidates, target, sum, i);
            target = target + candidates[i];
            temp.pop_back();
            //used[i] = 0;
        }
    }
}

////// 单词搜索， 79 

bool Search_79_Solution::solve1(vector<vector<char>>& board, string word)
{
    vector<vector<bool>> used(board.size(), vector<bool>(board[0].size(), false));
   for(int i = 0; i < board.size(); i++){
       for(int j = 0; j < board[0].size(); j++){
           if(board[i][j]= word[0] && DFS(board, i, j, word, 0, used)){
               return true;
           }
       }
   }
   return false;
}
bool Search_79_Solution::DFS(vector<vector<char>> &board, int i, int j, string word, 
   int length, vector<vector<bool>> &used){
    if(i >= board.size() || j >= board[0].size() || length >= word.size() 
    || board[i][j] != word[length] ||used[i][j]){
        return false;
    }
    else if(length = word.size() - 1 && board[i][j] == word[length]){
        return true;
    }
    else{
        used[i][j] = true;
        bool m1 = DFS(board, i - 1, j, word, length + 1, used);
        if(m1) return true;
        bool m2 = DFS(board, i + 1, j, word, length + 1, used);
        if(m2) return true;
        bool m3 = DFS(board, i, j + 1, word, length + 1, used);
        if(m3) return true;
        bool m4 = DFS(board, i, j - 1, word, length + 1, used);
        if(m4) return true;
        used[i][j] = false;
        return false;
    }

}


///////子集 90

vector<vector<int>> subset_90_Solution::solve(vector<int> &nums){
    vector<vector<int>> res;
    vector<int> temp;
    res.push_back({});
    sort(nums.begin(), nums.end());
    for(int i = 1; i <= nums.size(); i++){
        DFS(temp, res, nums, i, 0);
    }

    return res;


}
void subset_90_Solution::DFS(vector<int> &temp, vector<vector<int>> &res, vector<int> nums, int len, int posi){
       if(temp.size() == len){
        int flag = 0;
        for(int i = 0; i < res.size(); i++){
            if(temp == res[i]){
                 flag = 1;
            }
        }
        if(flag == 0) res.push_back(temp);
        //temp.clear();
        //DFS(temp, res, nums, len, posi + 1);
        return;
    }
    for(int i = posi; i < nums.size(); i++){
        if((nums[i] == nums[i-1] && i > posi) ){
            continue;
        }
        temp.push_back(nums[i]);
        DFS(temp, res, nums, len, i + 1);
        temp.pop_back();
    }
}
////有效括号
 bool isValid_20_Solution::isValid(string s){
     if(s.empty()) return true;
     stack<char> temp;
     //int posi = 0;
     temp.push(s[0]);
     //cout << "pass in 374" << endl;
     for(int i = 1; i < s.size(); i++){
        if(temp.empty()){
            temp.push(s[i]);
        }
        else if(compare(temp.top(), s[i])){
             temp.pop();
             //cout << "pass in 378" << endl;
             
        }
        else{
        temp.push(s[i]);
        //cout << "pass in 382" << endl;
        }
     }
     //return temp.empty();
     cout << "the size of temp :" << temp.size()<<endl;
     //return temp.size() == 0? true:false;
     return temp.empty();
 }

 bool isValid_20_Solution::compare(char &c1, char &c2){
     return(c1=='['&&c2==']'||c1=='{'&&c2=='}'||c1=='('&&c2==')');

}

///动态规划 不同路径1  62
/////
int uniquePaths_62_Solution::uniquePaths(int m, int n){
     /// m -> col   n -> row
    int res;
    vector<vector<int>> route;
    vector<int> temp;  ////0  代表向右移动， 1 代表向下移动
    vector<int> start = {0, 0};
    vector<int> target = {n - 1, m - 1};

    DFS(route, temp, start, target);
    for(int i =0; i < route.size(); i++){
        for(auto iter : route[i]){
            cout << iter << " ";
        }
        cout << endl;
    }
    cout << endl;
    res = route.size();
    return res;
}
void uniquePaths_62_Solution::DFS(vector<vector<int>> &route, vector<int> &temp,
     vector<int> &start, vector<int> &target){
    if((start[1] == target[1]) && (start[0] == target[0]))
    {
        route.push_back(temp);
        //temp.clear();
        return;
    }
    if( ((start[1] > target[1]) || (start[0] > target[0])) ){
            //temp.clear();
            return;
    }
    for(int i = 0; i < 2; i++){
        if(i == 0){
        start [1] = start [1] + 1;
        temp.push_back(0);
        DFS(route, temp, start, target);
        start [1] = start [1] - 1;
        temp.pop_back();
        }

        if( i == 1){
        start [0] = start [0] + 1;
        temp.push_back(1);
        DFS(route, temp, start, target);
        start [0] = start [0] - 1;
        temp.pop_back();
        }
    }
}

///动态规划 不同路径2  63
/////

int uniquePathsWithObstacles_63_Solution::uniquePathsWithObstacles(
    vector<vector<int>> &obstacleGrid){
    if(obstacleGrid.size() == 1 && obstacleGrid[0].size() == 1) return 0;
    int res;
    vector<vector<int>> route;
    vector<int> temp;  ////0  代表向右移动， 1 代表向下移动
    vector<int> start = {0, 0};
    int n = obstacleGrid.size();
    int m = obstacleGrid[0].size();
    vector<int> target = {n - 1, m - 1};
    DFS(route, temp, start, target, obstacleGrid);
    for(int i =0; i < route.size(); i++){
        for(auto iter : route[i]){
            cout << iter << " ";
        }
        cout << endl;
    }
    cout << endl;
    res = route.size();
    return res;
}
void uniquePathsWithObstacles_63_Solution::DFS(
    vector<vector<int>> &route, vector<int> &temp, vector<int> &start, vector<int> &target, 
    vector<vector<int>> &obstacleGrid){
    //cout << "the first in 482 :" << obstacleGrid[0][0] << endl;
    if((start[1] == target[1]) && (start[0] == target[0])) 
    {
        route.push_back(temp);
        //temp.clear();
        return;
    }
    if( ((start[1] > target[1]) || (start[0] > target[0])) ){
            //temp.clear();
        return;
    }
    for(int i = 0; i < 2; i++){
        int row = start[0];
        int col = start[1];
        if(i == 0 && col + 1 < obstacleGrid[0].size()){
        if(obstacleGrid[row][col + 1] == 0)
        {
        start [1] = start [1] + 1;
        temp.push_back(0);
        DFS(route, temp, start, target, obstacleGrid);
        start [1] = start [1] - 1;
        temp.pop_back();
        }
        }
        if( i == 1  && row + 1 < obstacleGrid.size()){
        if((obstacleGrid[row + 1][col] == 0))
        {
        start [0] = start [0] + 1;
        temp.push_back(1);
        DFS(route, temp, start, target, obstacleGrid);
        start [0] = start [0] - 1;
        temp.pop_back();
        }
        }
    }
}

///////最大子序列   LeetCode 53  并且记录所在位置
int maxSubArray_53_Solution::maxSubArray(vector<int> &nums){
    int res;
    vector<int> temp;  //记录加入的数
    DFS(nums, temp, res);

    for(int i = 0; i < temp.size(); i++){
        cout << temp[i] << " ";
    }
    cout << endl;

    return res;
}

void maxSubArray_53_Solution::DFS(vector<int> nums, vector<int> &temp, int &res){
    int len = nums.size();
    int result = 0;
    vector<int> dp(len); ///以nums[i]为结尾的最大子序列
    dp[0] = nums[0];  ///以nums[i]为结尾的最大子序列
    result = dp[0];
    int result_i = 0;
    temp.push_back(nums[0]);
    for(int i = 1; i < len; i++){

        if(dp[i-1] + nums[i] > nums[i]){
            temp.push_back(nums[i]);  ///新产生的dp[i]（dp[i-1] + nums[i]）比nums[i]大，将nums[i]加入到temp中
        }
        else{   
        //新产生的dp[i]（dp[i-1] + nums[i]）比nums[i]小，将nums[i]作为最大子序列，其他去除
            temp.clear();
            temp.push_back(nums[i]);
        }
        dp[i] = max(dp[i-1] + nums[i], nums[i]);  ///产生最大的子序列
        if(result > dp[i]){
        ////新产生的子序列没有原来的大，将新加入的nums[i]去除
            temp.pop_back(); 
        }
        else{
            /////新产生的子序列比原来的大，但是发现从result所在的位置，到dp[i]存在间距，
            ////需要将中间的nums加入，并且dp[i]不是仅仅由nums[i]组成
            if(i - result_i > 1 && dp[i] != nums[i]){  ////
                temp.pop_back();
                for(int j = result_i + 1; j < i ; j++){
                    temp.push_back(nums[j]);
                }
                temp.push_back(nums[i]);
            }
            result_i = i; ///记录result所在的位置
            //cout << result_i << " ";
        }
        result = max(result, dp[i]);
    }
    res = result;
}

int minPathSum_64_Solution::minPathSum(vector<vector<int>>& grid){
    int min_len;
    vector<vector<int>> min_path;
    vector<int> route;
    min_path = grid;
    DFS(grid, min_len, min_path, route);
    cout << "the route: " << endl;
    for(int i = 0; i < route.size(); i++){
        cout << route[i] << " ";
    }
    cout << endl;
    return min_len;


}
void minPathSum_64_Solution::DFS(vector<vector<int>> grid, 
         int &min_len, vector<vector<int>> &min_path, vector<int> &route){
    for(int i = grid.size() - 1; i >= 0; i --){
        for(int j = grid[0].size() - 1; j >= 0 ; j--){
            if( i == grid.size() - 1 && j != grid[0].size()- 1 ){
                min_path[i][j] = grid [i][j] + min_path[i][j + 1];
            }
            else if( i != grid.size() - 1 && j == grid[0].size()- 1 ){
                min_path[i][j] = grid [i][j] + min_path[i + 1][j];
            }
            else if(i != grid.size() - 1 && j != grid[0].size()- 1){
                min_path[i][j] = grid[i][j] + min(min_path[i][j+1], min_path[i+1][j]);
            }
            else{
                min_path[i][j] = grid[i][j];
                //route.push_back(grid[i][j]);
            }
        }
    }
    min_len = min_path[0][0];
    path(grid, min_path, route, 0, 0); ////记录路径
    return;
}

void minPathSum_64_Solution::path(vector<vector<int>> grid, vector<vector<int>> min_path, 
     vector<int> &route, int row, int col){
    route.push_back(grid[row][col]);
    while(row < min_path.size() && col < min_path[0].size()){
        //route.push_back(grid[row][col]);
        if(row == min_path.size() - 1 && col < min_path[0].size()){  ///达到下边界， 只能向右走
            for(int i = col + 1; i < min_path[0].size(); i++){
                route.push_back(grid[row][i]);
            }
            return;
        } 
        if(row < min_path.size() && col == min_path[0].size() - 1){  ///到达右边界，只能向下走
            for(int j = row + 1; j < min_path.size(); j ++){
                route.push_back(grid[j][col]);
            }
            return;
        }

        if(min_path[row + 1][col] > min_path[row][col + 1]){ //向右走小
            route.push_back(grid[row][col + 1]);
            col++;
        }
        else{ ////向下走小
            route.push_back(grid[row][col]);
            row ++;
        }
    }
    return;
}

/// 爬楼梯 leetcode _70
int climbStair_70_Solution::climbStairs(int n){
    int res;
    vector<int> temp;;
    vector<vector<int>> route;
    int count = 0;
    DFS(n, route, temp, count);

    for(int i = 0; i < route.size(); i++){
        for(auto iter : route[i]){
            cout << iter << " ";
        }
        cout << endl;
    }
    cout << endl;
    res = route.size();
    return res;
}
void climbStair_70_Solution::DFS(int n, vector<vector<int>> &route, vector<int> &temp, int &count){
    if(n == 0){
        route.push_back(temp);
        //temp.clear();
        return;
    }
    if(n == 1) {
        temp.push_back(1);
        DFS(0, route, temp, count);
        //route.push_back(temp);
        //return;
    }
    if(n == 2){
        temp.push_back(2);
        //route.push_back(temp);
        DFS(0, route, temp, count);
        temp.pop_back();
        temp.push_back(1);
        DFS(1, route, temp, count);
        //count = count + 2;
    }
    if(n > 2){

        temp.push_back(2);
        vector<int> temp1 = temp;
        DFS(n - 2, route, temp, count);

        temp1.pop_back();
        //temp.push_back(2);
        //int g = n -1;
        temp1.push_back(1);
        DFS(n -1 , route, temp1, count);
    }
}
////解码方法  leetcode_91
int numDecodings_91_Solution::numDecoding(string s){
    int res;
    vector<string> str;
    string str_temp;
    int res_len = 0;
    DFS(s, str, str_temp, res_len);
    res = str.size();
    for(int i = 0; i < res; i++){
        cout << str[i] << " ";
    }
    cout << endl;
    return res;
}
void numDecodings_91_Solution::DFS(string s, vector<string> &str, string &str_temp, int &res_len){
    if (res_len == s.size()){
        str.push_back(str_temp);
        return;
    }
    for(int i = res_len; i < s.size(); i++){
        if((int)s[i] > 0){
            str_temp.push_back('A' + ((int)s[i] - 1));
            res_len ++ ;
            DFS(s, str, str_temp, res_len);

        }
    }
}
 void numDecodings_91_Solution::print(vector<string> str){
     int len = str.size();
     cout << "the str: ";
     for(int i = 0; i < len; i++){
         cout << str[i];
     }
     cout << endl;
 }

///贪心算法， 跳跃游戏 , leetcode_45_and_55
bool jump_45_Solution::jump(vector<int> &nums){
    vector<int> path;
    int current = 0;
    int end = 1;
    bool res;
    DFS(nums, path, current, end, res);
    for(int i = 0; i < path.size(); i++){
        cout << path[i] << " ";
    }
    cout << endl;
    return res;

}
void jump_45_Solution::DFS(vector<int> nums, vector<int> &path, int &current, int &end, bool &res){
    
    if(current >= nums.size()-1){
        res = true;
        return;
    }
    if(nums[current] == 0 && current < nums.size()-1){ ///该位置的值为0, 且还没有到终点
        cout << "can not reache the last point" << endl;
        res = false;
        return;
    }
    int next = current_best_path(current, nums, end); //绝对位置
    //cout << "the next:" << next;
    current = next; 
    path.push_back(next);
    DFS(nums, path, current, end, res);

}

int jump_45_Solution::current_best_path(int current, vector<int> nums, int end){
    int best = 0;
    int posi = 0;
    if(current + nums[current] >= nums.size()-1){
        posi = nums.size() - 1;
        return posi;
    }
    for(int i = 1; i <= nums[current]; i++){
        if((current + i) < nums.size()){ //找下一个位置
            if(nums[current + i] + current + i >= best){  ///比较哪个位置能到达更远的位置
                best = nums[current + i] + current + i;
                posi = current + i;
            }
        }
    }

    //cout << "the posi :" << posi;
    return posi; //绝对位置
}
///贪心算法， 买卖股票的最佳时机, leetcode_122
int maxProfit_122_Solution::maxProfit(vector<int>& prices){
    vector<vector<int>> way;//买卖股票的方法， 什么时候买入， 什么时候卖出
    int res = 0;
    int buy = 0; // 买入价格
    int sell = 1; //卖出价格     
    int temp; //某次买卖的利润
    vector<int> temp_way; //用于存储某次买卖的买入和卖出
    if(prices.size() == 0){
        return 0;
    }
    for(int i = 1; i < prices.size() - 1; i++){
        if(prices[i] < prices[buy]){
        //选择第一次小于第一天的价格为买入价格， 
        //如果一直大于第一天价格， 则以第一天价格买入
            buy = i;
            cout << "the buy :" << buy << endl;
        }
        break;
    }
    DFS(res, way, prices, buy, sell, temp, temp_way);
    if(way.size() >= 1){
    for(int i = 0; i < way.size(); i++){
        for(auto iter : way[i]){
            cout << iter << " ";
        }
        cout << endl;
    }
    }

    return res;
}
void maxProfit_122_Solution::DFS(int &res, vector<vector<int>> &way, vector<int> prices,
    int &buy, int &sell, int &temp, vector<int> &temp_way){

        for(int i = buy  + 1; i < prices.size(); i++){
            cout << "the i : " << i << endl;
            temp = prices[i] - prices[i - 1]; //某一天价格和前一天比
            if(temp > 0){ //上涨则不卖出
                res = res + temp;
                if(i == prices.size() - 1){
                    temp_way.push_back(buy);
                    temp_way.push_back(i);
                    way.push_back(temp_way);
                    temp_way.clear();
                }
            }
            ///不涨， 卖出
            else{
                //判断是不是一直不涨
                if(res > 0){
                temp_way.push_back(buy);
                temp_way.push_back(i-1);
                cout << "the buy:" << buy << " " << "the sell: " << i-1 << endl;
                way.push_back(temp_way);
                temp_way.clear();
                buy = i;
                }
            }
        }

        return;
}
///贪心算法， 加油站 leetcode_134
int canCompleteCircuit_134_Solution::canCompleteCircuit(vector<int>& gas, 
     vector<int>& cost){
    int res = -1; //假设不能
    int start = 0; 
    int res_gas; //剩余汽油
    for(int i = 0; i < gas.size(); i++){
        //寻找能够出发的点
        if(cost[i] <= gas [i]){
            start = i;
            cout << "the start: " << start << endl; 
            res_gas = gas[start];
            cout << "the res_gas:" << res_gas << endl;
            ///开始尝试
            DFS(start, gas, cost, res, res_gas);
        }

        ///找到第一个可以到的,退出
        if(res != -1){ 
            break;
        }
    }

    return res;

}
void canCompleteCircuit_134_Solution::DFS(int start, vector<int> gas, 
     vector<int> cost, int &res, int &res_gas){
         for(int i = 1; i < gas.size() + 1; i++){
             int posi = start + i;
             int posi_before = posi - 1;
             ///过了末尾油站
             actual_posi(posi, gas);
             actual_posi(posi_before, gas);
             cout << "the posi :" << posi << endl;
             ///够不够去下一站
             if(res_gas < cost[posi_before]){
                 res = -1;
                 cout << "you are in posi " << posi << endl;
                 cout << "the res_gas: " << res_gas <<" "<< "you need: " << cost[posi_before] << endl;
                 return;

             }
             res_gas = res_gas - cost[posi_before] + gas[posi];
             cout << "the res_gas:" << res_gas << endl;

             if(res_gas >= 0 && posi == start){
                 res = start;
                 return;
             }

    }
}

void canCompleteCircuit_134_Solution::actual_posi(int &posi, vector<int> &gas){
    if(posi > gas.size() - 1){
        posi = posi - gas.size();
    }

}

////贪心算法， leetcode_135
int candy_135_Solution::candy(vector<int>& ratings){
    int res = 0;
    vector<int> candies(ratings.size(), 1);
    DFS(ratings, candies);
    for(int i = 0; i < candies.size(); i++){
        cout << candies[i] << " ";
    }
    cout << endl;
    res = accumulate(candies.begin(), candies.end(), 0);
    return res;

}
void candy_135_Solution::DFS(vector<int> ratings, vector<int> &candies){
    ///下面有+1,所以得-1
    for(int i = 0; i < ratings.size() - 1; i++){
        if(ratings[i] > ratings[i + 1]){
            if(candies[i] <= candies[i + 1]){
            candies[i] = candies[i+1] + 1;
            }
        }
        if(ratings[i] < ratings[i + 1]){
            if(candies[i] >= candies[i + 1]){
                candies[i + 1] = candies[i] + 1;
            }

        }
    }
    for(int j = ratings.size() - 1; j > 0; j--){
        if(ratings[j] > ratings[j - 1]){
            if(candies[j] <= candies[j - 1]){
            candies[j] = candies[j-1] + 1;
            }
        }
        if(ratings[j] < ratings[j - 1]){
            if(candies[j] >= candies[j - 1]){
            candies[j - 1] = candies[j] + 1;
            }
        }
    }
}

///分而治之 leetcode_23
vector<vector<int>> mergeLise_23_solution::merge_list(vector<vector<int>> &list){
    vector<vector<int>> res;
    int len = list.size();
    if (len == 0) {
        return list;
    }
    if (len == 1 ){
        return list;
    }
    int interval = 1;
    while (interval < len) {
        for (int i = 0; i < len - interval; i = i + interval * 2) {
            vector<int> vector_i_temp = list[i];
            vector<int> vector_i_interval_temp = list[i + interval];
            list[i].clear();
            list[i + interval].clear();
            list[i] = merge2(vector_i_temp, vector_i_interval_temp);
        }
        //cout << "pass in loop:" << interval;
        interval = interval * 2;
    }
    res.push_back(list[0]);
    
    return res;
}
vector<int> mergeLise_23_solution::merge2(vector<int> list1, vector<int> list2){
    vector<int> res;
    int len1 = list1.size();
    int len2 = list2.size();
    int i = 0, j = 0;
    while(i < len1 && j < len2){
        if (list1 [i] < list2 [j]){
            res.push_back(list1[i]);
            i ++;
        }
        else {
            res.push_back(list2[j]);
            j ++;
        }

    }
    //如果还剩下部分
    if (i < len1){
        for (int k = i; k < len1; ++k){
            res.push_back(list1[k]);
        }
    }
    //如果还剩下部分
    if (j < len2){
        for (int l = j; l < len2; ++l){
            res.push_back(list2[l]);
        }
    }
    return res;
}

int findKthLargest_215_solution::findKthLargest(vector<int> &nums, int k) {
    int result = 0;
        int numsSize = int(nums.size());
        if (numsSize == 0 || k > numsSize)
        {
            return 0;
        }
        priority_queue<int, vector<int>, greater<int>> store;
        //堆中维持k个最大数
        for (int i = 0; i < numsSize; i++)
        {
            store.push(nums[i]);
            if (int(store.size()) > k)
            {
                store.pop();
            }
        }
        result = store.top();
        return result;
}

int findKthLargest_215_solution::findKthLargest2(vector<int> &nums, int k){
    vector<int> store;
    store.assign(nums.begin(), nums.end());
    make_heap(begin(store), end(store), greater<int>());
    while (store.size() > k) {
        ////删除前先要pop_heap,然后在删除
        pop_heap(begin(store), end(store), greater<int>());
        store.pop_back();
    }
    auto flag = is_heap(begin(store), end(store), greater<int>());
    if (flag) {
        cout << "this is a heap" << endl;
    } else {
        cout << "this is not a heap" << endl;
    }

    for (int i = 0 ; i < store.size(); ++i) {
        cout << store[i] << " ";
    }
    cout << endl;
    ///对个小顶堆（greater<>）进行排序会达到大顶堆
    sort_heap(begin(store), end(store), greater<int>());
    for (int i = 0 ; i < store.size(); ++i) {
        cout << store[i] << " ";
    }
    cout << endl;
    int res = store[store.size() - 1];
    return res;
}
//滑动窗口,Leetcode_239
void maxSlideWindow_239_solution::maxSlideWindow(vector<int> &nums, int k) {
    vector<int> res;
    vector<int> window;
    int max;
    if (nums.size() == 0 && k > nums.size()) {
        cout << "there is no enough number int nums" << endl;
        return;
    }
    window.assign(nums.begin(), nums.begin() + k);
    cout << "the first window:" << endl;
    for (int i = 0; i < window.size(); ++i) {
        cout << window[i] << " ";
    }
    cout << endl;
    for (int i = k - 1; i < nums.size(); ++i) {
        auto max_posi = max_element(window.begin(), window.end());
        res.push_back(*max_posi);

        window.erase(window.begin());
        window.push_back(nums[i + 1]);
    }
    cout << "the res :" << endl;
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return;
}

void maxSlideWindow_239_solution::maxSlideWindow_in_heap
                               (vector<int> &nums, int k){
    if (nums.size() == 0 && k > nums.size()) {
        cout << "there is no enough number int nums" << endl;
        return;
    }
    vector<int> res;
    priority_queue<int, vector<int>, less<int>> store;
        //堆中维持k个最大数
    for (int i = 0; i < k; i++)
    {
        store.push(nums[i]);
    }
    res.push_back(store.top());
    for (int i = k; i < nums.size(); ++i) {
        store.pop();
        store.push(nums[i]);
        res.push_back(store.top());
    }
    for (int i = 0; i < res.size() ; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return;

}

bool searchMatrix_240_solution::searchMatrix(vector<vector<int>> &matrix, 
                                            int target) {
    if (matrix.size() == 0 || target < matrix[0][0]) {
        cout << "the matrix size is 0 or the target < the matrix[0][0]" << endl;
        return false;
    }
    bool res = false;
    int row = matrix.size();
    int col = matrix[0].size();
    int binary_row = 0;
    DFS_rows(matrix, target, row, binary_row);
    cout << "the binary_row in 1128: " << binary_row << endl;
    DFS_cols(matrix, target, col, binary_row, res);
    if (!res) {
        cout << "there is no targer:" << target << "in this matirx" << endl;
    }
    return res;

}
///二分法找可以在那些找
void searchMatrix_240_solution::DFS_rows(vector<vector<int>> &matrix, 
                                   int target, int row, int &binary_row){
    if (matrix[row -1][0] <= target) {
        binary_row = row - 1;
        return;
    }
    int min = 0;
    int max = row - 1;
    int binary = (min + max + 1)/2; 
    while (!(matrix[binary + 1][0] > target && matrix[binary][0] <= target )) {
        if (matrix[binary][0] > target) {
            min = min;
            max = binary;
            binary = (min + max + 1)/2;
        }
        else if (matrix[binary][0] < target) {
            min = min;
            max = (binary + max)/2;
            binary = (min + max + 1)/2;
        }
        else {
            //cout << "the binary_row in 1154: " << binary << endl;
            binary_row = binary;
            break;
        }
    }
    binary_row = binary;
    //cout << "the binary_row in 1160:" << binary << endl;
    return;
}
///二分法在行找
void searchMatrix_240_solution::DFS_cols(vector<vector<int>> &matrix, int target, 
                                         int col, int binary_row, bool &res){
    for (int i = 0; i <= binary_row; ++i) {
        if (matrix[i][col - 1] < target) {
            continue;
        }
        int min = 0;
        int max = col - 1;
        int binary_col = (min + max)/2;
        while ( binary_col != min) {
            if (matrix[i][min] == target) {
                cout << "find the target :" << target << "in:" << i << " "
                     << "row" <<  " " << min << " "<<"col";
                res = true;
                return;
            }
            if (matrix[i][max] == target) {
                cout << "find the target :" << target << "in:" << i <<" "
                     << "row" << " " << max <<" "<< "col";
                res = true;
                return;
            }
            if (matrix[i][binary_col] == target) {
                cout << "find the target :" << target << "in:" << i <<" "
                     << "row" << " " << binary_col <<" "<< "col";
                res = true;
                return;
            }
            if (matrix[i][binary_col] > target) {
                min = min;
                max = binary_col;
                binary_col = (min + max)/2;
                cout << "pass in 1195" << endl;
            }
            else if (matrix[i][binary_col] < target) {
                min = binary_col;
                max = max;
                binary_col = (min + max)/2;
                /*
                cout << "i: " << i <<endl;
                cout << "min: " << min << endl;
                cout << "max: " << max << endl;
                cout << "binary: " <<binary_col << endl;
                cout << "pass in 1201" << endl;
                */
            }
        }
    }
    return;
}

///从尾部开始操作，将数插入nums_sorted,并排序，同时找到该数在那个位置，后减去nums_sorted.begin()
vector<int> countSmaller_315_solution::countSmaller1(vector<int> &nums){
    vector<int> nums_sorted;
    vector<int> res;
    //cout << "passed in 1223" << endl;
    for (int i = nums.size() - 1; i >= 0; i--) {
        nums_sorted.push_back(nums[i]);
        sort(nums_sorted.begin(), nums_sorted.end());
        //cout << "passed in 1226" << endl;
        auto iter = lower_bound(nums_sorted.begin(), nums_sorted.end(), nums[i]);
         //cout << "passed in 1228" << endl;
        int pos = iter - nums_sorted.begin();
         //cout << "passed in 1230" << endl;
        //nums_sorted.insert(iter, nums[i]);
        res.push_back(pos);
    }
    reverse(res.begin(), res.end());
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return res;
}
vector<int> countSmaller_315_solution::countSmaller2(vector<int> &nums){
    ///pair<nums[i],i>
    vector<pair<int, int>> v;
    v.reserve(nums.size());
    for (int i = 0; i < nums.size(); ++i) {
        v.emplace_back(nums[i], i);
    }
    vector<int> res(v.size());
    merge_sort(v, 0, v.size(), res);
    cout << "the sorted v.first:" << endl;
    for (int i = 0; i < v.size(); ++i) {
        cout << v[i].first << " ";
    }
    cout << endl;
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return res;
}
void countSmaller_315_solution::merge_sort(vector<pair<int, int>> &v, 
                                           int n, int m, vector<int> &res) {
    if (m - n <= 1) return;
    int mid = n + (m - n)/2;
    merge_sort(v, n, mid, res);
    merge_sort(v, mid, m, res);
    cout << "n: " << n << "mid: " << mid << "m: " << m << endl;
    int right = mid;
    for (int left = n; left < mid; ++left) {
        while (right != m && v[left] > v[right]) ++right;
        res[v[left].second] += right - mid;
    }
    inplace_merge(v.begin() + n, v.begin() + mid, v.begin() + m);
}

///排序  归并排序
void merge_sorted::mergesort(vector<int> &list, int n, int m) {
    if (n == m) {
        return;
    }
    int mid = (m + n)/2;
    mergesort(list, n, mid);
    mergesort(list, mid + 1, m);
    //inplace_merge(list.begin() + n, list.begin() + mid, list.begin() + m);
    merge(list, n, mid, m);
    /*
    for (int i = 0; i < list.size(); ++i) {
        cout << list[i] << " ";
    }
    cout << endl;
    */
    return;
}
/// 合并
void merge_sorted::merge(vector<int> &list, int l, int mid, int r) {
    vector<int> sorted_list;
    int lindex = l;
    int rindex = mid + 1;
    while (lindex <= mid && rindex <= r) {

        if  (list[lindex] <= list[rindex]) {
            sorted_list.push_back(list[lindex]);
            lindex ++;
        } else {
            sorted_list.push_back(list[rindex]);
            rindex ++;
        }
    }
    while (lindex <= mid) {
        int temp = list[lindex++];
        sorted_list.push_back(temp);
    }
    while (rindex <= r) {
        int temp = list[rindex++];
        sorted_list.push_back(temp);
    }
    for (int i = 0; i < sorted_list.size(); ++i) {
        cout << sorted_list[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < sorted_list.size(); ++i) {
        list[l+i] = sorted_list[i];
    }
    ///打印
    for (int i = 0; i < list.size(); ++i) {
        cout << list[i] << " ";
    }
    cout << endl;
    return;
}
///排序 快速排序（从小到大）
//小于base的放在base左边，所以从最右边开始找小于base的， 同时在最左边开始找大于base的，两者交换位置
void quick_sort::small2big(int left, int right, vector<int> &list) {
    if (left >= right) return;
    int i, j, base, temp;
    i = left, j = right;
    base = list[left];
    while (i < j) {
        //从右边找小于base的数
        while (list[j] >= base && i < j) {
            j--;
        }
        //从左边找大于base的数
        while (list[i] <= base && i < j) {
            i++;
        }
        //交换
        if  (i < j) {
            temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        }
    }
    //将base和 list交换位置
    list[left] = list[i];
    list[i] = base;
    small2big(left, i - 1, list);//递归左边
    small2big(i + 1, right, list); //递归右边
    return;
}
///排序 快速排序（从大到小）
//大于base的放在base左边，所以从最右边开始找大于base的， 同时在最左边开始找小于base的，两者交换位置
void quick_sort::big2small(int left, int right, vector<int> &list) {
    if (left >= right) return;
    int i, j, base, temp;
    i = left, j = right;
    base = list[left];
    while (i < j) {
        //从右边找大于base的数
        while (list[j] <= base && i < j) {
            j--;
        }
        //从左边找小于base的数
        while (list[i] >= base && i < j) {
            i++;
        }
        //小于和大于base的数交换位置
        if (i < j) {
            temp = list[i];
            list[i] = list[j];
            list[j] = temp;
        }
    }

    list[left] = list[i];
    list[i] = base;
    big2small(left, i - 1, list); //递归左边
    big2small(i + 1, right, list); //递归右边
    //打印
    return;
}
///前K个高频词 Leetcode_347
vector<int> topKFrequence_347_solution::topKFrequence(vector<int> &nums, 
    int k) {
    vector<int> res;
    unordered_map<int, int> count;
    for (int i = 0; i < nums.size(); ++i) {
        count[nums[i]] ++;
    } 
    vector<pair<int, int>> container(count.begin(), count.end());
    auto comp = [](const pair<int, int> val1, const pair<int, int> val2) { 
        return val1.second < val2.second;
    };
    make_heap(container.begin(), container.end(), comp);
    for (int i = 0; i < k; ++i) {
        res.push_back(container.begin()->first);
        pop_heap(container.begin(), container.end() - i, comp);
    }

    return res;
}
///////用哈希表统计，然后sort，然后自定规则排序
vector<int> topKFrequence_347_solution::topKFrequence2(vector<int> &nums, int k) {
    vector<int> res;
    unordered_map<int, int> count;
    for (int i = 0; i < nums.size(); ++i) {
        count[nums[i]] ++;
    } 
    //排序规则
    ///如果频率一样，则值大的放前面
    auto comp = [](const pair<int, int> val1, const pair<int, int> val2) {
        bool res;
        if (val1.second == val2.second) {
            return val1.first > val2.first;
        }
        return val1.second > val2.second;
    };
    //将map转化为vector
    vector<pair<int, int>> count_vector(count.begin(), count.end());
    //排序
    sort(count_vector.begin(), count_vector.end(), comp);
    for (int i = 0; i < count_vector.size(); ++i) {
        res.push_back(count_vector[i].first);
    }
    return res;
}
////查找和最小的k对数字
vector<vector<int>> kSmallestPairs_373_solution::kSmallestPairs(
                        vector<int> &list1, vector<int> &list2, int k) {
    vector<vector<int>> res;
    vector<int> temp;
    struct pair_list {
        int list1_num;
        int list2_num;
    };
    auto comp = [](const pair<int, pair_list> val1, const pair<int, pair_list> val2) {
        if (val1.first == val2.first) {
            return val1.second.list1_num > val2.second.list1_num;
        }
        return val1.first < val2.first;
    };

    pair_list pair_1_2;
    pair<int, pair_list> pair_sum_1_2;
    ////[ {list[i], list[j]}, list[i]+list[j] ]
    vector<pair<int, pair_list>> count;
    for (int i = 0; i < list1.size(); ++i) {
        for (int j = 0; j < list2.size(); ++j) {
            //second
            pair_1_2.list1_num = list1[i];
            pair_1_2.list2_num = list2[j];
            pair_sum_1_2.second = pair_1_2;
            //first
            pair_sum_1_2.first = list1[i] + list2[j];
            count.push_back(pair_sum_1_2);
        }
    }
    sort(count.begin(), count.end(), comp);
    for (int i = 0; i < k; ++i) {
        temp.push_back(count[i].second.list1_num);
        temp.push_back(count[i].second.list2_num);
        res.push_back(temp);
    }

    return res;
}
/*
 vector<vector<int>> kSmallestPairs_373_solution::kSmallestPairs2(
                        vector<int> &list1, vector<int> &list2, int k) {
    vector<vector<int>> res;
    vector<int> temp;
    struct pair_list {
        int list1_num;
        int list2_num;
    };
    auto comp = [](const pair<int, pair_list>& val1, const pair<int, pair_list>& val2) {
        if (val1.first == val2.first) {
            return val1.second.list1_num > val2.second.list1_num;
        }
        return val1.first < val2.first;
    };
    vector<pair<int, pair_list>> count;
    pair<int, pair_list> pair_sum_1_2;
    for (int i = 0; i < list1.size(); ++i) {
        for (int j = 0; j < list2.size(); ++j) {
            if (count.size() <= k) {
            pair_sum_1_2.first = list1[i] + list2[j];
            pair_sum_1_2.second.list1_num = list1[i];
            pair_sum_1_2.second.list2_num = list2[j];
            count.push_back(pair_sum_1_2);
            make_heap(count.begin(), count.end(), comp);
            //priority_queue<int, pair_list>
            } else if (list1[i] + list2[j] < count[k - 1].first) {
                pop_heap(count.begin(), count.end() - 1,comp);
                pair_sum_1_2.first = list1[i] + list2[j];
                pair_sum_1_2.second.list1_num = list1[i];
                pair_sum_1_2.second.list2_num = list2[j];
                count.push_back(pair_sum_1_2);
                make_heap(count.begin(), count.end(), comp);
            }

        }
    }
    return res;
 }
 */

 vector<vector<int>> kSmallestPairs_373_solution::kSmallestPairs3(
                              vector<int> &list1, vector<int> &list2, int k) {
    struct cmp {
        bool operator()(pair<int, int> &a, pair<int, int> &b) {
            return a.first + a.second < b.first + b.second;
        } 
    };
    vector<vector<int>> res;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;
    for (int i = 0; i < list1.size(); ++i) {
        for (int j = 0; j < list2.size(); ++j) {
            if (q.size() < k) {
                q.push({list1[i], list2[j]});
            } else if (list1[i] + list2[j] < q.top().first + q.top().second) {
                q.pop();
                q.push({list1[i], list2[j]});
            }
        }
    }
    while (!q.empty()) {
        pair<int, int> top = q.top();
        res.push_back({top.first, top.second});
        q.pop();
    }
    return res;
 }

 int kthSmallest_378_solution::kthSmallest(vector<vector<int>> &matrix, int k) {
     int len = 0;
    for (int i = 0; i < matrix.size(); ++i) {
        len = len + matrix[i].size();
    }
    if (k < 0 || matrix.size() <= 0 || k > len) {
        cout << "the k or matrix have mistake " << endl;
        return 0;
    }
    int res;
    struct cmp {
        bool operator()(int &a, int &b) {
            return a < b;
        } 
    };
    priority_queue<int, vector<int>, cmp> q;
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[i].size(); ++j) {
            if (q.size() < k) {
                q.push(matrix[i][j]);
            } else if (matrix[i][j] < q.top()) {
                q.pop();
                q.push(matrix[i][j]);
            }
        }
    }
    res = q.top();
    while (!q.empty()) {
        cout << q.top() << " ";
        q.pop();
    }
    return res;
 }

int kthSmallest_378_solution::kthSmallest2(vector<vector<int>> &matrix, int k) {
    int len = matrix[0].size();
    int total_len = matrix.size() * len;
    if (k < 0 || matrix.size() <= 0 || k > total_len) {
        cout << "the k or matrix have mistake " << endl;
        return 0;
    }
    int left = matrix[0][0];
    int right = matrix[matrix.size()-1][matrix[0].size()-1];
    while(left <= right) {
        int count = 0;
        int mid = left + (right - left)/2;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size() - 1 
                        && (matrix[i][j] <= mid); ++j) {
                count ++;
            }
        }
        //说明在右边
        if (count < k) {
            left = mid + 1;
        } else {
            //在左边
            right = mid + 1;
        }
    }
    return left;
    

}

///根据字符出现频率排序
string frequencySort_451_solution::frequencySort(string s) {
    string res;
    unordered_map<char, int> frequency_record;
    ///排序规则
    auto comp = [](const pair<char, int> &val1, const pair<char, int> &val2) {
        return val1.second > val2.second;
    };
    ///记录频率
    for (int i = 0; i < s.size(); ++i) {
        frequency_record[s[i]] ++;
    } 
    ///将map转化为vector, map不能排序
    vector<pair<char, int>> vec;
    for (const auto iter: frequency_record) {
        vec.push_back(iter);
    }
    sort(vec.begin(), vec.end(), comp);
    for (const auto iter: vec) {
        res = res + string(iter.second, iter.first);
    }

    return res;
 }

 string frequencySort_451_solution::frequencySort2(string s) {
    string res;
    unordered_map<char, int> frequency_record;
    ///排序规则
    struct comp {
        bool operator()(const pair<char, int> &a, const pair<char, int> &b) {
            if (a.second == b.second) {
                return a.first < b.first;
            }
            return a.second < b.second;
        } 
    };
    ///记录频率
    for (int i = 0; i < s.size(); ++i) {
        frequency_record[s[i]] ++;
    } 
    ///优先队列
    priority_queue< pair<char, int>, vector<pair<char, int>>, comp> q;
    for (const auto iter: frequency_record) {
        q.push({iter.first, iter.second});
    }
    ///生成string
    while (!q.empty()) {
        auto top = q.top();
        res = res + string(top.second, top.first);
        q.pop();
    }

    return res;
 }

int IPO_502_solution::findMaxCapital(int k, int w, vector<int> &prifit, vector<int> &Capital) {
    int res = w;
    vector<int> avail; ///存项目编号 0, 1, 2, 3,4 ;
    vector<int> not_start;///存项目编号0, 1, 2, 3, 4;
    for (int i = 0; i < prifit.size(); ++i) {
        not_start.push_back(i);
    }

    for (int i = 1; i <= k; ++i) {
        available_proj(k, w, Capital, avail, not_start);
        for (int i = 0; i < avail.size(); ++i) {
            cout << avail[i] << " ";
        }
        cout << endl;
        int project;
        cout << "passed in line 1646" << endl;
        if (avail.size() != 0) {
            project = best_proj(prifit, Capital, avail, not_start);
            cout << "the best project:" << project << endl;
            res = res + prifit[project];
            //w = w + prifit[project] - Capital[project];
            w = w + prifit[project];
            vector<int>::iterator iter = find(not_start.begin(), not_start.end(), project);
            not_start.erase(iter);
        }
    }

    return res;
}
 
void IPO_502_solution::available_proj(int k, int w, vector<int> &Capital, vector<int> &avail,
                                    vector<int> &not_start) {
    avail.clear();
    for (int i = 0; i < Capital.size(); ++i) {
        if (w >= Capital[i]) {
            vector<int>::iterator iter;
            iter = find(not_start.begin(), not_start.end(), i);
            if (iter != not_start.end()){
                avail.push_back(i);
            }
            cout << "passed in line 1666" << endl;
        }
    }
    return;
}

int IPO_502_solution::best_proj(vector<int> &profit, vector<int> &Capital, vector<int> &avail, 
                                    vector<int> &not_start) {
    ///项目编号， 项目盈利
    pair<int, int> best;
    best = {NULL, NULL};
    for (int i = 0; i < avail.size(); ++i) {
        //if (profit[i] - Capital[i] > best.second) {
        ///可以取等号
        if (profit[i] >= best.second) {
            best = {avail[i], profit[i]};
        }
        cout << "passed in line 1681" << endl;
    }
    return best.first;
}

int IPO_502_solution::findMaxCapital2(int k, int w, vector<int> &prifit, vector<int> &Capital) {
    struct comp1 {
        ///小顶堆
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
            return a.first < b.first;
        } 
    };
    struct comp2 {
        ///小顶堆
        bool operator()(const pair<int, int> &a, const pair<int, int> &b) {
            return a.second > b.second;
        } 
    };
    ///{prifit[i], Capital[i]}
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp1> avail;
    priority_queue<pair<int, int>, vector<pair<int, int>>, comp2> not_start;
    for (int i = 0; i < Capital.size(); ++i) {
        if (Capital[i] <= w) {
            avail.push({prifit[i], Capital[i]});
        } else {
            not_start.push({prifit[i], Capital[i]});
        }
    }
    int index = 0;
    while(!avail.empty() && index++ != k) {
        pair<int, int> tmp = avail.top();
        w = w + tmp.first;
        //index ++;
        avail.pop();
        while(!not_start.empty()) {
            tmp = not_start.top();
            ///可以取等号
            if (tmp.second <= w) {
                avail.push(tmp);
                not_start.pop();
            }
            else {
                break;
            }
        }
    }
    return w;
}

void CutWord_659_solution::CutWord(vector<int> &nums, vector<vector<int>> &res) {
    //vector<vector<int>> res;
    vector<int> temp;
    unordered_map<int, int> frequence, tail;
    for (auto num: nums) {
        frequence[num]++;
    }
    for (auto num: nums) {
        if (frequence[num] == 0) {
            //res.push_back(temp);
            //temp.clear();
            continue;
        }
        //tail[i]大于0,前面有一个以i为结果的数列，此时，frequence[i+1]大于0,则可以加到前面去
        else if (frequence[num] > 0 && tail[num-1] > 0) {
            frequence[num]--;
            tail[num-1]--;
            tail[num] ++;
            //temp.push_back(num);
        } 
        ///可以产生一个num, num +1, num +2的数组。
        else if (frequence[num] > 0 && frequence[num+1] > 0 && frequence[num+2] > 0) {
            //temp.clear();
            frequence[num]--, frequence[num+1]--, frequence[num+2]--;
            //temp.push_back(num);
            //temp.push_back(num+1);
            //temp.push_back(num+2);
            tail[num+2]++;
        } else {
            cout << "there is no suitable res" << endl;
            return;
        }
    }
    ///以tail[i]为结尾，删除从nums[0]递增到tail[i]
    for (int i = 0; i < tail.size(); ++i) {
        if (tail[i] >= 1) {
            //如果tail大于1,则表示有多个相同的尾巴
            for (int j = tail[i]; j > 0; j--) {
                int list_tail = i;
                cout << "the list_tail:" << list_tail << endl;
       
                for (int k = 0; k < nums.size(); ++k) {
                    cout << nums[k] << " ";
                }

                for (int j = nums[0]; j <= list_tail; ++j) {
                    temp.push_back(j);
                //nums.erase(nums.begin() + j);
                    cout << "in 1739" << endl;
                    for (int k = 0; k < nums.size(); ++k) {
                        cout << nums[k] << " ";
                    }
                    cout << endl;
                }
                DeleteWord(nums, temp);
                cout << endl;
                res.push_back(temp);
                temp.clear();
            }
        }
    }

    return;
}
///从target中删除temp
void CutWord_659_solution::DeleteWord(vector<int> &target, vector<int> temp) {
    for (int i = 0; i < temp.size(); ++i) {
        for (int j = 0; j < target.size(); ++j) {
            if (target[j] == temp[i]) {
                target.erase(target.begin() + j);
                continue;
            }
        }
    }
}

///前K个高频词，leetcode_692
vector<string> topKFrequent_692_solution::topKFrequent(vector<string> &words, int k) {
    vector<string> res;
    unordered_map<string, int> count;
    for (auto k: words) {
        count[k]++;
    }
    struct comp {
        ///小顶堆
        bool operator()(const pair<string, int> &a, const pair<string, int> &b) {
            return a.second > b.second;
        } 
    };
    priority_queue<pair<string, int>, vector<pair<string, int>>, comp> queue;

    for (const auto iter: count) {
        if (queue.size() < k) {
            queue.push({iter.first, iter.second});
        }
        ///比最小的大， 换掉
        else if (queue.top().second < iter.second) {
            queue.pop();
            queue.push({iter.first, iter.second});
        }
        //queue.push({iter.first, iter.second});
    }
    cout << "the top" << queue.top().first << endl;
    while (!queue.empty()) {
        auto top = queue.top();
        //top为最小值，为了从大到小排列， 采用在begin()前面插入
        res.insert(res.begin(), top.first);
        queue.pop();
    }
    return res;
}
///排序
vector<string> topKFrequent_692_solution::topKFrequent2(vector<string> &words, int k) {
    vector<string> res;
    unordered_map<string, int> count;
    for (auto k: words) {
        count[k]++;
    }
    ///排序规则
    auto comp = [](const pair<string, int> &val1, const pair<string, int> &val2) {
        return val1.second > val2.second;
    };
    //将map转化为vector
    vector<pair<string, int>> string_vector;
    for (auto iter: count) {
        string_vector.push_back({iter.first, iter.second});
    }
    ///进行排序
    sort(string_vector.begin(), string_vector.end(), comp);
    //
    for (int i = 0; i < k; ++i) {
        res.push_back(string_vector[i].first);
    }
    return res;

}
//////数据流中的第K大元素
KthLargest_703_solution::KthLargest_703_solution(int k, vector<int> &nums) {
    kth = k;
    inter_nums.assign(nums.begin(), nums.end());
}
//////数据流中的第K大元素
int KthLargest_703_solution::add(int val) {
    inter_nums.push_back(val);
    sort(inter_nums.begin(), inter_nums.end(), greater<int>());
    if (inter_nums.size() < kth) {
        cout << "the len of nums is less than k" << endl;
        return 0;
    }
    cout << "the kth of nums:" << inter_nums[kth - 1];
    return inter_nums[kth - 1];
}
///找出第K小的距离堆对
int smallestDistancePair_719_solution::smallestDistancePair(vector<int> &nums, 
                                                           int k) {
    vector< pair<pair<int, int>, int> > queue;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            queue.push_back( {{nums[i], nums[j]}, abs(nums[i]- nums[j])} );
        }
    }

    auto comp = [](const pair<pair<int, int>, int> &val1, 
                            const pair<pair<int, int>, int> &val2) {
        return val1.second < val2.second;
    };

    sort(queue.begin(), queue.end(), comp);
    for (int i = 0; i < queue.size(); ++i) {
        cout <<queue[i].first.first << " " << queue[i].first.second << "->" << 
             queue[i].second << " " << endl;
    }
    cout << endl;
    int res = queue[k - 1].second;
    cout << "the kth :" << res << endl;
    return res;
                                                            
}

int smallestDistancePair_719_solution::smallestDistancePair2(vector<int> &nums, 
                                                           int k) {
    int res;
    struct comp {
        ///小顶堆
        bool operator()(const pair<pair<int, int>, int> &a, const pair<pair<int, int>, int> &b) {
            return a.second < b.second;
        } 
    };
    priority_queue< pair<pair<int, int>, int>, vector<pair<pair<int, int>, int>>, comp> queue;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            if (queue.size() < k) {
                queue.push({{nums[i], nums[j]}, abs(nums[i]- nums[j])});
            } else if (queue.top().second > abs(nums[i]- nums[j]) ) {
                queue.pop();
                queue.push({{nums[i], nums[j]}, abs(nums[i]- nums[j])});
            }
        }
    }
    res = queue.top().second;
    cout << "the kth:" << queue.top().second << endl; 
    while (!queue.empty()) {
        cout <<queue.top().first.first << " " << queue.top().first.second << "->" << 
             queue.top().second << " " << endl;
        queue.pop();
    }
    return res;
}

//网络延迟时间, 从某一点发出信号到所有节点都收到信号，要多长时间， leetcode_743 
int networkDelayTime_743_solution::networkDelayTime(vector<vector<int>> &nums,
                                                                 int N, int k) {
    vector<pair<int, int>> temp;
    int res;
    auto comp = [](const pair<int, int>  &val1, const pair<int, int> &val2) {
        return val1.second > val2.second;
    };

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i][0] == k) {
            if (nums[i][2] == 0)  {
                cout << "the time is 0, can not reach!" << "the target point: " << nums[i][1] << endl;
                return 0;
            }
            /// {target, time}
            temp.push_back({nums[i][1], nums[i][2]});
        }
    }
    sort(temp.begin(),temp.end(), comp); ///默认是less<int>(),从大到小
    for (int i = 0; i < temp.size(); ++i) {
        cout << temp[i].second << " ";
    }
    cout << endl;
    res = temp[0].second;
    cout << "the maxest time:" << res << endl;
    return res;
}

///格雷编码 leetcode_89
vector<int> grayCode_89_Solution::grayCode(int n) {
    vector<int> res;
    vector<int> temp;
    temp.push_back(0);
    if (n < 0) {
        return res;
    }
    DFS(res, temp, n);

    return res;
}
void grayCode_89_Solution::DFS(vector<int> &res, vector<int> &temp, int n) {
    for (int i = 0; i < n; ++i) {
        mirror(temp, i);
    }

    Two2Ten(temp, res);
    return;
}

void grayCode_89_Solution::mirror(vector<int> &temp, int n) {
    for (int i = temp.size() - 1; i >= 0; i--) {
        ///倒序插入， 需要先在前面加1, 意思是加上一个10^n
        int res_nums = temp[i] + pow(10, n);
        temp.push_back(res_nums);
    }
    for (int i = 0; i < temp.size(); ++i) {
        cout << temp[i] << " ";
    }
    cout << endl;
    return;
}

void grayCode_89_Solution::Two2Ten(vector<int> &temp, vector<int> &res) {
    for(int i = 0; i < temp.size(); ++i) {
        int res_temp = temp[i];
        int res_ten = 0;
        int count = 0;
        while(res_temp != 0) {
            res_ten = (res_temp % 10) * pow(2, count) + res_ten;
            res_temp = res_temp / 10;
            count ++;
        }
        res.push_back(res_ten);
    }
    return;

}
//复原ip地址， leetcode_93
vector<string> restoreIpAddresses_93_Solution ::restoreIpAddresses(string s) {
    vector<string> res;
    string temp;
    DFS(res, 0, s, temp);

    return res;
 }
void restoreIpAddresses_93_Solution::DFS(vector<string> &res, int n, 
            string s, string temp) {
    //已经有了四次
    if (n == 4) {
        if (s.empty()) res.push_back(temp);
    } else {
        //可以向后移动3个位置
        for (int k = 0; k < 4; ++k) {
            if (s.size() < k) break;
            //int val = stoi(s.substr(0, k));
            //cout << "the type :" << typeid(s.substr(0, k));
            string str_k = s.substr(0, k);
            ///atoi（）的变量需要为const,  所以调用c_str, 
            int val = atoi(str_k.c_str());
            if (val > 255 || k != to_string(val).size()) continue;
            ///(n == 3 ? "" : ".") 最后一位不用“.”
            DFS(res, n + 1, s.substr(k), temp + s.substr(0, k) + (n == 3 ? "" : "."));
        }
    }
    return;
}
///单词接龙 leetcode_126
vector<vector<string>> findLadders_126_Solution::findLadders(string beginWord, string endWord, 
             vector<string>& wordList) {
    vector<vector<string>> res;
    vector<string> temp;
    vector<string>::iterator iter, iter1;
    iter = find(wordList.begin(), wordList.end(), beginWord);
    iter1 = find(wordList.begin(), wordList.end(), endWord);
    //if (iter != wordList.end() && iter1 != wordList.end()) {
    temp.push_back(beginWord);
    int n = 0;
    DFS(n, endWord, wordList, res, temp);

    for (int i = 0; i < temp.size(); ++i) {
            cout << temp[i] << " ";
    }
    cout << endl;
    return res;
}

void findLadders_126_Solution::DFS(int &i, string endWord, 
                    vector<string>& wordList, vector<vector<string>> &res, vector<string> &temp) {
    if (temp[temp.size() - 1] == endWord) {
        res.push_back(temp);
        temp.clear();
        return;
    }
    if (i > wordList.size() - 1) {
        return;
    }
    bool next = next_string(temp, wordList[i]);
    if (next == true) {
        int j = i + 1;
         ///不压入当前的元素， 继续搜索
        //DFS(j, endWord, wordList, res, temp);
        temp.push_back(wordList[i]);
        ///压入当前元素， 继续搜索
        DFS(j, endWord, wordList, res, temp);
        cout << " pass in 2103" << endl;
    } else {
        int k = i + 1;
        DFS(k, endWord, wordList, res, temp);
    }

    for (int i = 0; i < temp.size(); ++i) {
        cout << temp[i] << " ";
    }
    cout << endl;
        //temp.pop_back();
    cout << "pass in 2115" << endl;
    return;
}

bool findLadders_126_Solution::next_string(vector<string> &temp, string condibate) {
    string top = temp[temp.size() - 1];
    int cout = 0;
    for (int i = 0; i < condibate.size(); ++i) {
        if (top[i] != condibate[i]) {
            cout++;
        }
    }
    //cout << " pass in 2108" << endl;
    if (cout == 1) {
        return true;
    }
    return false;
}
///分割回文串 leetcode_131
vector<vector<string>> partition_131_solution::partition(string s) {
    vector<vector<string>> res;
    vector<string> temp;
    int posi = 0;
    DFS(s, temp, res, posi);

    return res;

}

void partition_131_solution::DFS(string s, vector<string> &temp, vector<vector<string>> &res, 
                                                                                 int &posi) {
    if (posi > s.size() - 1) {
        cout << posi << endl;
        res.push_back(temp);
        /*
        for (int i = 0; i < temp.size(); ++i) {
            cout << temp[i] << " ";
        }
        cout << endl;
        */
        temp.clear();
        return;
    }
    ///可以切分的位置
    for (int i = posi + 1; i <= s.size(); ++i) {
        //切割取下字符
        string str_k = s.substr(posi, i - posi);
        cout << str_k << endl;
        bool bool_res = IsPartition(str_k);
        if (bool_res) {
            //cout << str_k << endl;
            temp.push_back(str_k);
            int next_posi = i;
            DFS(s, temp, res, next_posi);
        }
    }
}
///判断是否为回文字符
bool partition_131_solution::IsPartition(string part) {
    int len = part.size();
    for (int i = 0; i <= len/2 - 1; ++i) {
        if (part[i] != part[len - 1 - i]) {
            return false;
        }
    }
    return true;
}
//单词拆分 leetcode_140 
void wordBreak_140_solution::wordBreak(string s, vector<string> &wordDict) {
    vector<string> temp_res;
    int posi = 0;
    DFS(s, wordDict, posi, temp_res);

    return;
}
void wordBreak_140_solution::DFS(string s, vector<string> &wordDict, int &posi, 
                                                      vector<string> &temp_res) {
    if (posi > s.size() - 1) {
        res.push_back(temp_res);
        temp_res.clear();
        return;
    }
    for (int i = 0; i < wordDict.size(); ++i) {
        int len = wordDict[i].size();
        string str_k = s.substr(posi, len);
        if (str_k == wordDict[i]) {
            temp_res.push_back(str_k);
            int next_posi = posi + len;
            DFS(s, wordDict, next_posi, temp_res);
        }
    }
}
///添加和搜索单词 leetcode_211 回溯算法
void wordDictionary_211_solution::addWord(string s) {
    res.push_back(s);
    return;
}
void wordDictionary_211_solution::search(string s) {
    //int len = s.size();
    bool_res = true;
    bool res_temp;
    for (int i = 0; i < res.size(); ++i) {
        string temp = res[i];
        res_temp = true;
        res_temp = equi(s, res[i]);
        //cout << "the res_temp: " << res_temp << endl;
        if (res_temp) {
            break;
        }
    }
    bool_res = res_temp;
    return;
}
///s1:the string to be search  s2: the string from res;
bool wordDictionary_211_solution::equi(string s1, string s2) {
    bool res_s1_s2 = true;
    for (int i = 0; i < s1.size(); ++i) {
        if ('a' <= s1[i] && s1[i] <= 'z') {
            //cout << "the s1[i]: " << s1[i] << " " << "the s2[[i]: " << s2[i] << endl;
            if (s1[i] != s2[i]) {
                res_s1_s2 = false;
            }
        }
    }
    return res_s1_s2;
}

///组合总和 leetcode_216 回溯算法
void combinationSum3_216_solution::combinationSum3(int k, int n) {
    vector<int> temp_res;
    vector<bool> condibate = {true, true, true, true, true, true, true, true, true};
    //k: the num   n:the sum
    int posi = 1;
    DFS(k, n, temp_res, posi, condibate);
    return;
}
void combinationSum3_216_solution::DFS(int &k, int &n, vector<int> &temp_res, 
                                                        int &posi, vector<bool> &condibate) {
    if(temp_res.size() == k) {
        if (n == 0) res.push_back(temp_res);
        return;
    }
    for (int i = posi; i < 9 && i <= n; ++i) {
        //可以用于非升序的，除去内容重复
       // if (condibate[i]) {
            temp_res.push_back(i);
            int m = n - i;
            //n = n - i;
            //可以确保是升序
            int next_posi = i + 1;
            //可以出现很多重复的，但顺序不一样
            //int next_posi = posi + 1;
            condibate[i] = false;
            //posi = posi + 1;
            DFS(k, m, temp_res, next_posi, condibate);
            temp_res.pop_back();
            condibate[i] = true;
        //}
    }
}
/// 累加数 leetcode_306 
bool isAdditiveNumber_306_solution::isAdditiveNumber(string num) {
    bool res = false;
    vector<int> temp_num;
    vector<vector<int>> temp_total;
    int posi = 0;
    DFS(num, res, posi, temp_num, temp_total);
    for (int i = 0; i < temp_total.size(); ++i) {
        for (auto iter: temp_total[i]) {
            cout << iter << " ";
        }
        cout << endl;
    }
    cout << endl;

    return res;
}
void isAdditiveNumber_306_solution::DFS(string s, bool &res, int &posi, vector<int> &temp_num, 
                                                            vector<vector<int>> &temp_total) {
    if (posi > s.size() - 1 && temp_num.size() >= 3) {
        temp_total.push_back(temp_num);
        res = true;
        return;
    }
    for (int i = posi + 1; i <= s.size(); ++i) {
        string str_k = s.substr(posi, i - posi);
        int val = atoi(str_k.c_str());
        //cout << "the val in 2296: " << val << endl;
        //判断最新两位数是否相等
        if ((temp_num.size() >= 2 && temp_num[temp_num.size() - 1] + temp_num[temp_num.size() - 2] 
                      == val) || temp_num.size() <= 1) {
            temp_num.push_back(val);
            int next_posi = i;

            DFS(s, res, next_posi, temp_num, temp_total);
            temp_num.pop_back();
        }
        if (temp_num.size() >=2 && (temp_num[temp_num.size() - 1] + temp_num[temp_num.size() - 2]  
                                                 != val)) {
            continue;
        }
    }
}
//优美的排列 leetcode_526
int countArrangement_526_solution::count(int n) {
    vector<int> temp;
    vector<bool> used(n, false);
    int posi = 0;
    DFS(temp, n, used);

    return res.size();
}
void countArrangement_526_solution::DFS(vector<int> &temp, int n, vector<bool> &used) {
    if (temp.size() == n) {
        res.push_back(temp);
        return;
    }
    for (int i = 1; i <= n; ++i) {
        int len = temp.size();
        if ((i % (len + 1) == 0|| (len + 1) % i == 0) && used[i] == false) {
            temp.push_back(i);
            used[i] = true;
            //int next_posi = posi + 1;
            DFS(temp, n, used);
            temp.pop_back();
            used[i] = false;
        } else if (used[i] == true || (i % (len + 1) != 0 && (len + 1) % i != 0)) {
            continue;
        }
    }
}
///字母大小写全排列 leetcode_784
void letterCasePermutation_784_solution::letterCasePermutation(string s) {
    string temp;
    res.push_back(s);
    int posi = 0;
    DFS(s, posi);
    return;
}
void letterCasePermutation_784_solution::DFS(string s, int &posi) {
    if (posi > s.size() - 1) {
        return;
    }
    if (s[posi] <= 'z' && s[posi] >= 'a') {
        ///第一次进入需要改变大小写，大改小， 小改大
        if (res.size() == 1) {
        //res.push_back(s);
        string temp = s;
        char temp_posi = s[posi] - 32;
        temp[posi] = temp_posi;
        res.push_back(temp);
        } else {
            //第二次 只需要在原来的res的基础上， 将该位置大改小， 小改大
            int len = res.size();
            for (int i = 0; i < len; ++i) {
                char temp_posi = s[posi] - 32;
                string temp = res[i];
                temp[posi] = temp_posi;
                res.push_back(temp);
            }
        }
        int next_posi = posi + 1;
        DFS(s, next_posi);
    } else if (s[posi] <= 'Z' && s[posi] >= 'A') {
        if (res.size() == 1) {
        //res.push_back(s);
        char temp_posi = s[posi] + 32;
        string temp = s;
        temp[posi] = temp_posi;
        res.push_back(temp);
        } else {
            int len = res.size();
            for (int i = 0; i < len; ++i) {
                string temp = res[i];
                char temp_posi = s[posi] + 32;
                temp[posi] = temp_posi;
                res.push_back(temp);
            }
        }
        int next_posi = posi + 1;
        DFS(s, next_posi);
    } else {
        int next_posi = posi + 1;
        DFS(s, next_posi);
    }

}
///将数组拆分成斐波那契序列 leetcode_842
void splitIntoFibonacci_842_solution::splitIntoFibonacci(string s) {
    vector<int> temp;
    int posi = 0;
    DFS(s, temp, posi);
    
    return;
}
void splitIntoFibonacci_842_solution::DFS(string s,vector<int> &temp, int &posi) {
    if (posi > s.size() - 1 && temp.size() >= 3 ) {
        res.push_back(temp);
        return;
    }
    for (int i = posi + 1; i <= s.size(); ++i) {
        string str_k = s.substr(posi, i - posi);
        int val = atoi(str_k.c_str());
        if ((temp.size() >=2 && (temp[temp.size() - 1] + temp[temp.size() -2] == val)) 
                                                                    || temp.size() <=1) {
            temp.push_back(val);
            int next_posi = i;
            DFS(s, temp, next_posi);
            temp.pop_back();
        } else if (temp.size() >=2 && (temp[temp.size() - 1] + temp[temp.size() - 2] 
                                                                            != val)) {
            continue;
        }
    }
}
//不同路径3 leetcode_980 
void uniquePaths3_980_solution::uniquePaths3(vector<vector<int>> &grid) {
    pair<int, int> start_point;
    vector<vector<bool>> used;

    vector<bool> temp_used;
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            if (grid[i][j] == 1) {
                //寻找起始点
                start_point = {i, j};
            } else if (grid[i][j] == -1) {
                //计算障碍点的个数
                obstacle_nums ++;
            }
            temp_used.push_back(false);
        }
        //设置一个flag,标明该点有没有被使用
        used.push_back(temp_used);
    }
    //起始点被使用
    used[start_point.first][start_point.second] = true;
    res.push_back(start_point);
    DFS(grid, start_point, used);
    return;

}
void uniquePaths3_980_solution::DFS(vector<vector<int>> &grid, pair<int, int> &current_point, 
                              vector<vector<bool>> &used) {
    //如果res的个数达到可以行动的个数，且最后一个点为终点2,终止
    if (res.size() == grid.size() * grid[0].size() - obstacle_nums && 
        grid[res[res.size() - 1].first][res[res.size() - 1].second] == 2) {
        total_res.push_back(res);
        return;
    }
    vector<pair<int, int>> validPaths;
    cout << "the current posi:" << current_point.first << "-" << current_point.second << endl;
    //寻找可以行进的点
    validPath(current_point, grid, used, validPaths);

    for (auto iter: validPaths) {
        cout << iter.first << "-" << iter.second << " ";
    }

    cout << endl;
    for (int i = 0; i < validPaths.size(); ++i) {
        int x = validPaths[i].first;
        int y = validPaths[i].second;
        //判断该点可以行进，且还没被使用
        if (used[x][y] == false && grid[x][y] != -1) {
            res.push_back({x, y});
            used[x][y] = true;
            pair<int, int> next_point = {x, y};
            vector< pair<int, int>> temp_validPaths;
            DFS(grid, next_point, used);
            //弹出，且used = false, 使用下一个validPaths 点进行
            res.pop_back();
            used[x][y] = false;
        }
    }
}
void uniquePaths3_980_solution::validPath(pair<int, int> point, vector<vector<int>> &grid, 
                          vector<vector<bool>> &used, vector<pair<int, int>> &validPaths) {
    int x = point.first;
    int y = point.second;
    cout << "the x in 2481:" << x << endl;
    cout << "the y in 2482:" << y << endl;
    ///
    for (int j = -1; j < 2; j = j + 2) {
        if (y + j < grid[0].size() && y + j >= 0 && used[x][y + j] == false) {
            validPaths.push_back({x, y + j});
        }
    }
    for (int i = -1; i < 2; i = i + 2) {
        if (x + i < grid.size() && x + i >= 0 && used[x + i][y] == false) {
            validPaths.push_back({x + i, y});
        }
    }
    return;
}
//正方形数组的数目 leetcode_996
void numSquareFulPerms_996_solution::numSquareFulPerms(vector<int> &list) {
    vector<int> res;
    vector<bool> used(list.size(), false);
    int posi = 0;

    DFS(res, posi, used, list);
    return;

}
///TODO: the DFS is not ok

void numSquareFulPerms_996_solution::DFS(vector<int> &res, int &posi, vector<bool> &used,
                                         vector<int> &list) {
    /*
    if (res.size() == list.size()) {
        total_res.push_back(res);
        cout << "pass in 2518" << endl;
        return;
    }
    cout << "pass in 2520" << endl;
    for (int i = 0; i < list.size(); ++i) {
        if (res.size() < 1 && used[i] == false) {
            res.push_back(list[i]);
            used[i] = true;
            DFS(res, posi, used, list);

            cout << "pass in 2524" << endl;
        } else if (res.size() >= 1 && IsSquareFulPerms(list[i], res[res.size() - 1]) && 
                                                                       used[i] == false) {
            res.push_back(list[i]);
            used[i] = true;
            int next_posi = posi + 1;
            cout << "pass in 2534" << endl;
            DFS(res, next_posi, used, list);
            cout << "pass in 2529" << endl;
            res.pop_back();
            used[i] = false;
        } else if (res.size() >= 1 && !IsSquareFulPerms(list[i], res[res.size() - 1]) && 
                                                                      used[i] == false) {
            //res.clear();
            cout << "pass in 2541" << endl;
            continue;
        }
    }*/

}
bool numSquareFulPerms_996_solution::IsSquareFulPerms(int val1, int val2) {
    int temp = pow(val1, 2) + pow(val2, 2);
    if (sqrt(temp) == (int)sqrt(temp)) {
        return true;
    }
    return false;
}

//不同的二叉搜索树2

vector<TreeNode*> generateTrees_96_solution::getTree(int begin, int end) {
    vector<TreeNode*> res;
    if (begin > end) {
        res.push_back(NULL);
        return res;
    }
    for (int i = begin; i <= end; ++i) {
        vector<TreeNode*> leftNode = getTree(begin, i - 1);
        vector<TreeNode*> rightNode = getTree(i + 1, end);
        cout << "pass in 2570" << endl;
        for(auto left: leftNode) {
            for (auto right: rightNode) {
                cout << "pass in 2573" << endl;
                TreeNode* root = new TreeNode(i);
                //cout << root->val << " ";
                root->left = left;
                root->right = right;
                res.push_back(root);
            }
        }
    }
    return res;
}

vector<TreeNode*> generateTrees_96_solution::generateTrees(int n) {
    if (n == 0) {
        return vector<TreeNode*>();
    }
    cout << "pass in 2587" << endl;
    return getTree(1, n);
}

void generateTrees_96_solution::print(TreeNode* root) {
    if (root != NULL) {
        cout << root->val << " ";
        if (root->left != NULL) {
           print(root->left);
        }
        if (root->right != NULL) {
            print(root->right);
        }
    }
    return;
}
//被围绕的区域，leetcode_130
void solve_130_solution::solve(vector<vector<char>> &board, int flag) {
    if (board.size() <= 0) return;
    int row = board.size();
    int col = board[0].size();
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if ((i == 0 || j == 0 || i == row - 1 || j == col - 1) && board[i][j] == 'o') {
                if (flag == 1) {
                    cout << "running in DFS " << endl;
                    DFS(board, i, j);
                    
                } else if (flag == 2) {
                    cout << "running in DFS2 " << endl;
                    DFS2(board, i, j);
                } else if (flag == 3) {
                    cout << "running in BFS3 " << endl;
                    BFS3(board, i, j);
                
                } else if (flag == 4) {
                    cout << "running in BFS4 " << endl;
                    //BFS4(board, i, j);
                }
            }
        }
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (board[i][j] == 'o') {
                board[i][j] ='x';
            }
            if (board[i][j] == '#') {
                board[i][j] = 'o';
            }
        }
    }
    return;
}
///递归
void solve_130_solution::DFS(vector<vector<char>> &board, int i, int j) {
    if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() 
                       || board[i][j] == 'x' || board[i][j] == '#') {
        //board[i][j] == '#' 已经搜索过
        return;
    }
    board[i][j] = '#';
    DFS(board, i + 1, j);
    DFS(board, i - 1, j);
    DFS(board, i, j + 1);
    DFS(board, i, j - 1);
}
//非递归
void solve_130_solution::DFS2(vector<vector<char>> &board, int i, int j) {
    //先进后出
    stack<pair<int, int>> stack_pair;
    stack_pair.push({i, j});
    board[i][j] = '#';
    while(!stack_pair.empty()) {
        pair<int, int> current = stack_pair.top();
        //上
        if (current.first - 1 >= 0 && board[current.first - 1][current.second] == 'o') {
            stack_pair.push({current.first - 1, current.second});
            board[current.first - 1][current.second] = '#';
            continue;
        }
        if (current.first + 1 <= board.size() - 1 && board[current.first + 1][current.second] == 'o') {
            stack_pair.push({current.first + 1, current.second});
            board[current.first + 1][current.second] = '#';
            continue;
        }
        if (current.second - 1 >= 0 && board[current.first][current.second - 1] == 'o') {
            stack_pair.push({current.first, current.second - 1});
            board[current.first][current.second - 1] = '#';
            continue;
        }
        if (current.second + 1 <= board[0].size() - 1 && board[current.first][current.second + 1] == 'o') {
            stack_pair.push({current.first, current.second + 1});
            board[current.first][current.second + 1] = '#';
            continue;
        }
        stack_pair.pop();
    }
    return;
}
 //广度优先 非递归
///没有continue,不跳过，在一点的周围搜索完，再继续
void solve_130_solution::BFS3(vector<vector<char>> &board, int i, int j) {
    //由stack 改为 queue, 使得先进先出
    queue<pair<int, int>> queue_pair;
    queue_pair.push({i, j});
    board[i][j] = '#';
    while(!queue_pair.empty()) {
        pair<int, int> current = queue_pair.front();
        //上
        if (current.first - 1 >= 0 && board[current.first - 1][current.second] == 'o') {
            queue_pair.push({current.first - 1, current.second});
            board[current.first - 1][current.second] = '#';
            //continue;
        }
        //下
        if (current.first + 1 <= board.size() - 1 && board[current.first + 1][current.second] == 'o') {
            queue_pair.push({current.first + 1, current.second});
            board[current.first + 1][current.second] = '#';
            //continue;
        }
        //左
        if (current.second - 1 >= 0 && board[current.first][current.second - 1] == 'o') {
            queue_pair.push({current.first, current.second - 1});
            board[current.first][current.second - 1] = '#';
            //continue;
        }
        //右
        if (current.second + 1 <= board[0].size() - 1 && board[current.first][current.second + 1] == 'o') {
            queue_pair.push({current.first, current.second + 1});
            board[current.first][current.second + 1] = '#';
            //continue;
        }
        queue_pair.pop();
    }
    return;

}
///并差集
class UnionFind {
public:
    vector<int> parents;
    UnionFind(int totalNodes) {
        for (int i = 0; i < totalNodes; ++i) {
            parents.push_back(i);
        }
    }
    void Union(int node1, int node2) {
        int root1 = find(node1);
        int root2 = find(node2);
        if (root1 != root2) {
            parents[root2] = root1;
        }
    }
    int find(int node) {
        while(parents[node] != node) {
            parents[node] = parents[parents[node]];
            node = parents[node];
        }
        return node;
    }

    bool IsConnect(int node1, int node2) {
        return find(node1) == find(node2);
    }

};
void solve_130_solution::solve_union(vector<vector<char>> &board) {
    cout << "running in solve_union(并查集)" << endl;
    if (board.size() <= 0) return;
    row = board.size();
    col = board[0].size();

    UnionFind unfind(row * col + 1);
    int dummyNode = row * col;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (board[i][j] == 'o') {
                if (i == 0 || j == 0 || i == row -1 || j == col - 1) {
                    unfind.Union(node(i, j), dummyNode);
                } else {
                    if (i > 0 && board[i - 1][j] == 'o') {
                        unfind.Union(node(i, j), node(i - 1, j));
                    } 
                    if (i < row - 1 && board[i + 1][j] == 'o') {
                        unfind.Union(node(i, j), node(i + 1, j));
                    }
                    if (j > 0 && board[i][j - 1] == 'o') {
                        unfind.Union(node(i, j), node(i, j - 1));
                    }
                    if (j < col - 1 && board[i][j + 1] == 'o') {
                        unfind.Union(node(i, j), node(i, j + 1));
                    }
                }
            }
        }
    }
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (unfind.IsConnect(node(i, j), dummyNode)) {
                board[i][j] = 'o';
            } else {
                board[i][j] = 'x';
            }
        }
    }
    
}

int solve_130_solution::node(int i, int j) {
    return i * col + j;
}
//岛屿的数量  leetcode_200
int numIslands_200_solution::numIslands(vector<vector<char>> &grid, int flag) {
    row = grid.size();
    if(!row) return 0;
    col = grid[0].size();
    //int numIslands = 0;
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (grid[i][j] == '1') {
                ++numsIslands;
                if (flag == 1) DFS(grid, i, j);
                if (flag == 2) BFS(grid, i, j);
            }
        }
    }
    return numsIslands;

}
void numIslands_200_solution::DFS(vector<vector<char>> &grid, int i, int j) {
    cout << "running in DFS " << endl;
    int row1 = grid.size();
    int col1 = grid[0].size();
    grid[i][j] = '0';
    if (i - 1 >= 0 && grid[i - 1][j] == '1') DFS(grid, i - 1, j);
    if (i + 1 <= row1 && grid[i + 1][j] == '1') DFS(grid, i + 1, j);
    if (j - 1 >= 0 && grid[i][j - 1] == '1') DFS(grid, i, j - 1);
    if (j + 1 <= col1 && grid[i][j + 1] == '1') DFS(grid, i, j + 1);
    return;
}

void numIslands_200_solution::BFS(vector<vector<char>> &grid, int i, int j) {
    cout << "running in BFS " << endl;
    queue<pair<int, int>> queue_pair;
    queue_pair.push({i, j});
    grid[i][j] = '0';
    while(!queue_pair.empty()) {
        pair<int, int> current = queue_pair.front();
        //上
        if (current.first - 1 >= 0 && grid[current.first - 1][current.second] == '1') {
            queue_pair.push({current.first - 1, current.second});
            grid[current.first - 1][current.second] = '0';
            //continue;
        }
        //下
        if (current.first + 1 <= grid.size() - 1 && grid[current.first + 1][current.second] == '1') {
            queue_pair.push({current.first + 1, current.second});
            grid[current.first + 1][current.second] = '0';
            //continue;
        }
        //左
        if (current.second - 1 >= 0 && grid[current.first][current.second - 1] == '1') {
            queue_pair.push({current.first, current.second - 1});
            grid[current.first][current.second - 1] = '0';
            //continue;
        }
        //右
        if (current.second + 1 <= grid[0].size() - 1 && grid[current.first][current.second + 1] == '1') {
            queue_pair.push({current.first, current.second + 1});
            grid[current.first][current.second + 1] = '0';
            //continue;
        }
        queue_pair.pop();
    }
    return;
}
class UnionFind2 {
public:
    UnionFind2(vector<vector<char>> &grid) {
        //count = 0;
        int row = grid.size();
        int col = grid[0].size();
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (grid[i][j] == '1') {
                    parent.push_back(i * col + j);
                    ++count;
                    cout << "the count :" << count << endl;
                } else {
                    parent.push_back(-1);
                }
                rank.push_back(0);
            }

        }
    }

    /*int find (int i) {
        if (parent[i] != i) parent[i] = find(parent[i]);
        return parent[i];
    }*/

    int find(int node) {
        while(parent[node] != node) {
            parent[node] = parent[parent[node]];
            node = parent[node];
        }
        return node;
    }

    void Union(int i, int j) {
        int rooti = find(i);
        int rootj = find(j);
        if (rooti != rootj) {
            if (rank[rooti] > rank[rootj]) parent[rootj] = rooti;
            else if (rank[rooti] < rank[rootj]) parent[rooti] = rootj;
            else parent[rootj] == rooti; rank[rooti] += 1;
            cout << "the count in 2907" << count << endl;
            --count;
        }
    }

    int getCount() {
        return count;
    }
private:
    vector<int> parent;
    int count = 0; // num of component
    vector<int> rank;
};

void numIslands_200_solution::Union(vector<vector<char>> &board) {
    row = board.size();
    if (!row) return;
    col = board[0].size();
    UnionFind2 uf(board);
    for (int i = 0; i< row; ++i) {
        for (int j = 0; j < col; ++j) {
            if (board[i][j] == '1') {
                board[i][j] == '0';
                if (i - 1 >= 0 && board[i - 1][j] == '1') {
                    uf.Union(col * i + j, col * (i - 1) + j);
                }
                if (i + 1 <= row && board[i + 1][j] == '1') {
                    uf.Union(col * i + j, col * (i + 1) + j);
                }
                if (j - 1 >= 0 && board[i][j - 1] == '1') {
                    uf.Union(col * i + j, col * i + (j - 1));
                }
                if (j + 1 <= col && board[i][j + 1] == '1') {
                    uf.Union(col * i + j, col * i + j + 1);
                }
            }
        }
    }
    numsIslands = uf.getCount();
}
//最小高度树 leetcode 
void findMinHeightTrees_310_solution::findMinHeightTrees(int n, vector<vector<int>> &edges) {
    //int hight = 0;
    vector<pair<vector<int>, bool>> edges_bool;
    /// 0 - 1 - false 再加上是否被使用过的信息
    for (auto iter: edges) {
        vector<int> temp;
        temp.push_back(iter[0]);
        temp.push_back(iter[1]);
        edges_bool.push_back({temp, false});
    }
    //输出
    for (auto iter: edges_bool) {
        cout << iter.first[0] << "-" << iter.first[1] << "-"<< iter.second << endl;
    }
    vector<int> temp_res;
    //进行每个节点遍历
    for (int i = 0; i < n; ++i) {
        int hight = 0;
        DFS(i, edges_bool, temp_res, hight);
        //格式 {节点到末节点的距离， 节点}
        res.push_back({temp_res, i});
        temp_res.clear();
    }
    ///打印结果：格式： 
    for (int i = 0; i < res.size(); ++i) {
        cout << "the i:" << res[i].second << endl;
        for (auto iter: res[i].first) {
            cout << iter << " ";
        }
        cout << endl;
    }

    return;
}
void findMinHeightTrees_310_solution::DFS(int n, vector<pair<vector<int>, bool>> &edges_bool, 
                                                          vector<int> &temp_res, int &hight) {
    bool flag = false;
    //查询是否已经搜索完成
    for (auto iter: edges_bool) {
        int posi = 0;
        if (find_num(n, iter, posi)) {
            flag = true;
            //cout << "pass in 2985" << endl;
        }
    }
    //cout << "pass in 2981" << endl;   
    //全部搜索完成，则返回                               
    if (flag == false) {
        temp_res.push_back(hight);
        return;
    }
    //对所有边进行查询，看该节点是否能去
    for (int i = 0; i < edges_bool.size(); ++i) {
        int posi = 0;
        if (find_num(n, edges_bool[i], posi)) {
            //能去， height+1
            hight ++;
            cout << "the iter :" << edges_bool[i].first[0] << "-" << edges_bool[i].first[1] << "-" 
                                                         << edges_bool[i].second << endl;
            edges_bool[i].second = true;
            cout << "the link :" << edges_bool[i].first[posi] << endl;
            DFS(edges_bool[i].first[posi], edges_bool, temp_res, hight); 
            hight --;
            edges_bool[i].second = false;
        }
    }
}

bool findMinHeightTrees_310_solution::find_num(int n, pair<vector<int>, bool> &edges_bool_num, 
                                                                                  int &posi) {
    //该边还没被使用过
    if (edges_bool_num.second == false) {
        //查询该节点是否在这条边
        auto iter = find(edges_bool_num.first.begin(), edges_bool_num.first.end(), n);
        if (iter != edges_bool_num.first.end()) {
            //cout << "the edge:" << iter[0] << "-" << iter[1] << endl;
            //posi = iter - edges_bool_num.first.begin();
            if (iter - edges_bool_num.first.begin() == 1) {
                posi = 0;
            } else {
                posi = 1;
            }
            return true;
        }
    }
    return false;
}
//删除无效的括号 leetcode
void removeInvalidParentheses_301_solution::removeInvaliaParentheses(string s) {
    int left = 0, right = 0;
    //计算那个括号多
    for (char i: s) {
        if (i == '(') {
            left++;
        } else if (i == ')') {
            if (left > 0) {
                left --;
            } else {
                right++;
            }
        }
    }
    int st = 0;
    DFS(s, st, left, right);

}
void removeInvalidParentheses_301_solution::DFS(string s, int st, int left, int right) {
    //左右括号一样多，且满足要求
    if (left == 0 && right == 0) {
        if (check(s)) {
            res.push_back(s);
        }
        return;
    }
    //从st点开始，一个一个点的检查
    for (int i = st; i < s.size(); ++i) {
        if (i - 1 >= st && s[i] == s[i - 1]) continue;
        if (left > 0 && s[i] == '(') {
            string temp = s.substr(0, i) + s.substr(i + 1, s.size() - i - 1);
            //cout << "the temp" << temp << endl;
            DFS(temp, i, left - 1, right);
        } else if (right > 0 && s[i] == ')') {
            string temp = s.substr(0, i) + s.substr(i + 1, s.size() - i - 1);
            //cout << "the temp" << temp << endl;
            DFS(temp, i, left, right - 1);
        }
    }
}
///检查string 是否满足要求
bool removeInvalidParentheses_301_solution::check(string s) {
    int cnt = 0;
    for (char i: s) {
        if (i == '(') {
            cnt ++;
        }
        if (i == ')') {
            cnt --;
            if (cnt < 0) return false;
        }
    }
    return cnt == 0;
}
//矩阵中的最长增长路径 leetcode_329
void longestIncreasingPath_329_solution::longestIncresingPath(vector<vector<int>> &matrix) {
    vector<vector<bool>> used;
    vector<bool> temp_used(matrix[0].size(), false);
    for (int i = 0; i < matrix.size(); ++i) {
        used.push_back(temp_used);
    }
    for (int row_posi = 0; row_posi < matrix.size(); ++row_posi) {
        for (int col_posi = 0; col_posi < matrix[0].size(); ++col_posi) {

            vector<int> temp_res;
            cout << "the matrix:" << row_posi << "-" << col_posi << "-" 
                                  << matrix[row_posi][col_posi] << endl;
            temp_res.push_back(matrix[row_posi][col_posi]);
            DFS(temp_res, row_posi, col_posi, matrix);
            cout << "the len of res: " << res.size() << endl;
            LonestPath(res);
            total_res.push_back(lonestPath);
            res.clear();
            lonestPath.clear();
        }
    }
    return;

}
void longestIncreasingPath_329_solution::DFS(vector<int> &temp_res, int &row_posi, int &col_posi,
                                             vector<vector<int>> &matrix) {
    ///没有路了，返回该点
    if (NoWay(row_posi, col_posi, temp_res, matrix) == true) {
        cout << "pass in 3113 " << endl;
        res.push_back(temp_res);
        //temp_res.pop_back();
        return;
    }
    //每个方向 搜索一边
    for (int i = 0; i < direct.size(); ++i) {
        cout << "the i: " << direct[i].first << "-" << direct[i].second << endl;
        int row = row_posi + direct[i].first;
        int col = col_posi + direct[i].second;
        if (row >= 0 && row < matrix.size() && col >= 0 && col < matrix[0].size() &&
                                 matrix[row][col] > temp_res[temp_res.size() - 1]) {
            cout << "pass in 3122" << endl;
            cout << "the matrix[i][j]: " << matrix[row][col] << endl;
            temp_res.push_back(matrix[row][col]);
            DFS(temp_res, row, col, matrix);
            //弹出
            temp_res.pop_back();
            
        }
    }
    
}
///寻找最长的路径
void longestIncreasingPath_329_solution::LonestPath(vector<vector<int>> res) {
    int index = 0;
    int len = res[0].size();
    for (int i = 0; i < res.size(); ++i) {
        if (res[i].size() > len) {
            index = i;
            len = res[i].size();
        }

    }
    for (int i = 0; i < res[index].size(); ++i) {
        lonestPath.push_back(res[index][i]);
    }
    return;
}
///检查该点各个方向，是否没有路了
bool longestIncreasingPath_329_solution::NoWay(int row_posi, int col_posi, 
                                               vector<int> &temp_res, vector<vector<int>> &matrix) {
    //各个方向的都小于temp_res[temp_res.size() - 1])
    if ( ((row_posi - 1 < 0) ||(row_posi - 1 >= 0 && 
                               matrix[row_posi - 1][col_posi] <= temp_res[temp_res.size() - 1])) &&
        ((row_posi + 1 >= matrix.size()) || (row_posi + 1 < matrix.size() && 
                                matrix[row_posi + 1][col_posi] <= temp_res[temp_res.size() - 1])) &&
        ((col_posi - 1 < 0) || (col_posi - 1 >= 0 
                              && matrix[row_posi][col_posi - 1] <= temp_res[temp_res.size() - 1])) &&
        ((col_posi + 1 >= matrix[0].size()) || (col_posi + 1 < matrix[0].size() 
                              && matrix[row_posi][col_posi + 1] <= temp_res[temp_res.size() - 1])) ) {
            return true;
        }
    return false;
}
//矩阵中的最长增长路径 leetcode_329
void longestIncreasingPath_329_solution2::longestIncresingPath2(vector<vector<int>> &matrix) {
    if (matrix.size() == 0) {
        return;
    }
    const int rows = matrix.size();
    const int cols = matrix[0].size();
    vector<vector<int>> dp(rows, vector<int>(cols, 1));
    vector<pair<pair<int, int>, int>> vp;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            //vp.push_back(point(i, j, matrix[i][j]));
            vp.push_back({{i, j}, matrix[i][j]});
        }
    }
    //排序 按值的大小
    sort(vp.begin(), vp.end(), [](const pair<pair<int, int>, int> &a, 
                                const pair<pair<int, int>, int> &b) {
        return a.second < b.second;
    });
    int ret = 1;
    cout << "pass in 3198" << endl;
    //对每一个点进行向前搜索
    for (int i = 0; i < vp.size(); ++i) {
        vector<int> temp_res;
        int posi = i;
        cout << "i in 3202:" << i << endl;
        temp_res.push_back(vp[i].first.first);
        temp_res.push_back(vp[i].first.second);
        temp_res.push_back(vp[i].second);
        DFS(temp_res, posi, vp, matrix);
    }
    return;

}
void longestIncreasingPath_329_solution2::DFS(vector<int> &temp_res, 
                    int &posi, vector<pair<pair<int, int>, int>> &vp, vector<vector<int>> &matrix) {
    if (Noway(vp, posi) == true) {
        cout << "pass in 3212" << endl;
        res.push_back(temp_res);
        return;
    }
    cout << "pass in 3215" << endl;
    for (int i = posi + 1; i < vp.size(); ++i) {
        if ( ((abs(vp[i].first.first - vp[posi].first.first) == 1 && 
              vp[i].first.second == vp[posi].first.second) && vp[i].second > vp[posi].second) ||
             ((abs(vp[i].first.second - vp[posi].first.second) == 1 && 
              vp[i].first.first == vp[posi].first.first) && vp[i].second > vp[posi].second) ) {
            temp_res.push_back(vp[i].second);
            posi = i;
            DFS(temp_res, posi, vp, matrix);
            ///不弹出
        }
    }
}

bool longestIncreasingPath_329_solution2::Noway(vector<pair<pair<int, int>, int>> &vp, int posi) {
    bool flag = true;
    for (int i = posi + 1; i < vp.size(); ++i) {
        if ( ((abs(vp[i].first.first - vp[posi].first.first) == 1 && 
              vp[i].first.second == vp[posi].first.second) && vp[i].second > vp[posi].second) ||
             ((abs(vp[i].first.second - vp[posi].first.second) == 1 && 
              vp[i].first.first == vp[posi].first.first) && vp[i].second > vp[posi].second) ) {
            flag = false;
        }
    }
    return flag;
}
//矩阵中的最长增长路径 leetcode_329 动态规划
void longestIncreasingPath_329_solution3::longestIncresingPath2(vector<vector<int>> &matrix) {
    if (matrix.size() == 0) {
        return;
    }
    rows = matrix.size();
    cols = matrix[0].size();
    vector<vector<vector<int>>> dp;
    vector<int> dp_temp_1;
    vector<vector<int>> dp_temp_2;
    vector<pair<pair<int, int>, int>> vp;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            //vp.push_back(point(i, j, matrix[i][j]));
            dp_temp_1.push_back(matrix[i][j]);
            dp_temp_2.push_back(dp_temp_1);
            dp_temp_1.clear();
            vp.push_back({{i, j}, matrix[i][j]});
        }
        dp.push_back(dp_temp_2);
        dp_temp_2.clear();
    }
    //排序 按值的大小
    //val的值从小到大
    sort(vp.begin(), vp.end(), [](const pair<pair<int, int>, int> &a, 
                                const pair<pair<int, int>, int> &b) {
        return a.second < b.second;
    });
    int ret = 1;
    cout << "pass in 3198" << endl;
    //对每一个点进行向前搜索
    //先从最大的开始，因为大值的路径肯定是所有小值路径的部分
    for (int i = vp.size() - 1; i >= 0; --i) {
        //vector<int> temp_res;
        int posi = i;
        DFS(dp, posi, vp, matrix);
    }
    print(dp);
    return;
}
void longestIncreasingPath_329_solution3::DFS(vector<vector<vector<int>>> &dp, int &posi, 
            vector<pair<pair<int, int>, int>> &vp, vector<vector<int>> &matrix) {
    int x = vp[posi].first.first;
    int y = vp[posi].first.second;
    int val = vp[posi].second;
    int longest = 0, best_row = 0, best_col = 0;
    //4个方向都要进行搜索
    for (int i = 0; i < direct.size(); ++i) {
        int row = direct[i].first + x;
        int col = direct[i].second + y;
        if (row >= 0 && row < matrix.size() && col >= 0 && col < matrix[0].size() &&
                                 matrix[row][col] > val) {
            //找出路径最长的方向
            if (dp[row][col].size() > longest) {
                longest = dp[row][col].size();
                best_row = row;
                best_col = col;
            }                      
        }
    }
    //将路径最长的插入到前一个点
    if (longest != 0) {
        dp[x][y].insert(dp[x][y].end(), dp[best_row][best_col].begin(), 
                                        dp[best_row][best_col].end());
    }
    return;
}
///打印
void longestIncreasingPath_329_solution3::print(vector<vector<vector<int>>> &dp) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            for (auto iter: dp[i][j]) {
                cout << iter << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;
    return;
}
//重新安排行程 leetcode_332
void findItinerary_332_solution::findItinerary(vector<vector<string>> &tickets) {
    vector<string> cities;
    for (auto &iter: tickets) {
        cities.push_back(iter[0]);
        cities.push_back(iter[1]);
    }
    cout << "the size of cities: " << cities.size() << endl;
    cout << endl;
    //排序
    sort(cities.begin(), cities.end());
    //删除重复项
    cities.erase(unique(cities.begin(), cities.end()), cities.end());
    for (int i = 0; i < cities.size(); ++i) {
        cout << cities[i] << " ";
    }
    cout << endl;
    int N = cities.size();
    map<string, int> m;
    //将sting 转化为ID
    for (int i = 0; i < N; ++i) {
        m[cities[i]] = i;
    }
    //构建有向图
    vector<vector<int>> g(N, vector<int>(N, 0));
    for (auto &t: tickets) {
        ++g[m[t[0]]][m[t[1]]];
    }
    //深度优先搜索最终路径
    vector<int> path;
    path.push_back(m["JFK"]);
    DFS(g, m["JFK"], N, path);
    //total_path.push_back(path);
    //将path转化为res
    for (int j = 0; j < total_path.size(); ++j) {
        vector<string> res;
        for (auto i: total_path[j]) {
            res.push_back(cities[i]);
        }
        //reverse(res.begin(), res.end());
        total_res.push_back(res);
    }
    //reverse(res.begin(), res.end());
    for (int i = 0; i < total_res.size(); ++i) {
        for (auto iter: total_res[i]) {
            cout << iter << " ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}
void findItinerary_332_solution::DFS(vector<vector<int>> &g, int i, int N, vector<int> &path) {
    if (NoWay(g, i, N) == true) {
        //path.push_back(i);
        total_path.push_back(path);
        cout << "add one" << endl;
        return;
    }
    for (int j = 0; j < N; ++j) {
        if (g[i][j] > 0) {
            --g[i][j];
            path.push_back(j);
            //cout << "the i in 3386: " << i << endl;
            cout << "the j in 3383:" << j << endl;
            DFS(g, j, N, path);
            ++g[i][j];
            path.pop_back();
        }
    }
}

bool findItinerary_332_solution::NoWay(vector<vector<int>> &g, int i, int N) {
    bool flag = true;
    for (int j = 0; j < N; ++j) {
        if (g[i][j] > 0) {
            flag = false;
        }
    }
    return flag;
}
///太平洋大西洋水流问题 leetcode_417
void pacificAtlantic_417_solution::pacificAtlantic(vector<vector<int>> &matrix) {
    rows = matrix.size();
    cols = matrix[0].size();
    ///val : 0 -> cannot  1 -> can
    //大西洋
    vector<vector<int>> Atlantic_matrix(rows, vector<int>(cols, 0));
    //val: 0 -> cannot 1 -> can
    //太平洋
    vector<vector<int>> pacific_matrix(rows, vector<int>(cols, 0));
    //边上的先设置为1
    for (int i = 0; i < cols; ++i) {
        pacific_matrix[0][i] = 1;
        Atlantic_matrix[rows - 1][i] = 1; 
    }
    //边上的先设置为1
    for (int j = 0; j < rows; ++j) {
        pacific_matrix[j][0] = 1;
        Atlantic_matrix[j][cols - 1] = 1;
    }
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            ///每次都要重新刷新used
            vector<vector<bool>> pace_used(rows, vector<bool>(cols, false));
            vector<vector<bool>> Atlan_used(rows, vector<bool>(cols, false));
            cout << "the row and col in 3426:" << i << " " << j << endl;
            pace_used[i][j] = true;
            pacific(i, j, pacific_matrix, matrix, pace_used);
            int At_row = rows - i - 1;
            int At_col = cols - j - 1;
            Atlan_used[At_row][At_col] = true;
            Atlantic(At_row, At_col, Atlantic_matrix, matrix, Atlan_used);
        }
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            ///都为1,表示可以同时刘向大西洋和太平洋
            if (pacific_matrix[i][j] == 1 && Atlantic_matrix[i][j] == 1) {
                vector<int> temp;
                temp.push_back(i);
                temp.push_back(j);
                res.push_back(temp);
            }

        }
    }

    return;
}
void pacificAtlantic_417_solution::pacific(int &row, int &col, vector<vector<int>> &pacific_matrix, 
                                    vector<vector<int>> &matrix, vector<vector<bool>> &pace_used) {
    ///搜索到了边界，可以到达
    if (row == 0 || col == 0) {
        pacific_matrix[row][col] = 1;
        return;
    }
    //没有再往前的路了
    if (Noway(row, col, matrix, pace_used) == false) {
        return;
    }
    ///每个方向进行搜素
    for (int i = 0; i < direct.size(); ++i) {
        int row_next = row + direct[i].first;
        int col_next = col + direct[i].second;
        //满足要求
        if (posi_right(row_next, col_next) && matrix[row_next][col_next] <= matrix[row][col]) {
            ///使用过了
            pace_used[row_next][col_next] = true;
            if (pacific_matrix[row_next][col_next] == 1) {
                pacific_matrix[row][col] = 1;
                break;
            } else {
                pacific(row_next, col_next, pacific_matrix, matrix, pace_used);
                pacific_matrix[row][col] = pacific_matrix[row_next][col_next];
            }
        }
    }
}
void pacificAtlantic_417_solution::Atlantic(int &row, int &col, vector<vector<int>> &Atlantic_matrix, 
                                           vector<vector<int>> &matrix, vector<vector<bool>> &Atlan_used) {
    if (row == rows - 1 || col == cols - 1) {
        Atlantic_matrix[row][col] = 1;
        return;
    } 
    if (Noway(row, col, matrix, Atlan_used) == false) {
        return;
    }
    for (int i = 0; i < direct.size(); ++i) {
        int row_next = row + direct[i].first;
        int col_next = col + direct[i].second;
        if (posi_right(row_next, col_next) && matrix[row_next][col_next] <= matrix[row][col]) {
            Atlan_used[row_next][col_next] = true;
            if (Atlantic_matrix[row_next][col_next] == 1) {
                Atlantic_matrix[row][col] = 1;
                break;
            } else {
                Atlantic(row_next, col_next, Atlantic_matrix, matrix, Atlan_used);
                Atlantic_matrix[row][col] = Atlantic_matrix[row_next][col_next];
            }
        }
    }

}
bool pacificAtlantic_417_solution::Noway(int row, int col, vector<vector<int>> &matrix, 
                                                           vector<vector<bool>> &used) {
    bool flag = false;
    for (int i = 0; i < direct.size(); ++i) {
        int row_next = row + direct[i].first;
        int col_next = col + direct[i].second;
        if (posi_right(row_next, col_next) && matrix[row_next][col_next] <= matrix[row][col] 
                                                    && used[row_next][col_next] == false) {
            flag = true;
        }
    }
    return flag;
}
bool pacificAtlantic_417_solution::posi_right(int row, int col) {
    int flag = false;
    if (row >= 0 && row < rows && col >= 0 && col < cols) {
        flag = true;
    }
    return flag;
}
/////验证二叉树 leetcode
bool isValidBST_98_solution::isValidBST(Bitnode<char>* root) {
    if (root == NULL) {
        cout << "form this root, this is a empty tree" << endl;
        return flag;
    }
    int root_val = (int)root->val - 48;
    if ( (root->left == NULL && root->right != NULL) ||
                       (root->left != NULL && root->right == NULL)) {
        cout << "int the root:" << root_val << " the is not BST with no left or right" << endl;
        flag = false;
        return flag;
    }
    if (root->left != NULL && root->right != NULL) {
        int left_val = (int)root->left->val - 48;
        //int root_val = (int)root->val - 48;
        int right_val = (int)root->right->val - 48;
        cout << "the left, root, right val:" << left_val << " " << root_val 
                                              << " " << right_val << endl;
        if ( left_val >= root_val || right_val <= root_val ) {
            
            cout << "int the root:" << root_val << " the is not BST" << endl;
            flag = false;
            return flag;
        }
        isValidBST(root->left);
        isValidBST(root->right);
    }
}
//二叉树的层次c遍历
void levelOrder_102_solution::levelOrder(Bitnode<char> * root) {
    vector<Bitnode<char>*> vec;
    vec.push_back(root);
    int cur = 0;
    int last = 1;
    while (cur < vec.size()) {
        last = vec.size(); //重新置上一层节点数
        vector<char> res_temp;
        while (cur < last) {  // 计数还么到
            res_temp.push_back(vec[cur]->val);
            if (vec[cur]->left) { //不为空则压入
                vec.push_back(vec[cur]->left);
            }
            if (vec[cur]->right) { // 不为空则压入
                vec.push_back(vec[cur]->right);
            }
            cur ++; //层数加1
        }
        res.push_back(res_temp);
        cout << endl; // cur = last 都已经被遍历完事了
    }

}
///队列
void levelOrder_102_solution::levelOrder2(Bitnode<char>* root) {
    queue<Bitnode<char>*> vec;
    vec.push(root);
    while(!vec.empty()) {
        int len = vec.size();
        vector<char> res_temp;
        for (int i = 0; i < len; ++i) {
            Bitnode<char>* top = vec.front();
            res_temp.push_back(top->val);
            if (top->left != NULL) {
                vec.push(top->left);
            }
            if (top->right != NULL) {
                vec.push(top->right);
            }
            vec.pop();
        }
        res.push_back(res_temp);
    }

}
//递归
void levelOrder_102_solution::levelOrder3(Bitnode<char>* root) {
    if (!root) return;
    int n = howlen(root);
    res.resize(n);
    DFS(root, 0);
    return;

}
void levelOrder_102_solution::DFS(Bitnode<char>* root, int n) {
    res[n].push_back(root->val);
    if (root->left) DFS(root->left, n + 1);
    if (root->right) DFS(root->right, n + 1); 

}
//用递归求总层数
int levelOrder_102_solution::howlen(Bitnode<char>* root) {
    if (root == NULL) return 0;
    return max(howlen(root->left), howlen(root->right)) + 1;

}
///二叉树的锯齿型层次遍历
void zigzaglevelOrder_103_solution::zigzaglevelOrder(Bitnode<char>* root) {
    queue<Bitnode<char>*> vec;
    vec.push(root);
    while(!vec.empty()) {
        int len = vec.size();
        vector<char> res_temp;
        for (int i = 0; i < len; ++i) {
            Bitnode<char>* top = vec.front();
            res_temp.push_back(top->val);
            if (flag == 0) {
                if (top->right != NULL) {
                    vec.push(top->right);
                }
                if (top->left != NULL) {
                    vec.push(top->left);
                }
            }
            if (flag == 1) {
                if (top->left != NULL) {
                    vec.push(top->left);
                }
                if (top->right != NULL) {
                    vec.push(top->right);
                }
            }
            vec.pop();
        }
        inverse(flag);
        res.push_back(res_temp);
    }

}
///二叉树的锯齿型层次遍历
void zigzaglevelOrder_103_solution::inverse(int &flag) {
    if (flag == 0) {
        flag = 1;
        return;
    }
    if (flag == 1) {
        flag = 0;
        return;
    }
}
////路径总和2 leetcode_113
void pathSum_113_solution::pathSum(Bitnode<char>* root, int sum) {
    vector<int> temp_res;
    if (root == NULL) {
        cout << "the root is NULL" << endl;
        return;
    }
    DFS(root, sum, temp_res);
    return;
}

void pathSum_113_solution::DFS(Bitnode<char>* root, int sum, vector<int> &temp_res) {

    cout << "the res: " << root->val << endl;
    int temp = root->val - 48;
    temp_res.push_back(temp);
    print(temp_res);
    if (accumulate(temp_res.begin(),temp_res.end(),0) == sum) {
        res.push_back(temp_res);
        //temp_res.clear();
        cout << "pass in 3681" << endl;
        return;
    }
    //访问左边的叉树
    if (root->left != NULL) {
        cout << "pass in 3690" << endl;
        DFS(root->left, sum, temp_res);
        temp_res.pop_back();
    }
    //访问右边的叉树
    if (root->right != NULL) {
        cout << "pass in 3694" << endl;
        DFS(root->right, sum, temp_res);
        temp_res.pop_back();
    }

}

void pathSum_113_solution::print(vector<int> &temp_res) {
    cout << "the temp_res: " << endl;
    for (int i = 0; i < temp_res.size(); ++i) {
        cout << temp_res[i] << " ";
    }
    cout << endl;
}
/////二叉树转化为链表 leetcode_114
void flatten_114_solution::flatten(Bitnode<char> *root) {
    if (root == NULL) {
        cout << "the root is NULL" << endl;
    }
    DFS(root);
    return;

}
void flatten_114_solution::DFS(Bitnode<char> *root) {
    char temp = root->val;
    res.push_back(temp);
    if (root->left != NULL) {
        DFS(root->left);
    }
    if (root->right != NULL) {
        DFS(root->right);
    }
}
//////求根到叶子节点的数字之和
void sumNumbers_129_solution::sumNumbers(Bitnode<char>* root) {
    vector<int> temp_res;
    if (root == NULL) {
        cout << "the root is NULL" << endl;
        return;
    }
    DFS(root, temp_res);
    return;

}
void sumNumbers_129_solution::DFS(Bitnode<char>* root, vector<int> &temp_res) {
    cout << "the res: " << root->val << endl;
    int temp = root->val - 48;
    temp_res.push_back(temp);
    if (root->left == NULL && root->right == NULL) {
        res.push_back(temp_res);
        //temp_res.clear();
        cout << "pass in 3681" << endl;
        return;
    }
    //访问左边的叉树
    if (root->left != NULL) {
        cout << "pass in 3690" << endl;
        DFS(root->left, temp_res);
        temp_res.pop_back();
    }
    //访问右边的叉树
    if (root->right != NULL) {
        cout << "pass in 3694" << endl;
        DFS(root->right, temp_res);
        temp_res.pop_back();
    }
}
//二叉树的右视图
void rightSideView_199_solution::rightSideView(Bitnode<char>* root) {
    if (root == NULL) {
        cout << "the root is NULL" << endl;
        return;
    }
    right_DFS(root);
    return;
}
void rightSideView_199_solution::right_DFS(Bitnode<char>* root) {
    char temp = root->val;
    res.push_back(temp);
    //先往右搜索
    if (root->right != NULL) {
        right_DFS(root->right);
    } else if (root->left != NULL) { // 没有右叉树，只能搜索左叉树
        right_DFS(root->left);
    }
    return;

}
////二叉树中的第K小的元素
//使用优先队列
void KthSmallest_230_solution::KthSmallest(Bitnode<char>* root, int k) {
    if (root ==NULL) {
        cout << "the root is NULL" << endl;
        return;
    }
    DFS(root, k);
    return;
}
void KthSmallest_230_solution::DFS(Bitnode<char>* root, int k) {
    int temp = root->val - 48;
    cout << "the temp:" << temp << endl;
    if (queue.size() < k) {
        queue.push(temp);
    } else if (queue.top() > temp) { ///判断该节点的值是否可以插入，如果小于最大值，则可以插入
    //小于该大顶堆中的最大值，也是top
        queue.pop();
        queue.push(temp);
    }
    ///向左叉树
    if (root->left != NULL) {
        DFS(root->left, k);
    }
    ///向右叉树
    if (root->right != NULL) {
        DFS(root->right, k);
    }
    cout << "the top:" << queue.top() << endl;
    return;
}
////二叉树的最近公共祖先 leetcode_236
void lowestCommonAncestor_236_solution::lowestCommonAncestor(Bitnode<char>* root, 
                                            Bitnode<char>* p, Bitnode<char>* q) {
    if (root == NULL) {
        cout << "the root is NULL" << endl;
        return;
    }
    DFS(root, p, q);
    return;
}
void lowestCommonAncestor_236_solution::DFS(Bitnode<char>* root, Bitnode<char>* p, 
                                                              Bitnode<char>* q) {
    /*if (root->val == p->val || root->val == q->val) {
        return;
    }*/
    bool flag_p = false, flag_q = false;
    bool search_res = false;
    bool temp = search_ancestor(root, p, q, flag_p, flag_q, search_res);
    if (temp == true) {
        res.push_back(root->val);
        if (root->left != NULL) {
            DFS(root->left, p, q);
        }
        if (root->right != NULL) {
            DFS(root->right, p, q);
        }
    }

}
bool lowestCommonAncestor_236_solution::search_ancestor(Bitnode<char>* root, 
          Bitnode<char>* p, Bitnode<char>* q, bool &flag_p, bool &flag_q, bool &search_res) {
    //两个都找到了
    if (flag_p == true && flag_q == true) {
        search_res = true;
        return search_res;
    }
    int temp_root = root->val;
    //判断root是否要找的点
    if (root == q) {
        flag_q = true;
    }
    if (root == p) {
        flag_p = true;
    }
    ///向左叉树搜索
    if (root->left != NULL) {
        ///比较两个指针是否为同一个指针，可以通过比较两个指针所指向的值相等来判断吗？ 不可以
        if (root->left == q) {
            flag_q = true;
        }
        if (root->left == p) {
            flag_p = true;
        }
        ///继续搜索
        search_ancestor(root->left, p, q, flag_p, flag_q, search_res);
    }
    if (root->right != NULL) {
        if (root->right == q) {
            flag_q = true;
        }
        if (root->right == p) {
            flag_p = true;
        }
        search_ancestor(root->left, p, q, flag_p, flag_q, search_res);
    }

}
///找树左下角的值 leetcode_513
void findBottomLeftValue_513_solution::findBottomLeftValue(Bitnode<char>* root) {
    queue<Bitnode<char>*> vec;
    vec.push(root);
    while(!vec.empty()) {
        int len = vec.size();
        vector<char> res_temp;
        for (int i = 0; i < len; ++i) {
            Bitnode<char>* top = vec.front();
            res_temp.push_back(top->val);
            if (top->left != NULL) {
                vec.push(top->left);
            }
            if (top->right != NULL) {
                vec.push(top->right);
            }
            vec.pop();
        }
        res.push_back(res_temp);
    }

}
////在每一个树行中找最大值
void largestValue_515_solution::largestValue(Bitnode<char>* root) {
    queue<Bitnode<char>* > vec;
    vec.push(root);
    while(!vec.empty()) {
        int len = vec.size();
        int temp_max = INT32_MIN;
        for (int i = 0; i < len; ++i) {
            Bitnode<char>* top = vec.front();
            int val = top->val - 48;
            temp_max = max(temp_max, val);
            if (top->left != NULL) {
                vec.push(top->left);
            }
            if (top->right != NULL) {
                vec.push(top->right);
            }
            vec.pop();
        }
        res.push_back(temp_max);
    }
}
//火柴拼正方形 leetcode_473 
void makesquare_473_solution::makesquare(vector<int> &nums) {
    nums_ = nums;
    if (nums.size() < 4) {
        flag = false;
        return;
    }    
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 4 !=0) {
        flag = false;
        return;
    }
    target = sum / 4;
    sort(nums_.begin(), nums_.end(), greater<int>());
    vector<vector<int>> res(4, vector<int>());
    cout << "pass in 3944" << endl;
    DFS(0, res);
    cout << "pass in 3946" << endl;
    for (int i = 0; i < total.size(); ++i) {
        for (int j = 0; j < total[i].size(); ++j) {
            for (auto iter: total[i][j]) {
                cout << iter << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    cout << endl;
    return;
}

void makesquare_473_solution::DFS(int index, vector<vector<int>> &res) {
    if (index == nums_.size()) {
        int sum1 = accumulate(res[0].begin(), res[0].end(), 0);
        int sum2 = accumulate(res[1].begin(), res[1].end(), 0);
        int sum3 = accumulate(res[2].begin(), res[2].end(), 0);
        int sum4 = accumulate(res[3].begin(), res[3].end(), 0);
        if (sum1 == sum2 && sum2 == sum3 && sum3 == sum4) {
            flag = true;
            total.push_back(res);
            cout << "pass in 3958" << endl;
            return;
        }
    }
    for (int i = 0; i < 4; ++i) {
        //不满足要求， 跳过
        if (accumulate(res[i].begin(), res[i].end(), 0) + nums_[index] > target) {
           continue;
        }
        res[i].push_back(nums_[index]);
        cout << "pass in 3965" << endl;
        print_vector(res);
        DFS(index + 1, res);
        //print_vector(res);
        res[i].pop_back();
        cout << "pass in 3971" << endl;
        //print_vector(res);
    }
    
}
///输出vector
void makesquare_473_solution::print_vector(vector<vector<int>> &res) {
    for (int i = 0; i < res.size(); ++i) {
        for (int j = 0; j < res[i].size(); ++j) {
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}
///最长连续序列 leetcode_128
void longestConsecutive_128_solution::longestConsecutive(vector<int> &nums) {
    //从大到小排序
    //sort(nums.begin(), nums.end(), greater<int>());
    //从小到大排序
    sort(nums.begin(), nums.end(), less<int>());
    //元素个数从大到小排序
    auto comp = [](const vector<int> &res1, const vector<int> &res2) {
        return res1.size() > res2.size();
    };
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    res.push_back(nums[0]);
    for (int i = 1; i < nums.size(); ++i) {
        //nums[i] 与 res的最后元素相连续
        if (nums[i] == res[res.size() - 1] + 1) {
            res.push_back(nums[i]);
        } else {
            total_res.push_back(res);
            res.clear();
            res.push_back(nums[i]);
        }
    }
    total_res.push_back(res);
    //按vector<vector<int>> total_res中的元素vector<int> res的个数从大到小排序
    sort(total_res.begin(), total_res.end(), comp);
    for (int i = 0; i < total_res.size(); ++i) {
        for (int j = 0; j < total_res[i].size(); ++j) {
            cout << total_res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return;
}
void longestConsecutive_128_solution::longestConsecutive2(vector<int> &nums) {
    if (nums.empty()) {
        cout << "the nums is empty" << endl;
        return;
    }
    unordered_set<int> nums_set(nums.begin(), nums.end());
    for (auto num: nums) {
        cout << "the num in 4045:" << num << endl;
        if (nums_set.count(num - 1) == 0) {
            res.push_back(num);
            while(nums_set.count(num + 1)) {
                res.push_back(num + 1);
                num = num + 1;
            }

        }
        cout << "the num in 4054:" << num << endl;
        if (!res.empty()) {
            total_res.push_back(res);
        }
        res.clear();
    }
    cout << "the size of total_res: " << total_res.size() << endl;
    for (int i = 0; i < total_res.size(); ++i) {
        for (int j = 0; j < total_res[i].size(); ++j) {
            cout << total_res[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return;

}

//并查集#TODO
class UF1 {
public:
    int count;
    //存储整个朋友圈
    vector<vector<int>> circle;
    vector<vector<int>> last_circle;
    //存储一个圈子
    unordered_map<int, int> parent;
    //记录朋友圈人数
    vector<int> size;
    vector<int> nums_;
    UF1(vector<int> &nums) {
        nums_ = nums;
        count = nums.size();
        vector<vector<int>> temp_circle(count, vector<int>());
        circle = temp_circle;
        vector<int> temp(count, -1);
        size = temp;
        for (int i = 0; i < count; ++i) {
            vector<int> vector_temp;
            parent[nums[i]] = nums[i];
            size[nums[i]] = 1;
            vector_temp.push_back(nums[i]);
            circle[i] = vector_temp;
        }
        cout << "circle in 4096" << endl;
        printCircle(circle);
    }
    void Union(int p, int q) {
        int rootP =find(p);
        int rootQ = find(q);
        cout << "the p and rootP:" << p << " " << rootP << endl;
        cout << "the q and rootQ:" << q << " " << rootQ << endl;
        if (rootQ == rootP) {
            cout << "the p and rootP:" << p << " " << rootP << endl;
            cout << "the q and rootQ:" << q << " " << rootQ << endl;
            cout << "they have connected before" << endl;
            return;
        }
        //得到index in circle
        int rootP_idx = get_index(rootP);
        int rootQ_idx = get_index(rootQ);
        if (size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] = size[rootP] + size[rootQ];
            //将circle Q 添加到  circle P
            //circle[rootP].insert(circle[rootP].end(), circle[rootQ].begin(), circle[rootQ].end());
            circle[rootP_idx].insert(circle[rootP_idx].end(), circle[rootQ_idx].begin(), circle[rootQ_idx].end());
            circle[rootQ_idx].clear();
        } else {
            parent[rootP] = rootQ;
            size[rootQ] = size[rootP] + size[rootQ];
             //将circle P 添加到  circle Q
            circle[rootQ_idx].insert(circle[rootQ_idx].end(), circle[rootP_idx].begin(), circle[rootP_idx].end());
            circle[rootP_idx].clear();
        }
        printCircle(circle);
        count --;
        return;

    }
    bool connected(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        return rootP = rootQ;
    }
    ///找根节点
    int find(int x) {
        while (parent[x] != x) {
            //路径压缩
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    int Count () {
        return count;
    }
    void Circle() {
        for (int i = 0; i < circle.size(); ++i) {
            if (circle[i].size() != 0) {
                last_circle.push_back(circle[i]);
            } 
        }
        return;
    }
    void printCircle(vector<vector<int>> &circle) {
        for (int i = 0; i < circle.size(); ++i) {
            if (circle[i].size() == 0) {
                continue;
            }
            for (int j = 0; j < circle[i].size(); ++j) {
                cout << circle[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    int get_index(int root) {
        int res = 0;
        for (int i = 0; i < nums_.size(); ++i) {
            if (nums_[i] == root) {
                res = i;

            }
        }
        return res;
    }

};
void longestConsecutive_128_solution::longestConsecutive3(vector<int> &nums) {
    
    if (nums.size() == 0) {
        cout << "the nums is empty" << endl;
        return;
    }
    UF1 uf(nums);

    cout << endl;
    for (auto x: nums) {
        if (uf.parent.count(x - 1) > 0) {
            uf.Union(x, x - 1);
        }
    }

    uf.Circle();
    cout << "the last circle: " << endl;
    uf.printCircle(uf.last_circle);
    cout << "the circle: " << endl;
    uf.printCircle(uf.circle);
    
    cout << "the num of circle: " << uf.count << endl;
    return;

}

///并查集 API
class UF {
public:
    int count;
    //存储整个朋友圈
    vector<vector<int>> circle;
    vector<vector<int>> last_circle;
    //存储一个圈子
    vector<int> parent;
    //记录朋友圈人数
    vector<int> size;
    UF(int n) {
        count = n;
        vector<vector<int>> temp_circle(n, vector<int>());
        circle = temp_circle;
        vector<int> temp(n, -1);
        parent = temp;
        size = temp;
        for (int i = 0; i < n; ++i) {
            vector<int> vector_temp;
            parent[i] = i;
            size[i] = 1;
            vector_temp.push_back(i);
            circle[i] = vector_temp;
        }
    }
    void Union(int p, int q) {
        int rootP =find(p);
        int rootQ = find(q);
        if (rootQ == rootP) {
            cout << "they have connected before" << endl;
            return;
        }
        if (size[rootP] > size[rootQ]) {
            parent[rootQ] = rootP;
            size[rootP] = size[rootP] + size[rootQ];
            //将circle Q 添加到  circle P
            circle[rootP].insert(circle[rootP].end(), circle[rootQ].begin(), circle[rootQ].end());
            circle[rootQ].clear();
        } else {
            parent[rootP] = rootQ;
            size[rootQ] = size[rootP] + size[rootQ];
             //将circle P 添加到  circle Q
            circle[rootQ].insert(circle[rootQ].end(), circle[rootP].begin(), circle[rootP].end());
            circle[rootP].clear();
        }
        count --;

    }
    bool connected(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        return rootP = rootQ;
    }
    ///找根节点
    int find(int x) {
        while (parent[x] != x) {
            //路径压缩
            parent[x] = parent[parent[x]];
            x = parent[x];
        }
        return x;
    }
    int Count () {
        return count;
    }
    void Circle() {
        for (int i = 0; i < circle.size(); ++i) {
            if (circle[i].size() != 0) {
                last_circle.push_back(circle[i]);
            } 
        }
        return;
    }
    void printCircle(vector<vector<int>> &circle) {
        for (int i = 0; i < circle.size(); ++i) {
            for (int j = 0; j < circle[i].size(); ++j) {
                cout << circle[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

};

void findCircleNum_547_solution::findCircleNum(vector<vector<int>> &nums) {
    int n = nums.size();
    UF uf(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[i][j] == 1) {
                uf.Union(i, j);
            }
        }
    }
    uf.Circle();
    cout << "the last circle: " << endl;
    uf.printCircle(uf.last_circle);
    cout << "the circle: " << endl;
    uf.printCircle(uf.circle);
    
    cout << "the num of circle: " << uf.count << endl;
    return;
}
////除法求值
class UF399 {
public:
    unordered_map<string, string> fa;
    //string / root = val  a/b = 2; f[a] = b, val[a] = 2 * val[b]
    unordered_map<string, double> val;
    bool exit(const string &x) {
        return fa.find(x) != fa.end();
    }
    void init(const string &x) {
        if(exit(x)) {
            cout << "in this init, the x is exit " << endl;
            return;
        }
        val[x] = 1.0;
        fa[x] = x;
    }
    string getFather(string x) {
        while(x != fa[x]) {
            //string f = getFather(fa[x]);
            //fa[x] = fa[fa[x]];
            //val[x] = val[x] * val[fa[x]];
            x = fa[x];
        }
        return x;
        
    }
    void merge(string &a, string &b, double v) {
        init(a);
        init(b);
        string root_a = getFather(a);
        string root_b = getFather(b);
        fa[root_a] = root_b;
        val[root_a] = val[b] * 1.0 /val[a] * v; 
        cout << "a and b:" << a << " " << b << endl;
        cout << "the val[a] and val[b] in 4348: " << val[a] << " " << val[b] << endl;
        
    }
    double ask(string &a, string &b) {
        if (!exit(a) || !exit(b)) {
            cout << "the a or b do not exit" << endl;
            return -1;
        }
        string root_a = getFather(a);
        string root_b = getFather(b);
        cout << "the root_a and root_b: " << root_a << " " << root_b << endl;
        if (root_a != root_b) {
            cout << "the a and b has not connection" << endl;
            return -1;
        }
        cout << "the val[a] and val[b]: " << val[a] << " " << val[b] << endl;
        return val[a] * 1.0 / val [b];
    }

};
///并查集

void calcEquation_399_solution::calcEquation(vector<vector<string>> &equations, 
                            vector<double> &val, vector<vector<string>> &query){
    if (equations.size() == 0 && val.size() == 0) {
        cout << "the nums is empty" << endl;
        return;
    }
    UF399 uf;
    for (int i = 0; i < equations.size(); ++i) {
        uf.merge(equations[i][0], equations[i][1], val[i]);
    }
    vector<int> res;
    for (int i = 0; i < query.size(); ++i) {
        res.push_back(uf.ask(query[i][0], query[i][1]));
    }
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " " << endl;
    }

    return;
}

medianFinder::medianFinder() {
}
void medianFinder::addNum(int num) {
    collector.push_back(num);
    return;

}
double medianFinder::findMedian() {
    double res;
    sort(collector.begin(), collector.end());
    int len = collector.size();
    if (len % 2 == 0) {
        res = ((collector[len / 2 -1] + collector[len / 2]) * 1.0) * 0.5;

    } else {
        res = collector[len / 2] * 1.0;
    }
    cout << "the median: " << res << endl;
    return res;

}
/////合并排序数组 
void merge_1680_solution::merge(vector<int> &A, int m, vector<int> &B, int n) {
    for (int i = 0; i < n; ++i) {
        A[m + i] = B[i];
    }
    sort(A.begin(), A.end(), less<int>());
    for (int i = 0; i < A.size(); ++i) {
        cout << A[i] << " ";
    }
    cout << endl;

    return;
}
//双指针
void merge_1680_solution::merge2(vector<int> &A, int m, vector<int> &B, int n) {
    vector<int> res;
    int idx_A = 0, idx_B = 0;
    while (idx_A < m || idx_B < n) {
        if (idx_A == m) {
            res.push_back(B[idx_B]);
            idx_B ++;
        } else if (idx_B == n) {
            res.push_back(A[idx_A]);
            idx_A ++;
        }
        else if (A[idx_A] < B[idx_B]) {
            res.push_back(A[idx_A]);
            idx_A ++;
        } else {
            res.push_back(B[idx_B]);
            idx_B ++;
        }
    }
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return;

}
////逆向指针 从后面开始，因为后面是空的，占位子，但是没有数
void merge_1680_solution::merge3(vector<int> &A, int m, vector<int> &B, int n) {
    int idx_A = m - 1, idx_B = n - 1;
    int posi = A.size() - 1;
    while (idx_A >= 0 || idx_B >= 0) {
        if (idx_A == m) {
            A[posi] = B[idx_B];
            idx_B --;
        } else if (idx_B == n) {
            A[posi] = A[idx_A];
            idx_A --;
        }
        else if (A[idx_A] > B[idx_B]) {
            A[posi] = A[idx_A];
            idx_A --;
        } else {
            A[posi] = B[idx_B];
            idx_B --;
        }
        posi--;
    }
    for (int i = 0; i < A.size(); ++i) {
        cout << A[i] << " ";
    }
    cout << endl;
    return;
}
////存在重复元素 leetcode_220
//寻找两个数 abs(nums[i] - num [j]) < t   abs(i - j) < k
void containNearbyAlmost_220_solution::containNearbyAlmost(vector<int> &nums, int k, int t) {
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = max(i - k, 0); j < i; ++j) {
            if (abs(nums[i] - nums[j]) <= t) {
                res.push_back({nums[i], nums[j]});
            }
        }
    }
}

 void containNearbyAlmost_220_solution::containNearbyAlmost2(vector<int> &nums, int k, int t) {
     set<long> ss;
     long it = t;
     for (int i = 0; i < nums.size(); ++i) {
         set<long>::iterator iter_s = ss.lower_bound(nums[i]); //第一个大于nums[i]
         if(iter_s != ss.end() && ((*iter_s) <= nums[i] + t)) {
             res.push_back({*iter_s, nums[i]});
         }
         set<long>::iterator iter_g = ss.upper_bound(nums[i]);
         if (iter_g != ss.end() && nums[i] <= (*iter_g + t)) {
             res.push_back({*iter_g, nums[i]});
         }
         ss.insert(nums[i]);
         if (ss.size() > k) {
             ss.erase(nums[i - k]);
         }

     }
     return;

 }
//桶排序
 void containNearbyAlmost_220_solution::containNearbyAlmost3(vector<int> &nums, int k, int t) {
     if (t < 0) {
         cout << "there is no res" << endl;
         return;
     }
     long long mod = t + 1LL;
     unordered_map<long long, long long > buck;
     for (int i = 0; i < nums.size(); ++i) {
         long long nth = nums[i] / mod;
         // -4 / 5 = 0 所以负数应该减去1， -6 / 5 = -1, 也因该减去1
         if (nums[i] < 0) nth --;
         if (buck.find(nth) != buck.end()) {
             res.push_back({0, 0});
         } else if (buck.find(nth - 1) != buck.end() && abs(nums[i] - nums[nth - 1]) <= t) {
             res.push_back({nums[i], nums[nth - 1]});
         } else if (buck.find(nth + 1) != buck.end() && abs(nums[i] - nums[nth + 1]) <= t) {
             res.push_back({nums[i], nums[nth + 1]});
         }
         buck[nth] = nums[i];
         if (i >= k) {
             buck.erase(nums[i - k] / mod);
         }
     }
     return;

 }

 void removeDuplicate_80_solution::removeDuplicate(vector<int> &nums) {
    int preview_num = *nums.begin();
    int count = 1;
    vector<int>::iterator iter = nums.begin() + 1;
    while(iter != nums.end()) {
        cout << "the count and nums[i] in 4547: " << count << " " << *iter << endl;
        if (*iter == preview_num && count == 2) {
            preview_num = *iter;
            nums.erase(iter);

        } else if (*iter != count) {
            preview_num = *iter;
            count = 1;

        } else {
            preview_num = *iter;
            count++;
        }
        cout << "the count and nums[i] in 4560: " << count << " " << *iter << endl;
        iter ++;
    }
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

 }
 void removeDuplicate_80_solution::removeDuplicate2(vector<int> &nums) {
     int j = 1, count = 1;
     for (int i = 1; i < nums.size(); ++i) {
         if (nums[i] == nums[i - 1]) {
             count ++;
         } else {
             count = 1;
         }
         cout << "the count and nums[i]" << count << " " << nums[i] << endl;
         if (count <= 2) {
             //res.push_back(nums[i]);
             nums[j] = nums[i];
             j++;

         }
     }
     cout << endl;
     
     for (int i = 0; i < j; ++i) {
         cout << nums[i] << " ";
     }
     
     cout << endl;

 }
/////颜色分类 leetcode_75 
void sortColors_75_solution::sortColor(vector<int> &nums) {
    map<int, int> count;
    for (int i = 0; i < nums.size(); ++i) {
        if (count.find(nums[i]) != count.end()) {
            count[nums[i]] ++;
        } else {
            count.insert({nums[i], 1});
        }
    }
    for (int i = 0; i < count.size(); ++i) {
        for (int j = 0; j < count[i]; ++j) {
            cout << i << " " ;
        }
    }
    cout << endl;
}
//
void sortColors_75_solution::sortColor2(vector<int> &nums) {
    int p0 = 0, curr = 0;
    int p2 = nums.size() - 1;
    while (curr <= p2) {
        if (nums[curr] == 0) {
            swap(nums[curr], nums[p0]);
            curr ++;
            p0 ++;
        } else if (nums[curr] == 2) {
            swap(nums[curr], nums[p2]);
            p2--;
        } else {
            curr++;
        }
    }
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;

}
//最小覆盖子串  leetcode_76
void minWindow_76_solution::minWindow(string s, string t) {
    // right 用于扩大范围，直到包含   left 用于减小范围
    string temp;
    int start = 0, minlen = INT_MAX;
    int left = 0, right = 0;
    unordered_map<char, int> window;
    unordered_map<char, int> needs;
    //记录次数
    for (char c: t) {
        needs[c] ++;
    }
    int match = 0;
    //从左开始搜索，直到最右边
    while(right < s.size()) {
        char c1 = s[right];
        //如果这个元素在needs中
        if (needs.count(c1)) {
            //更新window中的元素数量
            window[c1] ++;
            //如果与need[c1] = window[c1],匹配成功一个
            if (window[c1] == needs[c1]) {
                match ++;
            }
        }
        right ++;
        cout << "the right:" << right << endl;
        ///有了全部的元素， 开始缩减大小直到不符合要求
        while(match == needs.size()) {
            if (right - left  < minlen) {
                start = left;
                minlen = right - left;
                cout << "pass in 4665" << endl;
            }
            char c2 = s[left];
            if (needs.count(c2)) {
                window[c2]--;
                if (window[c2] < needs[c2]) {
                    match --;
                }
            }
            left ++ ;
            temp = s.substr(start, right - start);
            cout << "the start and minlen: " << start << " " << minlen << endl;
            res.push_back(temp);
        }

    }
    
    return;
}


//长度最小的子数组 leetcode_209
//暴力法
int minSubArraylen_209_solution::minSubArraylen(int s, vector<int> &nums) {
    if (nums.size() == 0) {
        cout << "the len of nums is 0" << endl;
        return 0;
    }
    int ans = INT_MAX;
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i; j < nums.size(); ++j) {
            int sum = 0;
            //求和
            for (int k = i; k <= j; ++k) {
                sum = sum + nums[k];
            }
            //满足条件
            if (sum >= s) {
                ans = min(ans, (j - i + 1));
                //将i 到 j 赋值给 temp
                cout << "i: " << i << " " << "j: " << j << endl;
                vector<int> temp(nums.begin() + i, nums.begin() + j + 1);
                res.push_back(temp);
                break;
            }

        }
    }
    ans != INT_MAX ? ans : 0;
    cout << "the min_len: " << ans << endl;
    return ans;
}
//时间复杂度 O(n * n)
int minSubArraylen_209_solution::minSubArraylen2(int s, vector<int> &nums) {
    int n = nums.size();
    if (n == 0) {
        cout << "the len of nums is 0" << endl;
        return 0;
    }
    int ans = INT_MAX;
    //用来存储 前 n的元素的和  sums[2] = nums[0] + nums [1] + nums[2];
    vector<int> sums(n);
    sums[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        sums[i] = sums[i - 1] + nums[i];
    }
    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i; j < nums.size(); ++j) {
            int sum = sums[j] - sums[i] + nums[i];
            if (sum >= s) {
                ans = min(ans, (j - i + 1));
                cout << "i: " << i << " " << "j: " << j << endl;
                vector<int> temp(nums.begin() + i, nums.begin() + j + 1);
                res.push_back(temp);
                break;

            }
        }
    }
    ans != INT_MAX ? ans : 0;
    cout << "the min_len: " << ans << endl;
    return ans;
}
//使用二分法，时间复杂度 O(nlog(n))
int minSubArraylen_209_solution::minSubArraylen3(int s, vector<int> &nums) {
    int n = nums.size();
    if (n == 0) {
        cout << "the len of nums is 0" << endl;
        return 0;
    }
    int ans = INT_MAX;
    vector<int> sums(n + 1, 0);
    for (int i = 1; i <= nums.size(); ++i) {
        sums[i] = sums[i - 1] + nums[i - 1];
        cout << "the sums[i]" << sums[i] << endl;
    }
    for (int i = 1; i <= nums.size(); ++i) {
        //计算到哪个位置
        int to_find = s + sums[i - 1];
        //找到该位置 第一个大于等于to_find
        cout << "to_find: " << to_find << endl;
        auto bound = lower_bound(sums.begin(), sums.end(), to_find);
        if (bound != sums.end()) {
            ans = min(ans, static_cast<int>(bound - (sums.begin() + i - 1)));
            //确定需要哪些数
            vector<int> temp(nums.begin() + i - 1, nums.begin() + i + static_cast<int>(bound - (sums.begin() + i)) );
            res.push_back(temp);
        }
    }
    
    ans != INT_MAX ? ans : 0;
    cout << "the min_len: " << ans << endl;
    return ans;
}

//使用双指针 时间复杂度：o(n)
int minSubArraylen_209_solution::minSubArraylen4(int s, vector<int> &nums) {
    int n = nums.size();
    int ans = INT_MAX;
    int left = 0;
    int sum = 0;
    for (int i = 0; i < n; ++i) {
        sum = sum + nums[i];
        while(sum >= s) {
            ans = min(ans, i + 1 - left);
            cout << "i: " << i << " " << "j: " << left << endl;
            vector<int> temp(nums.begin() + left, nums.begin() + i + 1);
            res.push_back(temp);
            ///试着left往前移动
            sum = sum - nums[left];
            left++;
        }
    }
    
    ans != INT_MAX ? ans : 0;
    cout << "the min_len: " << ans << endl;
    return ans;
}
///滑动窗口最大值 leetcode_239 

vector<int> maxSlidingWindow_239_solution::maxSlidingWindow(vector<int>& nums, int k) {
    vector<int> res;
    if (nums.size() == 0 || k == 0) {
        return res;
    }
    //双向队列 滑动窗口,用于存储序号 先进先出,先进的元素在队头
    deque<int> window;
    for (int i = 0; i < k; ++i) {
        //当前的元素比堆后的要大，则弹出,则可以保证在front位置的元素最大
        while(!window.empty() && nums[i] > nums[window.back()]) {
            window.pop_back();
        }
        window.push_back(i);
    }
    res.push_back(nums[window.front()]);
    for (int i = k; i < nums.size(); ++i) {
        //去除不在范围内的元素
        if (!window.empty() && window.front() <= i - k) {
            window.pop_front();
        }
        while(!window.empty() && nums[i] > nums[window.back()]) {
            window.pop_back();
        }
        window.push_back(i);
        res.push_back(nums[window.front()]);
    }
    return res;
}


//替换后的最长重复字符
void characterReplacement_424_solution::characterReplacement(string s, int k) {
    if (s.size() == 0) {
        cout << "the len of s is 0" << endl;
        return;
    }
    int ans = 0; 
    int left = 0, right = 0, max_count = 0;
    int alpha[26] = {0};
    while (right < s.size()) {
        char c = s[right];
        alpha[c - 'A']++;
        //找取目前最长的序列
        max_count = max(max_count, alpha[c - 'A']);
        //如果窗口中需要替换的字数大于k
        if (right - left + 1 - max_count > k) {
            //将左边进行缩小
            alpha[s[left] - 'A'] --;
            left++;
        }
        vector<char> temp_res(s.begin() + left, s.begin() + right + 1);
        res.push_back(temp_res);
        ans = max(ans, right - left + 1);
        right ++;

    }
    ////替换后的最长重复字符
    cout << "the max len of replace:" << ans << endl;
    return;

}
///
bool checkInclusion_567_solution::checkInclusion(string s1, string s2) {
    bool res = false;
    int left = 0, right = 0;
    //目标元素容器
    unordered_map<char, int> need;
    //统计窗口目前含有多少目标元素
    unordered_map<char, int> window;
    //用来记录滑动窗口所有元素
    queue<char> slip_window;
    for(char c: s1) {
        need[c]++;
    }
    //目标满足计数器
    int match = 0;
    while(right < s2.size()) {
        //窗口满了，需要删除
        if (slip_window.size() == s1.size()) {
            char front = slip_window.front();
            if (window.count(front)) {
                window[front]--;
                cout << "the window[front] in 4887:" << window[front]  <<" "<< front << endl;
                //如果不满足条件 match --
                if (window[front] < need[front]) {
                    match--;
                }
            }

            slip_window.pop();
            left++;
        }
        cout << "the right and s2[right]:" << right << " " << s2[right] << endl;
        char c1 = s2[right];
        slip_window.push(c1);
        //如果c1是目标元素
        if (need.count(c1)) {
            //window更新
            window[c1] ++;
            cout << "the window[c1]:" << window[c1] << " " << c1 << endl;
            //满足一个要求
            if (window[c1] == need[c1]) {
                match++;
            }
            cout << "the match: " << match << endl;
        }
        //满足所有要求
        if (match == need.size()) {
            res = true;
            cout << "the left and right: " << left << " " << right << endl;
            vector<int> temp;
            temp.push_back(left);
            temp.push_back(right);
            container.push_back(temp);
        }
        right++;


    }
    return res;
}

//
bool checkInclusion_567_solution::checkInclusion2(string s1, string s2) {
    int left=0;
    int right=0;
    int match=0;
    unordered_map<char,int>window;
    unordered_map<char,int>need;
    for(char i:s1){
        need[i]++;
    }
    while(right<s2.size()){
        char tmp=s2[right];
        if(need.count(tmp)){
            window[tmp]++;
            if(window[tmp]==need[tmp]){
                match++;
            }
        }
        right++;
        //已经找到匹配的了
        while(match==need.size()){
            //如果大小一致，满足要求
            if(right-left==s1.size()){
                return true;
            }
            //缩小窗口，
            char num=s2[left];
            //nums是window里的
            if(window.count(num)){
                //减去1
                window[num]--;
                if(window[num]<need[num]){
                    match--;
                }
            }
            left++;
        }
    }
    return false;
}
//无重复字符的最长子串 leetcode_3 滑动窗口
int lengthOfLongestSubstring_3_solution::lengthOfLongestSubstring(string s) {
    int left = 0, right = 0;
    unordered_map<char, int> count;
    int max_len = 0;
    int max_left = 0;
    int max_right = 0;
    while(right < s.size()) {
        char c1 = s[right];
        count[c1] ++;
        right++;
        //元素c1的个数大于1，开始重复，则要计算最大长度
        while(count[c1] > 1) {
            char c2 = s[left];
            count[c2]--;
            left++;
        }
        if (right - left == max(max_len, right - left)) {
            max_right = right;
            max_left = left;
        }
        max_len = max(max_len, right - left);
        
    }
    vector<char>res(s.begin() + left, s.begin() + right);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    cout << "the max_len: " << max_len << endl;
    return max_len;
}
////最大连续1个的个数
int longestOnes_1004_solution::longestOnes(vector<int> &A, int k) {
    int left = 0, right = 0;
    int max_len = 0;
    unordered_map<char, int> window;
    while (right < A.size()) {
        int c1 = A[right];
        window[c1]++;
        right++;
        while(window[0] > k) {
            window[A[left]] --;
            left++;
        }
        res.push_back({left, right});
        max_len = max(right - left + 1, max_len);
    }
    return max_len;

}
//方法二
int longestOnes_1004_solution::longestOnes2(vector<int> &A, int k) {
    int left = 0, right = 0;
    int max_len = 0;
    int count = 0;
    while (right < A.size()) {
        int c1 = A[right];
        if (c1 == 0) count++;
        right++;
        //0的个数超过K，必须减少，left向前移动
        while(count > k) {
            if (A[left] == 0) count --;
            left++;
        }
        res.push_back({left, right});
        max_len = max(right - left + 1, max_len);
    }
    cout << "int way 2" << endl;
    return max_len;

}
////爱生气的书店老板 leetcode_1052
int maxSatisfied_1052_solution::maxSatisfied(vector<int> &customers, vector<int> &grump, int x) {
    int left = 0, right = x - 1;
    int maxSatisfy = 0;
    int max_res = 0;
    for (int i = 0; i < customers.size(); ++i) {
        if (grump[i] == 0) {
            maxSatisfy = maxSatisfy + customers[i];
        }
    }
    while(right < customers.size()) {
        int new_satisfy = 0;
        for (int i = left; i <= right; ++i) {
            if (grump[i] == 1) {
                new_satisfy = new_satisfy + customers[i];

            }
        }
        cout << "the new satisify: " << new_satisfy << endl;
        //max_res = maxSatisfy + new_satisfy;
        max_res = max(max_res, maxSatisfy + new_satisfy);
        res.push_back({{left, right}, maxSatisfy + new_satisfy});
        right ++;
        left ++;
    }
    cout << "the max_res: " << max_res << endl;
    return max_res;
}
///方法2
int maxSatisfied_1052_solution::maxSatisfied2(vector<int> &customers, vector<int> &grump, int x) {
    int left = 0, right = 0;
    int maxSatisfy = 0;
    int max_res = 0;
    //先计算老板不生气的情况下满意度（不忍受）
    for (int i = 0; i < customers.size(); ++i) {
        if (grump[i] == 0) {
            maxSatisfy = maxSatisfy + customers[i];
        }
    }
    int new_satisfy = 0;
    while(right < customers.size()) {
        //计算需要忍受下的满意度
        if (grump[right] == 1) {
            new_satisfy = new_satisfy + customers[right];
        }
        cout << "the right and new satisify: " << right << " "<< new_satisfy << endl;
        if (right >= x - 1) {
            max_res = max(max_res, maxSatisfy + new_satisfy);
            res.push_back({{left, right}, maxSatisfy + new_satisfy});
            //去掉不在X时间的满意度
            new_satisfy = new_satisfy - customers[left] * grump[left];
            left ++;
        }
        //cout << "the new satisify: " << new_satisfy << endl;
        //max_res = maxSatisfy + new_satisfy;
        //max_res = max(max_res, maxSatisfy + new_satisfy);
        //res.push_back({{left, right}, maxSatisfy + new_satisfy});
        right ++;
    }
    cout << "the max_res: " << max_res << endl;
    return max_res;
}
///方法2
int maxSatisfied_1052_solution::maxSatisfied3(vector<int> &customers, vector<int> &grump, int x) {
    int left  = 0;
    int max_save = 0;
    int curr_save = 0;
    int satisfy = 0;
    // i -> right
    for (int i = 0; i < customers.size(); ++i) {
        if (grump[i] == 1) {
            curr_save = curr_save + customers[i];
        }
        if (grump[i] == 0) {
            satisfy = satisfy + customers[i];
        }
        if( i >= x - 1) {
            max_save = max(max_save, curr_save);
            res.push_back({{i - x + 1, i}, curr_save});
            curr_save = curr_save - customers[i - x + 1] * grump[i - x + 1];
            //res.push_back({{i - x + 1, i}, max_save});
        }
    }
    cout << "the max_satisfy: " << satisfy + max_save << endl;
    return satisfy + max_save;
}
/////如何高效实现寻找素数
void countPrimes_solu::countPrimes(int n) {
    vector<bool> isPrime(n, true);
    for (int i = 2; i * i < n; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j < n; j = j + i) {
                isPrime[j] = false;
            }
        }
    }
    int count = 0;
    for (int i = 2; i < n; ++i) {
        if(isPrime[i]) {
            count ++;
            res.push_back(i);
        }
    }
    return;
}

/// Dijkstra
void Dijkstra_solu::dijkstra(Graph G, int vs) {
    cout << "pass in 5147" << endl;
    int i, j, k;
    int min;
    int tmp;
    cout << "pass in 5150" << endl;
    int flag[10000];  //flag[i]=1表示"顶点vs"到"顶点i"的最短路径已成功获取
    cout << "pass in 5151" << endl;
    vector<int> prev;
    vector<int> dist;
    for (i = 0; i < G.matrix.size(); ++i) {
        flag[i] = 0; //顶点i的最短路径还没获取到
        prev.push_back(0); //顶点i的前驱顶点为0
        dist.push_back(G.matrix[vs][i]); //顶点i的最短路径为"顶点vs"到"顶点i"的权。

    }
    flag[vs] = 1;
    dist[vs] = 0;
    cout << "pass in 5161" << endl;
    for (i = 0; i < G.vexnum; ++i) {
        //寻找当前的最小距离
        //即，在未获得最短路径的点中，找到距离vs最近的顶点
        min = INT_MAX;
        for (j = 0; j < G.vexnum; ++j) {
            if (flag[j] == 0 && dist[j] < min) {
                min = dist[j];
                cout << "the j and distance to vs in 5172:" << G.vexs[j] << " " << dist[j] << endl;
                k = j;
            }
        }
        cout << "pass in 5172" << endl;
        //标记已经获得最短路径
        flag[k] = 1;
        // 修正当前最短路径和前驱顶点
        // 即，当已经"顶点k的最短路径"之后，更新"未获取最短路径的顶点的最短路径和前驱顶点"
        for (j = 0; j < G.vexnum; ++j) {
            //判断 k 是否与 j 相连
            tmp = (G.matrix[k][j] == INT_MAX ? INT_MAX: (min + G.matrix[k][j]) );
            //还没找最近距离
            if (flag[j] == 0 && (tmp < dist[j])) {
                dist[j] = tmp;
                cout << "the j and distance to vs in 5186:" << G.vexs[j] << " " << dist[j] << endl;
                prev[j] = k;

            }
        }

    }

    cout << "the dijkstra:" << G.vexs[vs] << endl;
    for (i = 0; i < G.vexnum; ++i) {
        cout << "the shortest: from: " << G.vexs[vs] << " " <<
         G.vexs[i] << " " << dist[i] << endl;
    }
}
///Floyd
void Floyd_solution::Floyd(vector<vector<int>> &nums, int k) {
    for (int k = 1; k < nums.size(); ++k) {
        for (int i = 1; i < nums.size(); ++i) {
            for (int j = 1; j < nums.size(); ++j) {
                if (nums[i][j] > nums[i][k] + nums[k][j]) {
                    nums[i][j] = nums[i][k] + nums[k][j];
                    
                }
            }
            
        }
    }
    for (int i = 1; i < nums.size(); ++i) {
        for (int j = 1; j < nums.size(); ++j) {
            cout << nums[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

}
//////最长上升子序列  
//动态规划 , dp[i], 表示前i个元素的最长上升子序列
int lengthofLis_300_solution::lengthofLis(vector<int> &nums) {
    int n = (int)nums.size();
    if (n == 0) {
        cout << "the nums if empty." << endl;
        return 0;
    }
    vector<int> dp(n, 0);
    for (int i = 0; i < n; ++i) {
        //将第i个元素加入
        dp[i] = 1;
        for (int j = 0; j < i; ++j) {
            // nums[j] < nums[i] 上升的，可以加入
            if (nums[j] < nums[i]) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }
    return *max_element(dp.begin(), dp.end());

}
//
int lengthofLis_300_solution::lengthofLis2(vector<int> &nums) {
    int n = (int)nums.size();
    if (n == 0) {
        cout << "the nums if empty." << endl;
        return 0;
    }
    vector<vector<int>> dp_vector(n, vector<int>());
    for (int i = 0; i < n; ++i) {
        //将第i个元素加入
        dp_vector[i].push_back(nums[i]);
        if (i > 0) {
            //从i - 1开始判断dp_vector[j],是否可以插入dp_vector[i],如果可以只插入一次，后跳出
            for (int j = i - 1; j >= 0; j--) {
                //nums[j] < nums[i] 上升趋势，可以插入
                if (nums[j] < nums[i]) {
                    dp_vector[i].insert(dp_vector[i].begin(), dp_vector[j].begin(), dp_vector[j].end());
                    break;
                }
            }
        }
    }
    //打印
    int len = 0;
    for (int i = 0; i < dp_vector.size(); ++i) {
        if (dp_vector[i].size() > len) {
            len = dp_vector[i].size();
        }
        for (int j = 0; j < dp_vector[i].size(); ++j) {
            cout << dp_vector[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return len;
}
//贪心 + 二分查找  O(nlogn)
//要使得上升序列最长，则最后那个元素应该经可能小
int lengthofLis_300_solution::lengthofLis3(vector<int> &nums) {
    int len = 1, n = nums.size();
    if (n == 0) {
        cout << "the size of nums is 0" << endl;
        return 0;
    }
    vector<int> d(n + 1, 0);
    d[len] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] > d[len]) {
            len ++;
            d[len] = nums[i];
            print(d);
        } else {
            //upper_bound(begin(), end(), nums),找第一大于num的数
            //lower_bound(begin(), end(), nums),找第一个大于等于num的数
            //lower_bound(begin(), end(), nums, greater<type>()),第一个小于等于nums的数
            //upper_bound(begin(), end(), nums, greater<type>()),第一个小于num的数
            //找第一比nums[i]小的数d[k], d[k+1]=nums[i]
            int l = 1, r = len, posi = 0;
            //从后面往前找
            posi = upper_bound(d.begin() +len, d.begin(), nums[i], greater<int>()) - d.begin();
            cout << "the dp[posi]: " << d[posi] << endl;
            cout << "the posi: " << posi << endl;
            /*while (nums[posi - 1] > nums[i]) {
                posi = posi - 1;
            }*/
            cout << "the nums[i]: " << nums[i] << endl;
            cout << "the dp[posi]: " << d[posi] << endl;
            cout << "the posi: " << posi << endl;
            d[posi] = nums[i];
            print(d);
        }
    }

    return len;
}
int lengthofLis_300_solution::lengthofLis4(vector<int> &nums) {
    int len = 1, n = nums.size();
    if (n == 0) {
        cout << "the size of nums is 0" << endl;
        return 0;
    }
    vector<int> d(n + 1, 0);
    d[len] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] > d[len]) {
            len ++;
            d[len] = nums[i];
            print(d);
        } else {
            //upper_bound(begin(), end(), nums),找第一大于num的数
            //lower_bound(begin(), end(), nums),找第一个大于等于num的数
            //lower_bound(begin(), end(), nums, greater<type>()),第一个小于等于nums的数
            //upper_bound(begin(), end(), nums, greater<type>()),第一个小于num的数
            //////找第一比nums[i]小的数d[k], d[k+1]=nums[i]
            int l = 1, r = len, posi = 0;
            while(l <= r) {
                int mid = ( l + r) / 2;
                if (d[mid] < nums[i]) {
                    posi = mid;
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
                //d[posi + 1] = nums[i];
            }
            cout << "the posi: " << posi << endl; 
            d[posi + 1] = nums[i];
            print(d);
        }
    }
    return len;
}
//print
void lengthofLis_300_solution::print(vector<int> &d) {
    cout << "d[i]" << endl;
    for (int i = 0; i < d.size(); ++i) {
        cout << d[i] << " ";
    }
    cout << endl;
}
/////搜索二维矩阵 leetcode_74
void searchMatrix_74_solution::searchMatrix(vector<vector<int>> &matrix, int target) {
    //没有这个元素
    res.push_back({-1, -1});
    if (matrix.size() == 0) {
        cout << "the matrix is empty" << endl;
        return;
    }
    //元素所在位置 row col
    int row = 0, col = 0;
    int len = matrix[0].size();
    //将matrix看成一个数组，
    int left = 0;
    int right = matrix.size() * matrix[0].size() - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        // 所在位置 row col
        row = mid / len;
        col = mid % len;
        cout << "the row and col: " << row << " " << col;
        if (matrix[row][col] == target) {
            res[0] = {row, col};
            return;
        } else if (matrix[row][col] < target) {
            left = mid + 1;
        } else if (matrix[row][col] > target) {
            right = mid - 1;
        }
        
    }
    return;
}
///方法2，先定在哪一行，再定在那一列
void searchMatrix_74_solution::searchMatrix2(vector<vector<int>> &matrix, int target) {
    res.push_back({-1, -1});
     cout << "pass in 5401" << endl;
     // matrix = {{}}, 需要同时判断matrix.empty() and matrix[0].empty()
    if (matrix.empty() || matrix[0].empty()) {
        cout << "the matrix is empty" << endl;
        return;
    }
    cout << "the size of matrix: " << matrix.size() << " " << matrix[0].size() << endl;
    cout << "pass in 5405" << endl; 
    bool flag_row = false, flag_col = false;
    //一行的长度
    int len = matrix[0].size();
    //行
    int row_left = 0, row_right = matrix.size() - 1;
    //列
    int col_left = 0, col_right = matrix[0].size() - 1;
    int mid = 0, mid1 = 0; // mid : for row  , mid1 : for col
    //行搜度
    while (row_left <= row_right) {
        mid = (row_left + row_right) / 2;
        if (matrix[mid][0] <= target && matrix[mid][len - 1] >= target) {
            res[0].first =  mid;
            flag_row = true;
            break;
        } else if (matrix[mid][len - 1] < target) {
            row_left = mid + 1;
        } else if (matrix[mid][0] > target) {
            row_right = mid - 1;
        }
    }
    if (flag_row == false) {
        cout << "the is no target in matrix from row" << endl;
        return ;
    }
    //列搜索
    while (col_left <= col_right) {
        int mid1 = (col_right + col_left) / 2;
        if (matrix[mid][mid1] == target) {
            res[0].second = mid1;
            flag_col = true;
            break;
        } else if (matrix[mid][mid1] < target) {
            col_left = mid1 + 1;
        } else if (matrix[mid][mid1] > target) {
            col_right = mid1 - 1;

        }
    }
    if (flag_col == false) {
        res[0].first = -1;
        cout << "there is no target in matrix from col" << endl;
        return;
    }
    return;
}
///寻找山脉峰值 峰值：nums[i] > nums[i + 1] and nums[i] < nums[i - 1], 迭代
int findPeakElement_162_solution::findPeakElement(vector<int> &nums) {
    int l = 0, r = nums.size() - 1;
    while (l < r) {
        int mid = (l + r) / 2;
        if (nums[mid] < nums[mid + 1]) {
            l = mid + 1;
        } else if (nums[mid] > nums[mid + 1]) {
            r = mid;
        }
    }
    cout << "the peak posi: " << l << endl;
    cout << "the peak element: " << nums[l] << endl;
    return l;
}
//递归
int findPeakElement_162_solution::findPeakElement2(vector<int> &nums) {
    int start = 0, end = nums.size() - 1;
    return findPeakElementHelper(nums, start, end);
}
int findPeakElement_162_solution::findPeakElementHelper(vector<int> &nums, int start, int end) {
    if (start == end) {
        return start;
    }
    int mid = (start + end) / 2;
    if (nums[mid] > nums[mid + 1]) {
        return findPeakElementHelper(nums, start, mid);
    } else if (nums[mid] < nums[mid + 1]) {
        return findPeakElementHelper(nums, mid + 1, end);
    }

}
///
int countRangeSum_327_solution::countRangeSum(vector<int> &nums, int lower, int upper) {
    int res = 0;
    multiset<int> helper;
    helper.insert(0);
    int sum = 0;
    for (int j = 0; j < nums.size(); ++j) {
        sum = sum + nums[j];

        cout << "the sum: " << sum <<endl;
        ///使用二分法找一个  大于等于sum - upper,小于等于sum - lower
        //第一个大于等于sum - upper的数
        multiset<int>::iterator iter0 = lower_bound(helper.begin(), helper.end(), sum - upper);
        //第一个大于sum - upper的数
        //所以 [iter0, iter1)是我们需要的空间范围
        multiset<int>::iterator iter1 = upper_bound(helper.begin(), helper.end(), sum - lower);
        cout << "the helper.end(): " << *helper.end() << endl;
        cout << "in 5529: " << *iter0 << " " << *iter1 << endl;
        //multiset是非线性的容器，不可以iter0 + 1之类的操作，可以distance(iter0, iter1), advance(iter, 1)
        while (distance(iter0, iter1) > 0 && iter0 != helper.end() && iter0 != iter1) {
            res++;
            ans.push_back({*iter0, sum});
            cout << "iter0: " << *iter0 << endl;
            advance(iter0, 1);
        }
        helper.insert(sum);
    }
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    cout << endl;

}
//使用二分法找一个  大于等于 left,小于等于 right
int countRangeSum_327_solution::search(vector<int> nums, int low, int high) {
    int left = 0, right = nums.size() - 1;
    int mid = left + (right - left) / 2;
    while (left <= right) {
        if (nums[mid] >= low && nums[mid] <= high) {
            cout << "find it: " << mid << endl;
        } else if (nums[mid] < low) {
            left = mid + 1;
        } else if (nums[mid] > high) {
            right = mid - 1;
        }
    }
    return -1;

}
//
int countRangeSum_327_solution::countRangeSum2(vector<int> &nums, int lower, int upper) {
    int res = 0;
    multiset<int> helper;
    helper.insert(0);
    int sum = 0;
    for (int j = 0; j < nums.size(); ++j) {
        sum = sum + nums[j];
        helper.insert(sum);
        cout << "the sum: " << sum <<endl;
        ///使用二分法找一个  大于等于sum - upper,小于等于sum - lower
        //第一个大于等于sum - upper的数
        int left = sum - upper;
        int right = sum - lower;
        //zhao 
        for (int i = left; i <= right; ++i) {
            if (helper.find(i) != helper.end()) {
                auto iter = helper.find(i);
                ans.push_back({*iter, sum});
            }
        }
    }
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    cout << endl;

}
///统计优美子数组 leetcode_1248
//连续数组中有k个奇数
void numberofSubarrays_1248_solution::numberofSubarrays(vector<int> &nums, int k) {
    vector<int> helper;
    //插入0,作为辅助
    helper.push_back(0);
    int sum = 0;
    int lower = 0;
    for (int i = 0; i < nums.size(); ++i) {
        //x可能为负数nums[i] % 2 == 1不对
        //奇数
        if (nums[i] % 2 != 0) {
            sum = sum + 1;
        }
        helper.push_back(sum);
        cout << "the sum: " << sum << endl;
        //使用lower记录已经搜索过的地方，可以避免重复
        if(helper[helper.size() - 1] - helper[lower]>= k) {
            //需要搜素位置所对应的奇数个数
            int n = helper[helper.size() - 1] - k;
            //从lower开始搜
            int res = search(helper, lower, n);
            //找到了
            if (res != -1) {
                //因为从多了一前缀0,所以再减去1
                ans.push_back({res, helper.size() - 1 - 1});
                //更新开始搜索位置
                lower ++;
                cout << "the res: " << res << endl;
            }
        }
    }
    return;
}
///二分查找
int numberofSubarrays_1248_solution::search(vector<int> &helper, int lower, int k) {
    int left = lower, right = helper.size() - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if (helper[mid] == k) {
            cout << "find the mid, which val equal k" << endl;
            return mid;
        } else if (helper[mid] < k) {
            left = mid + 1;
        } else if (helper[mid] > k) {
            right = mid - 1;
        }

    }
    return -1;
}

///hash
void numberofSubarrays_1248_solution::numberofSubarrays2(vector<int> &nums, int k) {
    multiset<int> helper;
    //插入0,作为辅助
    helper.insert(0);
    int sum = 0;
    multiset<int>::iterator begin_iter = helper.begin();
    for (int i = 0; i < nums.size(); ++i) {
        //x可能为负数nums[i] % 2 == 1不对
        //奇数
        if (nums[i] % 2 != 0) {
            sum = sum + 1;
        }
        helper.insert(sum);
        cout << "the sum: " << sum << endl;
        //使用lower记录已经搜索过的地方，可以避免重复
        if(sum - *begin_iter>= k) {
            //需要搜素位置所对应的奇数个数
            int n = sum - k;
            //找到了
            if (helper.find(n) != helper.end()) {
                auto iter = helper.find(n);
                cout << "the distance: " << distance(iter, helper.end()) << endl;
                while(sum - *iter == k) {
                     ans.push_back({*iter, sum});
                     advance(iter, 1);
                }
                advance(begin_iter, 1);
            }
            
        }
    }
    return;

}
///
int numberofSubarrays_1248_solution::numberofSubarrays3(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> arr;
    arr.push_back(0);
    //计算 奇数个数
    for(auto x:nums) arr.push_back(arr.back() + (x&1));
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " " << endl;
    }
    cout << endl;
    unordered_map<int,int> h;
    int ans = 0;
    //
    for(auto x:arr) {
        cout << "h[x-k]: " << x - k << " " << h[x - k] << endl;
        cout << "h[x]: " << x  << " "<< h[x] << endl;
        ans += h[x-k];
        h[x] ++;
    }
    cout << "the ans: " << ans << endl;
    return ans;
}
///四个数之和
int foursumcout_454_solution::foursumcout(vector<int> &A, vector<int> &B, 
    vector<int> &C, vector<int> &D) {
    if (A.empty() || B.empty() || C.empty() || D.empty()) {
        cout << "A, B, C, D someone is empty." << endl;
        return 0;
    }
    unordered_map<int, pair<int, int>> AB;
    for (auto a: A) {
        for (auto b: B) {
            AB[a + b] = {a, b};
        }
    }
    for (auto c: C) {
        for (auto d: D) {
            int ans = c + d;
            if(AB.find(-ans) != AB.end()) {
                auto iter = AB.find(-ans);
                vector<int> temp;
                temp.push_back(iter->second.first);
                temp.push_back(iter->second.second);
                temp.push_back(c);
                temp.push_back(d);
                res.push_back(temp);
            }
        }
    }
    return 0;
}
// 找到K个最接近的元素
void findclosestelement_658_solution::findclosestelement(
    vector<int> &nums, int k, int x) {
    vector<pair<int, int>> container;
    for (int i = 0; i < nums.size(); ++i) {
        container.push_back({nums[i], abs(nums[i] - x)});
    }
     
    ///如果频率一样，则值大的放前面
    auto comp = [](const pair<int, int> val1, const pair<int, int> val2) {
        bool res;
        if (val1.second == val2.second) {
            return val1.first > val2.first;
        }
        return val1.second > val2.second;
    };
    //将map转化为vector
    vector<pair<int, int>> count_vector(count.begin(), count.end());
    //排序
    sort(count_vector.begin(), count_vector.end(), comp);
}