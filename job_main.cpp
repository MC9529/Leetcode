
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

/*
int main() {
    offer40 solu;
    int k = 3;
    vector<int> nums = {1, 7, 6, 4, 5, 3, 2};
    solu.getKthNumber(nums, k);

    return 0;
}
*/

// // offer42 连续子数组的最大和
/*
int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    offer42 solu;
    solu.maxSubArray(nums);

    return 0;
}
*/

/*
//  offer43 1～n整数中1出现的次数
int main() {
    int n = 12;
    offer43 solu;
    solu.countDigitone(n);

    return 0;
}
*/


// 把数组排列成最小的数 offer45
/*
int main() {
    offer45 solu;
    vector<int> nums = {3, 30, 34, 5, 9};

    solu.minNumber(nums);

    return 0;
}

*/

// offer47 礼物的最大值
/*
int main() {
    offer47 solu;
    vector<vector<int>> grid = {{1, 3, 1},
                                {1, 5, 1},
                                {4, 2, 1}};

    solu.maxValue(grid);


    return 0;
}
*/

 // offer48 最长不含重复字符的子字符串
 /*
 int main() {
    string s = "abcdeabcdecfghbb";
    offer48 solu;
    solu.lengthOflongestSubstring(s);


     return 0;
 }

 */

/*
int main() {
    offer49 solu;
    int n = 10;
    solu.nthUglyNumber(n);

    return 0;
}
*/

// offer50  // 第一个只出现一次的字符

/*
int main() {
    offer50 solu;

    string s = "abaccdeff";
    solu.firstUniqChar(s);


    return 0;
}

*/

/*
int main() {

    vector<int> nums = {7, 5, 6, 4, 1};
    offer51 solu;
    solu.reversePairs(nums);

    return 0;
}
*/

// // offer53_1  在排序数组中查找数字

/*
int main() {
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    int target = 8;
    int target1 = 6;

    offer532 solu;
    solu.search(nums, target);
    solu.search(nums, target1);

    return 0;
}
*/

/*
int main() {

    vector<int> nums = {0, 1, 3};
    offer533 solu;
    solu.missingnum(nums);

    return 0;
}
*/

// 55 二叉树的的深度

/*
int main() {

   offer55 solu;
    
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
    solu.maxdepth(root);

    return 0;
}
*/

//  / offer561 数组中数字出现的次数
/*
int main() {

    vector<int> nums = {4, 1, 4, 6};
    offer561 solu;
    solu.singlenumber(nums);

    return 0;
}
*/

// offer57 和为s的两个数字
/*
int main() {

    vector<int> nums = {2, 3, 5, 6, 11};
    int target = 8;
    offer57 solu;
    // solu.twosum(nums, target);
    solu.twosum2(nums, target);


    return 0;
}
*/

// // 和为s的连续正数序列 offer572
/*
int main() {
    offer572 solu;
    int target = 15;
    solu.findcontinussequence(target);

    return 0;
}
*/

// offer581 反转单词顺序

/*
int main() {
    offer581 solu;

    string s = "the sky is blue";
    solu.resverseWord(s);

    return 0;
}
*/

/*
int main() {
    string s = "abcdefg";
    int n = 2;
    offer582 solu;
    solu.resverseLeftWords(s, n);

    return 0;
}
*/

// offer591 滑动窗口的最大值

/*
int main() {
    offer591 solu;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    solu.maxSlidingWindow(nums, k);

    return 0;
}
*/

// offer60 n个赛子的点数

/*
int main() {
    offer60 solu;
    int n = 2;
    solu.twosum(n);



    return 0;
}
*/
//// offer61 扑克牌中的顺子

/*
int main() {
    offer61 solu;
    vector<int> nums = {0, 6, 3, 2, 6};

    // vector<int> nums = {3, 4, 1,2, 5};
    solu.isstraight(nums);


    return 0;
}
*/

/*
int main() {
    offer64 solu;

    int n = 4;
    solu.sumnums(n);


    return 0;
}
*/

// 股票最大利润  offfer63;
/*
int main() {
    offer63 solu;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    solu.maxprofit(prices);

    return 0;
}
*/

// 
/*
int main() {
    int a = 2, b = 3;
    int c = 3;
    offer65 solu;
    solu.add(a, b);
    solu.subtrack(a, c);


    return 0;
}
*/
// 构建乘积数组 offer66

/*
int main() {
    vector<int> a = {1, 2, 3, 4, 5};

    offer66 solu;
    // solu.constractArr(a);
    solu.constractArr2(a);
    return 0;
}
*/

// //  将字符串转换成整数  offer67
/*
int main() {
    string str = "4200";
    offer67 solu;
    solu.str2int(str);

    return 0;
}

*/

// // 二叉树的最近公共祖先 offer681;

/*
int main() {
    int p = 7, q = 9;
    offer681 solu;
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
    // 迭代
    //solu.lowestcommonancester(root, p, q);
    // 递归
    solu.lowestcommonancester2(root, p, q);



    return 0;
}
*/

// 二叉树的最近公共祖先 offer682;


/*
int main() {
    int p = 7, q = 6;
    offer682 solu;
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
    // 迭代
    //solu.lowestcommonancester(root, p, q);
    // 递归
    Bitnode<char> *res = solu.lowestcommonancester(root, p, q);
    if (res) {
        cout << "the res_val: " << res->val << endl;
    }


    return 0;
}

*/

// leetcode844 比较含有退格的字符
/*
int main() {
//    string T = "ab#c";
//    string S = "ad#c";
   string T = "a##b";
   string S = "#c#b";
   leetcode844 solu;
   solu.backspaceCCompare(T,S);

    return 0;
}
*/
// // leetcode1 两个数之和

