//
//  ITP1_6_C.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/07.
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
    
    int buildings[4][3][10];
    int num,b,f,v,r;
    
    for(int i = 0;i < 4;++i){
        for(int j = 0;j < 3;j++){
            for(int k = 0;k < 10;++k){
                buildings[i][j][k] = 0;
            }
        }
    }
    
    cin >> num;
    
    for(int i = 0;i < num;++i){
        cin >> b >> f >> r >> v;
        buildings[b - 1][f - 1][r - 1] += v;
    }
    
    for(int i = 0;i < 4;++i){
        for(int j = 0;j < 3;j++){
            for(int k = 0;k < 10;++k){
                cout << " " << buildings[i][j][k];
            }
            cout << endl;
        }
        if(i + 1 < 4){
            cout << "####################" << endl;
        }
    }
    
    return 0;
}
