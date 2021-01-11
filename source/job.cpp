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


// // offer42 连续子数组的最大和
int offer42::maxSubArray(vector<int> &nums) {
    // dp[i] 前i个数组的最大和
    vector<int> dp(nums.size(), 0);
    // base case
    dp[0] = nums[0];
    for (int i = 1; i < nums.size(); ++i) {
        dp[i] = max(dp[i-1] + nums[i], nums[i]);
    }


    int res = 0;
    for (int i = 0; i < dp.size(); ++i) {
        cout << dp[i] << " ";
        if (dp[i] > res) {
            res = dp[i];
        }
    }
    cout << endl;
    return res;

}

// offer43 1～n整数中1出现的次数

int offer43::countDigitone(int n) {
    // dp[i], 数字i 出现1的次数
    vector<int> dp(n + 1, 0);
    // base case
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        int previous = 0;
        if (dp[i - 1] - dp[i - 2] == 1) {
            previous = 1;
        }
        dp[i] = dp[i - 1] + calcu(i, previous);

    }
    for (int i = 0; i < dp.size(); ++i) {
        cout << "i: " << i << " " << "count_one: " << dp[i] << endl;
    }
    cout << "the res: " << dp[n] << endl;
    return dp[n];

}

// offer43 1～n整数中1出现的次数
int offer43::calcu(int n, int previous_one) {
    int res = 0;
    int temp = n;
    while (temp > 0) {
        if (temp % 10 == 1) {
            res = 1;
            break;
        }
        temp = temp / 10;
    }

    return res;

}
// // offer44 数字序列中的某一位的数字

int offer44::findNthDigit(int n) {



}

// 把数组排列成最小的数 offer45
 string offer45::minNumber(vector<int> &nums) {
     auto compare = [](string sa, string sb) {
         return sa + sb < sb + sa;
     };

     vector<string> temp;
     for(int i = 0; i < nums.size(); ++i) {
         temp.push_back(to_string(nums[i]));

     }
     sort(temp.begin(), temp.end(), compare);
     string ans = "";
     for(string s: temp) {
         ans = ans + s;
     }
     cout << "the ans: " << ans << endl;
     return ans;

 }

 // offer47 礼物的最大值

 int offer47::maxValue(vector<vector<int>> &grid) {
     // dp[i][j] 位置 i和j的礼物的最大值
     vector<vector<int>> dp( grid.size(),
                           vector<int> (grid[0].size(), 0) );
     // path
     vector<int> path;

     // base case
     dp[0][0] = grid[0][0];
     dp[0][1] = grid[0][0] + grid[0][1];
     dp[1][0] = grid[0][0] + grid[1][0];
     for (int i = 1; i < grid.size(); ++i) {
         for (int j = 1; j < grid[0].size(); ++j) {
             dp[i][j] = max(dp[i - 1][j] + grid[i][j], 
                            dp[i][j - 1] + grid[i][j] );
         }
     }
     cout << "the max: " << 
          dp[ grid.size()-1 ][ grid[0].size()-1 ] << endl;

     return dp[ grid.size()-1 ][ grid[0].size()-1 ];
 }

 // offer48 最长不含重复字符的子字符串

 int offer48::lengthOflongestSubstring(string s) {
     // dp[i], 前i个子字符 ，最长不含重复字符的子字符串
    int len = s.size();
    if (len == 0) return 0;
    int res = 1;
    int i = 0, j = 0;
    map<char, int> mp;
    for (; j< len; ++j) {
        mp[s[j]] ++;
        if (mp[s[j]] == 1) {
            res = max(j - i + 1, res);
            continue;
        } 
        if (j == len - 1) break;
        while(mp[s[j]] > 1) {
            mp[s[i]] --;
            ++i;
        }
    }
    
    cout << "the res: " << res << endl;
    return res;
 }

 /// 丑数 offer49

 int offer49::nthUglyNumber(int n) {
     vector<int> dp(n, 0);
     dp[0] = 1;
     int p2 = 0, p3 = 0, p5 = 0;
     for (int i = 1; i < n; ++i) {
         dp[i] = min(min(dp[p2] * 2, dp[p3] * 3), dp[p5]*5 );
         if (dp[i] == dp[p2] * 2) {
             p2++;
         }
         if (dp[i] == dp[p3] * 3) {
             p3++;
         }
         if (dp[i] == dp[p5] * 5) {
             p5++;
         }
     }
     
     for (int i = 0; i < dp.size(); ++i) {
         cout << dp[i] << endl;
     }
     cout << endl;

     return dp[n-1];

 }
 // 
  // // 第一个只出现一次的字符
char offer50::firstUniqChar(string s) {
    char res = '1';

    unordered_map<char, int> map;
    for (int i = 0; i < s.size(); ++i) {
        map[s[i]]++;
    }
    for (int i = 0; i < s.size(); ++i) {
        cout << "i and s[i]: " << i <<" " << s[i] << endl;
         if (map[s[i]] <= 1) {
             res = s[i];
             map[s[i]] = 1;
             break;
         } 
    }
    cout << "the res: " << res << endl;

    return res;

}

//
// 数组中的逆序对 offer51
int offer51::reversePairs(vector<int> &nums) {
    int ans = 0;
    // vector<int> temp_res;
    for ( int i = 0; i < nums.size(); ++i ) {
        vector<int> temp_res;
        temp_res.push_back(nums[i]);
        dfs(i, nums, temp_res);
    }

    for (int i = 0; i < res.size(); ++i) {
        vector<int> iter_res = res[i];
        for (auto iter: iter_res) {
            cout << iter << " ";
        }
        cout << endl;
    }

    ans = res.size();
    return ans;
}

void offer51::dfs(int i, vector<int> &nums, vector<int> &temp) {
    if (temp.size() == 2) {
        if (temp[0] > temp[1]) {
            res.push_back(temp);
        }
    }
    for (int j = i + 1; j < nums.size(); ++j) {
        temp.push_back(nums[j]);
        int new_i = j + 1;
        dfs(new_i, nums, temp);
        temp.pop_back();

    }

}

// offer53_1  在排序数组中查找数字

int offer532::search(vector<int> &nums, int target) {
    int res = -1;
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
        map[nums[i]] ++;
    }

    res = map[target];
    cout << "the res: " << res << endl;
    return res;
}

// // offer533 在 0 - n-1中缺失的数字

int offer533::missingnum(vector<int> &nums) {
    int res = -1;
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i] - nums[i-1] != 1) {
            res = nums[i-1] + 1;
            break;
        }
    }
    cout << "the res: " << res << endl;
    return res;

}

// 55 二叉树的的深度
int offer55::maxdepth(Bitnode<char>* root) {

    vector< vector<Bitnode<char>*> > res;
    int depth = 0;
    queue<Bitnode<char>*> container;
    container.push(root);
    int len = container.size();
    while(!container.empty()) {
        Bitnode<char> *temp = container.front();
        if (temp->left) {
            container.push(temp->left);
        }
        if (temp->right) {
            container.push(temp->right);
        }
        container.pop();
        len --;
        if (len == 0) {
            depth ++;
            len = container.size();
        }
    }

    cout << "the depth: " << depth << endl;
    return depth;
}

// offer55_2 平衡二叉树

bool offer552::isblanced(Bitnode<char>* root) {
    bool res = true;
    if (root == NULL) {
        res = true;
    }
    if ( abs( getheight(root->left) - getheight(root->right) ) > 1) {
        res = false;
    }

    if (isblanced(root->left) && isblanced(root->right)) {
        res = true;
    }

    return res;

}


int offer552::getheight(Bitnode<char>* root) {
    if (root == NULL) return 0;
    int left = getheight(root->left);
    int right = getheight(root->right);
    return left > right ? left + 1 : right + 1;

}

// offer561 数组中数字出现的次数

vector<int> offer561::singlenumber(vector<int> &nums) {
    vector<int> res;
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
        map[nums[i]] ++;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (map[nums[i]] == 1) {
            res.push_back(nums[i]);
        }
    }
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
    cout << endl;

    return res;

}

// offer57 和为s的两个数字
 vector<int> offer57::twosum(vector<int> &nums, int target) {
    vector<vector<int>> res;
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); ++i) {
        map[nums[i]] ++;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (map[target - nums[i]] >= 1) {
            vector<int> temp;
            temp.push_back(target - nums[i]);
            temp.push_back(nums[i]);
            res.push_back(temp);
        }
    }



   for (int i = 0; i < res.size(); ++i) {
       vector<int> temp_res = res[i];
       for (int i = 0; i < temp_res.size(); ++i) {
           cout << temp_res[i] << " ";
       }
       cout << endl;
   }
    cout << endl;

    return res[0];

 }

 // 双指针
 vector<int> offer57::twosum2(vector<int> &nums, int target) {
     vector<vector<int>> res;
     // sort(nums.begin(), nums.end());
     int l = 0, r = nums.size() - 1;
     while(l <= r) {

         if (nums[l] + nums[r] < target) {
             l ++;
         } else if (nums[l] + nums[r] > target) {
             r --;
         } else if (nums[l] + nums[r] == target) {
             vector<int> temp;
             temp.push_back(nums[l]);
             temp.push_back(nums[r]);
             res.push_back(temp);
             l ++;
             r --;

         }
         
     }

     cout << "the res: " << endl;
     for (int i = 0; i < res.size(); ++i) {
         vector<int> temp_res = res[i];

         for (int j = 0; j < temp_res.size(); ++j) {
             cout << temp_res[j] << " ";
         }
         cout << endl;
     }
     cout << "in 1518" << endl;
     cout << endl;

     return {};

 }


