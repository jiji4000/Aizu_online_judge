//
//  ITP2_4_D.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/12.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n1;
    cin >> n1;
    vector<int>a1(n1);
    for(int i = 0;i < n1;++i){
        cin >> a1[i];
    }
    
    sort(a1.begin(),a1.end());
    std::vector<int>:: iterator it = unique(a1.begin(), a1.end());
    a1.resize(distance(a1.begin(), it));
    
    for(it = a1.begin();it != a1.end();++it){
        if(it != a1.begin()){
            cout << " ";
        }
        cout << *it;
    }
    cout << endl;
}
