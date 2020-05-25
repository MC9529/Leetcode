
#include <algorithm>
#include <iomanip>
#include <limits>
#include <utility>
#include <vector>
//#include "Eigen/LU"
#include<iostream>

#include "solution.h"
#include <vector>
#include "BiTree.h"

using namespace std;
//using namespace Eigen;


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
  //int res = s1.findMaxCapital2(k, w, profits, capital);
  cout << "the max capital:" << res << endl;

  return 0;
}
*/
///分割数组有连续子序列 leetcode_659
/*
int main() {
  //vector<int> lists = {1, 2, 2, 3, 3, 4, 5};
  vector<int> lists = {1, 2, 3, 3, 4, 4, 5, 5};
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
*/
//////前K个高频词，leetcode_692
/*
int main() {
  vector<string> lists = {"a", "b", "c", "a", "a", "b", "d", "c"};
  int k = 3;
  topKFrequent_692_solution s1;
  //vector<string> res = s1.topKFrequent(lists, k);
  vector<string> res = s1.topKFrequent2(lists, k);
  cout << "the list(the frequence for high to low) :" << endl;
  for (int i = 0; i < res.size(); ++i) {
    cout << res[i] << " ";
  }
  cout << endl;

  return 0;
}
*/

//////数据流中的第K大元素
/*
int main() {
  vector<int> lists = {4, 5, 8 ,2};
  int k = 3;
  KthLargest_703_solution KthLargest(k, lists);
  KthLargest.add(3);
  KthLargest.add(5);
  KthLargest.add(10);
  KthLargest.add(9);

  return 0;
}
*/
///找出第K小的距离堆对
/*
int main() {
  vector<int> lists = {1, 3, 1, 5};
  int k = 3;
  smallestDistancePair_719_solution s1;
  //s1.smallestDistancePair(lists, k);
  s1.smallestDistancePair2(lists, k);

  return 0;
}
*/
/////网络延迟时间, 从某一点发出信号到所有节点都收到信号，要多长时间， leetcode_743 
/*
int main() {
  vector<vector<int>> list1 = {
                              {1, 2, 5}, {1, 3, 7}, {1, 4, 8},
                              {2, 1, 3}, {2, 3, 6}, {2, 4, 8},
                              {3, 1, 0}, {3, 2, 8}, {3, 4, 10},
                              {4, 1, 8}, {4, 2, 5}, {4, 3, 10} 
                              };
  int N = 4; ///total point
  int k = 2;  ///start point
  networkDelayTime_743_solution s1;
  cout << "the start point: " << k << endl;
  int res = s1.networkDelayTime(list1, N,  k);

  return 0;
}
*/

///格雷编码 leetcode_89
/*
int main() {
  grayCode_89_Solution s1;
  vector<int> res;
  int n = 3;
  res = s1.grayCode(n);
  for (int i = 0; i < res.size(); ++i) {
    cout << res[i] << " ";
  }
  
  cout << endl;

  return 0;
}
*/
//复原ip地址 leetcode_93
/*
int main() {
  restoreIpAddresses_93_Solution s1;
  vector<string> res;
  string ip_str = "25525511135";
  res = s1.restoreIpAddresses(ip_str);
  for (int i = 0; i < res.size(); ++i) {
    cout << res[i] << " ";
  }
  cout << endl;

  return 0;
}
*/
//单词接龙 leetcode_126
/*
int main() {
  vector<vector<string>> res;
  string beginWord = "hit";
  string endWord = "cog";
  vector<string> wordList = {"hot","dot","dog","lot","log","cog"};
  findLadders_126_Solution s1;
  res = s1.findLadders(beginWord, endWord, wordList);
  for (int i = 0; i < res.size(); ++i) {
    for (auto iter: res[i]) {
      cout << iter << " ";
    }
  }
  cout << endl;

  return 0;
}*/
///分割回文串 leetcode_131 
/*
int main() { 
  string s = "aba";
  partition_131_solution s1;
  vector<vector<string>> res = s1.partition(s);
  cout << "the res:" << endl;
  for (int i = 0; i < res.size(); ++i) {
    for (auto iter: res[i]) {
      cout << iter << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}
*/
//单词拆分 leetcode_140
/*
int main () {
  string s = "catsanddog";
  vector<string> wordDict = {"cat", "cats", "and", "sand", "dog"};
  wordBreak_140_solution s1;
  s1.wordBreak(s, wordDict);
  for (int i = 0; i < s1.res.size(); ++i) {
    for (auto iter: s1.res[i]) {
      cout << iter << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}*/
///添加和搜索单词 leetcode_211 回溯算法
/*
int main() {
  wordDictionary_211_solution s1;
  s1.addWord("bad");
  s1.addWord("dad");
  s1.addWord("mad");
  s1.search("pad"); 
  cout << "the bool res:" << s1.bool_res << endl;

  s1.search("bad");
  cout << "the bool res:" << s1.bool_res << endl;

  s1.search(".ad"); 
  cout << "the bool res:" << s1.bool_res << endl;

  s1.search("b..");
  cout << "the bool res:" << s1.bool_res << endl;
  return 0;
}
*/
///组合总和 leetcode_216 回溯算法
/*
int main() {
  int k = 3; 
  int n = 9;
  combinationSum3_216_solution s1;
  s1.combinationSum3(k, n);
  for (int i = 0; i < s1.res.size(); ++i) {
    for (auto iter: s1.res[i]) {
      cout << iter << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}*/
