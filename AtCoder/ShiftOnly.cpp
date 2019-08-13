//
//  ShiftOnly.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/08/13.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>

using namespace std;
int a[10000];

bool canShift(int max){
    for(int i = 0;i < max;++i){
        if(a[i] % 2 != 0){
            return false;
        }
    }
    return true;
}

void shift(int max){
    for(int i = 0;i < max;++i){
        a[i] = a[i] / 2;
    }
    
}

int main(){
    int num;
    int cnt = 0;
    cin >> num;
    
    for(int i = 0;i < num;++i){
        cin >> a[i];
    }
    
    while(canShift(num)){
        ++cnt;
        shift(num);
    }
    cout << cnt << endl;
    return 0;
}
