//
//  ITP2_7_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/16.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,command,x;
    set<int> mySet;
    cin >> n;

    for(int i = 0;i < n;++i){
        cin >> command >> x;
        switch(command){
                // insert
            case 0:
                mySet.insert(x);
                cout << mySet.size() << endl;;
                break;
                // find
            case 1:
                bool find = mySet.find(x) != mySet.end() ? true : false;
                cout << find << endl;
                break;
        }
    }
}
