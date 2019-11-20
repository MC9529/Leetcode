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
    /*
    for(int i = 0; i < target.size(); i++){
        cout << target[i] << " ";
    }
    cout<< endl;*/

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
    /*
    cout << "temp :" <<endl;
    for(int k = 0; k < temp.size(); k++){
        cout << temp[k] << " ";
    }
    cout << endl;
    */
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