//
//  ITP1_6_D.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/08.
//  Copyright © 2019 jiji4000. All rights reserved.
//

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
    int matrix2[100];
    // 行がn列がm lは1列っぽい
    // 行列n * m 行列m * l print thiere product ab
    int n,m,k;
    
    cin >> n >> m;
    
    for(int i = 0;i < n;++i){
        for(int j = 0;j < m;++j){
            cin >> k;
            //cin >> matrix[i][j];
            matrix[i][j] = k;
        }
    }

    for(int i = 0;i < m;++i){
        cin >> matrix2[i];
    }

    // 計算
    for(int i = 0;i < n;++i){
        int num = 0;
        for(int j = 0;j < m;++j){
            num += matrix[i][j] * matrix2[j];
        }
        cout << num << endl;
    }

    return 0;
}
