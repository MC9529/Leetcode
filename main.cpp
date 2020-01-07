
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
/*
int main(){

  int m = 3, n =2;
  uniquePaths_62_Solution s1;
  int res = s1.uniquePaths(3, 2);

  cout << "the num of route : " << res << endl;
  return 0;
}
*/
/////不同路径1  63

/*
int main(){
  vector<vector<int>> obstacleGrid = {{0, 0, 0},
                                      {0, 1, 0},
                                      {0, 0, 0}};
  uniquePathsWithObstacles_63_Solution s1;
  int res = s1.uniquePathsWithObstacles(obstacleGrid);

  cout << "the num of route : " << res << endl;
  return 0;
}
*/

////////////最大子序列   LeetCode 53

/*
int main(){
  //      dp[i] = max(dp[i-1] + nums[i], nums[i]);
  //      result = max(result, dp[i]);
  vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 9};
  //vector<int> nums = {2, 3, -6, 2 ,4};
  maxSubArray_53_Solution s1;
  int res = s1.maxSubArray(nums);
  cout << "the max of maxsubArray :" << res << endl;


  return 0;
}
*/

/////最小路径和 leetcode_64
/*
int main(){
 vector<vector<int>> Grid = {{1, 3, 1},
                              {1, 5, 1},
                              {4, 2, 1}};
                    
 vector<vector<int>> Grid = {{1, 2, 5},
                              {3, 2, 1}};
  minPathSum_64_Solution s1;
  int res = s1.minPathSum(Grid);

  cout << "the sum of route : " << res << endl;
  return 0;
}
*/

////// /// 爬楼梯 leetcode _70

/*
int main(){

  int  num_stair = 5;
  climbStair_70_Solution s1;
  int res = s1.climbStairs(num_stair);

  cout << "the res :" << res << endl;

  return 0;
}
*/
//////解码方法  leetcode_91
/*
int main(){

  string string_num = "226";
  numDecodings_91_Solution s1;
  int res = s1.numDecoding(string_num);

  cout << "the res :" << res << endl;

  return 0;
}
*/
/////动态规划  leetcode_45 and 55
/*
int main(){
  vector<int> nums = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 1, 0};
  //vector<int> nums = {3, 2, 1, 0, 4};
  //vector<int> nums = {0, 1};
  jump_45_Solution s1;
  bool res = s1.jump(nums);

  cout << "can reach the last ?(1-yes, 0-no) :" << (bool)res << endl;

  return 0;
}*/

///贪心算法， 买卖股票的最佳时机, leetcode_122
/*
int main(){
  vector<int> nums = {7, 1, 5, 3, 6, 4};
  //vector<int> nums = {1, 2, 3, 4, 5};
  //vector<int> nums = {5, 4, 3, 2, 1};
  //vector<int> nums = {0, 1};
  maxProfit_122_Solution s1;
  int res = s1.maxProfit(nums);

  cout << "the max_profit :" << res << endl;

  return 0;
}
*/

///贪心算法， 加油站 leetcode_134
/*
int main(){
  //vector<int> gas = {1, 2, 3, 4, 5};
  //vector<int> cost = {3, 4, 5, 1, 2};
  vector<int> gas = {2};
  vector<int> cost = {2};
  //vector<int> nums = {0, 1};
  canCompleteCircuit_134_Solution s1;
  int res = s1.canCompleteCircuit(gas, cost);

  cout << "can reach?(-1:no , other: the start) :" << res << endl;

  return 0;
}

*/

/*
////贪心算法， leetcode_135
int main(){
  //vector<int> ratings = {1, 2, 2};
  vector<int> ratings = {1, 3, 4, 5, 2};
  //vector<int> ratings = {1, 2, 87, 87, 87, 2, 1};
  candy_135_Solution s1;
  int res = s1.candy(ratings);

  cout << "the total candies :" << res << endl;

  return 0;
}
*/

///分而治之 leetcode_23
/*
int main(){
  vector<vector<int>> res;
  vector<vector<int>> list = {{1, 3, 5, 12},
                              {3, 5, 8},
                              {5, 7, 9, 11}};
                              
  mergeLise_23_solution s1;
  res = s1.merge_list(list);
  for (int i = 0; i < res.size(); ++i) {
    for (auto iter : res[i]) {
      cout << iter;
    }
    cout << endl;
  }

  return 0;
}
*/

//////堆 head
//设置一个大小为K的堆，堆顶就是你所找的第K大的元素
/*
int main() {
  vector<int> list = {1, 9, 5, 4, 15, 20, 17, 13, 12};
  findKthLargest_215_solution s1;
  int res = s1.findKthLargest(list, 5);
  int res2 = s1.findKthLargest2(list, 5);
  cout << "the Kth largest(res):" << res << endl;
  cout << "the Kth largest(res2):" << res2 << endl;
  return 0;
}*/