/// 累加数 leetcode_306 
/*
int main() {
  string s = "1235813";
  string s1 = "199100199";
  isAdditiveNumber_306_solution solu;
  solu.isAdditiveNumber(s);

  return 0;
}
*/
//优美的排列 leetcode_526
/*
int main() {
  int n = 3;
  countArrangement_526_solution s1;
  s1.count(n);
  for (int i = 0; i < s1.res.size(); ++i) {
    for (auto iter: s1.res[i]) {
      cout << iter << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}
*/
//字母大小写全排列 leetcode_784
/*
int main() {
  string s = "c1b2";
  string s1 = "12345";
  string s2 = "9A2g9Bb";
  letterCasePermutation_784_solution solu;
  solu.letterCasePermutation(s2);
  for (auto iter: solu.res) {
    cout << iter << " ";
  }
  cout << endl;
  return 0;
}*/
///将数组拆分成斐波那契序列 leetcode_842
/*
int main() {
  string s = "123456579";
  splitIntoFibonacci_842_solution solu;
  solu.splitIntoFibonacci(s);
  for (int i = 0; i < solu.res.size(); ++i) {
    for(auto iter: solu.res[i]) {
      cout << iter << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
*/
//不同路径3 leetcode_980
/*
int main() {
  vector<vector<int>> grid = { {1, 0, 0, 0}, 
                               {0, 0, 0, 0}, 
                               {0, 0, 0, 2},
                             };
  uniquePaths3_980_solution solu;
  solu.uniquePaths3(grid);
  cout << "the res :" << endl;
  for (int i = 0; i < solu.total_res.size(); ++i) {
    for (auto iter: solu.total_res[i]) {
      cout << iter.first << "-" << iter.second << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
*/
//正方形数组的数目 leetcode_996
/*
int main() {
  vector<int> grid = {1, 8, 17};
  numSquareFulPerms_996_solution solu;
  solu.numSquareFulPerms(grid);
  cout << "the res :" << endl;
  for (int i = 0; i < solu.total_res.size(); ++i) {
    for (auto iter: solu.total_res[i]) {
      cout << iter << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
*/
//不同的二叉搜索树2
/*
int main() {
  int n = 3;
  generateTrees_96_solution solu;
  vector<TreeNode*> res = solu.generateTrees(n);
  cout <<"the size :" << res.size() << endl;
  for (auto iter: res) {
    solu.print(iter);
    cout << endl;
  }
  cout << endl;

  return 0;
}
*/
/*
int main() {
  vector<vector<char>> board = { {'x', 'x', 'x', 'x'}, 
                               {'x', 'o', 'o', 'x'}, 
                               {'x', 'x', 'o', 'x'},
                               {'x', 'o', 'x', 'x'}};
  solve_130_solution solu;
  //flag: 1-> DFS 递归     2-> DFS 非递归    3-> BFS 递归  4-> BFS  非递归
  int flag = 3;
  //solu.solve(board, flag);
  solu.solve_union(board);
  for (int i = 0; i < board.size(); ++i) {
    for (int j = 0; j < board[i].size(); ++j) {
      cout << board[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
*/
////岛屿的数量 leetcode_200
/*
int main() {
  vector<vector<char>> board = { {'1', '1', '1', '1', '0'}, 
                                 {'1', '1', '0', '1', '0'}, 
                                 {'1', '1', '0', '0', '0'},
                                 {'0', '0', '0', '0', '0'}};
  
  numIslands_200_solution solu;
  //flag 1->深度优先搜索（DFS）  2->广度优先搜索（BFS）  3-> 并查集
  int flag = 3;
  if (flag == 3) {
    solu.Union(board);
  }
  solu.numIslands(board, flag);
  cout << "the res: " << solu.numsIslands<< endl;
  return 0;
}
*/
// test 
/*
int main() {
  vector<int> list = {1, 4, 3, 4, 2, 9, 8};
  int n = 7;
  auto iter = find(list.begin(), list.end(), n);
  if (iter != list.end()) {
    cout << "find it" << endl;
    int posi = (iter - list.begin());
    cout << "the n: " << n << "in posi: " << posi << endl; 
  } else {
    cout << "there is no " << n << endl;
  }

  return 0;
}
*/
///最小高度树 leetcode_310
/*
int main() {
  int n = 6;
  vector<vector<int>> board = {{0, 3}, {1, 3}, {2, 3}, {4, 3}, {5, 4}};
  findMinHeightTrees_310_solution solu;
  solu.findMinHeightTrees(n, board);

  return 0;
}
*/
//删除无效的括号 leetcode_301
/*
int main() {
  string s = "(a)())()";
  removeInvalidParentheses_301_solution solu;
  solu.removeInvaliaParentheses(s);
  for (int i = 0; i < solu.res.size(); ++i) {
    cout << solu.res[i] << endl;
  }
  cout << endl;

  return 0;
}
*/
//矩阵中的最长增长路径 leetcode_329
/*
int main() {
  vector<vector<int>> matrix = { {3, 4, 5}, 
                                 {3, 2, 6}, 
                                 {2, 2, 1}};
  longestIncreasingPath_329_solution solu;
  solu.longestIncresingPath(matrix);
  for (int i = 0; i < solu.total_res.size(); ++i) {
    for (int j = 0; j < solu.total_res[i].size(); ++j) {
      cout << solu.total_res[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
*/
//矩阵中的最长增长路径 leetcode_329—2
/*
int main() {
  vector<vector<int>> matrix = { {3, 4, 5}, 
                                 {3, 2, 6}, 
                                 {2, 2, 1}};
  longestIncreasingPath_329_solution2 solu;
  solu.longestIncresingPath2(matrix);
  for (auto iter_i: solu.res) {
    for (auto iter_j: iter_i) {
      cout << iter_j << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}*/
