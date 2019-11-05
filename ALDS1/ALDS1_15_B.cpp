//
//  ALDS_1_15_B.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/05.
//  Copyright © 2019 jiji4000. All rights reserved.
//
#include<iostream>
#include<algorithm>
#include"stdio.h"
using namespace std;

#define N 100000
struct object{
    int weight;
    int price;
    
    bool operator < (const object &o) const {
        return (double)price / (double)weight > (double)o.price / (double)o.weight;
    }
};

int main(void){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,weight,index = 0;
    double totalPrice = 0;
    object o[N];
    cin >> n >> weight;
    
    for(int i = 0;i < n;++i){
        cin >> o[i].price >> o[i].weight;
    }
    
    sort(o,o + n);
    while(1){
        if(weight > o[index].weight){
            weight -= o[index].weight;
            totalPrice += o[index].price;
            if(index++ >= n){
                break;
            }
        }
        else{
            totalPrice += ((double)o[index].price / (double)o[index].weight * (double)weight);
            break;
        }
    }
    printf("%.8lf\n",totalPrice);
}