// 和为s的连续正数序列 offer572

vector<vector<int>> offer572::findcontinussequence(int target) {
    vector<vector<int>> res;
    vector<int> res_temp;
    int l = 1, r = 2;

    while (r < target) {

        int sum = (l + r) * (r - l + 1) / 2;
        if (sum == target) {
            res_temp.clear();
            for (int i = l; i <= r; ++i) {
                res_temp.emplace_back(i);
            }
            res.emplace_back(res_temp);
            l ++;
        } else if (sum < target) {
            r ++;
        } else {
            l ++;
        }

    }
    for (int i = 0; i < res.size(); ++i) {
        vector<int> iter_res = res[i];
        for (int j = 0; j < iter_res.size(); ++j) {
            cout << iter_res[j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    return res;

}

// offer581 反转单词顺序

string offer581::resverseWord(string s) {
    string res;
    string res_temp;
    vector<string> res_vec;
    for (int i = 0; i < s.size() + 1; ++i) {
        // cout << "the res_temp: " << res_temp << endl;
        if (s[i] == ' ' || i == s.size()) {
            // res_temp.push_back(s[i]);
            res_vec.push_back(res_temp);
            res_temp.clear();
        } else {
            if (i < s.size()) {
                res_temp.push_back(s[i]);
                // res_vec.push_back(res_temp);
            }
        }
        cout << "the res_temp: " << res_temp << endl;

    }
    cout << "the size of res_vec: " << res_vec.size() << endl;
    for (int i = 0; i < res_vec.size(); ++i) {
        cout << res_vec[i] << " ";
        res = res + res_vec[res_vec.size() - 1 - i];
        if (i < res.size() - 1) {
            res = res + " ";
        }
    }

    cout << endl;
    cout << "the res: " << res << endl;
    return res;

}

// offer582 左旋转字符串

string offer582::resverseLeftWords(string s, int n) {
    string res;
    string left;
    string right;
    for (int i = 0; i < s.size(); ++i) {
        if (i < n) {
            left.push_back(s[i]);
        } else {
            right.push_back(s[i]);
        }

    }
    res = right + left;
    cout << "the res: " << res << endl;
    return res;
}

// offer591 滑动窗口的最大值

vector<int> offer591::maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> res;
    int l = 0, r = k - 1;
    while(r < nums.size()) {
        // int max_ele = 0;
        for (int i = l; i <= r; ++i) {
            cout << nums[i] << " ";
        }
        cout << endl;
        auto iter = max_element(nums.begin() + l, nums.begin() + r + 1);
        cout << "the max: " << *iter << endl;
        res.push_back(*iter);
        l ++;
        r ++;
    }

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }

    cout << endl;

    return res;

}

// offer60 n个赛子的点数
// n枚赛子，点数范围为（n, 6n), 数组长度为5n+1, 因为每个赛子指出的概率为1/6,所有n个赛子
// 每次指出概率为（1/6）^n ,如果有k种组合， 概率不为 k*（1/6）^n
vector<double>  offer60::twosum(int n) {
    // dp[n][j] 表示掷完n个赛子后，总点数为j的次数，
    // 如果前n-1次赛子的总点数为j-i, 则第n次掷出i就可以满足条件
    vector<vector<int>> dp(n + 1, vector<int>(6*n + 1, 0));
    vector<double> ans;
    for (int i = 1; i <= n; ++i) {
        for (int j = i; j <= 6 * i; ++j) {
            if (i == 1) {
                dp[i][j] = 1;
                continue;
            }
            for (int k = 1; k <= 6; ++k) {
                // if (j - k >= i -1) {
                dp[i][j] += dp[i - 1][j - k];
                // }
            }
        }
    }
    for (int i = n; i <= 6*n; ++i) {
        ans.push_back(dp[n][i] * pow(1.0/6, n));
    } 
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << " ";
    }

    cout << endl;
    return ans;
    
}

//// offer61 扑克牌中的顺子
bool offer61::isstraight(vector<int> &nums) {
    bool res = false;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    int len = 0;
    for (int i = 0; i < nums.size() - 1;++i) {
        if (nums[i] == 0) {
            len ++;
        }
        cout << "the len: " << len << endl;
        cout << "the nums: " << nums[i] << endl;
        if (nums[i+1] - nums[i] == 0 && nums[i] != 0) {
            res = false;
            continue;

        }
        if (nums[i+1] - nums[i] > 1 && nums[i] != 0) {
            len = len - (nums[i+1] - nums[i] - 1);
            cout << "the len in 1708: " << len << endl;

        }

    }
    cout << "the len: " << len << endl;
    if (len >= 0) {
        res = true;
    } else {
        // len > 0
        res = false;
    }
    if (res) {
        cout << "yes , is the straight" << endl;
    } else {
        cout << "no , not the straight" << endl;
    }
    
    return res;

}
// 股票的最大利润  offer65
int offer63::maxprofit(vector<int> &prices) {
    int profit = 0;
    // dp[i]表示前i的最大利润
    int price = prices[0];
    for (int i = 0; i < prices.size(); ++i) {
        // 取最小值
        cout << "the price: " << price <<  endl;
        cout << "the prices[i]: " << prices[i] << endl;
        price = min(price, prices[i]);
        // 取最大利润
        profit = max(profit, prices[i] - price);
        cout << "the profit: " << profit << endl;
    }
    cout << "the most profit: " << profit << endl;
    return profit;
}

int offer64::sumnums(int n) {
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <= n; ++i) {
        dp[i] = i + dp[i-1];
    }
    cout << "the res: " << dp[n] << endl;
    return dp[n];

}

// 

int offer65::add (int a, int b) {
    // 无进位和， 只有进位和
    int carry = 0, sum = 0;
    while(b != 0) {
        // 异或操作得无进位和
        sum = a ^ b;
        // 与操作后移位得进位值
        carry = ((unsigned int)(a & b) << 1);
        // 循环，直到进位为0
        a = sum;
        b = carry;
    }
    cout << "the add res: " << a << endl;
    return a;
}

int offer65::subtrack(int a, int b) {

    int c = ~b + 1;
    cout << "the res subtract: " << add(a, c) << endl;
    return add (a, c);

}

// 构建乘积数组
vector<int> offer66::constractArr(vector<int> &a) {
    vector<int> res(a.size(), 0);
    for (int i = 0; i < a.size(); ++i) {
        int temp_res = 1;
        for (int j = 0; j < i; ++j) {
            temp_res = temp_res * a[j];
        }
        for (int k = i + 1; k < a.size(); ++k) {
            temp_res = temp_res * a[k];
        }
        res[i] = temp_res;
    }
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] <<  " ";
    }
    cout << endl;
    return res;
}

vector<int> offer66::constractArr2(vector<int> &a) {
    int n = a.size();
    vector<int> ret(n, 1);
    int left = 1;
    for (int i = 0; i < n; ++i) {
        ret[i] = left;
        left = left * a[i];
    }
    int right = 1;
    for (int j = n-1; j >= 0; --j) {
        ret[j] = ret[j] * right;
        right = right * a[j];
    }

    for (int i = 0; i < ret.size(); ++i) {
        cout << ret[i] << " ";
    }
    cout << endl;
    return ret;

}

//  将字符串转换成整数  offer67

int offer67::str2int(string str) {
    int res = 0;
    for (int i = 0; i < str.size(); ++i) {
        int temp_int = str[i] - '0';
        res = res * 10 + temp_int;
    }
    cout << "the res: " << res <<  endl;

    return res;
}

// // 二叉树的最近公共祖先 offer681;
// 迭代版本
Bitnode<char>* offer681::lowestcommonancester(
    Bitnode<char> * root, int p_val, int q_val) {
    while(root) {
        int root_val = root->val - '0';
        // int p_val = p->val - '0';
        // int q_val = q->val - '0';
        if (root_val > p_val && root_val > q_val) {
            root = root-> left;
        } else if (root_val < p_val && root_val < q_val) {
            root = root->right;
        } else {
            cout << "the root_val in iteration: " << root_val << endl;
            return root;
        }
    }

    return NULL;

}
// 递归版本
Bitnode<char>* offer681::lowestcommonancester2(
    Bitnode<char> * root, int p_val, int q_val) {
    Bitnode<char> * res = NULL;
    cout << "pass in 1864 " << endl;
    res = travel(root, p_val, q_val);

   cout << "pass in 1867 " << endl;
   // cout << "the res in recusion: " << res->val << endl;
    return res;
}

Bitnode<char>* offer681::travel(
    Bitnode<char> * root, int p_val, int q_val) {
    if (!root) {
        return NULL;
    }
    int root_val = root->val - '0';
    cout << "the root_val: " << root_val << endl;
    // int p_val = p->val - '0';
    // int q_val = q->val - '0';
    cout << "pass in 1876 " << endl;
    if (root_val < p_val && root_val < q_val) {
        cout << "pass in 1879 " << endl;
        travel(root->right, p_val, q_val);
    } else if(root_val > p_val && root_val > q_val) {
        cout << "pass in 1881 " << endl;
        travel(root->left, p_val, q_val);
    } else {
        cout << "pass in 1884 " << endl;
        cout << "the root_val in in recurse: " << root_val << endl;
        return root;
    }

    return NULL;

}

// 二叉树的最近公共祖先 offer682;

