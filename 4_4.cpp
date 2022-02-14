// 連結リストの実装
// Nodeのメモリを確保
#include <iostream>

using namespace std;


struct Node{
    int key;
    Node *prev, *next;
};

Node *nil; //番兵 (リストの起点となるポインタ)

void init(){
    nil = (Node *)malloc(sizeof(Node));
    nil->next = nil;
    nil->prev = nil;
}

Node* listSearch(int key){
    Node *cur = nil->next;
    while(cur != nil && cur->key != key){
        cur = cur->next;
    }
    return cur;
}

void deleteNode(Node *t){ //指定したポインタの要素を削除
    if(t == nil) return;
    t->prev->next = t->next;
    t->next->prev = t->prev;
}

void deleteKey(int key){ //要素を探して削除
    deleteNode(listSearch(key));
}

void insert(int key){
    Node *x = (Node *)malloc(sizeof(Node));
    x->key = key;
    x->next = nil->next;
    x->prev = nil;
    nil->next->prev = x;
    nil->next = x;
    
}

void pritList(){
    Node *cur = nil->next;
    while(1){
        if(cur == nil) break;
        cout << cur->key << endl;
        cur = cur->next;
    }
}


int main(){
    init();
    insert(3);
    insert(6);
    insert(7);
    pritList();
    deleteKey(3);
    pritList();
}