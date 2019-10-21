//
//  ALDS1_6_A.cpp
//  AizuOnlineJudge
//
//  Created by 佐藤俊一朗 on 2019/10/20.
//  Copyright © 2019年 jiji4000. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <algorithm>

using namespace std;
#define VMAX 10000

int main(){
    unsigned short *A, *B, maxNum = 0;
    int C[VMAX+1] = {};
    int n;
    
    scanf("%d", &n);
    
    A = (unsigned short*)malloc(sizeof(unsigned short)*n+1);
    B = (unsigned short*)malloc(sizeof(unsigned short)*n+1);
    
    for(int i = 0;i < n;++i){
        scanf("%hu",&A[i + 1]);
        maxNum = max(maxNum,A[i + 1]);
        C[A[i + 1]]++;
    }
    
    for(int i = 1;i <= maxNum;++i){
        C[i] = C[i] + C[i - 1];
    }
    
    for(int i = 1;i <= n;++i){
        B[C[A[i]]] = A[i];
        C[A[i]]--;
    }
    
    for(int i = 1;i <= n;++i){
        if(i > 1){
            printf(" ");
        }
        printf("%d",B[i]);
    }
    printf("\n");
    return 0;
}

