
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

/*
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
*/

// 费波那契数列
/*
int main() {

    offer10 solu;
    for (int i = 1; i < 10; ++i) {
        solu.fib(i);
    }
    // solu.fib(7);

    return 0;
}
*/
// 青蛙跳台 offer10_2
/*
int main() {
    offer10_2 solu;
    for (int i = 0; i < 10; ++i) {

        solu.numWays(i);
    }



    return 0;
}
*/
// 旋转数组的最小值  二分法
/*
int main() {
    offer11 solu;
    vector<int> nums = {3, 4, 5, 6, 1, 2};
    solu.minArray(nums);


    return 0;
}*/

// offer12 矩阵中的路径

/*
int main() {
    offer12 solu;
    // string word = "abcd";
    string word = "ABCCED";
    vector<vector<char>> borad = { {'A', 'B', 'C', 'E'},
                                    {'S', 'F', 'C', 'S'},
                                    {'A', 'D', 'E', 'E'} };

    bool ans = solu.exit(borad, word);
    if(ans) {
        cout << "there exit" << endl;
    } else {
        cout << "there do not exit" << endl;
    }


    return 0;
}
*/

// offer13 机器人的运动范围
/*
int main() {
    offer13 solu;
    // int m = 2, n = 3, k = 1;
    int m = 3, n = 1, k = 0;
    solu.movingCount(m, n, k);


    return 0;
}
*/

/*
// // offer14_1 割绳子
int main() {
    offer14_1 solu;
    int n = 10;
    solu.cuttingRope(n);

    return 0;
}
*/

 // 二进制中1的个数
 /*
int main() {
    offer15 solu;
    int n = 4;
    solu.hammingWeight(n);

    return 0;
}
*/
 // offer_16 数值的整数次方

 /*
 int main() {
    offer16 solu;
    double x = 2.1000;
    int n = 3;
    solu.mypow(x, n);


     return 0;
 }
 */



// offer18 删除链表的节点

/*
int main() {
    LinkList list;
    list.creatLinkList_one(1);
    list.creatLinkList_one(2);
    list.creatLinkList_one(3);
    list.creatLinkList_one(3);
    list.creatLinkList_one(4);
    list.TravelLinkList();
    int val = 3;
    offer18 solu;
    solu.deleteNode(list.head, val);

    list.TravelLinkList();


    return 0;
}
*/
// offer21 调整数组顺序使得奇数位于偶数前面

/*
int main() {

   offer21 solu;
   vector<int> nums = {1, 2, 3, 4, 5, 6};
   solu.exchange(nums);
   return 0;
}
*/

 // offer24 反转链表
/*
int main() {

    LinkList list;
    list.creatLinkList_one(1);
    list.creatLinkList_one(2);
    list.creatLinkList_one(3);
    list.creatLinkList_one(3);
    list.creatLinkList_one(4);
    list.TravelLinkList();

    offer241 solu;
    Node * head = solu.reverseList(list.head);


    return 0;
}
*/


/*
int main() {

  Tree<char> my_tree;
  // Tree<char> my_tree_2;
  //A{ B {C, },  D} ->ABC# ## D##
  //      A
  //     / \
  //     B  D
  //    /
  //   C
  //A{B{, D}, C}  ->ABD###C##
  //      A
  //     / \
  //     B  C
  //    /
  //   D
  Bitnode<char>* root = my_tree.GetRoot();
  // Bitnode<char>* root2 = my_tree_2.GetRoot();
  
  cout << "the res in inorder:" << endl;
  my_tree.InOrder(root);
  /*
  cout << "the res in preorder:" << endl;
  my_tree.PreOrder(root);
  cout << "the res in postorder:" << endl;
  my_tree.PostOrder(root);
  //层次
  my_tree.PrintNode_style(root);
  cout << endl;
  // Bitnode<char>* root2 = my_tree.GetRoot();
  cout << endl;
*/

/*
  string a = "abcdefg";
  string b = "cdde";
  offer26 solu;
  solu.judge(a, b);
  string str_root;
  solu.preOrder(root, str_root);
  cout << "the preorder: " << str_root << endl;
  // Bitnode<char>* root2 = my_tree.GetRoot();
  // solu.isSubstructure(root, root2);
  // my_tree.~Tree();

  return 0;
}

*/

// // offer27 二叉树的镜像

/*
int main() {

    Tree<char> my_tree;
  // Tree<char> my_tree_2;
  //A{ B {C, },  D} ->ABC# ## D##
  //      A
  //     / \
  //     B  D
  //    /
  //   C
  //A{B{, D}, C}  ->ABD###C##
  //      A
  //     / \
  //     B  C
  //    /
  //   D
  Bitnode<char>* root = my_tree.GetRoot();
   //层次
  my_tree.PrintNode_style(root);
  offer27 solu;
  solu.mirrorTree(root);
  my_tree.PrintNode_style(root);

  return 0;
}
*/

