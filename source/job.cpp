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

// offer14_1 割绳子
 int offer14_1::cuttingRope(int n) {
     vector<vector<int>> path(n + 1, vector<int>());
     vector<int> temp;
     path.push_back(temp);
     path.push_back(temp);
     temp = {1, 1};
     path.push_back(temp);
     vector<int> dp(n + 1, 0);
     dp[0] = 0, dp[1] = 0, dp[2] = 1;
     for (int i = 3; i <= n; ++i) {
         vector<int> temp_path;
         int max_res = 0;

         for (int j = 1; j < i; ++j) {
             // j * (i - j) 不继续分
             // j * dp[i-j] 继续分
             
             if ( j * (i - j) >= j * dp[i - j]) {
                 max_res = j * (i - j);
                 temp_path = {j, (i - j)};

             } else {
                 max_res = j * dp[i - j];
                 temp_path = path[i - j];
                 temp_path.push_back(j);
             }

             if (dp[i] > max_res) {
                max_res = dp[i];
                temp_path = path[i];

             } 
             dp[i] = max_res;
             path[i] = temp_path;
             // dp[i] = max(dp[i], max( (j * (i - j)), j * dp[i-j]) );
         }
          
         // dp[i] = max_res;
         // path[i] = temp_path;
     }
     cout << "the sement of rope: " << endl; 
     for (int i = 0; i < path[n].size(); ++i) {
         cout << path[n][i] << " ";
     }
     cout << endl;
     cout << "the bigesst res: " << dp[n] << endl;
     return dp[n];

 }

 // 二进制中1的个数
 int offer15::hammingWeight(int n) {
     int res = 0;
     while (n > 0) {
         int temp = n % 2;
         if (temp == 1) {
             res ++;
         }
         n = n /2;
     }
     cout << "the res: " << res << endl;
     return res;

 }

 // 数值的整数次方
 double offer16::mypow(double x, int n) {
     int n_ = n;
     double x_ = x;
     if (n < 0) {
         n_ = abs(n);
         x_ = 1.0 / x;
     }
     vector<double> dp(n_ + 1, 0.0);
     dp[0] = 0.0;
     dp[1] = x_;
     for (int i = 2; i <= n_; ++i) {
         cout << "dp[i-1]: " << dp[i-1] << endl; 
         dp[i] = dp[i-1] * x_;
     }
     cout << "the res: " << dp[n_] << endl;
     return dp[n_];
 }

 // offer18 删除链表的节点
 Node* offer18::deleteNode(Node *head, int val) {
     Node *temp_head = head;
     while (temp_head->next != NULL) {

          Node *target_node = temp_head->next;

         int temp_val = target_node->val;
         if (temp_val == val) {
            temp_head->next = target_node->next;
            free(target_node);
            // return head;

         } else {
             temp_head = temp_head->next;
         }

     }
     return head;

 }

// offer21 调整数组顺序使得奇数位于偶数前面
 vector<int> offer21::exchange(vector<int> &nums) {
     for (int i = 0; i < nums.size(); ++i) {
         if (nums[i] % 2 == 1) {
            int temp_val = nums[i];

            for (int j = i; j >= 1; --j) {
                nums[j] = nums[j -1];
            }

            nums[0] = temp_val;
         }
     }

    for (int i = 0; i < nums.size(); ++i) {

        cout << nums[i] << " ";
    }
    cout << endl;
    return nums;

 }
 // offer24 反转链表

 Node *offer241::reverseList(Node *head) {
     stack<Node*> node_stack;
     Node *temp_head = head;
     while(temp_head->next != NULL) {
         node_stack.emplace(temp_head->next);
         temp_head = temp_head->next;
     }

     Node *new_head;
     Node *tail = new_head;
     while(node_stack.empty()) {
         tail->next = node_stack.top();
         tail = tail->next;
         node_stack.pop();
     }

     return new_head;

 }