////矩阵中的最长增长路径 leetcode_329 动态规划
/*
int main() {
  vector<vector<int>> matrix = { {3, 4, 5}, 
                                 {3, 2, 6}, 
                                 {2, 2, 1}};
  longestIncreasingPath_329_solution3 solu;
  solu.longestIncresingPath2(matrix);

  return 0;
}
*/
//重新安排行程 leetcode_332
/*
int main() {
  
  vector<vector<string>> tickets = { {"MUC", "LHR"}, 
                                     {"JFK", "MUC"}, 
                                     {"SFO", "SJC"},
                                     {"LHR", "SFO"} };
  /*
  vector<vector<string>> tickets = { {"JFK", "SFO"}, {"JFK", "ATL"}, 
                                     {"SFO", "ATL"}, {"ATL", "JFK"}, 
                                     {"ATL", "SFO"}};*/
/*
  
  findItinerary_332_solution solu;
  solu.findItinerary(tickets);
  return 0;

}
*/
///太平洋大西洋水流问题 leetcode_417
/*
int main() {
  vector<vector<int>> matrix = { {'1', '2', '2', '3', '5'}, 
                                 {'3', '2', '3', '4', '4'}, 
                                 {'2', '4', '5', '3', '1'},
                                 {'6', '7', '1', '4', '5'},
                                 {'5', '1', '1', '2', '4'}};
  pacificAtlantic_417_solution solu;
  solu.pacificAtlantic(matrix);
  for (int i = 0; i < solu.res.size(); ++i) {
    for (int j = 0; j < 2; ++j) {
      cout << solu.res[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
*/
///二叉树
/*
int main() {
  Tree<char> my_tree;
  //A{B{C, }, D} ->ABC###D##
  //A{B{, D}, C}  ->AB#D##C##
  Bitnode<char>* root = my_tree.GetRoot();
  cout << "the res in inorder:" << endl;
  my_tree.InOrder(root);
  cout << "the res in preorder:" << endl;
  my_tree.PreOrder(root);
  cout << "the res in postorder:" << endl;
  my_tree.PostOrder(root);
  //层次
  my_tree.PrintNode_style(root);
  cout << endl;
  my_tree.~Tree();


  return 0;
}
*/


///验证二叉树 leetcode
//A{B{C, }, D} ->ABC###D##
  //A{B{, D}, C}  ->AB#D##C##
/*
int main() {
  Tree<char> my_tree;
  // 21##3## -> 2{1, 3}
  //51##43##6##
  Bitnode<char>* root = my_tree.GetRoot();
  //print in style
  my_tree.PrintNode_style(root);
  cout << endl;
  isValidBST_98_solution solu;
  solu.isValidBST(root);
  if (solu.flag) {
    cout << "this is BST tree" << endl;
  }

  return 0;
}
*/
//二叉树的层次c遍历
//A{B{C, }, D} ->ABC###D##
  //A{B{, D}, C}  ->AB#D##C##
