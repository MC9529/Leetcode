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

// offer_10 费伯纳起数列
long long offer10::fib(int n) {

    dp.resize(n + 1);
    if (n < 1) {
        cout << "the n is error " << endl;
        return 404;
    }
    int ans = 0;
    for (int i = 2; i < n + 1; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    ans = dp[n];
    // ans = ans % 1000000007;
    cout << "n: " << n  << " "<< "the ans : "<< ans << endl;
    return ans;


}

// offer10_2 青蛙跳台
int offer10_2::numWays(int n) {
    if (n < 0) {
        cout << "the n is less 0" << endl;
        return 404;
    }
    int ans = 0;
    vector<int> dp = {1, 1, 2};
    dp.resize(n + 1);
    for (int i = 3; i <= n; ++i) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    
    if (n == 0) {
        ans = 1;
    } else {
        ans = dp[n];
    }
    cout << "n: " << n << " "<< "the ans : "<< ans << endl;
    return ans;

}

// 旋转数组的最小值  二分法
// 递增的数组，则
int  offer11::minArray(vector<int> &nums) {
    int low = 0;
    int high = nums.size() - 1;
    while(low < high) {
        int mid = low + (high - low) / 2;
        // 只要右边比中间大，则右边一定是有序数组
        // 中间值小于右边值，则最小值在左边
        if (nums[mid] < nums[high]) {
            high = mid;
        } else if (nums[mid] > nums[high]) {
            low = mid + 1;
        } else {
            high = high - 1;
        }
    }
    cout << "the res: " << nums[low] << endl;

    return nums[low];

}
// offer12 矩阵中的路径

 bool offer12::exit(vector<vector<char>> &board,
                     string word) {
    vector<pair<int, int> > temp_path;
    bool ans = false;
    word_ = word;
    board_ = board;
    int cur_posi = 0;
    for (int i = 0; i < board.size(); ++i) {
        for (int j = 0; j < board[0].size(); ++j) {
            cout << "i and j" << i << " " << j << endl;
            dfs(i, j, cur_posi, ans, temp_path);

        }
    }
    for (int i = 0; i < path.size(); ++i) {
        vector<pair<int, int> > iter_path = path[i];
        for (int j = 0; j < iter_path.size(); ++j) {
            cout << iter_path[j].first << " " << iter_path[j].second << "->";
        }
        cout << endl;
        
    }
    cout << endl;
    return ans;

 }

 void offer12::dfs(int row, int col, int &cur_posi, bool &ans,
                   vector<pair<int, int> > &temp_path) {

     if (cur_posi == word_.size()) {
         path.emplace_back(temp_path);
         ans = true;
         return;
     }
     if (board_[row][col] == word_[cur_posi]) {
        temp_path.push_back({row, col});
         for (int k = 0; k < direction.size(); ++k) {
             int temp_row = row + direction[k][0];
             int temp_col = col + direction[k][1];
             if ( (temp_row >= 0 && temp_row < board_.size()) &&
                  (temp_col >= 0 && temp_col < board_[0].size()) ) {
                      int temp_posi = cur_posi + 1;
                      dfs(temp_row, temp_col, temp_posi, ans, temp_path);

                }
         }

     } else {
         return;
     }

 }

 // offer13 机器人的运动范围
 int offer13::movingCount(int m, int n, int k) {
    int temp = 0;
    vector<vector<bool>> visiter(m, vector<bool>(n, false));
    int cur_row = 0, cur_col = 0;
    dfs(cur_row, cur_col, m, n, k, temp, visiter);
    cout << "the res: " << longest << endl;
    return longest;
    

 }

 void offer13::dfs(int &row, int &col, int m, int n,
        int k, int &temp, vector<vector<bool>> &visiter) {
    if (!enter(row, col, k)) {

        if (longest < temp) {
            longest = temp;
        }
        cout << "can not enter" << endl;
        return;
    } else {
        visiter[row][col] = true;

        for (int k = 0; k < direction.size(); ++k) {
             int temp_row = row + direction[k][0];
             int temp_col = col + direction[k][1];
             if ( (temp_row >= 0 && temp_row < m &&
                   temp_col >= 0 && temp_col < n) && 
                   !visiter[temp_row][temp_col]) {

                      int new_temp = temp + 1;
                      cout << "the temp: " << new_temp << endl;
                      dfs(temp_row, temp_col, m, n, k, new_temp, visiter);

                }
         }
        
    }

 }

 bool offer13::enter(int row, int col, int k) {
     bool ans = false;
     int sum_row = sum(row);
     int sum_col = sum(col);
     cout << "the sum of row: " << sum_row
          << " " << "col: " << sum_col << endl;
     if (sum_col + sum_row > k) {
         ans = false;
     } else {
         ans = true;
     }

     return ans;
 }

 int offer13::sum(int num) {
     int ans = 0;
     while(num > 0) {
         int temp = num % 10;
         ans = ans + temp;
         num = num / 10;
     }
     return ans;

 }