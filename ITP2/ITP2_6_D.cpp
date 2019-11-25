//
//  ITP2_6_D.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/15.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
using namespace std;

int lowerBounds(int* a,int key,int length){
    // 存在しない場合
    if(a[length - 1] < key) return length;
    int left = 0;
    int right = length;
    int center;
    int targetIndex = 0;

    while(1){
        center = (left + right) / 2;
        if(a[center] == key){
            targetIndex = center;
            break;
        }
        else if(a[center] > key){
            right = center;
        }else{
            left = center + 1;
        }
        if(left >= right){
            targetIndex = right;
            break;
        }
    }

    while(targetIndex > 0){
        if(a[targetIndex - 1] < key){
            break;
        }
        targetIndex--;
    }
    return targetIndex;
}

int upperBounds(int* a,int key,int length){
    // 存在しない場合
    if(a[length - 1] <= key) return length;
    int left = 0;
    int right = length;
    int center;
    int targetIndex = 0;
    
    while(1){
        center = (left + right) / 2;
        if(a[center] == key){
            targetIndex = center;
            break;
        }
        else if(a[center] > key){
            right =  center;
        }else{
            left = center + 1;
        }
        if(left >= right){
            targetIndex = left;
            break;
        }
    }
    
    while(targetIndex < length - 1){
        if(a[targetIndex] > key){
            break;
        }
        targetIndex++;
    }
    return targetIndex;
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
        cout << lowerBounds(a,key,n) << " " << upperBounds(a,key,n) << endl;
    }
}
