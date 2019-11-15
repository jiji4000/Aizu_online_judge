//
//  ITP2_6_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/15.
//  Copyright © 2019 jiji4000. All rights reserved.
//


#include <iostream>
using namespace std;

bool binarySearch(int* a,int key,int length){
    int left = 0;
    int right = length;
    int center;
    
    while(left < right){
        center = (left + right) / 2;
        if(a[center] == key){
            return true;
        }
        else if(a[center] > key){
            right = center;
        }else{
            left = center + 1;
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,n2,key;
    cin >> n;
    int a[n];
    for (int i = 0;i < n;++i) {
        cin >> a[i];
    }
    cin >> n2;
    for(int i = 0;i < n2;++i){
        cin >> key;
        cout << binarySearch(a,key,n) << endl;
    }
}
