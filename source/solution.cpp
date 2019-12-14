#include "solution.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>
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