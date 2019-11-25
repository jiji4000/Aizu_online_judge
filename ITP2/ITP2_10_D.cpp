//
//  ITP2_10_D.cpp
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
    int maskNum,commandNum,command,k;
    unsigned long num = 0,one = 1,index,bit;
    cin >> maskNum;
    unsigned long masks[maskNum];

    for(int i = 0;i < maskNum;++i){
        masks[i] = 0;
        cin >> k;
        for(int j = 0;j < k;++j){
            cin >> bit;
            bit = one << bit;
            masks[i] = masks[i] | bit;
        }
    }

    cin >> commandNum;
    for(int i = 0;i < commandNum;++i){
        cin >> command >> index;
        switch (command) {
                // test(i): i番目のフラグの状態がONの場合1、OFFの場合0を出力する
            case 0:{
                index = one << index;
                bool on = (num & index) > 0 ? true : false;
                cout << on << endl;
                break;
            }
            // set(i): i番目のフラグをONにする
            case 1:
                num = masks[index] | num;
                break;
                // clear(i): i番目のフラグをOFFにする
            case 2:
                num =  ~masks[index] & num;
                break;
                // flip(i): i番目のフラグを反転する
            case 3:
                num = masks[index] ^ num;
                break;
                // all(m): 指定されたマスクが表す部分の全てのフラグがONになっている場合1、なっていない場合0を出力する
            case 4:{
                bool isAll = (masks[index] & num) == masks[index] ? true : false;
                cout << isAll << endl;
                break;
            }
            // any: 指定されたマスクが表す部分のいずれかのフラグがONになっている場合1、なっていない場合0を出力する
            case 5:{
                bool isAny = (masks[index] & num) > 0 ? true : false;
                cout << isAny << endl;
                break;
            }
            // none(m): 指定されたマスクが表す部分の全てのフラグがOFFになっている場合1、なっていない場合0を出力する
            case 6:{
                bool isNone = (masks[index] & num) > 0 ? false : true;
                cout << isNone << endl;
                break;
            }
            // count(m): 指定されたマスクが表す部分のONになっているフラグの数を出力する
            case 7:{
                int bitNum = 0;
                unsigned long bit = one;
                for(int i = 0;i < 64;++i){
                    bit = one << i;
                    if(masks[index] & bit){
                        if((num & bit) > 0){
                            bitNum++;
                        }
                    }
                }
                cout << bitNum << endl;
                break;
            }
            // val: 状態の整数値を出力する
            default:{
                cout << (masks[index] & num) << endl;
                break;
            }
        }
    }
}
