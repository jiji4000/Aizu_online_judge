//
//  ALDS1_7_C.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/09/05.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include<iostream>

using namespace std;

// node最大量
#define MAX 100005
#define NIL -1

struct Node {
    int parent;
    int left;
    int right;
};

// 配列で保持する
Node gNode[MAX];
int n;

/**
    根→左→右の順番で出力する
*/
void preOrder(int node){
    // 根である自身を出力する
    cout << " " << node;
    // 左
    if(gNode[node].left != NIL){
        preOrder(gNode[node].left);
    }
    // 右
    if(gNode[node].right != NIL){
        preOrder(gNode[node].right);
    }
}

/**
    左部分木 → 根節点 → 右部分木の順番で節点をまわること
*/
void inOrder(int node){
    if(node == NIL){
        return;
    }
    // 左を探す
    if(gNode[node].left != NIL){
        inOrder(gNode[node].left);
    }
    // 左がなくなったら左を出力する
    cout << " " << node;
    // 右
    if(gNode[node].right != NIL){
        inOrder(gNode[node].right);
    }
}

/**
    左部分木 → 右部分木 → 根節点の順番
*/
void postOrder(int node){
    if(node == NIL){
        return;
    }
    // 左を探す
    if(gNode[node].left != NIL){
        postOrder(gNode[node].left);
    }
    // 右
    if(gNode[node].right != NIL){
        postOrder(gNode[node].right);
    }
    // 右がなくなったら右を出力する
    cout << " " << node;
}

int main(){
    int leftIndex,rightIndex,nodeIndex,node,root;
    leftIndex = rightIndex = nodeIndex = node = root = 0;
    
    cin >> n;
    // 1.初期化
    for(int i = 0;i < n;++i){
        gNode[i].parent = gNode[i].left = gNode[i].right = NIL;
    }
    // 2.nodeに代入していく
    for(int i = 0;i < n;++i){
        cin >> nodeIndex >> leftIndex >> rightIndex;
        gNode[nodeIndex].left = leftIndex;
        gNode[nodeIndex].right = rightIndex;
        
        if(leftIndex != NIL){
            gNode[leftIndex].parent = nodeIndex;
        }
        if(rightIndex != NIL){
            gNode[rightIndex].parent = nodeIndex;
        }
    }
    
    // 3.rootを探す
    for(int i = 0;i < n;++i){
        if(gNode[i].parent == NIL){
            root = i;
            break;
        }
    }

    // 木の先行巡順回
    cout << "Preorder" << endl;
    preOrder(root);
    cout << endl;
    // 木の中間巡順回
    cout << "Inorder" << endl;
    inOrder(root);
    cout << endl;
    // 木の後行巡順回
    cout << "Postorder" << endl;
    postOrder(root);
    cout << endl;
    
    return 0;
}
