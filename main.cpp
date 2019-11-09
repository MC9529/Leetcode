
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


////Permute_46
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

///NQueue_51

int main(){
  vector<vector<string>> res;
  //std::cout << "pass in 41" << std::endl;
  sloveNQueue_51_Solution s1;
  //std::cout << "pass in 41" << std::endl;
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


