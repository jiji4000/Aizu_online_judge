//
//  DPL_3_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/08/03.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <stdio.h>
#include<algorithm>
using namespace std;

#define MAX 1400

int dp[MAX][MAX],G[MAX][MAX];

int getLargestSquare(int h,int w){
    int maxWidth = 0;
    for(int i = 0;i < h;++i){
        for(int j = 0;j < w;++j){
            // 1が汚れたタイルなので、面積は0に、0は綺麗なタイルなので、面積が1になる
            dp[i][j] = (G[i][j] + 1) % 2;
            // 面積が1の場合、最大面積を計算する処理がスルーされるので、面積を暫定でいれる
            maxWidth |= dp[i][j];
        }
    }

    for(int i = 1;i < h;++i){
        for(int j = 1;j < w;++j){
            // 汚れている状態
            if(G[i][j]){
                dp[i][j] = 0;
            }else{
                // 左上,上,左の最小値の+1がdp[i][j]の正方形の最大面積となる
                dp[i][j] = min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j - 1])) + 1;
                maxWidth = max(maxWidth,dp[i][j]);
            }
        }
    }
    return maxWidth * maxWidth;
}

int main(){
    int h,w;
    scanf("%d %d",&h,&w);
    
    for(int i = 0;i < h;++i){
        for(int j = 0;j < w;++j){
            // 地面の状態
            scanf("%d",&G[i][j]);
        }
    }
    
    printf("%d\n",getLargestSquare(h,w));
    return 0;
}
