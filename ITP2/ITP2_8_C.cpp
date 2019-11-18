//
//  ITP2_8_C.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/18.
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
    string key,l,r;
    map<string,int> myMap;
    cin >> n;
    
    for(int i = 0;i < n;++i){
        cin >> command;
        // insert
        if(command == 0){
            cin >> key >> x;
            myMap[key] = x;
        // find
        }else if(command == 1){
            cin >> key;
            if(myMap.count(key)){
                cout << myMap[key] << endl;
            }else{
                cout << 0 << endl;
            }
        }
        // delete
        else if(command == 2){
            cin >> key;
            myMap.erase(key);
        }
        // dump
        else if(command == 3){
            cin >> l >> r;
            map<string,int>::iterator begin,end;
            begin = myMap.lower_bound(l);
            end = myMap.upper_bound(r);
            for(;begin != end;++begin){
                cout << begin->first << " " << begin->second << endl;
            }
        }
    }
}
