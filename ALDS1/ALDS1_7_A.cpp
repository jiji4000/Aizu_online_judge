//
//  ALDS1_7_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/09/03.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <stdio.h>
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
int gDepth[MAX];

void print(int node){
    cout << "node " << node << ": ";
    cout << "parent = " << gNode[node].parent << ", ";
    cout << "depth = " << gDepth[node] << ", ";
    
    if(gNode[node].parent == NIL) cout << "root, ";
    else if(gNode[node].left == NIL)cout << "leaf, ";
    else cout << "internal node, ";
    
    cout << "[";
    
    for(int i = 0,left = gNode[node].left;left != NIL;++i,left = gNode[left].right){
        if(i) cout << ", ";
        cout << left;
    }
    cout << "]" << endl;
}

// 再帰的に深さを求める
void rec(int node ,int parent){
    gDepth[node] = parent;
    if(gNode[node].right != NIL){
        // 右の兄弟に同じ深さを設定
        rec(gNode[node].right,parent);
    }
    // 子がある場合
    if(gNode[node].left != NIL){
        // 最も左の子に自分の深さ+1を設定
        rec(gNode[node].left,parent + 1);
    }
}

int main(){
    int nodeNum,nodeIndex,node,root,left,n = 0;
    
    cin >> n;
    // 1.初期化
    for(int i = 0;i < n;++i){
        gNode[i].parent = gNode[i].left = gNode[i].right = NIL;
    }
    // 2.nodeに代入していく
    for(int i = 0;i < n;++i){
        cin >> nodeIndex >> nodeNum;
        for(int j = 0;j < nodeNum;++j){
            cin >> node;
            // 初期値はleftに入れる
            if(j == 0){
                gNode[nodeIndex].left = node;
            }
            else{
                gNode[left].right = node;
            }
            left = node;
            gNode[node].parent = nodeIndex;
        }
    }
    
    // 3.rootを探す
    for(int i = 0;i < n;++i){
        if(gNode[i].parent == NIL){
            root = i;
        }
    }
    
    // 根からはじめて深さを代入する
    rec(root,0);
    
    // 4.nodeのindexごとに出力する
    for(int i = 0;i < n;++i){
        print(i);
    }
    return 0;
}
