//
//  ALDS1_13_C.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/22.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <math.h>
#include <string>
#include <cassert>

using namespace std;

#define N 4
#define N2 16
#define LIMIT 100

// 逆
static const int dx[4] = {0,-1,0,1};
static const int dy[4] = {1,0,-1,0};
// right up left down
static const char dir[4] = {'r','u','l','d'};

int MDT[N2][N2];

struct Puzzle {
    int f[N2];
    int space;
    int MD;
};

Puzzle state;
int limit;
int path[LIMIT];

/**
    マンハッタンkを測る
*/
int getAllMD(Puzzle pu){
    int sum = 0;
    for(int i = 0;i < N2;++i){
        if(pu.f[i] == N2){
            continue;
        }
        sum += MDT[i][pu.f[i] - 1];
    }
    return sum;
}

bool isSolved(){
    for(int i = 0;i < N2;++i){
        // 最初の数字が1から始まるので
        if(state.f[i] != i + 1){
            return false;
        }
    }
    return true;
}

bool dfs(int depth,int prev){
    if(state.MD == 0){
        return true;
    }
    // 現在の深さにヒューリスティックを足して制限を超えたら枝を狩る
    if( depth + state.MD > limit){
        return false;
    }
    
    int sx = state.space / N;
    int sy = state.space % N;
    Puzzle tmp;
    
    for(int r = 0;r < 4;++r){
        int tx = sx + dx[r];
        int ty = sy + dy[r];
        
        // 範囲外チェック
        if(tx < 0 || ty < 0 || tx >= N || ty >= N){
            continue;
        }
        if(max(prev,r) - min(prev,r) == 2){
            continue;
        }
        tmp = state;
        // マンハッタン距離の差分を計算しつつ、ピースを入れ替える
        state.MD -= MDT[tx * N + ty][state.f[tx * N + ty] - 1];
        state.MD += MDT[sx * N + sy][state.f[tx * N + ty] - 1];
        // 入れ替え
        swap(state.f[tx * N + ty],state.f[sx * N + sy]);
        state.space = tx * N + ty;
        
        if(dfs(depth + 1,r)){
            path[depth] = r;
            return true;
        }
        state = tmp;
    }
    return false;
}

string iterativeDeepening(Puzzle in){
    // 初期状態のマンハッタン距離
    in.MD = getAllMD(in);
    
    for(limit = in.MD;limit <= LIMIT;++limit){
        state = in;
        if(dfs(0,-100)){
            string ans = "";
            for(int i = 0;i < limit;++i){
                ans += dir[path[i]];
            }
            return ans;
        }
    }
    return "unsolvable";
}

int main(){
    for(int i = 0;i < N2;++i){
        for(int j = 0;j < N2;++j){
            MDT[i][j] = fabs(i / N - j / N) + fabs(i % N - j % N);
        }
    }
    
    Puzzle in;
    
    for(int i = 0;i < N2;++i){
        cin >> in.f[i];
        if(in.f[i] == 0){
            in.f[i] = N2;
            in.space = i;
        }
    }
    string ans = iterativeDeepening(in);
    cout << ans.size() << endl;
}