/*
int main() {
  Tree<char> my_tree;
  // 21##3## -> 2{1, 3}
  //51##43##6##
  Bitnode<char>* root = my_tree.GetRoot();
  //print in style
  my_tree.PrintNode_style(root);
  cout << endl;
  levelOrder_102_solution solu;
  //solu.levelOrder(root);
  //solu.levelOrder2(root);
  solu.levelOrder3(root);
  for (int i = 0; i < solu.res.size(); ++i) {
    for (auto iter: solu.res[i]) {
      cout << iter << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
*/
///
///二叉树的锯齿型层次遍历
/*
int main() {
  Tree<char> my_tree;
  // 21##3## -> 2{1, 3}
  //51##43##6##
  Bitnode<char>* root = my_tree.GetRoot();
  //print in style
  my_tree.PrintNode_style(root);
  cout << endl;
  zigzaglevelOrder_103_solution solu;
  
  solu.zigzaglevelOrder(root);
  for (int i = 0; i < solu.res.size(); ++i) {
    for (auto iter: solu.res[i]) {
      cout << iter << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
*/
///路径总和2 leetcode_113
/*
int main() {
  Tree<char> my_tree;
  // 21##3## -> 2{1, 3}
  //51##43##6##
  Bitnode<char>* root = my_tree.GetRoot();
  //print in style
  my_tree.PrintNode_style(root);
  cout << endl;
  pathSum_113_solution solu;
  int sum = 15;
  solu.pathSum(root, sum);
  cout << "the res:" << endl;
  for (int i = 0; i < solu.res.size(); ++i) {
    for (auto iter: solu.res[i]) {
      cout << iter << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
*/
///二叉树转化为链表 leetcode_114
/*
int main() {
  Tree<char> my_tree;
  // 21##3## -> 2{1, 3}
  //51##43##6##
  Bitnode<char>* root = my_tree.GetRoot();
  //print in style
  my_tree.PrintNode_style(root);
  cout << endl;
  flatten_114_solution solu;
  solu.flatten(root);

  cout << "the res:" << endl;
  for (int i = 0; i < solu.res.size(); ++i) {
    cout << solu.res[i] << " ";
  }
  cout << endl;
  return 0;
}
*/
//求根到叶子节点的数字之和
/*
int main() {
  Tree<char> my_tree;
  // 21##3## -> 2{1, 3}
  //51##43##6##
  Bitnode<char>* root = my_tree.GetRoot();
  //print in style
  my_tree.PrintNode_style(root);
  cout << endl;
  sumNumbers_129_solution solu;
  solu.sumNumbers(root);

  cout << "the res:" << endl;
  for (int i = 0; i < solu.res.size(); ++i) {
    for (int j = 0; j < solu.res[i].size(); ++j) {
      cout << solu.res[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;
  return 0;
}
*/
/////二叉树的右视图
/*
int main() {
  Tree<char> my_tree;
  // 21##3## -> 2{1, 3}
  //51##43##6##
  Bitnode<char>* root = my_tree.GetRoot();
  //print in style
  my_tree.PrintNode_style(root);
  cout << endl;
  rightSideView_199_solution solu;
  solu.rightSideView(root);

  cout << "the res:" << endl;
  for (int i = 0; i < solu.res.size(); ++i) {
    cout << solu.res[i] << " ";
  }
  cout << endl;
  return 0;
}*/
/////二叉树中的第K小的元素
/*
int main() {
  Tree<char> my_tree;
  // 21##3## -> 2{1, 3}
  //51##43##6##
  Bitnode<char>* root = my_tree.GetRoot();
  //print in style
  my_tree.PrintNode_style(root);
  cout << endl;
  KthSmallest_230_solution solu;
  int k = 3;
  solu.KthSmallest(root, k);
  while (!solu.queue.empty()) {
      auto top = solu.queue.top();
      cout << top << " ";
      solu.queue.pop();
  }
  cout << endl;
  return 0;
}*/
//二叉树的最近公共祖先 leetcode_236
/*
int main() {
  Tree<char> my_tree;
  // 21##3## -> 2{1, 3}
  //51##43##6##
  Bitnode<char>* root = my_tree.GetRoot();
  //print in style
  Bitnode<char>* p = root->left->left;
  Bitnode<char>* q = root->left;
  my_tree.PrintNode_style(root);
  cout << endl;
  lowestCommonAncestor_236_solution solu;
  solu.lowestCommonAncestor(root, p, q);
  for (auto iter: solu.res) {
    cout << iter << " ";
  }
  cout << endl;

  return 0;
}
*/
//找树左下角的值 leetcode_513
/*
int main() {
  Tree<char> my_tree;
  // 21##3## -> 2{1, 3}
  //51##43##6##
  Bitnode<char>* root = my_tree.GetRoot();
  //print in style
  my_tree.PrintNode_style(root);
  cout << endl;
  findBottomLeftValue_513_solution solu;
  solu.findBottomLeftValue(root);
  for (int i = 0; i < solu.res.size(); ++i) {
    for (auto iter: solu.res[i]) {
      cout << iter << " ";
    }
    cout << endl;
  }
  cout << "the Bottom left value:" << solu.res[solu.res.size() - 1][0] << endl;
  cout << endl;

  return 0;
}
*/
//在每一个树行中找最大值
/*
int main() {
  Tree<char> my_tree;
  // 21##3## -> 2{1, 3}
  //51##43##6##
  Bitnode<char>* root = my_tree.GetRoot();
  //print in style
  my_tree.PrintNode_style(root);
  cout << endl;
  largestValue_515_solution solu;
  solu.largestValue(root);

  for (int i = 0; i < solu.res.size(); ++i) {
    cout << solu.res[i] << " ";
  }
  cout << endl;
  
  return 0;
}
*/
//火柴拼正方形 leetcode_473 
/*
int main() {
  vector<int> nums = {1, 3, 2, 2, 4, 4};
  makesquare_473_solution solu;
  solu.makesquare(nums);

  return 0;
}*/
//最长连续序列 leetcode_128
/*
int main() {
  vector<int> nums = {100, 4, 200, 1, 2, 3, 201, 202};
  longestConsecutive_128_solution solu;
  //solu.longestConsecutive(nums);
  //solu.longestConsecutive2(nums);
  solu.longestConsecutive3(nums);
  return 0;

}
*/
////并查集 leetcode_547 朋友圈
/*
int main() {
  vector<vector<int>> nums = { {1, 1, 0, 0, 0}, 
                               {1, 1, 1, 0, 0}, 
                               {0, 1, 1, 0, 0},
                               {0, 0, 0, 1, 0},
                               {0, 0, 0, 0, 1}
                                               };
  findCircleNum_547_solution solu;
  solu.findCircleNum(nums);
  return 0;
}*/
/*
int main() {
  calcEquation_399_solution solu;
  vector<vector<string>> equations = { {"a", "b"}, 
                                       {"b", "c"} };
  vector<double> val = {2.0, 3.0};
  vector<vector<string>> query = { {"a", "c"}, 
                                   {"b", "a"},
                                   {"a", "e"},
                                   {"a", "a"},
                                   {"x", "x"} };
  solu.calcEquation(equations, val, query);
  return 0;
}*/
/////median is the middle value in an ordered list if the 
//[2, 3, 4] the median is 3
//[2, 3] the median is 2 + 3/2 =  2.5
/*
int main() {
  medianFinder solu;
  solu.addNum(2);
  solu.addNum(3);
  solu.findMedian();
  solu.addNum(4);
  solu.findMedian();
  solu.addNum(5);
  solu.findMedian();
  solu.addNum(6);
  solu.findMedian();
  return 0;
}*/
//存在重复元素 leetcode_220
/*
int main() {
  vector<int> A = {1, 2, 6, 0, 0, 0};
  //int len_A = A.size();
  vector<int> B = {3, 5, 7};
  int len_B = B.size();
  int len_A = A.size() - len_B;
  merge_1680_solution solu;
  //solu.merge(A, len_A, B, len_B);
  solu.merge2(A, len_A, B, len_B);
  //solu.merge3(A, len_A, B, len_B);
  
  return 0;
}
*/
///删除排序数组中的重复项 leetcode_80
/*
int main() {
  vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 4, 5, 5, 5, 6};
  removeDuplicate_80_solution solu;
  solu.removeDuplicate(nums);
  //solu.removeDuplicate2(nums);
  return 0;
}*/
///颜色分类 leetcode_75
/*
int main() {
  //vector<int> nums = {0, 0, 1, 2, 1, 0, 2, 3, 4};
  vector<int> nums = {0, 0, 1, 2, 1, 0, 2};
  sortColors_75_solution solu;
  //solu.sortColor(nums);
  solu.sortColor2(nums);
  
  return 0;
}*/


