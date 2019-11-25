//
//  ALDS1_7_D.cpp
//
//  Created by jiji on 2019/09/09.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include<iostream>
#include<string>
#include<algorithm>
#include<vector>

using namespace std;

int n,pos;

vector<int>preOrder,inOrder,postOrder;

void rec(int l,int r){
    if(l >= r) return;
    // preOrderの初期位置が根になる
    int root = preOrder[pos++];
    // InOrderからPreOrder巡回の根までの距離を割り出す
    int m = distance(inOrder.begin(),find(inOrder.begin(),inOrder.end(),root));
    rec(l,m);       // 左部分木を復元する
    rec(m + 1,r);   // 右部分木を復元する
    postOrder.push_back(root);
}

void solve(){
    pos = 0;
    rec(0,inOrder.size());
    for(int i = 0;i < n;++i){
        if(i) cout << " ";
        cout << postOrder[i];
    }
    cout << endl;
}

int main(){
    int k;
    cin >> n;
    
    for(int i = 0;i < n;++i){
        cin >> k;
        preOrder.push_back(k);
    }
    
    for(int i = 0;i < n;++i){
        cin >> k;
        inOrder.push_back(k);
    }
    
    solve();
    return 0;
}