Bitnode<char>* offer682::lowestcommonancester(
        Bitnode<char> * root, int val_p, int val_q) {
    Bitnode<char> *res = NULL;
    if (root == NULL) {
        return NULL;
    }
    int root_val = root->val - '0';
    if (root_val == val_p || root_val == val_q) {
        
        // cout << "the res_val in 1908: " << root_val << endl;
        return root;
    }
    Bitnode<char> *left = lowestcommonancester(root->left, val_p, val_q);
    Bitnode<char> *right = lowestcommonancester(root->right, val_p, val_q);
    if (left && right) {
        // cout << "the res_val in 1914: " << root->val << endl;
        return root;
    }
    
    res = left ? left: right;
    if (res) {
        // cout << "the res_val in 1919: " << res->val << endl;
    }
    return  res;

}

// leetcode844 
 bool leetcode844::backspaceCCompare(string t, string s) {
     string str_t = getString(t);
     string str_s = getString(s);
     if (str_t == str_s || (str_t.size() == 0 && str_s.size() == 0) ) {
         cout << "yes.." << endl;
         return true;
     } else {
         cout << "no.." << endl;
         return false;
     }

 }

 string leetcode844::getString(string str) {
     string res;
     string temp_res;
     for (int i = 0; i < str.size(); ++i) {
        if (str[i] == '#') {
            if (temp_res.size() == 0) {
                continue;
            } else {
                temp_res.erase(temp_res.begin() + temp_res.size() - 1);
            }

        } else {
            temp_res.push_back(str[i]);

        }
     }
     
    //  for (int i = 0; i < temp_res.size(); ++i) {
    //      if (temp_res[i] != '#') {
    //          res.push_back(temp_res[i]);
    //      }
    //  }

     return temp_res;
 }

 // leetcode1 两个数之和
 vector<int> leetcode1::twosum(vector<int> &nums, int target) {
     vector<int> res;
     unordered_map<int, int> map;
     for (int i = 0; i < nums.size(); ++i) {
         map[nums[i]] = i;
     }
     for (int i = 0; i < nums.size(); ++i) {
         auto iter = map.find(target - nums[i]);
         if (iter != map.end()) {
             cout << i << " " << iter->second << endl;
             res.push_back(i);
             res.push_back(iter->second);
         }
     }

    //  for (int i = 0; i < res.size(); ++i) {
    //      cout << res[i] << " " << nums[i] << endl;

    //  }
     cout << endl;


     return res;

 }


// 两数相加 leetcode2
Node* leetcode2::addTwonumbers(Node* l1, Node* l2) {
    LinkList list;
    int next_posi = 0;
    int cur_posi = 0;
    while(l1->next) {
        int temp = l1->next->val + l2->next->val;
        cur_posi = temp % 10 + next_posi;
        next_posi = temp / 10 + cur_posi / 10;
        cout << "the temp: " << temp << " "
             << "cur_posi: " << cur_posi << " "
             << "next_posi: " << next_posi << endl;
        
        list.creatLinkList_one(cur_posi);
        l1 = l1->next;
        l2 = l2->next;
        if (!l1->next && next_posi != 0) {
            list.creatLinkList_one(next_posi);
        }
    }
     Node *temp = list.head->next;
     while(temp) {
         cout << temp->val << endl;
         temp = temp->next;

     }
    return list.head;

}

// // 无重复字符的最长子串
// 滑动窗口法
int leetcode3::lenoflongestsubstring(string s) {
    int len = s.size();
    if (len == 0) return 0;
    int res = 1;
    // 滑动窗口
    int i = 0, j = 0;  // start   end
    unordered_map<char, int> mp;
    for (; j < len; ++j) {
        mp[s[j]] ++;
        if (mp[s[j]] == 1) {
            res = max(j - i + 1, res);
        }
        if (j == len - 1) break;
        while (mp[s[j]] > 1) {
            mp[s[i]] --;
            ++i;
        }
    }
    cout << "the res :" << res << endl;

   return res;

}

// 最长回文子串  leetcode5
string leetcode5::longestPalindrome(string s) {
    int n = s.size();
    // dp[i][j] 表示从i到j的子串是否为回文
    vector<vector<int>> dp(n, vector<int>(n));
    string ans;
    for (int l = 0; l < n; ++l) {
        for (int i = 0; i + l < n; ++i) {
            int j = i + l;
            if (l == 0) {
                dp[i][j] = 1;
            } else if (l == 1) {
                dp[i][j] = (s[i] == s[j]);
            } else {
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j-1]);
            }
            if (dp[i][j] && l + 1 > ans.size()) {
                ans = s.substr(i, l +1);
            }

        }
    }

    cout << "the res: " << ans << endl;

    return ans;
}

//

string leetcode5::longestPalindrome2(string s) {
    int n = s.size();
    string ans = "";
    vector<vector<int>> dp(n, vector<int>(n));
   
    return ans;
}

// 整数反转 leetcode7
int leetcode7::reverse(int x) {
    int temp_x = x > 0 ? x: -1 * x;
    int ans = 0;
    while(temp_x > 0) {
        int tail = temp_x % 10;
        temp_x = temp_x / 10;
        ans = tail + ans * 10;

    }

    if (x < 0) {
        ans = -1 * ans;
    }
    cout << "res: " << ans << endl;

    return ans;
}

// 字符串转整数 leetcode8
int leetcode8::myatoi(string s) {
    int ans = 0;
    bool negative_flag = false;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '-') {
            negative_flag = true;
        } else if (s[i] - 48 >= 0 && s[i] - 48 <= 9) {
            int temp = s[i] - 48;
            ans = temp + ans * 10;
        }
    }

    if (negative_flag) {
        ans = -1 * ans;
    }
    cout << "the res: " << ans << endl;

    return ans;

}

// // 回文  leetcode9

bool leetcode9::ispalindrome(int x) {
    bool res = false;
    if (x < 0) {
        res = false;
        return res;
    }
    int temp_x = x;
    int ans = 0;
    while(x > 0) {
        int tail = x % 10;
        x = x / 10;
        ans = tail + ans * 10;

    }
    if (ans == temp_x) {
        res = true;
       
    } else {
        res = false;
    }

    return res;

}

// 成最多水的容器 leetcode11
// 双指针法
int leetcode11::maxarea(vector<int> &height) {
    int l = 0, r = height.size() - 1;
    int ans = 0;
    while(l < r) {
        int area = min(height[l], height[r]) * (r - l);
        ans = max(area, ans);
        // 哪边高度低,就移动哪一个
        if (height[l] < height[r]) {
            l ++;
        } else {
            r--;
        }
    }
    cout << "ans: " << ans << endl;
    return ans;
}

// 整数转罗马数字 leetcode12

string leetcode12::int2roman(int num) {
    string res;
    vector<string> tmp_1 = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
    vector<string> tmp_10 = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    vector<string> tmp_100 = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    vector<string> tmp_1000 = {"", "M", "MM", "MMM"};
    res.append(tmp_1000[num / 1000 % 10]);

    res.append(tmp_100[num / 100 % 10]);
    res.append(tmp_10[num / 10 % 10]);

    res.append(tmp_1[num / 1 % 10]);

    cout << "the res: " << res << endl;
    return res;

}

// // 罗马数字转数字  leetcode13

int leetcode13::roman2int(string s) {
    int res = 0;
    map<char, int> luomab = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };
    for (int i = 0; i < s.size(); ++i) {

        if (luomab[s[i]] < luomab[s[i+1]]) {
            res = res - luomab[s[i]];
        } else {
            res = res + luomab[s[i]];
        }

    }
    cout << "the res: " << res << endl;

    return res;

}


// leetcode14 最长公共子串
string leetcode14::longestcommonPrefix(vector<string> &strs) {
    if (!strs.size()) {
        return "";
    }
    string prefix = strs[0];
    int count = strs.size();
    for (int i = 1; i < count; ++i) {
        prefix = longestcommonPrefix(prefix, strs[i]);
        if (prefix.size() == 0) {
            break;
        }
    }
    cout << "the res: " << prefix << endl;

    return prefix;

}

string leetcode14::longestcommonPrefix(const string &str1, const string &str2) {
    int len = min(str1.size(), str2.size());
    int index = 0;
    while(index < len && str1[index] == str2[index]) {
        ++index;
    }
    return str1.substr(0, index);

}

// 三数之和  leetcode15  二数之和 leetcode1

vector<vector<int>> leetcode15::threeSum(vector<int>& nums, int target) {
    vector<vector<int>> res;
    int n = nums.size();
    sort(nums.begin(), nums.end());
    for (int first = 0; first < n; ++first) {
        if (nums[first] > target) {
            continue;
        }
        if (first > 0 && nums[first] == nums[first -1]) {
            continue;
        }
        int left = first + 1, right = n - 1;
        while(left < right) {
            if (nums[first] + nums[left] + nums[right] > target) {
                right --;
            } else if (nums[first] + nums[left] + nums[right] < target) {
                left ++;
            } else {
                res.push_back({nums[first], nums[left], nums[right]});
                while(right > left && nums[right] == nums[right - 1]) {
                    right --;
                }
                while(right > left && nums[left] == nums[left + 1]) {
                    left ++;
                }
                right --;
                left ++;
            }
        }
    }
    for (int i = 0; i < res.size(); ++i) {
        vector<int> temp_vec = res[i];
        for (int j = 0; j < temp_vec.size(); ++j) {
            cout << temp_vec[j] << " ";
        }
        cout << endl;
        
    }
    cout << endl;
    return res;
}

