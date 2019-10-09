//
//  ITP1_7_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/09.
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
    int m[1000];
    int f[1000];
    int r[1000];
    char grade[1000];
    int i = 0;
    
    while(1){
        cin >> m[i] >> f[i] >> r[i];
        if(m[i] == -1 && f[i] == -1 && r[i] == -1){
            break;
        }
        ++i;
    }
    
    // ランクのを表示する
    for(int k = 0;k < i;++k){
        int totalScore = m[k] + f[k];
        if(m[k] == -1 || f[k] == -1){
            grade[k] = 'F';
        }
        else if(totalScore >= 80){
            grade[k] = 'A';
        }
        else if(totalScore >= 65){
            grade[k] = 'B';
        }
        else if(totalScore >= 50){
            grade[k] = 'C';
        }
        else if(totalScore >= 30 && r[k] >= 50){
            grade[k] = 'C';
        }
        else if(totalScore >= 30){
            grade[k] = 'D';
        }
        else{
            grade[k] = 'F';
        }
        
        cout << grade[k] << endl;
    }
    
    return 0;
}
