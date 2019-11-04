//
//  ALDS1_14_C.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/04.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include<iostream>

using namespace std;

#define MAX 1010
typedef unsigned long long ull;

int H,W,R,C;
char field[MAX][MAX],pattern[MAX][MAX];
ull hash1[MAX][MAX],tmp[MAX][MAX];

void compute_hash(char a[MAX][MAX],int w,int h){
    const ull B1 = 9999973;
    const ull B2 = 950527;
    
    ull t1 = 1;
    // ハッシュ作成列
    for(int j = 0; j < C ; ++j) t1 *= B1;
    
    for(int i = 0; i < w ; ++i){
        ull e = 0;
        for(int j = 0; j < C ; ++j){
          e = e * B1 + a[i][j];
        }
        for(int j = 0; j + C <= h; ++j){
            tmp[i][j] = e;
            if(j + C < h) e = e * B1 - t1 * a[i][j] + a[i][j + C];
        }
    }
    
    // ハッシュ作成行
    ull t2 = 1;
    for(int i = 0 ; i < R ; ++i) t2 *= B2;
    
    for(int j = 0 ; j + C <= h ; ++j){
        ull e = 0;
        for(int i = 0 ; i < R ; ++i) e = e * B2 + tmp[i][j];
        
        for(int i = 0 ; i + R <= w; ++i){
            hash1[i][j] = e;
            if(i + R < w) e = e * B2 - t2 * tmp[i][j] + tmp[i + R][j];
        }
    }
}

void solve(){
    compute_hash(pattern, R, C);
    ull res = hash1[0][0];
    compute_hash(field, W, H);
    for(int i = 0 ; i <= W ; ++i){
        for(int j = 0 ; j <= H ; ++j){
            if(res == hash1[i][j]){
                cout << i << " " << j << endl;
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cin >> W >> H;
    for(int i = 0 ; i < W ; ++i){
        for(int j = 0 ; j < H ; j++){
            cin >> field[i][j];
        }
    }
    cin >> R >> C;
    for(int i = 0 ; i < R ;++i){
        for(int j = 0 ; j < C ;++j){
            cin >> pattern[i][j];
        }
    }
    if(W < R && H < C) return 0;
    solve();
}
