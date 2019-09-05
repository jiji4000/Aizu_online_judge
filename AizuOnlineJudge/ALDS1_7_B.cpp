//
//  ALDS1_7_B.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/09/04.
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
int gDepth[MAX];
int gHeight[MAX];
int n;

/**
 兄弟の番号を返す
 */
int getSibling(int u){
    int parent = gNode[u].parent;
    if(parent != NIL){
        // 自分と同じ番号でない、もしくはnil出ない場合兄弟になる
        if(gNode[parent].left != u && gNode[parent].left != NIL){
            return gNode[parent].left;
        }
        else if(gNode[parent].right != u && gNode[parent].right != NIL){
            return gNode[parent].right;
        }
    }
    return NIL;
}

/**
  子の数を返す
*/
int getDegree(int u){
    int degreeNum = 0;
    if(gNode[u].left != NIL){
        degreeNum++;
    }
    if(gNode[u].right != NIL){
        degreeNum++;
    }
    return degreeNum;
}

void print(int node){
    cout << "node " << node << ": ";
    cout << "parent = " << gNode[node].parent << ", ";
    cout << "sibling = " << getSibling(node) << ", ";
    cout << "degree = " << getDegree(node) << ", ";
    cout << "depth = " << gDepth[node] << ", ";
    cout << "height = " << gHeight[node] << ", ";
    
    if(gNode[node].parent == NIL) {
        cout << "root" << endl;
    }
    else if(gNode[node].left == NIL && gNode[node].right == NIL){
        cout << "leaf" << endl;
    }
    else cout << "internal node" << endl;
}

/**
    再帰的に高さを求める
*/
int setHeight(int u){
    int leftHeight = 0,rightHeight = 0;
    if(gNode[u].left != NIL){
        leftHeight = setHeight(gNode[u].left) + 1;
    }
    if(gNode[u].right != NIL){
        rightHeight = setHeight(gNode[u].right) + 1;
    }
    return gHeight[u] = max(leftHeight,rightHeight);
}

// 再帰的に深さを求める
void rec(int node ,int parent){
    gDepth[node] = parent;
    
    if(gNode[node].left != NIL){
        // 最も左の子に自分の深さ+1を設定
        rec(gNode[node].left,parent + 1);
    }
    if(gNode[node].right != NIL){
        rec(gNode[node].right,parent + 1);
    }
}

int main(){
    int leftIndex,rightIndex,nodeIndex,node,root,left = 0;
    
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
    // 根からはじめて深さを代入する
    rec(root,0);
    // 高さ代入
    setHeight(root);
    
    // 4.nodeのindexごとに出力する
    for(int i = 0;i < n;++i){
        print(i);
    }
    return 0;
}
