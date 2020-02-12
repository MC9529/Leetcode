#include "BiTree.h"
using namespace std;

/*
template<typename T>
Tree<T>::Tree() {
    T ch[100];
    cin.get(ch, 100);
    int num = 0;
    m_root = createTree(ch, num);
}

template<typename T>
Tree<T>::~Tree() {
    Release(m_root);
}
//创建
template<typename T>
Bitnode<T>* Tree<T>::createTree(T X[], int &n) {
    T ch = X[n];
    n ++;
    if (ch == '#') {
        return NULL;
    } else {
        Bitnode<T> *node = new Bitnode<T>(ch);
        node->left = createTree(X, n);
        node->right = createTree(X, n);
        return node;
    }
}
//删除
template<typename T>
void Tree<T>::Release(Bitnode<T>* root) {
    if (root != NULL) {
        Release(root->left);
        Release(root->right);
        delete root;
    }

}
//前序遍历
template<typename T>
void Tree<T>::PreOrder(Bitnode<T>* node) {
    if (node == NULL) {
        return;
    } else {
        cout << "the val in PreOrder:" << node->val << endl;
        PreOrder(node->left);
        PreOrder(node->right);
    }

}
//中序遍历
template<typename T>
void Tree<T>::InOrder(Bitnode<T>* node) {
    if (node == NULL) {
        return;
    } else {
        InOrder(node->left);
        cout << "the val in InOrder: " << node->val << endl;
        InOrder(node->right);
    }

}
    //后序遍历
template<typename T>
void Tree<T>::PostOrder(Bitnode<T>* node) {
    if (node == NULL) {
        return;
    } else {
        PostOrder(node->left);
        PostOrder(node->right);
        cout << "the val in PostOrder: " << node->val << endl;
    }

}
    //层次遍历
template<typename T>
void Tree<T>::PrintNode(Bitnode<T>* node) {
    vector<Bitnode<T>*> vec;
    vec.push_back(node);
    int cur = 0; // 保存的是之前的层的节点数
    int last = 1; // 加上待遍历层的节点数
    while (cur < vec.size()) {
        last = vec.size(); //重新置上一层节点数
        while (cur < last) {  // 计数还么到
            cout << vec[cur]->val << " "; //访问
            if (vec[cur]->left) { //不为空则压入
                vec.push_back(vec[cur]->left);
            }
            if (vec[cur]->right) { // 不为空则压入
                vec.push_back(vec[cur]->right);
            }
            cur ++; //层数加1
        }
        cout << endl; // cur = last 都已经被遍历完事了
    }

}
//根节点
template<typename T>
Bitnode<T>* Tree<T>::GetRoot() {
    return m_root;
}
*/