/////最小覆盖子串  leetcode_76 
/*
int main() {
  minWindow_76_solution solu;
  string s = "ADOBECODEBANC";
  string t = "ABC";
  cout << "the string s: " << s << endl;
  solu.minWindow(s, t);
  for (int i = 0; i < solu.res.size(); ++i) {
    for (auto iter: solu.res[i]) {
      cout << iter << " ";
    }
    cout << endl;
  }
  cout << endl;


  return 0;
}
*/

///长度最小的子数组 leetcode_209
/*
int main() {
  vector<int> nums = {2, 3, 1, 2, 4, 3};
  int s = 7;
  minSubArraylen_209_solution  solu;
  //solu.minSubArraylen(s, nums);
  //solu.minSubArraylen2(s, nums);
  solu.minSubArraylen3(s, nums);
  for (int i = 0; i < solu.res.size(); ++i) {
    for (int j = 0; j < solu.res[i].size(); ++j) {
      cout << solu.res[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}
*/
//滑动窗口最大值 leetcode_239 
/*
int main() {
  maxSlidingWindow_239_solution solu;
  vector<int> res;
  vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
  cout << "the nums: ";
  for (int i = 0; i < nums.size(); ++i) {
    cout << nums[i] << " ";
  }
  cout << endl;
  int k = 3;
  res = solu.maxSlidingWindow(nums, k);

  for (int i = 0; i < res.size(); ++i) {
    cout << res[i] << " ";
  }
  cout << endl;

  return 0;
}
*/

