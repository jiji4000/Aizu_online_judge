//
//  ITP2_4_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/11.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n1,n2,b,e;
    cin >> n1;
    vector<int>a(n1);
    for(int i = 0;i < n1;++i){
        cin >> a[i];
    }
    
    cin >> n2;
    for(int i = 0;i < n2;++i){
        cin >> b >> e;
        reverse(a.begin() + b,a.begin() + e);
    }
    for(int i = 0;i < n1;++i){
        cout << a[i];
        if(i + 1 < n1){
            cout << " ";
        }
    }
    cout << endl;
}
