//
//  ITP1_7_C.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/09.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <stdio.h>
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
    int r,c;
    cin >> r >> c;
    
    int tables[1000][1000];
    
    for(int i = 0;i < r;++i){
        for(int j = 0;j < c;++j){
            cin >> tables[i][j];
        }
    }

    // 横表示
    for(int i = 0;i < r;++i){
        int sum1 = 0;
        for(int j = 0;j < c;++j){
            cout << tables[i][j] << " ";
            sum1 += tables[i][j];
        }
        cout << sum1 << endl;
        tables[i][c] = sum1;
    }
    
    // 縦表示
    for(int i = 0;i < c + 1;++i){
        int sum1 = 0;
        for(int j = 0;j < r;++j){
            sum1 += tables[j][i];
        }
        cout << sum1 ;
        if(i + 1 < c + 1){
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}