/*
int main() {

    vector<int> nums = {2, 7, 11, 15, -2, -6};
    int target = 9;
    leetcode1 solu;
    solu.twosum(nums, target);

    return 0;
}
*/

// leetcode2 两数相加

/*
int main() {

    LinkList list;
    list.creatLinkList_one(1);
    list.creatLinkList_one(2);
    list.creatLinkList_one(3);
    list.creatLinkList_one(4);
    list.TravelLinkList();
    
    LinkList list1;
    list1.creatLinkList_one(5);
    list1.creatLinkList_one(6);
    list1.creatLinkList_one(7);
    list1.creatLinkList_one(8);
    list1.TravelLinkList();
    
    leetcode2 solu;

    solu.addTwonumbers(list.head, list1.head);


    return 0;
}

*/
//  // // 无重复字符的最长子串
/*
int main() {
  
    string str = "pwwkew";
    leetcode3 solu;
    solu.lenoflongestsubstring(str);


    return 0;
}
*/

// // 最长回文子串  leetcode5

/*
int main() {
    string s = "babad";
    // string s = "cbba";
    leetcode5 solu;
    // solu.longestPalindrome(s);
    solu.longestPalindrome2(s);

    return 0;
}
*/

// 
// 整数反转 leetcode7
/*
int main() {
    // int x = 123;
    // int x = -123;
    int x = 120;
    leetcode7 solu;
    solu.reverse(x);

    return 0;
}
*/
// leetcode8 
/*
int main() {
 //  string s = "42";
 //   string s = "  -42";
    string s = "  -42 with the words";

   leetcode8 solu;
   solu.myatoi(s);

    return 0;
}
*/
/*
int main() {
    int x = -121;
    leetcode9 solu;
    bool ans = solu.ispalindrome(x);
    if (ans) {
        cout << "yes" << endl;
    } else {
        cout << "no " << endl;
    }
    return 0;
}
*/
/*

int main() {
    vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    leetcode11 solu;
    solu.maxarea(nums);

    return 0;
}
*/

/*
int main() {


    // int num = 3;
    // int num = 4;
    // int num = 9;
    int num = 58;
    leetcode12 solu;

    solu.int2roman(num);

    return 0;
}
*/

// // 罗马数字转数字  leetcode13

/*
int main() {
    leetcode13 solu;
    //string s = "III";
    // string s = "IV";
    // string s = "IX";
    // string s = "LVIII";
    string s = "MCMXCIV";


    solu.roman2int(s);

    return 0;
}
*/

// // leetcode14 最长公共子串

/*
int main() {
    leetcode14 solu;
    vector<string> strs = {"flower", "flow", "flight"};
    solu.longestcommonPrefix(strs);


    return 0;
}
*/

// 三数之和  leetcode15  二数之和 leetcode1
/*
int main() {

    leetcode15 solu;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    int target = 1;
    solu.threeSum(nums, target);

    return 0;
}
*/

// leetcode16 最接近的三数之和 
/*
int main() {
    leetcode16 solu;
    vector<int> nums = {-1,2,1,-4};
    int target = 1;
    solu.threeSumClosest(nums, target);

    return 0;
}
*/

// 电话号码的字母组合 leetcode17

/*
int main() {
    leetcode17 solu;
    string digits = "234";
    solu.letterCombinations(digits);

    return 0;
}
*/

//  leetcode18 四数之和
/*
int main() {
    leetcode18 solu;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    solu.fourSum(nums, target);

    return 0;
}
*/

/*
int main() {
    LinkList list;
    list.creatLinkList_one(1);
    list.creatLinkList_one(2);
    list.creatLinkList_one(3);
    list.creatLinkList_one(4);
    list.creatLinkList_one(5);
    list.TravelLinkList();
    int n = 3;
    leetcode19 solu;
    solu.deleteNthNode(list.head, n);

    list.TravelLinkList();


    return 0;
}
*/

/// // 有效括号  leetcode20

/*
int main() {
    leetcode20 solu;
    //string s = "()";
    //string s = "(){}[]";
    //string s = "(]";
    string s = "([])";
    solu.isValid(s);

    return 0;
}

*/
/*
int main() {
    leetcode21 solu;

    LinkList list;
    list.creatLinkList_one(1);
    list.creatLinkList_one(2);
    list.creatLinkList_one(3);
   
    list.TravelLinkList();
    
    LinkList list2;
    list2.creatLinkList_one(2);
    list2.creatLinkList_one(4);
    list2.creatLinkList_one(5);
   
    list2.TravelLinkList();
    cout << "pass in 1451" << endl;
    solu.merge2Node(list.head, list2.head);
    cout << "pass in 1453" << endl;

    list.TravelLinkList();
    list2.TravelLinkList();


    return 0;
}
*/
// 

/*
int main() {
    leetcode22 solu;
    int n = 3;
    solu.generaterParents(n);

    return 0;
}
*/

/*
int main() {
    leetcode24 solu;
    LinkList list;
    list.creatLinkList_one(1);
    list.creatLinkList_one(2);
    list.creatLinkList_one(3);
    //list.creatLinkList_one(4);
    list.TravelLinkList();
    solu.swapPairs(list.head);

    return 0;
}
*/

/*
int main() {
    leetcode26 solu;
    vector<int> nums = {1, 1, 2, 3, 3, 3, 4};
    solu.removeDuplicates(nums);

    return 0;
}
*/

int main() {

    leetcode27 solu;
    //vector<int> nums = {3, 2, 2, 3};

    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    int val = 2;

    solu.removeelement(nums, val);

    return 0;
}