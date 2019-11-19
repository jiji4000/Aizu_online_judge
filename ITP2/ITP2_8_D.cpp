//
//  ITP2_8_D.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/19.
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
    multimap<string,int> myMap;
    cin >> n;
    
    for(int i = 0;i < n;++i){
        cin >> command;
        // insert
        if(command == 0){
            cin >> key >> x;
            myMap.insert(pair<string,int>(key,x));
            // find
        }else if(command == 1){
            cin >> key;
            map<string,int>::iterator begin = myMap.find(key);
            unsigned long cnt = myMap.count(key);
            for(int i = 0;i < cnt;++i){
                cout << begin->second << endl;
                ++begin;
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