/////替换后的最长重复字符
/*
int main() {
  string s = "ABAB";
  int k = 2;
  characterReplacement_424_solution solu;
  solu.characterReplacement(s, k);
  for (int i = 0; i < solu.res.size(); ++i) {
    for (int j = 0; j < solu.res[i].size(); ++j) {
      cout << solu.res[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}
*/
/////字符串的排列 leetcode_567 最大字符串是否包含最小字符串
/*
int main() {
  string long_str = "dcda";
  string short_str = "adc";
  checkInclusion_567_solution solu;
  solu.checkInclusion(short_str, long_str);
  cout << "all the posi :" << endl;
  for (int i = 0; i < solu.container.size(); ++i) {
    for (int j = 0; j < solu.container[i].size(); ++j) {
      cout <<solu.container[i][j] << " "; 
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}
*/
///无重复字符的最长子串 leetcode_3 滑动窗口
/*
int main() {
  string s = "pwwkew";
  lengthOfLongestSubstring_3_solution solu;
  solu.lengthOfLongestSubstring(s);

  return 0;
}
*/
///最大连续1个的个数
/*
int main() {
  vector<int> A = {1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1};
  int k = 2;
  longestOnes_1004_solution solu;
  //solu.longestOnes(A, k);
  solu.longestOnes2(A, k);
  for (int i = 0; i < solu.res.size(); ++i) {

    cout << solu.res[i].first << " " << solu.res[i].second << endl;
  }

  return 0;
}*/
///爱生气的书店老板 leetcode_1052
/*
int main() {
  vector<int> customers = {1, 0, 1, 2, 1, 1, 7, 5};
  vector<int> grumpy    = {0, 1, 0, 1, 0, 1, 0, 1};
  int x = 3;
  maxSatisfied_1052_solution solu;
  solu.maxSatisfied3(customers, grumpy, x);
  for (int i = 0; i < solu.res.size(); ++i) {
    cout << "the left, right and max_satisify: " << solu.res[i].first.first 
    << " " << solu.res[i].first.second  <<" "<< solu.res[i].second << endl;
  }

  return 0;
}
*/
///高效实现寻找素数
/*
int main() {
  int n = 10;
  countPrimes_solu solu;
  solu.countPrimes(n);
  for (int i = 0; i < solu.res.size(); ++i) {
    cout << solu.res[i] << " ";
  }
  cout << endl;
  return 0;
}*/
/*
int main() {
  Dijkstra_solu solu;
  Graph G;
  G.vexnum = 7;
  G.vexs  = {"A", "B", "C", "D", "E", "F", "G"};
  cout << "pass in 1585" << endl;
  //G.edgenum = 12;
  //INT_MAX 表示不直接连接
  G.matrix = { {0,   12,   INT_MAX,  INT_MAX,  INT_MAX,  16,   14}, 
               {12,   0,    10,   INT_MAX,  INT_MAX,   7,  INT_MAX}, 
              {INT_MAX,  10,    0,    3,     5,     6,   INT_MAX} , 
              {INT_MAX, INT_MAX,   3,    0,     4,    INT_MAX, INT_MAX} , 
              {INT_MAX, INT_MAX,   5,    4,     0,     2,     8}, 
               {16,    7,    6,   INT_MAX,   2,     0,     9}, 
               {14,   INT_MAX, INT_MAX, INT_MAX,   8,     9,     0}};
  cout << "pass in 1594" << endl;
  int vs = 3;
  solu.dijkstra(G, vs);
  //solu.dijkstra(G, vs);
  cout << "pass in 1597" << endl;
  
  return 0;
}
*/
/////最长上升子序列 
/*
int main() {
  lengthofLis_300_solution  solu;
  //vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
  vector<int> nums = {4, 10, 4, 3, 8, 9};
  //int len = solu.lengthofLis(nums);
  //int len = solu.lengthofLis2(nums);
  int len = solu.lengthofLis3(nums);
  //int len = solu.lengthofLis4(nums);
  cout << "the len: " << len << endl;

  return 0;
}
*/
//搜索二维矩阵 leetcode_74
/*
int main() {
  searchMatrix_74_solution solu;
  
  //vector<vector<int>> matrix = { {1,  3,  5,  7}, 
  //                               {10, 11, 16, 20}, 
  //                               {23, 30, 34, 50} };
  vector<vector<int>> matrix = {{1} };
  int target = 1;
  //solu.searchMatrix(matrix, target);
  solu.searchMatrix2(matrix, target);
  cout << "the row and col: " << solu.res[0].first 
       << " " << solu.res[0].second << endl;

  return 0;
}
*/
//寻找山脉峰值 峰值：nums[i] > nums[i + 1] and nums[i] < nums[i - 1]
/*
int main() {
  vector<int> nums = {1, 2, 1, 3, 5, 6, 4};
  findPeakElement_162_solution solu;
  //solu.findPeakElement(nums);
  int res = solu.findPeakElement2(nums);
  cout << "the peak posi: " << res << endl;
  cout << "the peak element: " << nums[res] << endl;
  return 0;
}
*/
//区间和的个数 给定一个整数数组 nums，
//返回区间和在 [lower, upper] 之间的个数，
//包含 lower 和 upper。
/*
int main() {
  vector<int> nums = {-2, 5, -1};
  for (int i = 0; i < nums.size(); ++i) {
    cout << nums[i] << endl;
  }
  cout << endl;
  int lower = -2, upper = 2;
  countRangeSum_327_solution solu;
  solu.countRangeSum(nums, lower, upper);


  return 0;
}
*/
/////统计优美子数组 leetcode_1248
//连续数组中有k个奇数
/*
int main() {
  vector<int> nums = {2,2,2,1,2,2,1,2,2,2};
  int k = 2;
  numberofSubarrays_1248_solution solu;
  solu.numberofSubarrays3(nums, k);

  return 0;
}
*/
// 四个数之和 leetcode_454
/*
int main() {
  vector<int> A = {1, 2};
  vector<int> B = {-2, -1};
  vector<int> C = {-1, 2};
  vector<int> D = {0, 2};
  foursumcout_454_solution solu;
  solu.foursumcout(A, B, C, D);
  for (int i = 0; i < solu.res.size(); ++i) {
    for (int j = 0; j < solu.res[i].size(); ++j) {
      cout << solu.res[i][j] << " ";
    }
    cout << endl;
  }
  cout << endl;

  return 0;
}
*/
// // 找到K个最接近的元素 leetcode_658
/*
int main() {
  findclosestelement_658_solution solu;
  vector<int> nums = {1, 2, 3, 4, 5};
  int k = 4;
  int x = 3;
  solu.findclosestelement(nums, k, x);

  return 0;
}*/
//  乘法表中第K小的数 leetcode_668
/*
int main() {
  int m = 3, n = 3, k = 5;
  findKthnumber_668_solution solu;
  solu.findKthnumber(m, n, k);



  return 0;
}
*/
//  最长重复子数组 leetcode_718
/*
int main() {
  vector<int> A = {1, 2, 3, 7, 8};
  vector<int> B = {6, 9, 1, 2, 3};
  findLength_718_solution solu;
  solu.findLength(A, B);

  return 0;
}
*/

