//
//  ITP2_11_C.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/24.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n,k;
    unsigned int bitNum = 0,maxNum = 0;
    cin >> n >> k;
    vector<int> vec(k),vec2;
    for(int i = 0;i < k;++i){
        cin >> vec[i];
        maxNum |= 1 << vec[i];
    }
    
    
    for(int i = 0;i < n;++i){
        
    }
    for(int i = 0;i < (1 << n);++i){
        if(i > maxNum){
            return 0;
        }
        for(int j = 0;j < vec.size();++j){
            int bit = 1 << vec[j];
            if(i & bit){
                bitNum |= bit;
                vec2.push_back(vec[j]);
                if(bitNum == i){
                    j = vec.size();
                }
            }
        }
        if(bitNum == i){
            cout << i << ":";
            for(int j = 0;j < vec2.size();++j){
                cout << " " << vec2[j];
            }
            cout << endl;
        }
        vec2.clear();
        bitNum = 0;
    }
}
