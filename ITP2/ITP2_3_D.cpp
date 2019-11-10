//
//  ITP2_3_D.cpp
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
    int n1,n2;
    cin >> n1;
    vector<int>a1(n1);
    for(int i = 0;i < n1;++i){
        cin >> a1[i];
    }

    cin >> n2;
    vector<int>a2(n2);
    for(int i = 0;i < n2;++i){
        cin >> a2[i];
    }
    cout << lexicographical_compare(a1.begin(),a1.end(),a2.begin(),a2.end()) << endl;
}
