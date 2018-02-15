//
//  ALDS_1_10_A_BibonacciNumber.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2018/02/15.
//  Copyright © 2018年 jiji4000. All rights reserved.
//

#include <iostream>
using namespace std;

int result[45];

int fib(int n){
    if(n == 0 || n == 1)return result[n] = 1;
    if(result[n] != -1) return result[n];
    return result[n] = fib(n - 1) + fib(n - 2);
}

int main(){
    int n;
    for(int i = 0;i < 45;++i){
        result[i] = -1;
    }
    cin >> n;
    cout << fib(n) << endl;
    return 0;
}
