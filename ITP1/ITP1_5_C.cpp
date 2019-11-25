//
//  ITP1_5_C.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/04.
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
            // 偶数時
            if(i % 2 == 0){
                for(int j = 0;j < w;++j){
                    if(j % 2 == 0){
                        cout << "#";
                    }
                    else{
                        cout << ".";
                    }
                }
            }else{
                for(int j = 0;j < w;++j){
                    if(j % 2 == 0){
                        cout << ".";
                    }
                    else{
                        cout << "#";
                    }
                }
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