// 树的子结构
bool offer26::isSubstructure(Bitnode<char> *A, Bitnode<char> *B) {
    bool res = false;
    string str_A, str_B;
    preOrder(A, str_A);
    preOrder(B, str_B);
    
    if (judge(str_B, str_A) || judge(str_A, str_B)) {
        res = true;
    }
    if (res) {
        cout << "yes" <<endl;
    } else {
        cout << "no" <<endl;
    }

    return res;

}


void offer26::preOrder(Bitnode<char> *A, string &str_A) {
    if (A->left != NULL) {
        preOrder(A->left, str_A);
    }
    str_A.push_back(A->val);
    if (A->right != NULL) {
       preOrder(A->right, str_A);
    }
    return;
}
bool offer26::judge(const string &a,const string &b) {
    int i,j;
    bool res = false;
    if(a.length()<b.length()) {
        res = false;
        cout << "not the substr" << endl;
        return res;
    }
    for(i=0;i<a.length();i++){
        for(j=0;j<b.length();j++){
            if(a[i+j]!=b[j])
                break;   // 字符不相等，退出
        }
        if(j==b.length()) { // 达到了b.length,说明字符全部相等
            cout << "yes, is the substr" <<endl;
            res = true;
            return res;
        }
    }
    cout << "not the substr" << endl;
    return false;

}

// offer27 二叉树的镜像
Bitnode<char> *offer27::mirrorTree(Bitnode<char> *root) {
    if (root == NULL || 
       (root->left == NULL && root->right !=NULL) || 
       (root->right == NULL && root->left !=NULL) ) {
        cout << "the tree is the mirror tree " << endl;
        return NULL;

    } 
    mirror(root);
    mirrorTree(root->left);
    mirrorTree(root->right);
    

   
    return root;

}

void offer27::mirror(Bitnode<char> *root) {
    if (!root || (!root->left && !root->right ) ) {
        return;
    }
    Bitnode<char> * tmp = root->left;
    root->left = root->right;
    root->right = tmp;
    
}

//
// 对称的二叉数  offer28
bool offer28::issymmetric(Bitnode<char> *root) {
    if (!root) return true;
    return judge(root->left, root->right);

}
bool offer28::judge(Bitnode<char> *left, Bitnode<char> *right) {
    if (!left && !right) return true;
    if ((!left && right) && (left && !right)) return false;
    if (left->val != right->val) {
        return false;
    }
    return judge(left->left, right->right) &&
           judge(left->right, right->left);

}
// offer29 顺时针的打印矩阵
vector<int> offer29::spiralOrder(vector<vector<int>> &matrix) {

    // vector<vector<int>> direction =
    //     {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    vector<vector<bool>> visited( matrix.size(),
                         vector<bool>(matrix[0].size(), false));
    cout << "pass in 759" << endl;
    travel(visited, matrix, 0, 0, 0);
     cout << "pass in 761" << endl;
    for (auto iter: res) {
        cout << iter << " ";
    }
    cout << endl;
    cout << "pass in 766" << endl;
    return res;

}

void offer29::travel(vector<vector<bool>> &visited,
vector<vector<int>> &matrix, int row, int col, int direct) {
    if (res.size() == matrix.size() * matrix[0].size()) {
        return;

    }
    res.push_back(matrix[row][col]);
    visited[row][col] = true;
    cout << "pass in 775" << endl;
    int new_direct = direct;
    int new_row = row + direction[new_direct][0];
    int new_col = col + direction[new_direct][1];

    if (new_row < 0 || new_row >= matrix.size() || new_col < 0 ||
        new_col >= matrix[0].size() || visited[new_row][new_col] ) {

        new_direct = direct + 1;
        if (direct == 3) {
            new_direct = 0;
        }
    }

    cout << "pass in 789" << endl;
    new_row = row + direction[new_direct][0];
    new_col = col + direction[new_direct][1];
    travel(visited, matrix, new_row, new_col, new_direct);
     cout << "pass in 793" << endl;
}

