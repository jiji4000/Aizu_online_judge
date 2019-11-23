//
//  ITP2_11_B.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/23.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

void print(int i,int n){
    cout << i << ":";
    for(int j = 0;j < n;++j){
        if(i & (1 << j)){
            cout << " " << j;
        }
    }
    cout << endl;
}

int main() {
    int n,k,vIndex = 0;
    cin >> n >> k;
    vector<int> vec(k);
    for(int i = 0;i < k;++i){
        cin >> vec[i];
    }
    
    for(int i = 0;i < (1 << n);++i){
        if(vec.size() != 0){
            vIndex = 0;
            for(int j = 0;j < n;++j){
                int bit = 1 << j;
                int targetBit = 1 << vec[vIndex];
                if(i & bit && bit == targetBit){
                    if(++vIndex == vec.size()){
                        j = n;
                    }
                }
            }
            
            // 部分集合だった場合
            if(vIndex == vec.size()){
                print(i,n);
            }
        }
        else{
            print(i,n);
        }
    }
}
