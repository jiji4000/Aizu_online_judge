//
//  ITP2_7_C.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/16.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,command,x,l,r;
    set<int> mySet;
    set<int>::iterator begin;
    set<int>::iterator end;
    cin >> n;

    for(int i = 0;i < n;++i){
        cin >> command;
        if(command == 0){
            cin >> x;
            mySet.insert(x);
            cout << mySet.size() << endl;
        }else if(command == 1){
            cin >> x;
            bool find = mySet.find(x) != mySet.end() ? true : false;
            cout << find << endl;
        }
        else if(command == 2){
            cin >> x;
            mySet.erase(x);
        }
        else{
            cin >> l >> r;
            begin = mySet.lower_bound(l);
            end = mySet.upper_bound(r);

            for(;begin != end;++begin){
                cout << *begin << endl;
            }
        }
    }
}
