//
//  ITP2_6_B.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/15.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,n2,index = 0,key;
    cin >> n;
    int a[n];
    for (int i = 0;i < n;++i) {
        cin >> a[i];
    }
    cin >> n2;
    for(int i = 0;i < n2;++i){
        cin >> key;
        while(1){
            if(a[index++] == key){
                break;
            }
            else if(a[index] > key || index + 1 > n){
                cout << "0" << endl;
                return 0;
            }
        }
    }
    cout << "1" << endl;
}


