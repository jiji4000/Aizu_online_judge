//
//  ALDS1_13_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/08/07.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <stdio.h>
#include <iostream>

using namespace std;

#define N 8
#define FREE -1
#define NOT_FREE 1

int row[N],col[N],dpos[2 * N - 1],dneg[2 * N - 1];

// 入力時に置かれたqueenを記録しておく配列,true = queenが置かれた
bool X[N][N];

void init(){
    for(int i = 0;i < N;++i){
        row[i] = col[i] = FREE;
    }
    for(int i = 0;i < 2 * N - 1;++i){
        dpos[i] = dneg[i] = FREE;
    }
    
    for(int i = 0;i < N;++i){
        for(int j = 0;j < N;++j){
            X[i][j] = false;
        }
    }
}

/**
 出力関数
*/
void printBoard(){
    for(int i = 0;i < N;++i){
        for(int j = 0;j < N;++j){
            if(X[i][j]){
                if(row[i] != j){
                    return;
                }
            }
        }
    }
    
    for(int i = 0;i < N;++i){
        for(int j = 0;j < N;++j){
            cout << ((row[i] == j) ?  "Q" : ".");
        }
        cout << endl;
    }
}

void recursive(int i){
    // 最後の行までクイーンを置くことができた
    if(i == N){
        printBoard();
        return;
    }
    
    for(int j = 0;j < N;++j){
        // (i,j)が他のクイーンに襲撃されている場合は飛ばす
        if(col[j]  == NOT_FREE || dpos[i + j] == NOT_FREE || dneg[i - j + N - 1] == NOT_FREE){
            continue;
        }
        // (i,j)にクイーンを配置する
        row[i] = j;
        col[j] = dpos[i + j] = dneg[i - j + N - 1] = NOT_FREE;
        // 次の行を試す
        recursive(i + 1);
        // 次の行がダメだった場合(i,j)に配置されたクイーンを取り除く
        row[i] = j;
        col[j] = dpos[i + j] = dneg[i - j + N - 1] = FREE;
    }
    // クイーンの配置に失敗した
}

int main(){
    init();
    
    int k;
    cin >> k;
    for(int i = 0;i < k;++i){
        int r,c;
        cin >> r >> c;
        X[r][c] = true;
    }
    
    recursive(0);
    
    return 0;
}
