//
//  0089.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2020/03/29.
//  Copyright © 2020 jiji4000. All rights reserved.
//
// 参考:http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2069485#1
#include <stdio.h>
#include <stack>
#include <math.h>

using namespace std;

int main(){
    int dp[100][200],row = 0,tmp,index,width[100],maxWidth = 0, maxRowWidth;
    char buf[200];

    while(scanf("%s",buf)!=EOF){
        index = tmp = 0;
        for(int i=0;buf[i] != '\0'; i++){
            if(buf[i] >= '0' && buf[i] <= '9'){
                tmp = tmp*10 + (buf[i] - '0');
                if(buf[i+1] == '\0'){
                    dp[row][index++] = tmp;
                }
            }else{
                dp[row][index++] = tmp;
                tmp = 0;
            }
        }
        if(maxWidth < index){
            maxWidth = index;
            maxRowWidth = row;
        }

        width[row] = index;
        row++;
    }

    for(int i=1; i <= maxRowWidth; i++){
        for(int k=0; k < width[i]; k++){
            if(k == 0){
                dp[i][0] += dp[i-1][0];
            }else if(k == width[i]-1){
                dp[i][k] += dp[i-1][width[i-1]-1];
            }else{
                dp[i][k] += max(dp[i-1][k-1],dp[i-1][k]);
            }
        }
    }

    for(int i = maxRowWidth+1;i < row; i++){
        for(int k=0; k < width[i]; k++){
            dp[i][k] += max(dp[i-1][k],dp[i-1][k+1]);
        }
    }
    printf("%d\n",dp[row-1][0]);
}
