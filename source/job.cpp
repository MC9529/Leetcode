#include "solution.h"
#include "job.h"
#include <vector>
#include <stack>
#include <algorithm>
#include <numeric>
#include <stdio.h>
#include <functional>
#include <queue>
#include <unordered_map>
#include <map>
#include <set>
#include <unordered_set>
#include <cstring>
#include <stdlib.h>
#include <limits.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};



// offer 03 数组中重复的数字
void offer03::findRepeatNum(vector<int> &nums) {
    unordered_map<int, int> map;
    for (auto num: nums) {
        map[num] ++;
    }
    vector<pair<int, int>> map_vector(map.begin(), map.end());
    cout << "the repeat num: " << endl;
    for (auto iter: map_vector) {
        if (iter.second > 1) {
            cout << iter.first << endl;
        }
    }
    return;

}

// offer 53_1 统计一个数字在数组中出现的次数
void offer53_1::search(vector<int> &nums, int target) {
    unordered_map<int, int> map;
    for (auto num: nums) {
        map[num] ++;
    }
    auto iter = map.find(target);
    if (iter != map.end()) {
        cout << "the res: " << iter->second << endl;
    } else {
        cout << "the res: " << 0 << endl;
    }
    
    return;
}

// offer 53_1 统计一个数字在数组中出现的次数
void offer53_1::search2(vector<int> &nums, int target) {
    // 先排序
    sort(nums.begin(), nums.end());
    int res =  upper_bound(nums.begin(), nums.end(), target) - 
               lower_bound(nums.begin(), nums.end(), target);
    cout << "the res: " << res << endl;
    return;

}

// offer05 替换空格 ， 需要额外的空间
void offer05::replaceSpace(string s) {
    string res;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            res.push_back('%');
            res.push_back('2');
            res.push_back('0');
        } else {
            res.push_back(s[i]);
        }
    }
    cout << "the res: " << res << endl;

}

// // offer05 替换空格， 不需要额外的空间
void offer05::replaceSpace2(string s) {
    int count = 0;
    int solidsize = s.size();
    cout << "the solid size " << solidsize << endl;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ' ') {
            count ++;
        }
    }
    s.resize(s.size() + count * 2);
    int newsize = s.size();
    cout << "the new size: " << newsize << endl;
    for (int i = 0; i < s.size(); ++i) {
         if (s[i] == ' ') { 
            cout << '#';
         } else {
            cout << s[i];
         }
    }
    cout << endl;
    for (int i = newsize - 1, j = solidsize - 1; j < i; --i, --j) {
       if (s[j] != ' ') {
           s[i] = s[j];
       } else {
           s[i] = '0';
           s[i - 1] = '2';
           s[i - 2] = '%';
           i = i - 2;

       }

    }
    cout << s << endl;
    return;

}

// offer06 从尾到头打印链表


void offer06::reverseprint(Node *head) {
    stack<int> stack_list;
    Node *ptemp = head;
    while(ptemp->next != NULL) {
        int temp_val = ptemp->next->val;
        stack_list.emplace(temp_val);
        // Node *ptemp2 = ptemp;
        ptemp = ptemp->next;
    }
    cout << "the res: " << endl;
    while(!stack_list.empty()) {
        cout << stack_list.top() << " ";
        stack_list.pop();
    }
    cout << endl;
    return;

}

// // offer 24 反转链表
void offer24::reverselist(Node *head) {
    stack<int> stack_list;
    Node *ptemp = head;
    while(ptemp->next != NULL) {
        int temp_val = ptemp->next->val;
        stack_list.emplace(temp_val);
        // Node *ptemp2 = ptemp;
        ptemp = ptemp->next;
    }

    while (head->next != NULL) {
        head->next->val = stack_list.top();
        stack_list.pop();
        head = head->next;
    }

    
    cout << endl;

    return;
}

Bitnode<int>* offer07::buildTree(vector<int> &preorder, vector<int> &inorder) {
    for (int i = 0; i < inorder.size(); ++i) {
        map[inorder[i]] = i;
    }
    
    return dfs(preorder, inorder, 0, 0, inorder.size() - 1);


}

// 中序的 start  end  前序的 root
Bitnode<int>* offer07::dfs(vector<int> &preorder, vector<int> &inorder, int root, int start, int end) {
    if (start > end) return NULL;
    Bitnode<int> * head = new Bitnode<int>( preorder[root] );
    // 找到 root 在前序的位置
    /*
    int i = start;
    while (i < end && preorder[root] != inorder[i]) {
        i ++;
    }
    */
    int i = map[preorder[root]];

    head->left = dfs(preorder, inorder, root + 1, start, i - 1);
    head->right = dfs(preorder, inorder, root + 1 + i - start, i + 1, end);

    return head;


}

void offer07::levelorder(Bitnode<int>* root) {
    if (!root) return;
    int n = howlen(root);
    res.resize(n);
    DFS(root, 0);
    return;

}
void offer07::DFS(Bitnode<int>* root, int n) {
    res[n].push_back(root->val);
    if (root->left) DFS(root->left, n + 1);
    if (root->right) DFS(root->right, n + 1); 

}

int offer07::howlen(Bitnode<int>* root) {
    if (root == NULL) return 0;
    return max(howlen(root->left), howlen(root->right)) + 1;

}

// 用队列实现栈

void queue2stack::push(int x) {
    queue1.push(x);
    top_element = x;
    count ++;
    return;


}
int queue2stack::pop() {

    int len = queue1.size();
    if (queue1.empty()) {
        cout << "the stack is empty" << endl;
        return -404;
    }
    while(len > 1) {
        int temp = queue1.front();
        if (len == 2) {
            top_element = temp;
        }
        queue1.pop();
        queue1.push(temp);
        len --;
    }
    int pop_element = queue1.front();
    queue1.pop();
    return pop_element;

}
int queue2stack::top() {
    if (queue1.empty()) {
        cout << "there is no top element" << endl;
        return -404;
    }
    return top_element;

}
bool queue2stack::empty() {
    if (queue1.empty()) {
        return true;
    }
    return false;

}

// stack_2_queue

void  stack2queue::push(int x) {
    s1.push(x);
    return;

}

int stack2queue::pop() {
    if (empty()) {
        cout << "the queueu is empty" << endl;
        return -404;
    }
    int res = front();
    s2.pop();
    return res;

}
int stack2queue::front() {
    if (empty()) {
        cout << "the queueu is empty" << endl;
        return 404;
    }
    if (s2.empty()) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
    }
    return s2.top();


}

bool stack2queue::empty() {
    if (s1.empty() && s2.empty()) {
        return true;
    }
    return false;

}