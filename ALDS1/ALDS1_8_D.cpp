//
//  ALDS1_8_D.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/31.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node{
    Node(int key,int priority){
        this->key = key;
        this->priority = priority;
        this->parent = NULL;
        this->left = NULL;
        this->right = NULL;
    }
    int key;
    int priority;
    Node *parent,*left,*right;
};

Node* rightRotate(Node* node);
Node* leftRotate(Node* node);
Node* deleteNode2(Node* t,int key);


Node *root;

Node* minimumTree(Node* x){
    while(x->left != NULL){
        x = x->left;
    }
    return x;
}

Node* treeSuccessor(Node *x){
    if(x->right != NULL){
        return minimumTree(x->right);
    }
    
    Node *y = x->parent;
    
    while(y != NULL && x == y->right){
        x = y;
        y = y->parent;
    }
    return y;
}

Node* deleteNode(Node* t, int key){
    if(t == NULL){
        return NULL;
    }
    if( key < t->key){                                // 削除対象を検索
        t->left = deleteNode(t->left, key);
    }
    else if( key > t->key){
        t->right = deleteNode(t->right, key);
    }
    else{
        return deleteNode2(t, key);
    }
    return t;
}

Node* deleteNode2(Node* t,int key){ // 削除対象の節点の場合
    if( t->left == NULL && t->right == NULL){           // 葉の場合
        delete t;
        return NULL;
    }
    else if( t->left == NULL){                        // 右の子のみを持つ場合左回転
        t = leftRotate(t);
    }
    else if( t->right == NULL){                       // 左の子のみを持つ場合右回転
        t = rightRotate(t);
    }
    else{                                         // 左の子と右の子を両方持つ場合
        if( t->left->priority > t->right->priority){    // 優先度が高い方を持ち上げる
            t = rightRotate(t);
        }
        else{
            t = leftRotate(t);
        }
    }
    return deleteNode(t, key);
}

Node* insert(Node* t, int key, int priority){
    if(t == NULL){
        return new Node(key, priority);              // 葉に到達したら新しい節点を生成して返す
    }
    if(key == t->key){
        return t;                                 // 重複したkeyは無視
    }
    
    if( key < t->key){                               // 左の子へ移動
        t->left = insert(t->left, key, priority);   // 左の子へのポインタを更新
        if( t->priority < t->left->priority){          // 左の子の方が優先度が高い場合右回転
            t = rightRotate(t);
        }
    }
    else{                                         // 右の子へ移動
        t->right = insert(t->right, key, priority); // 右の子へのポインタを更新
        if( t->priority < t->right->priority){         // 右の子の方が優先度が高い場合左回転
            t = leftRotate(t);
        }
    }
    
    return t;
}

/**
 根→左→右の順番で出力する
 */
void preOrder(Node* node){
    if(node == NULL){
        return;
    }
    // 根である自身を出力する
    cout << " " << node->key;
    // 左
    if(node->left != NULL){
        preOrder(node->left);
    }
    // 右
    if(node->right != NULL){
        preOrder(node->right);
    }
}

/**
 対象のキーを散策する
 キーを持つノードを返す
 */
Node* find(int key){
    Node* x = root;
    while(x != NULL && key != x->key){
        if(key < x->key){
            x = x->left;
        }
        else{
            x = x->right;
        }
    }
    return x;
}

/**
 左部分木 → 根節点 → 右部分木の順番で節点をまわること
 */
void inOrder(Node* node){
    if(node == NULL){
        return;
    }
    // 左を探す
    if(node->left != NULL){
        inOrder(node->left);
    }
    // 左がなくなったら左を出力する
    cout << " " << node->key;
    // 右
    if(node->right != NULL){
        inOrder(node->right);
    }
}

/**
    右回転
*/
Node* rightRotate(Node* node){
    Node *s = node->left;
    node->left = s->right;
    s->right = node;
    return s; // root of the subtree
}
/**
    左回転
*/
Node* leftRotate(Node* node){
    Node* s = node->right;
    node->right = s->left;
    s->left = node;
    return s; // root of the subtree
}

int main(void){
    int n,key,priority;
    
    cin >> n;
    
    for(int i = 0;i < n;++i){
        string input;
        cin >> input;
        // insert
        if(input[0] == 'i'){
            cin >> key >> priority;
            root = insert(root,key,priority);
        }
        else if(input[0] == 'f'){
            cin >> key;
            Node* node = find(key);
            if(node == NULL){
                cout << "no" << endl;
            }
            else{
                cout << "yes" << endl;
            }
        }
        else if(input[0] == 'd'){
            cin >> key;
            root = deleteNode(root, key);
        }
        else{
            inOrder(root);
            cout << endl;
            preOrder(root);
            cout << endl;
        }
    }
    return 0;
}