// leetcode16 最接近的三数之和 
int leetcode16::threeSumClosest(vector<int>& nums, int target) {
    int res;
    int n = nums.size();
    int mincut = nums[1] + nums[2] + nums[3];

    sort(nums.begin(), nums.end());
    for (int first = 0; first < n; ++first) {
         
        if (first > 0 && nums[first] == nums[first -1]) {
            continue;
        }
        int left = first + 1, right = n - 1;
        while(left < right) {
            cout << "the first and left and right: " << first << " "
                 << left << " " << right << endl;
            int threesum = nums[first] + nums[left] + nums[right];
            cout << "the three sum: " << threesum << endl;
            if (abs(threesum - target) < abs(mincut - target)) {
                mincut = threesum;
                cout << "the mincut: " << mincut << endl;
            } else if(threesum < target) {
                while(left < right && nums[right] == nums[right]) {
                    right --;
                }
            } else if(threesum > target) {

                while(left < right && nums[left] == nums[left + 1]) {
                    left ++;
                }
            }

            left ++;
            right --;

        }
    }

    cout << "the res: " << mincut << endl;
    
    cout << endl;
    return mincut;

}

// 电话号码的字母组合 leetcode17
vector<string> leetcode17::letterCombinations(string digits) {
    vector<string> combinations;
    if (digits.empty()) {
        return combinations;
    }
    unordered_map<char, string> phonemap {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    string combination;
    backtrack(combinations, phonemap, digits, 0, combination);
    for (auto iter: combinations) {
        cout << iter << endl;
    }
    cout << endl;
    
    return combinations;

}
// 回溯
void leetcode17::backtrack(vector<string>& combinations, 
    const unordered_map<char, string>& phoneMap,
    const string& digits, int index, string& combination) {
    if (index == digits.size()) {
        combinations.emplace_back(combination);
    } else {
        char digit = digits[index];
        const string letters = phoneMap.at(digit);
        for (auto iter: letters) {
            combination.push_back(iter);
            backtrack(combinations, phoneMap, digits, index + 1, combination);
            combination.pop_back();
        }
    }

}

//  leetcode18 四数之和

vector<vector<int>> leetcode18::fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> res;
    if (nums.size() < 4) {
        return res;
    }
    int a, b, c, d, len = nums.size();
    for (int a = 0; a < len - 4; ++a) {
        if (a > 0 && nums[a] == nums[a-1]) {
            continue;
        }
        for (b = a+1; b < len -3; ++b) {
            if (b > a + 1 && nums[b] == nums[b-1]) {
                continue;
            }
            c = b + 1;
            d = len - 1;
            while(c < d) {
                if (nums[a] + nums[b] + nums[c] +nums[d] < target) {
                    c++;
                } else if (nums[a] + nums[b] + nums[c] +nums[d] > target) {
                    d--;
                } else {
                    res.push_back({nums[a], nums[b], nums[c], nums[d]});
                    while(c < d && nums[c+1] == nums[c]) {
                        c ++;
                    }
                    while(c < d && nums[d -1] == nums[d]) {
                        d --;
                    }
                    c ++;
                    d --;
                }

            }
        }
    }
    for (int i = 0; i < res.size(); ++i) {
        vector<int> temp_res = res[i];
        for (auto iter: temp_res) {
            cout << iter << " ";
        }
        cout << endl;
    }
    cout << endl;
    return res;

}

//  删除链表的第n个节点 leetcode19
Node* leetcode19::deleteNthNode(Node *head, int n) {
    Node *temp_head = head;
    int count = 0;
     while (temp_head->next != NULL) {

          Node *target_node = temp_head->next;
          count++;
         
         if (count == n) {
            temp_head->next = target_node->next;
            free(target_node);
            break;
            // return head;

         } else {
             temp_head = temp_head->next;
         }

     }
     cout << "the count: " << count << endl;
     if (count < n) {
         cout << "the num of node < n" << endl;
     }

     return head;

}

// 有效括号  leetcode20

bool leetcode20::isValid(string s) {
    stack<char> s_stack;
    bool res = false;
    for (int i = 0; i < s.size(); ++i) {
        if (s_stack.empty()) {
            s_stack.push(s[i]);
        } else {
            if ((s_stack.top() == '(' && s[i] == ')') ||
                 (s_stack.top() == '{' && s[i] == '}') ||
                 (s_stack.top() == '[' && s[i] == ']')) {
                s_stack.pop();

            } else {
                s_stack.push(s[i]);
            }  
        }
    }
    if (s_stack.empty()) {
        cout << "is true" << endl;
        res = true;
    } else {
        cout << "is false" << endl;
        res = false;
    }

    return res;
}

// // 合并两个升序链表  leetcode21
Node* leetcode21::merge2Node(Node *head1, Node *head2) {
    // 链表2插入链表1
    Node* insert_node = head1->next;
    Node* head2_temp = head2->next;

    while(head2_temp != nullptr) {
        // head2_temp的值小于插入点, 且该点是第一个点
        if (insert_node->next == nullptr) {
            insert_node->next = head2_temp;
            break;
        }
        if (head2_temp->val < insert_node->val &&
            insert_node->val == head1->next->val) {

            Node *ptemp = new Node;
            ptemp->val = head2_temp->val;
            ptemp->next = insert_node;

            insert_node = insert_node->next;

            head2_temp = head2_temp->next;

        } else if (head2_temp->val < insert_node->next->val && 
                   head2_temp->val >= insert_node->val){

            Node *ptemp = new Node;
            ptemp->val = head2_temp->val;
            ptemp->next = insert_node->next;
            insert_node->next = ptemp;

            insert_node = insert_node->next;
            head2_temp = head2_temp->next;

        } else if (head2_temp->val >= insert_node->next->val) {
            cout << "the insert node: " << insert_node->val << endl;
            cout << "the head2_temp node: " << head2_temp->val << endl;
            while(head2_temp->val >= insert_node->next->val) {
                if (insert_node->next != nullptr) {
                    insert_node = insert_node->next;
                    cout << "the insert node insert in 2542: " << insert_node->val << endl;
                } 
                if (insert_node->next == nullptr) {
                    break;
                }
            }

            cout << "the insert node: " << insert_node->val << endl;
            
        }

    }
    Node* search_node = head1->next;
    while (search_node) {
        cout << "the val: " << search_node->val << endl;
        search_node = search_node->next;
    }

    return head1;

}

// 括号生成器  leetcode22
vector<string> leetcode22::generaterParents(int n) {
    vector<string> res;
    string path;
    int lc = 0, rc = 0;
    dfs(res, path, n, lc, rc);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
    cout << endl;
    return res;
}

void leetcode22::dfs(vector<string> &res, string path, int n,
            int lc, int rc) {
    if (rc > lc || lc > n || rc > n) {
        return;
    }
    if (lc == n && rc == n) {
        res.push_back(path);
        return;
    }

    dfs(res, path + '(', n, lc + 1, rc);
    dfs(res, path + ')', n, lc, rc + 1);

}

// 两两交换链表中的节点  leetcode24

Node *leetcode24::swapPairs(Node *head) {
    Node* temp_node = head->next;
    while(temp_node->next) {
        auto temp_val = temp_node->val;
        auto temp_next_val = temp_node->next->val;
        temp_node->val = temp_next_val;
        temp_node->next->val = temp_val;
        if (temp_node->next->next == nullptr) {
            break;

        } else {
            temp_node = temp_node->next->next;
        }

    }
    Node* temp_node1 = head->next;
    while(temp_node1) {
        cout << "the temp_node1: " << temp_node1->val << endl;
        temp_node1 = temp_node1->next;
    }
    
    return head;

}

// 删除排序数组中的重复数组  leetcode26
int leetcode26::removeDuplicates(vector<int> &nums) {
    // unordered_set<int> set_nums;
    set<int> set_nums;
    for (int i = 0; i < nums.size(); ++i) {
        set_nums.emplace(nums[i]);
    }
    cout << "the len of set_nums: " << set_nums.size() << endl;
    return set_nums.size();
}

// 移除元素 leetcode27 

int leetcode27::removeelement(vector<int> &nums, int val) {

    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == val) {
            nums.erase(nums.begin() + i);
            i --;
        }
    }

    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " " << endl;
    }
    cout << endl;

    return nums.size();
}


// 实现 strStr leetcode28
int leetcode28::strStr(string haystack, string needle) {

}

// 除法 leetcode29

int leetcode29::divide(int dividend, int divisor) {
    if (dividend == 0) {
        return 0;
    }
    if (divisor == 1) {
        return dividend;
    }
    if (divisor == -1) {
        if (dividend > INT_MIN) {
            return -1.0 * dividend;
        }
        return INT_MIN;
    }
    long a = dividend;
    long b = divisor;
    int sign = 1;
    if ( (a>0 && b<0) || (a<0 && b>0) ) {
        sign = -1;
    }

    a = a>0 ? a: -a;
    b = b>0 ? b: -b;
    long res = div(a, b);
    if (sign>0) {
        return res > INT_MAX ? INT_MAX: res;
    }
    return -res;
}

int leetcode29::div(long a, long b) {
    if (a < b) return 0;
    long count = 1;
    long tb = b;
    while( (tb + tb) <= a ) {
        count = count + count;
        tb = tb + tb;

    }
    return count + div(a - tb, b);

}

