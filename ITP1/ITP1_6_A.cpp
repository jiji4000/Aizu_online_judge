//
//  ITP1_6_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/05.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void){
    vector<int> v;
    
    int num;
    cin >> num;
    
    for(int i = 0;i < num;++i){
        int n;
        cin >> n;
        v.push_back(n);
    }
    
    bool isFirst = false;
    while (!v.empty()) {
        if(!isFirst){
            isFirst = true;
        }
        else{
            cout << " ";
        }
        cout << v.back();
        v.pop_back();
    }
    
    cout << endl;
    
    return 0;
}

