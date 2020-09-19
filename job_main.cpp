
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
// #include "BiTree.h"
// #include "LinkList.h"

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

// 创建一个链表

/*
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
*/

// offer06 从尾到头打印链表
/*
int main() {

    LinkList list;
    list.creatLinkList_one(1);
    list.creatLinkList_one(2);
    list.creatLinkList_one(3);
    list.creatLinkList_one(4);
    list.TravelLinkList();
    offer06 solu;
    solu.reverseprint(list.head);
    
    return 0;
}
*/

// // offer 24 反转链表
/*
int main() {

    LinkList list;
    list.creatLinkList_one(1);
    list.creatLinkList_one(2);
    list.creatLinkList_one(3);
    list.creatLinkList_one(4);
    list.TravelLinkList();
    offer24 solu;
    solu.reverselist(list.head);
    list.TravelLinkList();

    return 0;
}
*/

/*
int main() {
  Tree<char> my_tree;
  //A{ B {C, },  D} ->ABC###D##
  //      A
  //     / \
  //     B  D
  //    /
  //   C
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
// offer07 重建二叉树
/*

int main() {
    offer07 solu;
    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    Bitnode<int> *tree = solu.buildTree(preorder, inorder);

    solu.levelorder(tree);
    for (int i = 0; i < solu.res.size(); ++i) {
        vector<int> temp = solu.res[i];
        for (auto iter: temp) {
            cout << iter << " ";
        }
        cout << endl;
    }
    
   
    return 0;
}
*/

/*
int main() {
     queue2stack solu;
     int temp = 1;
     solu.push(temp);

     solu.push(2);
     solu.push(3);
     solu.push(4);

     cout << "the top: " << solu.top() << endl;
     cout << "the top1: " << solu.top_element << endl;
     solu.pop();

     cout << "the top: " << solu.top() << endl;
     cout << "the top1: " << solu.top_element << endl;
     solu.pop();

     cout << "the top: " << solu.top() << endl;
     cout << "the top1: " << solu.top_element << endl;
     solu.pop();

     cout << "the top: " << solu.top() << endl;
     cout << "the top1: " << solu.top_element << endl;
     solu.pop();
      
     solu.pop();
     


    return 0;
}
*/

int main () {
    stack2queue solu;
    
    int temp = 1;
     solu.push(temp);

     solu.push(2);
     solu.push(3);
     solu.push(4);
     solu.pop();

     
     cout << "the top: " << solu.front() << endl;
     // cout << "the top1: " << solu.top_element << endl;
      solu.push(5);

     solu.pop();

     cout << "the top: " << solu.front() << endl;
     // cout << "the top1: " << solu.top_element << endl;
     solu.pop();

     cout << "the top: " << solu.front() << endl;
     // cout << "the top1: " << solu.top_element << endl;
     solu.pop();

     cout << "the top: " << solu.front() << endl;
     // cout << "the top1: " << solu.top_element << endl;
     solu.pop();

     cout << "the top: " << solu.front() << endl;
     // cout << "the top1: " << solu.top_element << endl;
     solu.pop();
      
     solu.pop();
     



    return 0;
}