// 对称的二叉数  offer28
/*
int main() {
    bool res = false;
    Tree<char> my_tree;
  // Tree<char> my_tree_2;
  //A{ B {C, },  D} ->ABC# ## D##
  //      A
  //     / \
  //     B  D
  //    /
  //   C
  //A{B{, D}, C}  ->ABD###C##
  //      A
  //     / \
  //     B  C
  //    /
  //   D

    Bitnode<char>* root = my_tree.GetRoot();
    my_tree.PrintNode_style(root);
    offer28 solu;
    res = solu.issymmetric(root);
    if (res) {
        cout << "yse" << endl;
    } else {
        cout << "no" << endl;
    }


    return 0;
}
*/

// offer29 顺时针的打印矩阵

/*
int main() {

    vector<vector<int>> matrix = { {1, 2, 3},
                                    {4, 5, 6}, 
                                    {7, 8, 9} };
    

   offer29 solu;
   solu.spiralOrder(matrix);
   return 0;


}*/

/*
// 从上到下打印二叉树  offer32_1
int main() {

    Tree<char> my_tree;
  // Tree<char> my_tree_2;
  //A{ B {C, },  D} ->ABC# ## D##
  //      A
  //     / \
  //     B  D
  //    /
  //   C
  //A{B{, D}, C}  ->ABD###C##
  //      A
  //     / \
  //     B  C
  //    /
  //   D

    Bitnode<char>* root = my_tree.GetRoot();

    offer321 solu;
    solu.levelorder(root);
    

    return 0;

}
*/

// 从上到下打印二叉树  offer32_2
/*
int main() {

    Tree<char> my_tree;
  // Tree<char> my_tree_2;
  //A{ B {C, },  D} ->ABC# ## D##
  //      A
  //     / \
  //     B  D
  //    /
  //   C
  //A{B{, D}, C}  ->ABD###C##
  //      A
  //     / \
  //     B  C
  //    /
  //   D

    Bitnode<char>* root = my_tree.GetRoot();

    offer322 solu;
    solu.levelorder(root);
    
    return 0;

}
*/

// 从上到下打印二叉树  offer32_3

/*
int main() {

    Tree<char> my_tree;
  // Tree<char> my_tree_2;
  //A{ B {C, },  D} ->ABC# ## D##
  //      A
  //     / \
  //     B  D
  //    /
  //   C
  //A{B{, D}, C}  ->ABD###C##
  //      A
  //     / \
  //     B  C
  //    /
  //   D

    Bitnode<char>* root = my_tree.GetRoot();
    vector<int> example = {1, 2, 3, 4};
    reverse(example.begin(), example.end());
    for (auto iter: example) {
        cout << iter << " ";
    }
    cout << endl;

    offer323 solu;
    solu.levelorder(root);
    
    return 0;

}
*/


// offer34 二叉树中和为某一值的路径

/*
int main() {
    
    Tree<char> my_tree;
  // Tree<char> my_tree_2;
  //A{ B {C, },  D} ->ABC# ## D##
  //      A
  //     / \
  //     B  D
  //    /
  //   C
  //A{B{, D}, C}  ->ABD###C##
  //      A
  //     / \
  //     B  C
  //    /
  //   D

    Bitnode<char>* root = my_tree.GetRoot();
    cout << "pass in 691" << endl;
    offer34 solu;
    int sum = 6;
    solu.pathSum(root, sum);
    
    return 0;
}

*/
/*
int main() {

    searchRange_solution solu;
    int target = 8;
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    vector<int> res = solu.searchRange(nums, target);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return 0;
}
*/

// offer37 序列化二叉树
/*
int main() {
    
    Tree<char> my_tree;
  // Tree<char> my_tree_2;
  //A{ B {C, },  D} ->ABC# ## D##
  //      A
  //     / \
  //     B  D
  //    /
  //   C
  //A{B{, D}, C}  ->ABD###C##
  //      A
  //     / \
  //     B  C
  //    /
  //   D

    Bitnode<char>* root = my_tree.GetRoot();
    cout << "pass in 691" << endl;
    offer37 solu;
    solu.serialize(root);
    
    return 0;
}

*/
// offer38
/*
int main() {
    offer38 solu;
    string s = "abcddc";
    solu.permutable(s);

    return 0;
}
*/



// offer39
/*
int main() {
    int ans;
    offer39 solu;
    vector<int> nums = {1, 2, 3, 2, 2, 2, 5, 4, 2};
    solu.majorityElement(nums);

    return 0;
}
*/

int main() {
    offer40 solu;
    int k = 3;
    vector<int> nums = {1, 7, 6, 4, 5, 3, 2};
    solu.getKthNumber(nums, k);

    return 0;
}