// 最短编辑距离，对一个string s进行编辑，使得s变成string t,要求操作次数最短
/*
int main() {
  string s1 = "ros";
  string s2 = "horse";
  cout << "the string s1 and s2: " << s1 <<" "<< s2 << endl;
  ShortEditLen_solution solu;
  solu.ShortEditLen(s1, s2);

  return 0;
}
*/

/*
// 如何去除有序数组的重复元素
// labuladong 算法小抄
int main() {
  // 有序
  vector<int> nums = {0, 0, 0, 1, 1, 2, 2, 2, 3, 3, 4, 6};
  // 无序
  vector<int> nums1 = {0, 1, 0, 9, 1, 8, 9, 6, 6, 5, 4, 6};
  removeDuplicate_solu solu;
  solu.removeDuplicate2(nums1);
  solu.removeDuplicate(nums);

  return 0;
}
*/
// 如何寻找最长回文子串
/*
int main() {
  string s = "babad";
  longestPalindrome_solu solu;
  solu.longestPalindrome(s);

  return 0;
}
*/
// leetcode_45 跳格子
/*
int main() {
  vector<int> nums = {2, 3, 1, 1, 4};
  jump_45_solution solu;
  solu.jump(nums);

  return 0;
}
*/
// // labuladong算法小抄 
// 最长递增序列（序列可以不连续，但是串必须连续）
/*
int main() {
  vector<int> nums = {3, 5, 6, 2, 5, 4, 5, 19 ,5, 6, 7, 12};
  lengthOfLIS_solu solu;
  solu.lengthOfLis2(nums);

  return 0;
}
*/
// 0-1背包问题
/*
int main() {
  int N = 3, W = 4;
  vector<int> weight = {2, 1, 3};
  vector<int> value= {4, 2, 3};
  knapsack_solu solu;
  solu.knapsack(N, W, weight, value);
  
  cout << endl;

  return 0;
}
*/
// 高楼掉鸡蛋 
/*
int main() {
  // 3个鸡蛋, 7层楼
  int K = 3, N = 7;
  superEggDrop_solu solu;
  solu.superEggDrop(K, N);

  return 0;
}
*/
// 最长公共子序列
/*
int main() {
  longestCommonSubsequence_solution solu;
  string str2 = "babcde";
  string str1 = "ace";
  solu.longestCommonSubsequence(str1, str2);

  return 0;
}
*/
// 最长回文子序列
/*
int main() {
  string str1 = "cbbdbdac";
  cout << "the string: " << str1 << endl;
  longestPalindromeSubseq_solution solu;
  solu.longestPalindromeSubseq(str1);
  
  return 0;
}
*/
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
/*
int main() {
  stoneGame_solu solu;
  vector<int> stone = {3, 9, 1, 2};
  solu.stoneGame(stone);
  cout << "pass in 1857" << endl;
  return 0;
}
*/
// 贪心算法之区间调度问题
/*
在区间集合 intvs 中选择一个区间 x，这个 x 是在当前所有区间中结束最早的（end 最小）。
把所有与 x 区间相交的区间从区间集合 intvs 中删除。
重复步骤 1 和 2，直到 intvs 为空为止。之前选出的那些 x 就是最大不相交子集。
*/
/*
int main() {
  vector<vector<int>> nums = 
    {{2, 4}, {1, 5}, {3, 6}, {5, 7}, {6, 9}, {8, 9}};
  intervalSchedule_solu solu;
  solu.intervalSchedule(nums);

  return 0;
}*/
// leetcode_435 无重叠区间
// 给定一个区间，找出最少需要去除的子区间，使得剩下的区间不重复
// 转化问题， 就是找一个最长的不重叠区间 
/*
int main() {
  vector<vector<int>> nums = 
    {{1, 2}, {2, 3}, {3, 4}, {1, 3}};
  eraseOverlapIntervals_435_solu solu;
  solu.eraseOverlapIntervals(nums);

  return 0;
}
*/

// 股票买卖问题 最多允许进行一次买和卖
/*
int main() {
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  //vector<int> prices = {7, 6, 4, 3, 2, 1};
  Solution_121_solution solu;
  solu.maxProfit(prices);


  return 0;
}*/

// 股票买卖问题，允许进行多次买和卖
/*
int main() {
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  //vector<int> prices = {7, 6, 4, 3, 2, 1};
  Solution_122_solution solu;
  solu.maxProfit(prices);


  return 0;
}
*/
// 股票买卖问题，允许进行2次操作(买和卖加起来算一次)
/*
int main() {
  //vector<int> prices = {7, 1, 5, 3, 6, 4, 1};
  //vector<int> prices = {7, 6, 4, 3, 2, 1};
  vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
  Solution_123_solution solu;
  solu.maxProfit(prices);


  return 0;
}
*/

