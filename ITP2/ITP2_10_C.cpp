//
//  ITP2_10_C.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/21.
//  Copyright © 2019 jiji4000. All rights reserved.
//
#include <iostream>
#include <bitset>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,command;
    unsigned long num = 0,one = 1,index;
    cin >> n;
    
    for(int i = 0;i < n;++i){
        cin >> command;
        switch (command) {
            // test(i): i番目のフラグの状態がONの場合1、OFFの場合0を出力する
            case 0:{
                cin >> index;
                index = one << index;
                bool on = (num & index) > 0 ? true : false;
                cout << on << endl;
                break;
            // set(i): i番目のフラグをONにする
            }
            case 1:
                cin >> index;
                index = one << index;
                num = index | num;
                break;
            // clear(i): i番目のフラグをOFFにする
            case 2:
                cin >> index;
                index = ~(one << index);
                num = index & num;
                break;
            // flip(i): i番目のフラグを反転する
            case 3:
                cin >> index;
                index = one << index;
                num = index ^ num;
                break;
            // all: 全てのフラグがONになっている場合1、なっていない場合0を出力する
            case 4:
                cout << (num == __UINT_LEAST64_MAX__) << endl;
                break;
            // any: 何れかのフラグがONになっている場合1、なっていない場合0を出力する
            case 5:
                cout << (num != 0) << endl;
                break;
            // none: 全てのフラグがOFFになっている場合1、なっていない場合0を出力する
            case 6:
                cout << (num == 0) << endl;
                break;
            // count: ONになっているフラグの数を出力する
            case 7:{
                int bitNum = 0;
                unsigned long bit = one;
                for(int i = 0;i < 64;++i){
                    bit = one << i;
                    bool on = (num & bit) > 0 ? true : false;
                    if(on){
                        bitNum++;
                    }
                }
                cout << bitNum << endl;
                break;
            }
            // val: 状態の整数値を出力する
            default:
                cout << num << endl;
                break;
        }
    }
}
