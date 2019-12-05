//
//  DSL_2_I.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/12/04.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include "stdio.h"
#include "math.h"
#include <algorithm>
using namespace std;

typedef  long long ll;
#define SUQARE_SIZE  100000

// 一括更新
ll block[SUQARE_SIZE];
ll sumBlock[SUQARE_SIZE];

int blockSize;
int n;

int getBlockIndex(int index){
    return index / blockSize;
}

// arrをblock数分だけnumで更新する
void updateArr(ll arr[],int left,ll num){
    for(int i = left;i < left + blockSize;++i){
        if(i >= n){
            break;
        }
        arr[i] = num;
    }
}

void update(ll arr[],int l, int r,int value)
{
    // 左端
    int leftBlockIndex = l % blockSize;
    // 更新がblockの先頭から始まらないケース
    if(leftBlockIndex != 0){
        // blockの値を初期化する
        int blockIndex = getBlockIndex(l);
        // blockの値が代入されていた場合はblockの値で、arrを更新する
        if(block[blockIndex] != 0){
            updateArr(arr, blockIndex * blockSize, block[blockIndex]);
            // block値を初期化
            block[blockIndex] = sumBlock[blockIndex] = 0;
        }
        // block間かつl < r間でarrを更新
        do{
            arr[l] = value;
            l++;
        }while(l % blockSize != 0 && l <= r);
    }
    
    // block間
    leftBlockIndex = l % blockSize;
    // blockの先頭かつ、block1つ分を更新できる場合
    if(leftBlockIndex == 0 && (l - 1) + blockSize <= r){
        // blockの値を更新する
        do{
            int blockIndex = getBlockIndex(l);
            block[blockIndex] = value;
            // 0の場合は更新しないので、arrを0で更新する必要がある
            if(value == 0){
                updateArr(arr, l, value);
            }
            // sumは再び計算する必要がある
            sumBlock[blockIndex] = 0;
            l += blockSize;
        }while((l - 1) + blockSize <= r);
    }
    
    // 右端の更新
    if(l <= r){
        leftBlockIndex = l % blockSize;
        int blockIndex = getBlockIndex(l);
        // blockの値が代入されていた場合はblockの値で、arrを更新する
        if(block[blockIndex] != 0){
            updateArr(arr, blockIndex * blockSize, block[blockIndex]);
            // block値を初期化
            block[blockIndex] = sumBlock[blockIndex] = 0;
        }
        // l <= r間でarrを更新
        do{
            arr[l] = value;
            l++;
        }while(l <= r);
    }
}

void updateSum(int blockIndex){
    // 配列オーバーは考慮しない
    for(int i = 0;i < blockSize;++i){
        sumBlock[blockIndex] += block[blockIndex];
    }
}

ll query(ll arr[],int l,int r){
    ll sum = 0;
    // 左端
    int leftBlockIndex = l % blockSize;
    // 更新がblockの先頭から始まらないケース
    if(leftBlockIndex != 0 && l <= r){
        // arrが更新されていなかった場合更新する
        int blockIndex = getBlockIndex(l);
        if(block[blockIndex] != 0){
            updateArr(arr, blockIndex * blockSize, block[blockIndex]);
            // block値を初期化
            block[blockIndex] = sumBlock[blockIndex] = 0;
        }
        
        // block間かつl < r間でsumを取得
        do{
            sum += arr[l];
            l++;
        }while(l % blockSize != 0 && l <= r);
    }
    
    // block間
    leftBlockIndex = l % blockSize;
    // blockの先頭かつ、block1つ分を更新できる場合
    if(leftBlockIndex == 0 && (l - 1) + blockSize <= r){
        // 合計値の更新
        do{
            int blockIndex = l / blockSize;
            // ブロックが計算されていないケース
            if(block[blockIndex] == 0){
                do{
                    sum += arr[l];
                    l++;
                }while(l % blockSize != 0);
            }
            else{
                // sumが計算されていないケース
                if(sumBlock[blockIndex] == 0){
                    updateSum(blockIndex);
                }
                sum += sumBlock[blockIndex];
                l += blockSize;
            }
        }while((l - 1) + blockSize <= r);
    }
    
    // 右端の更新
    if(l <= r){
        // arrが更新されていなかった場合更新する
        int blockIndex = getBlockIndex(l);
        if(block[blockIndex] != 0){
            updateArr(arr, blockIndex * blockSize, block[blockIndex]);
            // block値を初期化
            block[blockIndex] = sumBlock[blockIndex] = 0;
        }
        // l <＝= r間でsumを更新
        do{
            sum += arr[l];
            l++;
        }while(l <= r);
    }
    return sum;
}

int main(){
    int q,command,l,r,x;
    scanf("%d %d",&n,&q);
    ll a[n];
    blockSize = sqrt(n);
    
    for(int i = 0;i < n;++i){
        a[i] = block[i] = sumBlock[i] = 0;
    }

    for(int i = 0;i < q;++i){
        scanf("%d" "%d" "%d",&command,&l,&r);
        // update(s,t,x): as,as+1,...,at をxに変更する。
        if(command == 0){
            scanf("%d",&x);
            update(a,l,r,x);
        // getSum(s,t):as,as+1,...,at の合計値を出力する。
        }else{
            printf("%lld\n",query(a,l,r));
        }
    }
}
