//
//  DSL_5_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/12/14.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <algorithm>
#include <stdio.h>
using namespace std;

int getMaxOverlapedNum(int start[], int end[],int n){
    int maxOverlap = 0,currentOverlap = 0,i = 0,j = 0;
    sort(start,start + n);
    sort(end,end + n);
    
    while(i < n && j < n){
        if(start[i] < end[j]){
            currentOverlap++;
            maxOverlap = max(maxOverlap, currentOverlap);
            i++;
        }
        else{
            currentOverlap--;
            j++;
        }
    }
    return maxOverlap;
}

int main(){
    int n,t;
    scanf("%d %d",&n,&t);
    int begin[n],end[n];

    for(int i = 0;i < n;i++){
        scanf("%d %d",&begin[i],&end[i]);
    }
    printf("%d\n",getMaxOverlapedNum(begin,end,n));
}
