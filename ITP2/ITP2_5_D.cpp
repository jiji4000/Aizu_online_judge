//
//  ITP2_5_D.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/15.
//  Copyright © 2019 jiji4000. All rights reserved.
//
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int>v;
    for (int i = 0;i < n;++i) {
        v.push_back(i + 1);
    }
    while(1){
        for(int i = 0;i < n;++i){
            if(i){
                cout << " ";
            }
            cout << v[i];
        }
        cout << endl;
        if(!next_permutation(v.begin(),v.end())){
            break;
        }
    }
}
