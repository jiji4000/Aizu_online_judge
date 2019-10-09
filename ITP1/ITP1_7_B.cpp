//
//  ITP1_7_B.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/09.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <stdio.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int main(void){
    int n[1000];
    int x[1000];
    int num = 0;
    int answer = 0;
    
    
    while(1){
        cin >> n[num] >> x[num];
        if(n[num] == 0 && x[num] == 0){
            break;
        }
        ++num;
    }

    for(int i = 0;i < num;++i){
        int sum = 0;
        answer = 0;
        // 1つ目の数値
        for(int j = n[i];j > 0;--j){
            if(j > x[i]){
                while(j > x[i]){
                    --j;
                }
            }
            for(int k = j - 1;k > 0;--k){
                if(k + j >= x[i]){
                    while(k + j  >= x[i]){
                        --k;
                    }
                }
                
                for(int l = k - 1;l > 0;--l){
                    sum = j + k + l;
                    if(sum == x[i]){
                        answer++;
                        l = 0;
                    }
                }
            }
        }
        cout << answer << endl;
    }
    return 0;
}
