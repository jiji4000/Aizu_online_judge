//
//  DSL_3_D.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/12/11.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <stdio.h>
using namespace std;

int getMinIndex(int* arr,int l,int r){
    if(arr[l] < arr[r]){
        return l;
    }
    // 値が同じ場合は便宜上末端を返すようにする
    else{
        return r;
    }
}

int main() {
    int n,partLength,minIndex = -1;
    //cin >> n >> partLength;
    scanf("%d %d",&n,&partLength);
    int a[n];
    for(int i = 0;i < n;++i){
        //cin >> a[i];
        scanf("%d",&a[i]);
    }
    
    for(int i = 0;i + partLength - 1 < n;++i){
        // 最小値のindexが範囲外になった場合
        if(minIndex < i){
            minIndex = i;
            // 範囲内から最小のindexを探し出す奥の値を返すようにすればいいじゃねぇか
            for(int j = i + 1;j < i + partLength;++j){
                if(a[minIndex] >= a[j]){
                    minIndex = j;
                }
            }
        }
        else{
            // 最小値の値と末端の値を比べる
            minIndex = getMinIndex(a,minIndex,i + partLength - 1);
        }
        if(i){
            //cout << " ";
            printf(" ");
        }
        //cout << a[minIndex];
        printf("%d",a[minIndex]);
    }
    //cout << endl;
    printf("\n");
}