// 搜索排序数组  leetcode 33
int leetcode33::search(vector<int> &nums, int target) {
    int res = -1;
    int l = 0, r = nums.size() - 1;
    cout << "the l and r" << l << " " << r << endl;
    while(l < r) {
        int mid = (r + l) / 2;
        if (nums[mid] == target) {
            res = mid;
            break;
        }
        if (nums[mid] >= nums[l]) {
            if (nums[l] <= target && nums[mid] > target) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else {

            if (nums[mid] <= target && nums[r] > target) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
            
        }
        cout << "in 2721" << endl;
    }

    cout << "the posi: " << res << endl;
    cout << "in 2722 " << endl;
    return res;
}

// 在排序数组中查找元素的第一个和最后一个位置 时间复杂度O(log(n))
// leetcode34
 vector<int> leetcode34::searchRange(vector<int> &nums, int target) {
     vector<int> res;
     auto liter = lower_bound(nums.begin(), nums.end(), target);
     auto hiter = upper_bound(nums.begin(), nums.end(), target);

     int low = liter -nums.begin();
     int high = hiter - nums.begin();
     if (low == high) {
         res = {-1, -1};
     } else {
         res = {low, high-1};
     }
     for (int i = 0; i < res.size(); ++i) {
         cout << res[i] << " ";
     }
     cout << endl;
     return res;

 }

/*
int leetcode34::lower_bound(vector<int> &nums, int target) {
    int l = 0, r = nums.size();
    while(l < r) {
        int mid = (r+l) >> 1;
        if (target <= nums[mid]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;
}
int leetcode34::upper_bound(vector<int> &nums, int target) {
    int l = 0, r = nums.size();

    while(l < r) {
        int mid = (r+l) >> 1;
        if (target < nums[mid]) {
            r = mid;
        } else {
            l = mid + 1;
        }
    }
    return l;

}

*/

// 搜索插入位置  leetcode35

int leetcode35::searchInsert(vector<int> &nums, int target) {
    int res = 0;
    for (int i = 0; i < nums.size(); ++i) {
        if (nums[i] == target) {
            res = i;
            break;
        } else {
            if (nums[i] < target && nums[i+1] > target && i + 1 < nums.size()) {
                res = i + 1;
                break;
            }
            if (nums[i] > target && i == 0) {
                res = 0;
                break;
            }
            if (nums[i] < target && i == nums.size() - 1) {
                res = i + 1;
                break;
            }
        }
    }
    cout << "the posi: " << res << endl;

    return res;
}


// 快速排序 
void quickSort::quicksort(vector<int> &nums, int l, int r) {
    if (l > r) {
        return;
    }
    int i = l, j = r;
    int key = nums[i];
    while (j > i) {
        while(j > i && nums[j] >= key) {
            j --;
        }
        if (i < j) {
            nums[i] = nums[j];
            i++;
        }
        while(j > i && nums[i] <= key) {
            i++;
        }
        if (i < j) {
            nums[j] = nums[i];
            j --;
        }

    }
    nums[i] = key;
    quicksort(nums, l, i - 1);
    quicksort(nums, i + 1, r);

}

//  归并排序
void mergeSort::mergesort(vector<int> &nums, int low, int high) {
    if (low >= high) {return;}
    int mid = low + (high - low)/2;
    mergesort(nums, low, mid);
    mergesort(nums, mid + 1, high);
    cout << "pass in 2846" << endl;
    merge(nums, low, mid, high);

}
void mergeSort::merge(vector<int> &nums, int low, int mid, int high) {
    int i = low, j = mid + 1, k = 0;
    vector<int> nums_c;
    while( i <= mid && j <= high) {
        if (nums[i] < nums[j]) {
            nums_c.push_back(nums[i++]);
        } else {
            nums_c.push_back(nums[j++]);
        }

    }
    while(i <= mid) {
        nums_c.push_back(nums[i++]);
    }
    while(j <= high) {
        nums_c.push_back(nums[j++]);
    }

    k = nums_c.size();
    for (int i = low, j = 0; i <= high, j < k; ++i, ++j) {
        nums[i] = nums_c[j];
    }

}

// 
// leetcode36 有效数独
bool leetcode36::isvalidsuduku(vector<vector<char>> &board) {
    // row[i][num] 第i行num元素存在与否  0 不存在 1 存在
    int row[9][10] = {0};
    // col[j][num] 第j列num元素存在与否  0 不存在 1 存在
    int col[9][10] = {0};
    // box[j/3 + (i/3) * 3][num] 第（j/3 +(i/3)*3）BOX第num元素存在与否  0 不存在 1 存在
    int box[9][10] = {0};
    // 
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if(board[i][j] = ',') {
                continue;
            }
            int curnumber = board[i][j] - '0';
            if (row[i][curnumber]) {
                return false;
            }
            if (col[j][curnumber]) {
                return false;
            }
            if (box[j/3 + (i/3) * 3][curnumber]) {
                return false;
            }
            row[i][curnumber] = 1;
            col[j][curnumber] = 1;
            // 第几个boX 
            box[j/3 + (i/3) * 3][curnumber] = 1;
        }
    }

    return true;
}

// leetcode39 组合总和
vector<vector<int>> leetcode39::commbinationsum(vector<int> &nums, int target) {
        vector<int> temp;
        int sum = 0;
        int i = 0;
        //sort(nums.begin(), nums.end());
        dfs(nums, temp, target, sum, i);
    for (int i = 0; i < res.size(); ++i) {
        vector<int> temp_res = res[i];
        for (int j = 0; j < temp_res.size(); ++j) {
            cout << temp_res[j] << " ";
        }
        cout << endl;
    }


    return res;

}
void leetcode39::dfs(vector<int> &nums, vector<int> &temp,int target, int sum, int posi) {
    if (sum == target) {
        res.push_back(temp);
        return;
    }
    for (int j = posi; j < nums.size(); ++j) {
        if (sum < target) {
            sum = sum + nums[j];
            temp.push_back(nums[j]);
            // j 表示可以重复利用

            //dfs(nums, temp, target, sum, j);
            dfs(nums, temp, target, sum, j);
             sum = sum - nums[j];
             temp.pop_back();

        }
    }
    
}

void leetcode39::dfs1(vector<int> &nums, vector<int> &temp,int target, int sum, int posi) {
    if (sum == target) {
        res.push_back(temp);
        return;
    }
    for (int j = posi; j < nums.size(); ++j) {
        // 重复元素，跳过
        if (j > posi && nums[j] == nums[j-1]) {
            continue;
        }
        if (sum < target) {
            sum = sum + nums[j];
            temp.push_back(nums[j]);
            // j+1 表示可以重复利用
            
            dfs1(nums, temp, target, sum, j+1);
             sum = sum - nums[j];
             temp.pop_back();

        }
    }
    
}

// leetcode40
vector<vector<int>> leetcode40::commbinationsum(vector<int> &nums, int target) {
    vector<int> temp;
    int sum = 0;
    int i = 0;
    sort(nums.begin(), nums.end());
    dfs1(nums, temp, target, sum, i);
    for (int i = 0; i < res.size(); ++i) {
    vector<int> temp_res = res[i];
    for (int j = 0; j < temp_res.size(); ++j) {
        cout << temp_res[j] << " ";
    }
        cout << endl;
    }

    return res;

}
    // 不可以重复利用
void leetcode40::dfs1(vector<int> &nums, vector<int> &temp,int target, int sum, int posi) {
    if (sum == target) {
        res.push_back(temp);
        return;
    }
    for (int j = posi; j < nums.size(); ++j) {
        // 重复元素，跳过
        if (j > posi && nums[j] == nums[j-1]) {
            continue;
        }
        if (sum < target) {
            sum = sum + nums[j];
            temp.push_back(nums[j]);
            // j+1 表示可以重复利用
            
            dfs1(nums, temp, target, sum, j+1);
             sum = sum - nums[j];
             temp.pop_back();

        }
    }
}

// leetcode42 接雨水
int leetcode42::trap(vector<int> &height) {
    int left = 0, right = height.size() - 1;
    int ans = 0;
    int left_max = 0, right_max = 0;
    
    while(left < right) {
        cout << "pass in 3023" << endl;
        // 左边值小于右边，这个时候装多少水取决于最短的板块
        // 如果值比左边最大值还大，则更新，否则进行计算
        if (height[left] < height[right]) {
            if (height[left] >= left_max) {
                left_max = height[left];
            } else {
                ans = ans + left_max - height[left];
                cout << "the ans: " << ans << endl;
            }
            ++left;
        } else {
            if (height[right] >= right_max) {
                right_max = height[right];
            } else {
                ans = ans + right_max - height[right];
                cout << "the ans: " << ans << endl;
            }
            right--;

        }
    }
    cout << "the ans: " << ans << endl;
    return ans;

}

// 全排列  leetcode46

