
#include <algorithm>
#include <iomanip>
#include <limits>
#include <utility>
#include <vector>
//#include "Eigen/LU"
#include<iostream>

#include "solution.h"
#include "job.h"
#include <vector>
#include "BiTree.h"
#include "LinkList.h"
using namespace std;
// leetcode_120

/*
int main() {
  vector<vector<int>> nums = { {2},
                              {3, 4},
                             {6, 5, 7},
                            {4, 1, 8, 3} };
  
  minimumTotal_120_solution solu;
  solu.minimumTotal(nums);

  return 0;
}*/

// offer 03 数组中重复的数字
/*
int main() {
    vector<int> nums = {2, 3, 1, 0, 2, 5, 3};
    offer03 solu;
    solu.findRepeatNum(nums);


    return 0;
}
*/

// offer 53_1 统计一个数字在数组中出现的次数

/*
int main() {
    offer53_1 solu;
    vector<int> nums = {2, 3, 1, 0, 2, 5, 3};
    int target1 = 9;
    int target2 = 2;
    solu.search(nums, target1);
    solu.search(nums, target2);


    solu.search2(nums, target1);
    solu.search2(nums, target2);
    return 0;
}
*/

/*
// offer05 替换空格
int main() {
    offer05 solu;
    string s = "We are  family";
    solu.replaceSpace(s);
    solu.replaceSpace2(s);

    return 0;
}
*/

int main() {

    LinkList list;
    list.creatLinkList_one(1);
    list.creatLinkList_one(2);
    // 
    list.TravelLinkList();
    list.Getlen();
    list.Isempty();
    // 
    list.insertLinkList(3, 1);
    list.insertLinkList(4, 2);
    list.TravelLinkList();
    list.Getlen();
    list.Isempty();
    // 
    list.deleteLinkLint(1);
    list.TravelLinkList();
    list.deleteLinkLint(2);
    list.TravelLinkList();
    list.deleteLinkLint(list.size);
    list.TravelLinkList();

    list.Getlen();
    list.Isempty();
    //
    list.creatLinkList(2);
    list.TravelLinkList();
    list.Getlen();
    list.Isempty();
    list.TravelLinkList();
    // 
     list.ByeLinkList();
     list.Getlen();
    list.Isempty();
    list.TravelLinkList();
    return 0;
}