// 股票买卖问题，允许进行k次操作(买和卖加起来算一次)
/*
int main() {
  //vector<int> prices = {7, 1, 5, 3, 6, 4, 1};
  vector<int> prices = {7, 1, 5, 3, 6, 4};
  //vector<int> prices = {7, 6, 4, 3, 2, 1};
  //vector<int> prices = {3, 3, 5, 0, 0, 3, 1, 4};
  int k = 1;
  Solution_188_solution solu;
  solu.maxProfit(prices, k);


  return 0;
}
*/
// labuladong算法小抄
// 实现计算器
/*
int main() {
  string s = "-(1-(2-3))-3/3";
  calculator_solution solu;
  solu.pre_process(s);
  

  return 0;
}
*/
// 
// labuladong算法小抄
/*
对于比较小的数字，做运算可以直接使用编程语言提供的运算符，但是如果相乘的两个因数非常大，
语言提供的数据类型可能就会溢出。一种替代方案就是，运算数以字符串的形式输入，
然后模仿我们小学学习的乘法算术过程计算出结果，并且也用字符串表示。
*/
/*
int main() {
  multiply_string_solution solu;
  string s2 = "123", s1 = "45";
  solu.multiply_string(s1, s2);

  return 0;
}
*/

// 给出一个区间的集合，请合并所有重叠的区间
// leetcode_56
/*
int main() {
  merge_56_solution solu;
  vector<vector<int>> nums = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
  vector<pair<int, int>> ans;
  solu.merge(nums, ans);


  return 0;
}
*/
// 给出两个区间，请输出两个区间的重叠部分
// leetcode_986
/*
int main() {
  intervalIntersection_986_solution solu;
  vector<vector<int>> nums1 = {{0, 2}, {5, 10}, {13, 23}, {24, 25}};
  vector<vector<int>> nums2 = {{1, 5}, {8, 12}, {15, 24}, {25, 26}};
  solu.intervalIntersection(nums1, nums2);

  return 0;
}
*/
// 俄罗斯套娃，信封问题
/*
int main() {
  envelops_solution solu;
  vector<vector<int>> nums = {{1, 8}, {2, 3}, {5, 4}, {5, 2}, {6, 7}, {6, 4}};
  solu.envelops(nums);

  return 0;
}
*/
// labuladong算法小抄
// 颜色填充问题 
/*
int main() {
  FloodFill_solution solu;
  vector<vector<int>> nums = {{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
  int sr = 1, sc = 1;
  int newcolor = 2;
  solu.floodfill(nums, sr, sc, newcolor);

  for (int i = 0; i < nums.size(); ++i) {
      for (int j = 0; j < nums[i].size(); ++j) {
          cout << nums[i][j] << " ";
      }
      cout << endl;
  }
    cout << endl;
  return 0;
}
*/
// labuladong算法小抄
// 二分查找高效判断子序列
/*
int main() {
  isSubsequence_solu solu;
  string s1 = "abc";
  string s2 = "cacbhbc";
  // solu.isSubsequence(s1, s2);
  solu.isSubsequence2(s1, s2);


  return 0;
}
*/
//// 三数之和
// 在一个数组中找3个数使得他们的和等于0
/*
int main() {
  ThreeSum_15_solution solu;
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  // solu.ThreeSum(nums);
  int target = 0;
  solu.ThreeSum2(nums, target);
  return 0;
}
*/
// 四数之和
// 在一个数组中找4个数使得他们的和等于target
/*
int main() {
  FourSum_18_solution solu;
  vector<int> nums = {-1, -1, 0, 1, 0, -2, 2};
  // solu.ThreeSum(nums);
  int target = 0;
  solu.FourSum(nums, target);

  return 0;
}
*/
// 最接近的三个数之和
// 
/*
int main() {
  vector<int> nums = {-1, 2, 1, -4};
  int target = 1;
  ThreeSumClosest_16_solution solu;
  solu.ThreeSumClosest(nums, target);


  return 0;
}*/
// 盛最多水的容器
// leetcode_11
/*
int main() {
  maxArea_11_solution solu;
  //vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
  vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
  // solu.maxArea(nums);
  // solu.maxArea2(nums);
  solu.maxArea3(nums);
  return 0;
}
*/
// labuladong算法小抄
// 用栈实现队列，用双栈实现队
/*
int main() {
  Stack_2_queue_solution solu;
  solu.push(1);
  solu.push(2);
  solu.push(3);
  solu.push(4);
  //
  int top_val = solu.peek();
  cout << "the top: " << top_val << endl;
  solu.pop();
  //
  top_val = solu.peek();
  cout << "the top: " << top_val << endl;
  solu.pop();
  //
  top_val = solu.peek();
  cout << "the top: " << top_val << endl;
  solu.pop();
  //
  top_val = solu.peek();
  cout << "the top: " << top_val << endl;
  solu.pop();
  //
  top_val = solu.peek();
  cout << "the top: " << top_val << endl;
  solu.pop();

  return 0;
}
*/
// // labuladong算法小抄
// 用队列实现栈，用队列实现栈

int main() {
  Queue_2_stack_solution solu;
  solu.push(1);
  solu.push(2);
  solu.push(3);
  solu.push(4);
  //
  int top_val = solu.top();
  cout << "the top: " << top_val << endl;
  solu.pop();
  //
  top_val = solu.top();
  cout << "the top: " << top_val << endl;
  solu.pop();
  //
  top_val = solu.top();
  cout << "the top: " << top_val << endl;
  solu.pop();
  //
  top_val = solu.top();
  cout << "the top: " << top_val << endl;
  solu.pop();
  //
  top_val = solu.top();
  cout << "the top: " << top_val << endl;
  solu.pop();


  return 0;
}