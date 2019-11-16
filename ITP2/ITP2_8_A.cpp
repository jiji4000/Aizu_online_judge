//
//  ITP2_8_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/17.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,command,x;
    string key;
    map<string,int> myMap;
    cin >> n;

    for(int i = 0;i < n;++i){
        cin >> command >> key;
        // insert
        if(command == 0){
            cin >> x;
            myMap[key] = x;
        }else if(command == 1){
            // find
            cout << myMap[key] << endl;
        }
    }
}
