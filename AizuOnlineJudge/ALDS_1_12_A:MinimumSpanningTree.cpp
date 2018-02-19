//
//  ALDS_1_12_A:MinimumSpanningTree.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2018/02/19.
//  Copyright © 2018年 jiji4000. All rights reserved.
//

#include <iostream>
using namespace std;

#define MAX 100
#define INFTY 1 << 21
// 未訪問状態
#define WHITE 0
#define GRAY 1
#define BLACK 2

// 隣接行列
int gMatrix[MAX][MAX];

int prim(int n){
    // 頂点
    int u;
    // 最小の重み
    int minV;
    // Tに属する頂点と(V - T)に属する頂点をつなぐ辺の中で、重みが最小の辺の重みを記録する
    int weight[MAX];
    // MSTにおける頂点vの親を記録する
    int parent[MAX];
    // 訪問状態を記録する
    int color[MAX];
    // 初期化
    for(int i = 0;i < n;++i){
        weight[i] = INFTY;
        parent[i] = -1;
        color[i] = WHITE;
    }
    // 初回探索地点をindex0にする
    weight[0] = 0;
    
    while(1){
        minV = INFTY;
        u = -1;
        // 隣接する地点で
        for(int i = 0;i < n;++i){
            if(minV > weight[i] && color[i] != BLACK){
                // 最小の重みを記録する
                u = i;
                minV = weight[i];
            }
        }
        // 全て訪問した
        if(u == -1)break;
        // 訪問済み
        color[u] = BLACK;
        for(int v = 0;v < n;++v){
            // uとvの間に辺が存在する
            if(color[v] != BLACK && gMatrix[u][v] != INFTY){
                if(weight[v] > gMatrix[u][v]){
                    // 隣接する辺に重みを割り当てる
                    weight[v] = gMatrix[u][v];
                    parent[v] = u;
                    color[v] = GRAY;
                }
            }
        }
    }
    int sum = 0;
    for(int i = 0;i < n;++i){
        if(parent[i] != -1) sum += gMatrix[i][parent[i]];
    }
    
    return sum;
}

int main(){
    int n;
    cin >> n;
    
    for(int i = 0;i < n;++i){
        for(int j = 0;j < n;++j){
            int edge;
            cin >> edge;
            gMatrix[i][j] = (edge == -1) ? INFTY : edge;
        }
    }
    
    cout << prim(n) << endl;
    return 0;
}
