//
//  ALDS1_10_C.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/02.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

#define N 1000

int lcs(string x,string y){
    int c[N + 1][N + 1] = {};
    int maxl = 0;
    x = ' ' + x; // X[0]に空白を挿入
    y = ' ' + y; // Y[0]に空白を挿入

    for(int i = 1;i <= x.size();++i){
        for(int j = 1;j <= y.size();++j){
            if(x[i] == y[j]){
                c[i][j] = c[i - 1][j - 1] + 1;
            }else{
                c[i][j] = max(c[i - 1][j],c[i][j - 1]);
            }
            maxl = max(maxl,c[i][j]);
        }
    }
    
    for(int i = 1;i <= x.size();++i){
        for(int j = 1;j <= y.size();++j){
            if(x[i] == y[j]){
                c[i][j] = c[i - 1][j - 1] + 1;
            }else{
                c[i][j] = max(c[i - 1][j],c[i][j - 1]);
            }
            maxl = max(maxl,c[i][j]);
        }
    }
    // 空白一致分
    return maxl - 1;
}

int main(){
    string s1,s2;
    int n;
    cin >> n;
    
    for(int i = 0;i < n;++i){
        cin >> s1 >> s2;
        cout << lcs(s1,s2) << endl;
    }
}
