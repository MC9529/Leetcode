
#include <algorithm>
#include <iomanip>
#include <limits>
#include <utility>
#include <vector>
#include "Eigen/LU"
#include<iostream>

#include "solution.h"
#include <vector>

using namespace std;
using namespace Eigen;


////Permute_46   全排列 
/*
int main(int argc, char **argv)
{
  vector<vector<int>> result;
  Permute_46_Solution solution ;
  int nums[] ={1, 2, 3};
  vector<int> vector_nums(nums, nums+3);
  result = solution.permute(vector_nums);

  for(vector<int>::size_type i = 0; i < result.size(); i++){
    for(vector<int>::size_type j = 0; j < result[0].size(); j++){
      std::cout << result[i][j] << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}
*/

//////NQueue_51  N皇后
/*
int main(){
  vector<vector<string>> res;
  sloveNQueue_51_Solution s1;
  int n = 4;
  res = s1.sloveNQueue(4);
  std::cout << "pass in 41" << std::endl;
  for(vector<string>::size_type i = 0; i < res.size(); i++){
    for(int j = 0; j < n; j++){
      for(int k = 0; k < n; k++){
      std::cout << (res[i][j])[k];
      }
      std::cout << std::endl;
    }
    std::cout << std::endl;
  }
  return 0;
}
*/
////totalNQueue_52   N皇后2
/*
int main(){
  int n = 4;
  int res;
  totalNQueue_52_Solution s1;
  cout << "pass in 62" << endl;
  res = s1.totalNQueue(n);
  cout << "pass in 64" << endl;
  std::cout << "the res: " << res << std::endl;
  return 0;
}
*/

///////
/// 括号生成
/*
int main(){
  vector<string> result;
  generateParenthesis_22_Solution s1;
  int n = 3;
  result = s1.generateParenthesis(n);
  for(vector<string>::size_type i = 0; i < result.size(); i++){
    for(int j = 0; j < n * 2; j++){
      cout << result[i][j];
    }
    cout << endl;
  }
  return 0;
}*/

/////////解数独

/*
int main(){

  vector<vector<char>> board;
  SuDu_37_Solution s1;
  board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
           {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
           {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
           {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
           {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
           {'7', '.', '.', '.', '2', '.', '.', '.', '6'},    
           {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
           {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
           {'.', '.', '.', '.', '8', '.', '.', '7', '9'} };
  s1.solveSuDu(board);
  for(int i = 0; i< 9; i++){
    for(int j = 0; j< 9; j++){
      cout << board[i][j] << " ";
    }
    cout << endl;
  }

  return 0;
}
*/

////组合总和    每个数值可以使用多次
/*
int main(){
  vector<vector<int>> res;
  vector<int> candi = {2, 3, 6, 7};
  int target = 7;
  combinationSum_39_Solution s1;
  res = s1.combinationSum(candi, target);
  for(int i =0; i< (int)res.size(); i++){
    for(auto iter : res[i]){

        cout << iter << " ";
    }
    cout << endl;
  }
  return 0;
}
*/
////组合总和    每个数值只能使用1次

/*
int main(){
  vector<vector<int>> res;
  //vector<int> candi = {10, 1, 2, 7, 6, 1, 5};
  vector<int> candi = {1, 1};
  // vector<int> candi = {2, 5, 2, 1, 2};
  int target = 1;
  combinationSum_40_Solution s1;
  res = s1.combinationSum2(candi, target);
  for(int i =0; i< (int)res.size(); i++){
    for(auto iter : res[i]){
        cout << iter << " ";
    }
    cout << endl;
  }
  return 0;
}
*/

//// 单词搜索  79

/*
int main(){
  bool res;
  vector<vector<char>> board = {{'A', 'B', 'C', 'E'},
                               {'S', 'F', 'C', 'S'},
                               {'A', 'D', 'E', 'E'} };
  string word = "ABCB";
  //string word = {"ABCCE"};  word == vector<string>
  Search_79_Solution s1;
  res = s1.solve1(board, word);
  cout << "passed in 165 " << endl;
  if(res == true || res == false){
    cout << " the type of res is bool" << endl;
  }
  cout << "the res : " << res << endl;
  cout << endl;
  return 0;
}
*/
///// 子集 2 
/*
int main(){

  vector<vector<int>> res;
  vector<int> nums = {1, 2, 2};
  subset_90_Solution s1; 
  res = s1.solve(nums);
  cout << "the len of res: " << res.size();
  for(int i = 0; i < res.size(); i++){
    for(auto iter: res[i]){
      cout << iter << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}
*/

///////有效括号 20
/*
int main(){
  string str = "()[][";
  isValid_20_Solution s1;
  bool res = s1.isValid(str);

  cout << "the res : " << res << endl;

  return 0;
}
*/

/////不同路径1  62

int main(){

  int m = 3, n =2;
  uniquePaths_62_Solution s1;
  int res = s1.uniquePaths(3, 2);

  cout << "the num of route : " << res << endl;
  return 0;
}