// // 从上到下打印二叉树 offer32_1
vector<char> offer321::levelorder(Bitnode<char> *root) {
    vector<char> res;

    queue<Bitnode<char> *> container;
    container.push(root);
    while( !container.empty() ) {

        Bitnode<char> *temp = container.front();
        res.push_back(temp->val);
        if (temp->left) {
            container.push(temp->left);
        }
        if (temp->right) {
            container.push(temp->right);
        }
        container.pop();

    }
    cout << "the res: " << endl;
    for (auto iter: res) {
        cout << iter << " ";
    }
    cout << endl;
    return res;
}

//// 从上到下打印二叉树 offer32_2
vector<vector<char>> offer322::levelorder(Bitnode<char> *root) {
    vector<vector<char>> res;

    queue<Bitnode<char> *> container;
    container.push(root);
    int len_container = container.size();
    vector<char> temp_res;
    while( !container.empty() ) {
        // vector<char> temp_res;
        Bitnode<char> *temp = container.front();
        temp_res.push_back(temp->val);
        if (temp->left) {
            container.push(temp->left);
        }
        if (temp->right) {
            container.push(temp->right);
        }
        // if (len_container == 0) {
        //     res.push_back(temp_res);
        //     len_container = container.size();
        //     temp_res.clear();
        // }
        container.pop();
        len_container --;
        if (len_container == 0) {
            res.push_back(temp_res);
            len_container = container.size();
            temp_res.clear();
        }
    }

    cout << "the res: " << endl;
    for (int i = 0; i < res.size(); ++i) {
        vector<char> iter_res = res[i];
        for (auto iter: iter_res) {
            cout <<  iter << " ";
        }
        cout << endl;
    }
    cout << endl;

    return res;
}


// // 从上到下打印二叉树 offer32_3
vector<vector<char>> offer323::levelorder(Bitnode<char> *root) {

    vector<vector<char>> res;
    int reverse = -1;
    queue<Bitnode<char> *> container;
    container.push(root);
    int len_container = container.size();
    vector<char> temp_res;
    while( !container.empty() ) {
        // vector<char> temp_res;
        Bitnode<char> *temp = container.front();
        temp_res.push_back(temp->val);
        if (temp->left) {
            container.push(temp->left);
        }
        if (temp->right) {
            container.push(temp->right);
        }
        // if (len_container == 0) {
        //     res.push_back(temp_res);
        //     len_container = container.size();
        //     temp_res.clear();
        // }
        container.pop();
        len_container --;
        if (len_container == 0) {
            if (reverse == 1) {
                std::reverse(temp_res.begin(), temp_res.end());
                res.push_back(temp_res);
            } else {
                 res.push_back(temp_res);
            }
            // res.push_back(temp_res);
            len_container = container.size();
            temp_res.clear();
            reverse = -1 * reverse;
        }
    }

    cout << "the res: " << endl;
    for (int i = 0; i < res.size(); ++i) {
        vector<char> iter_res = res[i];
        for (auto iter: iter_res) {
            cout <<  iter << " ";
        }
        cout << endl;
    }
    cout << endl;

    return res;
   
}


