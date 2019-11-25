//
//  ITP1_7_D.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/10.
//  Copyright © 2019 jiji4000. All rights reserved.
//

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
    int matrix[100][100];
    int matrix2[100][100];
    int n,m,l;

    cin >> n >> m >> l;

    // matrix1
    for(int i = 0;i < n;++i){
        for(int j = 0;j < m;++j){
            cin >> matrix[i][j];
        }
    }
    
    // matrix2
    for(int i = 0;i < m;++i){
        for(int j = 0;j < l;++j){
            cin >> matrix2[i][j];
        }
    }

    // 計算
    // n = 3 m = 2 l = 3
    for(int i = 0;i < n;++i){
        for(int j = 0;j < l;++j){
            long long int num = 0;
            for(int k = 0;k < m;++k){
                num += matrix[i][k] * matrix2[k][j];
            }
            cout << num;
            if(j + 1 < l){
                cout << " ";
            }
        }
        cout << endl;
    }

    return 0;
}
