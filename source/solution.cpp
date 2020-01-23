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
#include <cstring>
#include <stdlib.h>
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