vector<vector<int>> offer34::pathSum(Bitnode<char>* root, 
                                     int sum) {
    if (!root) return {};
    vector<vector<int>> res_last;
    vector<int> temp_res;
    dfs(root, sum, temp_res);
     cout << "pass in 933" << endl;
    cout << "the res: " << endl;

    for (int i = 0; i < res.size(); ++i) {
        vector<int> iter_res = res[i];
        for (int j = 0; j < iter_res.size(); ++j) {
            cout << iter_res[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    cout << "pass in 945" << endl;

    return res_last;

}

void offer34::dfs(Bitnode<char>* root, int sum, vector<int> &temp_res) {
    if (!root) return;
    cout << "pass in 953" << endl;
    int val = (root->val) - 48;
    cout << "the char and int: " 
         << root->val << " " << val <<endl;
    temp_res.push_back(val);
    int new_sum = sum - val;
    for (int i = 0; i < temp_res.size(); ++i) {
        cout << temp_res[i] << " ";
    }
    cout << endl;
    if (new_sum == 0) {
        res.push_back(temp_res);
    }
    cout << "pass in 962" << endl;
    dfs(root->left, new_sum, temp_res);  // 左分支
    dfs(root->right, new_sum, temp_res);  // 右分支
    temp_res.pop_back();
    dfs(root->left, sum, temp_res);  // 左分支
    dfs(root->right, sum, temp_res);  // 右分支
    // temp_res.pop_back();
}

// Search for a Range
vector<int> searchRange_solution::searchRange(vector<int>& nums, int target) {
    const int l = distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
    const int u = distance(nums.begin(), prev(upper_bound(nums.begin(), nums.end(), target)));

    if (nums[l] != target) {
        return vector<int> { -1, -1 };
    } else {
        return vector<int> { l, u };
    }
}


string offer37::serialize(Bitnode<char>* root) {
    string res;
    // vector<char> res;
    queue<Bitnode<char> *> container;
    container.push(root);
    bool flag = true;
    
    while( !container.empty() ) {

        Bitnode<char> *temp = container.front();
        container.pop();
        if (temp) {
            res.push_back(temp->val);
            container.push(temp->left);
            container.push(temp->right);
            if (temp->left) {
                flag = true;
            }
            if (temp->right) {
                flag = true;
            }
        } else {
            res.push_back('#');
        }

    }
    cout << "the res: " << endl;
    for (auto iter: res) {
        cout << iter << " ";
    }
    cout << endl;

    return res;
}
Bitnode<char>* offer37::deserialize(string data) {
    int num = 0;
    Bitnode<char> *root = creatNode(data, num);
    return root;
}

Bitnode<char>* offer37::creatNode(string data, int &n) {
    char ch = data[n];
    n ++;
    if (ch == 'null') {
        return NULL;
    } else {
        Bitnode<char> *node = new Bitnode<char>(ch);
        node->left = creatNode(data, n);
        node->right = creatNode(data, n);
        return node;

    }

}

// offer38

vector<string> offer38::permutable(string s) {
    if (s.empty()) {
        return {};
    }
    sort(s.begin(), s.end());
    vector<bool> visited(s.size(), false);
    string track;
    dfs(s, track, visited);
    for (int i = 0 ; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
    cout << endl;
    return res;
}

void offer38::dfs(string s, string &track, vector<bool> &visited) {
    if (track.size() == s.size()) {
        res.push_back(track);
    }
    for (int i = 0; i < s.size(); ++i) {
        if (visited[i]) {
            continue;
        }
        if (i > 0 && !visited[i - 1] && s[i - 1] == s[i]) {
            continue;
        }
        visited[i] = true;
        track.push_back(s[i]);
        dfs(s, track, visited);
        track.pop_back();
        visited[i] = false;
    }

}

// offer39  次数超过一半的数字
int offer39::majorityElement(vector<int> &nums) {
    unordered_map<int, int> map;
    for (auto iter: nums) {
        map[iter] ++;
        if (map[iter] > nums.size() / 2) {
            cout << "the ans: " << iter << endl;
            return iter;
        }
    }
    cout << "find the majorityElement failed" << endl;
    return 0;

}

// offer40 最小的k个数字

vector<int> offer40::getKthNumber(vector<int> &nums, int k) {
    vector<int> res;
    if (nums.size() == 0 || k > nums.size()) {
        cout << "the len of nums is zero or k is bigger than the len of nums" << endl;
        return {};
    }
    priority_queue<int, vector<int>, less<int>> store;
    for (int i = 0; i < nums.size(); ++i) {
        store.push(nums[i]);
        if (store.size() > k) {
            store.pop();
        }
    }
    while( !store.empty() ) {
        res.push_back(store.top());
        store.pop();

    }
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return res;
}
