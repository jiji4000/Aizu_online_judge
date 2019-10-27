//
//  ALDS1_6_D.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/25.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <algorithm>
using namespace std;

#define MAX 1000
// 最大入力値
#define VMAX 10001

int n;
//数列入力用
int A[MAX];
// 入力数列の中の最小値
int s;
// 入力したAをソートした配列
int B[MAX];
// 数値をINDEXとしてソートした数列がどの位置に置かれるのかを記録する
int T[VMAX];

int solve(){
    // コスト
    int ans = 0;
    // 交換終了フラグ
    bool V[MAX] = {};
    for(int i = 0;i < n;++i){
        B[i] = A[i];
    }
    // Bをソートする
    sort(B,B + n);
    
    for(int i = 0;i < n;++i){
        // ソートされた並び順ごとに順番を入れておく
        // ソートされた数列が1 3 5 7 9とするとT[1] = 0,T[3] = 1のように順番が入る
        T[B[i]] = i;
    }
    
    for(int i = 0;i < n;++i){
        if(V[i]) continue;
        // 初回は0が対象になる
        int cursor = i;
        // 1サイクルでかかるコスト
        int S = 0;
        // 1サイクルにおける最小コスト、取りうる最大数値にしておく
        int m = VMAX;
        // サイクルの長さ
        int an = 0;
        // 1サイクル処理
        while(1){
            // ソート済みフラグ
            V[cursor] = true;
            an++;
            // 対象のコスト
            int v = A[cursor];
            // 最小コスト
            m = min(m,v);
            // 最小の値においての交換を加味しないサイクルの合計コスト
            S += v;
            // 対象が置かれるべき位置を割り出すT[v]に置かれるべき1を入れています。
            cursor = T[v];
            // サイクルが終了していたら、次に移る
            if(V[cursor]) break;
        }
        // サイクル内の最小値を利用したコスト計算
        int cost1 = S + (an - 2) * m;
        // 数列の最小コストを借りた場合のコスト
        int cost2 = m + S + (an + 1) * s;
        // 最小値のコストを外から借りた場合とコストを比較する
        ans += min(cost1,cost2);
    }
    return ans;
}

int main(){
    cin >> n;
    // 最小値
    s = VMAX;
    for(int i = 0;i < n;++i){
        cin >> A[i];
        s = min(s,A[i]);
    }
    int ans = solve();
    cout << ans << endl;
}