vector<vector<int>> leetcode46::permut(vector<int> &nums) {
    vector<int> temp;
    vector<bool> visited(nums.size(), false);
    int posi = 0;
    dfs(visited, temp, nums, posi);
    for (int i = 0; i < ans.size(); ++i) {
        vector<int> temp_ans = ans[i];
        for (int j = 0; j < temp_ans.size(); ++j) {
            cout << temp_ans[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    return ans;

}
void leetcode46::dfs(vector<bool> &visited, vector<int> &temp, vector<int> &nums, int &posi) {
    if (temp.size() == nums.size()) {
        ans.push_back(temp);
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        if (!visited[i]) {
            temp.push_back(nums[i]);
            visited[i] = true;
            dfs(visited, temp, nums, posi);
            temp.pop_back();
            visited[i] = false;
        }
    }

}

// leetcode47 全排列2
vector<vector<int>> leetcode47::permut(vector<int> &nums) {
    vector<int> temp;
    vector<bool> visited(nums.size(), false);
    sort(nums.begin(), nums.end());
    int posi = 0;
    dfs(visited, temp, nums, posi);
    for (int i = 0; i < ans.size(); ++i) {
        vector<int> temp_ans = ans[i];
        for (int j = 0; j < temp_ans.size(); ++j) {
            cout << temp_ans[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    
    return ans;

}
void leetcode47::dfs(vector<bool> &visited, vector<int> &temp, vector<int> &nums, int &posi) {
    if (temp.size() == nums.size()) {
        ans.push_back(temp);
        return;
    }
    for (int i = 0; i < nums.size(); ++i) {
        // 去除已经遍历的， 以及去除重复
        if ( (i > 0 && nums[i] == nums[i -1] && !visited[i-1]) || visited[i] ) {
            continue;
        }
        
        temp.push_back(nums[i]);
        visited[i] = true;
        dfs(visited, temp, nums, posi);
        temp.pop_back();
        visited[i] = false;
        
    }

}

//  // Pow(x, n) leetcode50
double leetcode50::myPow(double x, int n) {
    vector<double> dp(n+1);
    // base case
    dp[0] = 0;
    dp[1] = x;
    for (int i = 2; i <= n; ++i) {
        dp[i] = dp[i-1] * x;
    }
    cout << "the nth of dp: " << dp[n] << endl;
 }


 // O(log(N))
double leetcode50::myPow2(double x, int n) {
    // n是否能被2 整除
    double ans = 0.0;
    bool flag = n%2 == 0 ? true: false;
    vector<double> dp(n/2);
    dp[0] = 0;
    dp[1] = x * x;
    for (int i = 2; i <= n/2; ++i) {
        dp[i] = dp[i-1] * dp[i-1];
    }
    if (flag) {
        ans = dp[n/2];
    } else {
        ans = dp[n/2] * x;
    }
    cout << "the ans: " << ans << endl;
    return ans;

}


// // N 皇后 leetcode51

vector<vector<string>> leetcode51::SolveNQueens(int n) {
    //vector<vector<string>> ans;
    //vector<string> temp;
    string string_temp(n, ',');
    vector<string> temp(n, string_temp);
    int row = 0;
    dp(n, row, temp);
    for (int i = 0; i < ans.size(); ++i) {
        vector<string> temp_ans = ans[i];
        for (int j = 0; j < temp_ans.size(); ++j) {
            cout << temp_ans[j] << endl;
        }
        cout << endl;
        cout << endl;
    }
    return ans;
}
void leetcode51::dp(int n, int row, vector<string> &temp) {
    if (row == n) {
        ans.push_back(temp);
        return;
    }
    // i -> col  
    for (int i = 0; i < n; ++i) {
        if ( valid(row, i, temp, n) ) {
            temp[row][i] = 'Q';
            dp(n, row + 1, temp);
            temp[row][i] = ',';
        }
    }

}
bool leetcode51::valid(int row, int col, vector<string> &temp, int n) {
    // 检查 列
    for (int i =0; i < row; ++i) {
        if (temp[i][col] == 'Q') {
            return false;
        }
    }
    for (int i = row -1, j = col -1; i >= 0 && j >= 0; i--, j--) {
        if (temp[i][j] == 'Q') {
            return false;
        }
    }
    for (int i = row -1, j = col+1; i >= 0 && j < n; i--, j++) {
        if (temp[i][j] == 'Q') {
            return false;
        }
    }
    return true;
    

}

// leetcode53 最大子序列和 

int leetcode53::maxSubarray(vector<int> & nums) {
    int n = nums.size();
    int tailsum = nums[0], ans = nums[0];
    for (int i = 1; i < n; ++i) {
        tailsum = tailsum > 0? tailsum + nums[i]: nums[i];
        ans = max(ans, tailsum);
    }
    cout << "the ans: " << ans << endl;
    return ans;

}
// leetcode54 旋转矩阵
vector<int> leetcode54::spiralOrer(vector<vector<int>> &nums) {
    
    int rows = nums.size(), cols= nums[0].size();
    vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    vector<vector<bool>> visiter(rows, vector<bool>(cols, false));
    int total = rows * cols;
    int directions = 0;
    int row = 0, col = 0;
    vector<int> res;
    for (int i = 0; i < total;  ++i) {
        
        res.push_back(nums[row][col]);
        visiter[row][col] = true;
        int next_row = row + direction[directions][0];
        int next_col = col + direction[directions][1];
        if (next_row < 0 || next_row >= rows || next_col < 0 || next_col >= cols ||
            visiter[next_row][next_col] == true) {
            directions = (directions + 1) % 4;

        }
        row = row + direction[directions][0];
        col = col + direction[directions][1];
    }
    for (int i = 0; i < total; ++i) {
        cout << res[i] << " ";
    }
    cout << endl;

    return res;
}

// leetcode55 跳跃游戏
bool leetcode55::canjump3( vector<int> &nums ) {

    int n = nums.size();
    // 可以往右边跳的最大位置
    int rightmost = 0;
    for (int i = 0; i < n; ++i) {
        // i这个位置是能跳到的
        if (i <= rightmost) {
            rightmost = max(rightmost, i + nums[i]);
            if (rightmost > n-1) {
                cout << "yes, can jump" << endl;
                return true;
            }
        }
    }
    cout << "no, can not jump" << endl;
    return false;

}

// leetcode55 回溯算法
bool leetcode55::canjump2(vector<int> &nums) {
    // vector<vector<int>> path;
    bool ans = false;
    vector<int> temp_path;
    int cur_level = 0;
    int most_step = nums[0];
    temp_path.push_back(0);
    ans = dfs(cur_level, most_step, temp_path, nums);
    cout << "the path: " << endl;
    for (int i = 0; i < path.size(); ++i) {
        vector<int> temp = path[i];
        for (int j = 0; j < temp.size(); ++j) {
            cout << temp[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return ans;
}

bool leetcode55::dfs(int cur_level, int &most_step, vector<int> &temp_step, vector<int> &nums) {

    if (cur_level == nums.size() - 2 && cur_level + nums[cur_level] < nums.size() - 1) {
        // path.push_back(temp_step);
        return false;
    }
    if (cur_level + most_step >= nums.size() - 1) {
        cout <<" the level: " << cur_level << " " 
             << "most step: " << most_step << endl;
        temp_step.push_back(nums.size() - 1);
        path.push_back(temp_step);
        return true;
    }
    for (int i = 1; i <= most_step; ++i) {
        cout << "the most_step: " << most_step << endl;
        cout << "i: " << i << endl;
        int new_level = cur_level + i;
        cout << "the new_level: " << new_level << endl;

        int new_most_step = nums[new_level];
        cout << "the new_most_level: " << new_most_step << endl;
        temp_step.push_back(new_level);
        for (int k = 0; k < temp_step.size(); ++k) {
            cout << temp_step[k] << " ";
        }
        cout << endl;
        dfs(new_level, new_most_step, temp_step, nums);
        temp_step.pop_back();

    }

}

// leetcode56 合并区间
void leetcode56::merge(vector<vector<int>> &nums, 
           vector<pair<int, int>> &ans) {
    auto comp = [](const vector<int> &val1, const vector<int> &val2) {
        return val1[0] < val2[0];
    };
    sort(nums.begin(), nums.end(), comp);
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i][0] <<" " << nums[i][1] << endl;
    }
    int min_begin = nums[0][0];
    int max_end = nums[0][1];
    for (int i = 1; i < nums.size(); ++i) {
        if (nums[i][0] > min_begin && nums[i][0] < max_end) {
            cout << "have: " << endl;
            if (nums[i][i] > max_end) {
                max_end = nums[i][1];
            }
        } else {
            cout << "the min_begin and max_end: " << min_begin << " " << max_end << endl; 
            cout << "do not have" << endl;
            ans.push_back({min_begin, max_end});
            min_begin = nums[i][0];
            max_end = nums[i][1];

        }
    }
    ans.push_back({min_begin, max_end});
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i].first << " " << ans[i].second << endl;
    }
    cout << endl;
    return;

}

// 旋转矩阵 leetcode59 

vector<vector<int>> leetcode59::generatematrix(int n) {
    if (n <= 0) {
        cout << "the n is <= 0" << endl;
        vector<vector<int>> ans;
        return ans; 
    }
    vector<vector<int>> ans(n, vector<int>(n));
    vector<vector<bool>> visited(n, vector<bool>(n, false));
    vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int row = 0, col = 0;
    int cur_direct_flag = 0;
    const int total_num = n * n;
    const int size_row = n;
    const int size_col = n;
    ans[0][0] = 1;
    visited[0][0] = true;
    int count = 1;
    while(count != total_num) {
        if (cur_direct_flag == 3 && visited[row - 1][col] == true) {
            cur_direct_flag = 0;
        }
        if ( (cur_direct_flag == 0 && col == size_col - 1) ||
             (cur_direct_flag == 0 && visited[row][col+1] == true) ||
             (cur_direct_flag == 1 && row == size_row - 1) ||
             (cur_direct_flag == 1 && visited[row + 1][col] == true) ||
             (cur_direct_flag == 2 && col == 0) ||
             (cur_direct_flag == 2 && visited[row][col - 1] == true)) {
            cur_direct_flag ++;
        }
        vector<int> curent_direct = direction[cur_direct_flag];
        cout << endl;
        row = row + curent_direct[0];
        col = col + curent_direct[1];
        count++;
        ans[row][col] = count;
        visited[row][col] = true;
    }
    for (auto iter: ans) {
        for (auto iter1: iter) {
            cout << iter1 << " ";
        }
        cout << endl;
    }
    cout << endl;

    return ans;

}

// leetcode61 旋转列表

Node* leetcode61::rotateRight(Node* head, int k) {
    if (!head->next) return NULL;
    int n = 0;
    for (auto p = head->next; p; p = p->next) {
        n ++;
    }
    cout << "the len of list: " << n << endl;
    k = k % n; // 求余数 整数倍是可以回到原点的
    // 双指针
    auto first = head->next;
    auto second = head->next;
    // 先动k
    while(k > 0) {
        first = first->next;
        k --;
    }
    cout << "the first val: " << first->val << endl;
    cout << "the second val: " << second->val << endl;
    // 移动到末尾
    while(first->next) {
        first = first->next;
        second = second->next;
    }
    // 切断
    cout << "the first val after k: " << first->val << endl;
    cout << "the second val after k: " << second->val << endl;
    first->next = head->next;
    head->next = second->next;
    second->next = NULL;
    Node *temp = head->next;
    while(temp) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
    return head;

}

// leetcode62 不同路径
// 回溯算法
int leetcode62::uniquePath(int m, int n) {
    vector<pair<int, int>> path;
    int row = 0, col = 0;
    path.push_back({0, 0});

    dfs(path, row, col, m, n);
    for (int i = 0; i < ans.size(); ++i) {
        vector<pair<int, int>> temp = ans[i];
        for (auto iter: temp) {
            cout << iter.first << "-" << iter.second << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "the size of ans: " << ans.size() << endl;
    return ans.size();
}

// 

void leetcode62::dfs(vector<pair<int, int>> &path, int &row, int &col, int m, int n) {
    if (row == m-1 && col == n-1 ) {
        ans.push_back(path);
        return;
    }
    for (int i = 0; i < 2; ++i) {
        int newrow = row + directions[i][0];
        int newcol = col + directions[i][1];
        cout << "the row ans col: " << newrow << " " << newcol << endl;
        if (newrow >= m || newcol >= n) {
            continue;
        }
        path.push_back({newrow, newcol});
        dfs(path, newrow, newcol, m, n);
        path.pop_back();
    }

}

// 
// 动态规划
int leetcode62::uniquePath2(int m, int n) {
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        dp[i][0] = 1;
    }
    for (int j = 0; j < n; ++j) {
        dp[0][j] = 1;
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = dp[i-1][j] + dp[i][j-1];


        }
    }
    cout << "the  ans: " << dp[m-1][n-1] << endl;
    return dp[m-1][n-1];
}

// leetcode63  不同路径 障碍物
// 回溯算法
int leetcode63::uniquePathwithobs(vector<vector<int>> &obsgrid) {
    vector<pair<int, int>> path;
    int row = 0, col = 0;
    path.push_back({0, 0});
    int m = obsgrid.size();
    int n = obsgrid[0].size();
    obsgrid_ = obsgrid;

    dfs(path, row, col, m, n);
    for (int i = 0; i < ans.size(); ++i) {
        vector<pair<int, int>> temp = ans[i];
        for (auto iter: temp) {
            cout << iter.first << "-" << iter.second << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "the size of ans: " << ans.size() << endl;
    return ans.size();

}
    
void leetcode63::dfs(vector<pair<int, int>> &path, int &row, int &col, int m, int n) {
     if (row == m-1 && col == n-1 ) {
        ans.push_back(path);
        return;
    }
    
    for (int i = 0; i < 2; ++i) {
        int newrow = row + directions[i][0];
        int newcol = col + directions[i][1];
        cout << "the i: " << i << endl;
        cout << "the row ans col: " << newrow << " " << newcol << endl;
        if (newrow >= m || newcol >= n) {
            continue;
        }
        // 跳过障碍物
        if (obsgrid_[newrow][newcol] == 1) {
            continue;
        }
        path.push_back({newrow, newcol});
        dfs(path, newrow, newcol, m, n);
        path.pop_back();
    }

}


// leetcode63  不同路径 障碍物
// 动态规划
int leetcode63::uniquePath2(vector<vector<int>> &obsgrid) {
    int m = obsgrid.size();
    int n = obsgrid[0].size();
     vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; ++i) {
        // 有障碍物
        if (obsgrid[i][0] == 1) {
            dp[i][0] = 0;
            for (int j = i; j < m; ++j) {
                dp[j][0] == 0;
            }
            break;
        } else if (obsgrid[i][0] == 0) {
            dp[i][0] = 1;
        }
    }
    for (int j = 0; j < n; ++j) {
        // 有障碍物
        if (obsgrid[0][j] == 1) {
            dp[0][j] = 0;
            for (int k = j; k < n; ++k) {
                dp[0][k] == 0;
            }
            break;

        } else if (obsgrid[0][j] == 0) {
            dp[0][j] = 1;
        }

        // dp[0][j] = 1;
    }

    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
             // 有障碍物
            if (obsgrid[i][j] == 1) {
                dp[i][j] = 0;
            } else if (obsgrid[i][j] == 0) {

                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
            // dp[i][j] = dp[i-1][j] + dp[i][j-1];

        }
    }
    cout << "the  ans: " << dp[m-1][n-1] << endl;
    return dp[m-1][n-1];

}

// leetcode64  最小路径和
int leetcode64::minPathsum(vector<vector<int>> &grid) {
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0) );
    dp[0][0] = grid[0][0];
    for (int i = 1; i < m; ++i) {
        dp[i][0] = dp[i-1][0] + grid[i][0];
    }
    for (int j = 1; j < n; ++j) {
        dp[0][j] = dp[0][j-1] + grid[0][j];
    }
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            dp[i][j] = min(dp[i][j-1] + grid[i][j], dp[i-1][j] + grid[i][j]);
        }
    }
    for (int i = 0; i < dp.size(); ++i) {
        vector<int> temp_dp = dp[i];
        for (int j = 0; j < temp_dp.size(); ++j) {
            cout << temp_dp[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    cout << "the minsum of dp[m-1][n-1]: " << dp[m-1][n-1];
    return dp[m-1][n-1];
}

// leetcode67 二进制求和

string leetcode67::addBinary(string a, string b) {
    int a1 = a.size();
    int b1 = b.size();
    while(a1 < b1) {
        a = '0' + a;
        ++a1;
    }
    while(a1 > b1) {
        b = '0' + b;
        ++b1;
    }
    cout << "the a: " << a << endl;
    cout << "the b: " << b << endl;
    for (int j = a.size() -1; j > 0; --j) {
        a[j] = a[j] - '0' + b[j];
        if (a[j] >= '2') {
            a[j] = (a[j] - '0') % 2 + '0';
            a[j-1] = a[j-1] + 1;
        }
    }
    cout << "the a: " << a << endl;
    cout << "the b: " << b << endl;
    a[0] = a[0] - '0' + b[0];
    if (a[0] >= '2') {
        a[0] = (a[0] - '0') % 2 + '0';
        a = '1' + a;
    }
    cout << "the a: " << a << endl;
    cout << "the b: " << b << endl;
    cout << "the res: " << a << endl;
    return a;
}

// leetcode69     x的平方根
int leetcode69::mysqrt(int x) {
    int ans = 0;
    for (int i = 0; i < x; ++i) {
        if (i * i <= x && (i + 1) * (i + 1) > x ) {
            ans = i;
            break;
        }
    }
    cout << "the ans: " << ans << endl;
    return ans;
}

// leetcode70 爬楼梯

int leetcode70::climbStairs(int n) {
    vector<int> dp(n, 0);
    dp[0] = 1;
    dp[1] = 2;

    // 可以从走1步和2步
    for (int i = 2; i < n; ++i) {
        dp[i] = dp[i-1] + dp[i-2];
    }
    
    cout << "the res: " << dp[n-1] << endl;
    return dp[n-1];

}

//// leetcode74 搜索二维矩阵
// 将二维矩阵扩展为单维矩阵 然后进行 二分法搜索
bool leetcode74::searchMatrix(vector<vector<int>> &matrix, int target) {
    bool ans = false;
    int m = matrix.size();
    if (m==0) {
        ans = false;
    }
    int n = matrix[0].size();
    // 二分查找
    int left = 0, right = m * n -1;
    int pivotIDX, pivotElenment;
    while(left <= right) {
        pivotIDX = (left + right) / 2;
        int  row = pivotIDX / n;
        int col = pivotIDX % n;
        pivotElenment = matrix[row][col];
        if (target == pivotElenment) {
            ans = true;
            cout << "the row ans col: " << row << " " << col << endl;

            return ans;
        } else {

            if (target < pivotElenment) {
                right = pivotIDX -1;
            } else {
                left = pivotIDX + 1;
            }

        }

    }

    return ans;

}

// 
// 单指针
void leetcode75::sortColor(vector<int> &nums) {
    int n = nums.size();
    int front_ptr = 0;
    int end_ptr = n - 1;
    for (int i = 0; i < n; ++i) {
        if (nums[i] == 0) {
            // 将0 扔到头部
            swap(nums[i], nums[front_ptr]);
            ++front_ptr;
        } 
    }

    for (int i = n-1; i >= 0; --i) {
        if (nums[i] == 2) {
            swap(nums[i], nums[end_ptr]);
            end_ptr = end_ptr - 1;
        }
    }
    for (int i = 0; i < n; ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return;

}


// 双指针
void leetcode75::sortColor2(vector<int> &nums) {
    int n = nums.size();
    int front = 0, end = n -1;
    for(int i = 0; i <= end; ++i) {
        while(i <= end && nums[i] == 2) {
            swap(nums[i], nums[end]);
            --end;
        }
        if (nums[i] == 0) {
            swap(nums[i], nums[front]);
            ++front;

        }
    }
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << " ";
    }
    cout << endl;
    return ;
}
 // 组合 leetcode77

vector<vector<int>> leetcode77::combine(int n, int k) {
   int cur_posi = 1;
   vector<int> temp;
   dfs(temp, cur_posi, n, k);
   for (int i = 0; i < ans.size(); ++i) {
       vector<int> temp_ans = ans[i];
       for (int j = 0; j < temp_ans.size(); ++j) {
           cout << temp_ans[j] << " ";
       }
       cout << endl;
   }
   cout << endl;




    return ans;
}
void leetcode77::dfs(vector<int> &temp, int cur_posi, int n, int k) {
    if (temp.size() == k) {
        ans.push_back(temp);
        return;
    }
    for(int j = cur_posi; j <= n; ++j) {
        temp.push_back(j);
        // int new_posi = cur_posi + 1;
        // 从下一个数开始
        dfs(temp, j + 1, n, k);
        // 从
        // dfs(temp, j + 1, n, k);
        temp.pop_back();

    }

}

// 子集 leetcode78

vector<vector<int>> leetcode78::subsets(vector<int> &nums) {
    int n = 0;
    dfs(n, nums);
    cout << "the size of ans: " << ans.size() << endl;
    for (int i = 0; i < ans.size(); ++i) {
        vector<int> temp_ans = ans[i];
        for (int j = 0; j < temp_ans.size(); ++j) {
            cout << temp_ans[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return ans;

}
void leetcode78::dfs(int cur_posi, vector<int> nums) {
    ans.push_back(temp);
    for (int j = cur_posi; j < nums.size(); ++j) {
        temp.push_back(nums[j]);
        dfs(j + 1, nums);
        temp.pop_back();
    }


}

// leetcode80

int leetcode80::removeDuplicates(vector<int> &nums) {
   if (nums.size() == 0) {
       return 0;
   }
   int fast = 1;
   int slow = 1;
   int count = 1;
   while(fast < nums.size()) {
       if (nums[fast] == nums[fast-1]) {
           count ++;
       } else {
           count = 1;
       }
       nums[slow] = nums[fast];
       if (count <= 2) {
           slow++;
       }

       fast++;
   }
   cout << "the ans: " << slow << endl;
   return slow;
}

// leetcode81  搜索旋转矩阵2

bool leetcode81::search(vector<int> &nums, int target) {
    if (nums.empty()) {
        return false;
    }
    int left = 0, right = nums.size();
    while(left < right) {
        int mid = left + (right - left) /2;
        if (nums[mid] == target) {
            return true;
        }
        if(nums[mid] > nums[left]) {  // left -> mid 是有序的
            if (target >= nums[left] && target < nums[mid]) {
                right = mid;
            } else {
                left = mid + 1;
            }

        } else if (nums[mid] < nums[left]) { // mid -> right 有序
            if (target > nums[mid] && target <= nums[target - 1]) {
                left = mid + 1;
            } else {
                right = mid;
            }
        } else if (nums[mid] == nums[left]) {
            left ++;
        }
    }
    return false;

}

//

 int leetcode84::largeRectangleArea(vector<int> &nums) {
     int n = nums.size();
     int ans = 0;
     for (int left = 0; left < n; ++left) {
         int minHeight = INT_MAX;
         for (int right = left; right < n; ++right) {
             minHeight = min(minHeight, nums[right]);
             ans = max(ans, (right - left + 1) * minHeight);
         }
     }
    cout << "the ans: " << ans << endl;
     return ans;

 }
 //

 int leetcode84::largeRectangleArea1(vector<int> &nums) {
     int n = nums.size();
     vector<int> left(n), right(n, n);
     stack<int> mono_stack;
     for (int i = 0; i < n; ++i) {
         while(! mono_stack.empty() && nums[mono_stack.top()] >= nums[i]) {

         }
     }

 }

 // leetcode90 // 没有重复的元素
vector<vector<int>> leetcode90::subsetwithDup(vector<int> &nums) {
    if (nums.size() == 0) {
        return ans;
    }
    sort(nums.begin(), nums.end());
    vector<int> temp;
    vector<bool> used(nums.size(), false);
    int curposi = 0;
    dfs(nums, temp, curposi, used);
    cout << "passed in 3975" << endl;
    for (int i = 0; i < ans.size(); ++i) {
        vector<int> temp_ans = ans[i];
        for (int j = 0; j < temp_ans.size(); ++j) {
            cout << temp_ans[j] << " "; 
        }
        cout << endl;
    }
    cout << endl;
    cout << "the size of ans: " << ans.size() << endl;
    return ans;
}


//

void leetcode90::dfs(vector<int> &nums, vector<int> &temp, int posi, vector<bool> &used) {
    ans.push_back(temp);

    for (int i = posi; i < nums.size(); ++i) {
        cout << "the i: " << i << endl;
        temp.push_back(nums[i]);
        used[i] = true;
        dfs(nums, temp, i + 1, used);
        temp.pop_back();
        used[i] = false;
        // 去除重复
        while( i < nums.size() - 1 && nums[i] == nums[i + 1]) {
            ++i;
        }

    }

}

// leetcode92  反转链表2

Node* leetcode92::reverseBetween(Node *head, int m, int n) {
   if (m == n || !head->next) {
       return head;
   }
   Node *prehead = head;
   cout << "pass in 4018" << endl;
   Node *p = prehead, *q = head;
   for (int i = 1; i < n; ++i) {
       p = p->next; // 翻转前一个
   }
   cout << "pass in 4023" << endl;
   q = p->next;
   int i = n - m -1;
   while(i -- ) {
       Node *t = q->next;  // 头插法
       q->next = t->next;
       t->next = p->next;
       p->next = t;
   }
   cout << "pass in 4030" << endl;
   Node *temp = head;
   while(temp->next) {
       cout << temp->next->val << " ";
       temp = temp->next;
   }
   cout << endl;
    return head;
}

// 递归实现

Node* leetcode92::reverseBetween2(Node *head, int m, int n) {
    // Node* successor = nullptr;
    // base case
    if (m == 0) {
        return reverseN(head, n);
    }
    // 前进到反转的起点触发base_case
    head->next = reverseBetween2(head->next, m -1, n -1);
    cout << "pass in 4030" << endl;
    // Node *temp = head;
    // cout << "the res: " << endl;
    // while(temp->next) {
    //    cout << temp->next->val << " ";
    //    temp = temp->next;
    // }
    // cout << endl;
    return head;

}
Node* leetcode92::reverseN(Node *head_m, int n) {
    if (n == 0) {
        successor = head_m->next;
        return head_m;
    }
    Node* last = reverseN(head_m->next, n -1);
    head_m->next->next = head_m;
    head_m->next = successor;
    return last;
}

// leetcode94 二叉树的中序遍历
void leetcode94::inorder(Bitnode<char> *root, vector<char> &res) {
    if (!root) {
        return;
    }
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
}

// 

void leetcode94::inorderTravel(Bitnode<char> *root) {
    vector<char> res;
    inorder(root, res);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
    cout << endl;
    return;
}

//  leetcode120 

int leetcode120::minisumTotal(vector<vector<int>> &triangle) {
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n));
    dp[0][0] = triangle[0][0];
    cout << "passed in 4102" << endl;
    for (int i = 1; i < n; ++i) {
        // j = 0 , dp[i-1][j-1] 没有意义
        dp[i][0] = dp[i-1][0] + triangle[i][0];
        for (int j = 1; j < i; ++j) {
            dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];
        }
        // 当 i= j时， 上一行i-1 行， 将 j最大为 i-1
        dp[i][i] = dp[i-1][i-1] + triangle[i][i];
    }
    cout << "passed in 4111." << endl;
    int ans = *min_element(dp[n-1].begin(), dp[n-1].end());
    cout << "the ans: " << ans << endl;
    return ans;

}

// leetcode121 买卖股票的最佳时机

int leetcode121::maxProfit(vector<int> &prices) {
   int inf = 1e9;
   // 用最低的价格买入，然后计算在该天卖出的利润，求利润的最大值
   int minprices = inf, maxprofit = 0;
   for (int price: prices) {
        maxprofit = max(maxprofit, price - minprices);
        cout << "the maxprofit: " << maxprofit << endl;
        minprices = min(price, minprices);
        cout << "the the minprice: " << minprices << endl;
   }

   cout << "the ans: " << maxprofit << endl;

   return maxprofit;

}
         
// leetcode122 买卖股票的最佳时机2
// dp[i][0] 表示 第i天交易完后手里没有股票的最大利润 
// dp[i][1] 表示 第i天交易完后手里有股票的最大利润
// dp[i][0] = max(dp[i-1][0], dp[i-1][1] + prices[i] )
// dp[i][1] = max(dp[i-1][1], dp[i-1][0] - prices[i] )
int leetcode122::maxProfit(vector<int> &profit) {
    int n = profit.size();
    vector<vector<int>> dp(n, vector<int> (2, 0));
    dp[0][0] = 0, dp[0][1] = -profit[0];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = max(dp[i-1][0], dp[i-1][1] + profit[i] );

        dp[i][1] = max(dp[i-1][1], dp[i-1][0] - profit[i] );
    }

    cout << "the maxprofit: " << dp[n-1][0] << endl;
    return dp[n-1][0];
}