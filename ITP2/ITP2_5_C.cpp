//
//  ITP2_5_C.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/14.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0;i < n;++i) {
        cin >> v[i];
    }
    vector<int> p(v), nx(v);
    prev_permutation(p.begin(), p.end());
    next_permutation(nx.begin(), nx.end());
    if (p < v){
        for(int i = 0;i < n;++i){
            if(i){
                cout << " ";
            }
            cout << p[i];
        }
        cout << endl;
    }
    for(int i = 0;i < n;++i){
        if(i){
            cout << " ";
        }
        cout << v[i];
    }
    cout << endl;
    if (nx > v){
        for(int i = 0;i < n;++i){
            if(i){
                cout << " ";
            }
            cout << nx[i];
        }
        cout << endl;
    }
}
