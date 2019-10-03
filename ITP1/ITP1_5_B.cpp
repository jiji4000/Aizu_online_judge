//
//  ITP1_5_B.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/03.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>
#include <vector>
#include <algorithm>

using namespace std;

int main(void){
    int h,w;
    while(1){
        cin >> h >> w;
        
        if(h == 0 && w == 0){
            break;
        }
        for(int i = 0;i < h;++i){
            // 始めと最初は#で
            if(i == 0 || (i + 1) >= h){
                for(int j = 0;j < w;++j){
                    cout << "#";
                }
            }
            else{
                for(int j = 0;j < w;++j){
                    if(j == 0 || (j + 1) >= w){
                        cout << "#";
                    }
                    else{
                        cout << ".";
                    }
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}

