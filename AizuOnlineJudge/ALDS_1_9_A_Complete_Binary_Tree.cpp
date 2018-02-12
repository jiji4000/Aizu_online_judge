//
//  main.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2018/02/12.
//  Copyright © 2018年 jiji4000. All rights reserved.
//

#include <iostream>
using namespace std;

#define MAX 100000

int parent(int i){
    return i / 2;
}

int left(int i){
    return 2 * i;
}

int right(int i){
    return (2 * i) + 1;
}

int main(int argc, const char * argv[]) {
    int num,Heap[MAX + 1];
    
    cin >> num;
    for(int i = 1;i <= num;++i){
        cin >> Heap[i];
    }
    
    for(int i = 1;i <= num;++i){
        cout << "node " << i << ": key = " << Heap[i] << ", ";
        if(parent(i) >= 1) cout << "parent key = " << Heap[parent(i)] << ", ";
        if(left(i) <= num) cout << "left key = " << Heap[left(i)] << ", ";
        if(right(i) <= num) cout << "right key = " << Heap[right(i)] << ", ";
        cout << endl;
    }
    
    return 0;
}
