//
//  ITP2_9_B.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/20.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <set>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n1,num;
    set<int> set1;
    cin >> n1;
    
    for(int i = 0;i < n1;++i){
        cin >> num;
        set1.insert(num);
    }
    
    cin >> n1;
    for(int i = 0;i < n1;++i){
        cin >> num;
        if(!set1.insert(num).second){
            cout << num << endl;
        }
    }
}
