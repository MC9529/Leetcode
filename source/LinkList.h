#include <string>
#include <iostream>
using namespace std;

// 节点
struct Node {
    int val;
    Node *next;
    // Node(int x): val(x), next(NULL) {}
};


// 链表

class LinkList {
public: 
    LinkList();
    ~LinkList();
    void creatLinkList(int size);
    void creatLinkList_one(int num);
    void ByeLinkList();
    void TravelLinkList();
    void insertLinkList(int data, int posi);
    void deleteLinkLint(int n);
    
    int Getlen();
    bool Isempty();
    // 链表头
    Node *head;
    Node *current;
    // 长度
    int size;

};

int LinkList::Getlen() {
    cout << "the len : " << this->size << endl;
    return this->size;
}

bool LinkList::Isempty() {
    if (head->next == NULL) {
        cout << "this is a empty list" << endl;
        return true;
    } else {
        cout << "this is not a empty list" << endl;
        return false;
    }

}

 void  LinkList::insertLinkList(int data, int posi) {
     if (head->next == NULL) {
         cout << "this is a empty LinkList" << endl;
         return;
     }
     if (posi < 2) {
         cout << "insert in the head" << endl;
         Node *ptemp = new Node;
         ptemp->val = data;

         ptemp->next = this->head->next;

         this->head->next = ptemp;
         this->size ++;
         return;
     } else if (posi > this->size) {
         cout << "insert in the tail" << endl;
         Node *ptemp = new Node;
         ptemp->val = data;
         ptemp->next = NULL;
         current->next = ptemp;
         this->size ++;
         current = ptemp;
         return;
     } else {
         cout << "insert in the middle" << endl;
         Node *ptemp = this->head;
         for (int i = 1; i < posi; i++) {
             ptemp = ptemp->next;
         }
          Node *pnew = new Node;
          pnew->val = data;

          pnew->next = ptemp->next;
          ptemp->next = pnew;

          this->size ++;
          return;
     }

 }

 void LinkList::deleteLinkLint(int n) {
     Node *ptemp;
     Node *ptemp2;
     if (n > this->size) {
         cout << "the n is too large" << endl;
         return;
     }
     if (n < 2) {
         cout << "delete in the head" << endl;
         ptemp = this->head->next;
         this->head->next = ptemp->next;
         free(ptemp);
         this->size --;
         return;
         
     } else if (n == this->size) {
         cout << "delete in the tail" << endl;
         ptemp = this->head;
         for (int i = 1; i < this->size; ++i) {
             ptemp = ptemp->next;
         }
         ptemp2 = ptemp->next;
         ptemp->next = NULL;
         free(ptemp2);
         this->size --;
         current = ptemp;
         return;
     } else {
          cout << "delete in the middle" << endl;
          ptemp = this->head;
          for (int i = 1; i < n; ++i) {
             ptemp = ptemp->next;
          }

          ptemp2 = ptemp->next;
          ptemp->next = ptemp2->next;

          free(ptemp2);
          this->size --;
          return;

     }

 }
  
LinkList::LinkList() {
    
    head = new Node;
    head->val = 0;
    head->next = NULL;
    current = head;
    size = 0;
}

LinkList::~LinkList() {
    delete head;
}

 void LinkList::creatLinkList(int n) {
     if (n < 0) {
         cout << "the size is negative" << endl;
         return;
     }
     Node *pnew = NULL;
     Node *ptemp = NULL;

     ptemp = this->current;
     int temp;
     for (int i = 0; i < n; ++i) {
        pnew = new Node;
        pnew->next = NULL;
        cout << "输入第 " << i + 1 << "个节点值" << endl;

        cin >> temp;
        pnew->val = temp;
        ptemp->next = pnew;
        ptemp = pnew;
        this->size ++;
     }

     current = ptemp;
     cout << "创建完成" << endl;
     return;
 }

 void LinkList::creatLinkList_one(int num) {
     Node *ptemp = current;
     Node *pnew = new Node;
     pnew->next = NULL;
     pnew->val = num;
     ptemp->next = pnew;

     current = pnew;
     size ++;
     return;
 }

 void LinkList::ByeLinkList() {
     Node *ptemp;
     if(this->head == NULL) {
         cout << "this is a empty LinkList" << endl;
         return;
     }
     while (this->head->next) {
         ptemp = head->next;
         free(head);
         head = ptemp;

     }

     this->size = 0;
     cout << "destory the LinkList success" << endl;
     return;

 }

 void LinkList::TravelLinkList() {
     Node *ptemp = this->head->next;
     if (head->next == NULL) {
         cout << "this is a empty LinkList" << endl;
         return;
     }
     cout << "the res: " << endl;
     while(ptemp) {
         cout << ptemp->val << "->";
         ptemp = ptemp->next;
     }
     cout << endl;
     cout << "print all the node success" << endl;
     return;

 }