//滑动窗口,Leetcode_239
/*
int main() {
  vector<int> list = {1, 9, 5, 4, 15, 20, 17, 13, 12};
  maxSlideWindow_239_solution s1;
  s1.maxSlideWindow(list, 3);
  s1.maxSlideWindow_in_heap(list, 3);

  return 0;
}
*/
/// ////二分查找 leetcode_240 
/*
int main () {
  bool res;
  vector<vector<int>> list = {{2, 3, 5, 12},
                              {3, 4, 8, 15},
                              {5, 9, 10, 11},
                              {7, 8, 11, 13}};
  int target = 6;
  searchMatrix_240_solution s1;
  res = s1.searchMatrix(list, target);

  return 0;
}
*/
////////二分查找 leetcode_315， 查找右边小于本位置的数
/*
int main () {
  vector<int> res;
  vector<int> list = {5, 3, 6, 1, 4, 2};

  countSmaller_315_solution s1;
  res = s1.countSmaller1(list);
  vector<int> res2 = s1.countSmaller2(list);

  return 0;
}
*/
///排序  归并排序
/*
int main () {
  vector<int> list = {5, 3, 6, 1, 4, 2};

  merge_sorted s1;
  cout << "passed in 439" << endl;
  if (list.size() < 2) {
    cout << "the num int list is less 2!" << endl;
    return 0;
  }
  s1.mergesort(list, 0, list.size()-1);
  for (int i = 0; i < list.size(); ++i) {
        cout << list[i] << " ";
  }
  cout << endl;
  return 0;
}
*/

///排序  快速排序
/*
int main () {
  vector<int> list = {5, 3, 6, 6, 1, 4, 4, 2};

  quick_sort s1;
  cout << "from small to big :" << endl;
  s1.small2big(0, list.size() - 1, list);
  //打印
  for (int i = 0; i < list.size(); ++i) {
        cout << list[i] << " ";
  }
  cout << endl;

  cout << "big small to small :" << endl;
  s1.big2small(0, list.size() - 1, list);
  ///打印
  for (int i = 0; i < list.size(); ++i) {
        cout << list[i] << " ";
  }
  cout << endl;
  return 0; 
}
*/

//////前K个高频词 Leetcode_347
/*
int main() {
  vector<int> list = {5, 3, 6, 6, 6, 4, 4, 4, 2, 1, 1};
  int k = 3;
  topKFrequence_347_solution s1;
  vector<int> res = s1.topKFrequence(list, k);
  for (int i = 0; i < res.size(); ++i) {
    cout << res[i] << " ";
  }
  cout << endl;
  vector<int> res2 = s1.topKFrequence2(list, k);
  for (int i = 0; i < res2.size(); ++i) {
    cout << res2[i] << " ";
  }
  cout << endl;
  
  return 0;
}
*/
////查找和最小的k对数字
/*
int main() {
  //vector<int> list1 = {1, 7, 11};
  //vector<int> list2 = {2, 4, 6};
  //vector<int> list1 = {1, 1, 2};
  //vector<int> list2 = {1, 2, 3};
  vector<int> list1 = {1, 2};
  vector<int> list2 = {3};
  int k = 3;
  kSmallestPairs_373_solution s1;
  //vector<vector<int>> res = s1.kSmallestPairs(list1, list2, k);
  vector<vector<int>> res = s1.kSmallestPairs3(list1, list2, k);
  for (int i = 0; i < res.size(); ++i) {
    for(auto iter: res[i]) {
      cout << iter << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}
*/
////有序矩阵中第K小的元素
/*
int main() {
  vector<vector<int>> list1 = {{2, 3, 5},
                              {3, 4, 8, 15},
                              {5, 9, 10, 11},
                              {7, 8, 11, 13}};
  int k = 5;
  kthSmallest_378_solution s1;
  //vector<vector<int>> res = s1.kSmallestPairs(list1, list2, k);
  int res = s1.kthSmallest(list1, k);
  cout << "the kthSmallest:" << res << endl;
  return 0;
}
*/
///根据字符出现频率排序
/*
int main() {
  string s = "bAab";

  frequencySort_451_solution s1;
  //vector<vector<int>> res = s1.kSmallestPairs(list1, list2, k);
  string res = s1.frequencySort(s);
  //string res = s1.frequencySort2(s);
  cout << "the Sorted_string:" << res << endl;
  return 0;
}
*/
////////IPO leetcode_502
/*
int main() {
  int k = 11, w = 11;
  vector<int> profits = {1, 2, 3};
  vector<int> capital = {11, 12, 13};
  IPO_502_solution s1;
  int res = s1.findMaxCapital(k, w, profits, capital);
  cout << "the max capital:" << res << endl;

  return 0;
}
*/
///分割数组有连续子序列 leetcode_659
int main() {
  vector<int> lists = {1, 2, 2, 3, 3, 4, 5};
  vector<vector<int>> res;
  CutWord_659_solution s1;
  s1.CutWord(lists, res);
  for (int i = 0; i < res.size(); ++i) {
    for (auto iter: res[i]) {
      cout << iter << " ";
    }
    cout << endl;
  }

  return 0;
}


