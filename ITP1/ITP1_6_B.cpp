//
//  ITP1_6_B.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/10/06.
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
    bool cards[4][13];
    int num;
    int cardNum;
    char c;
    
    for(int i = 0;i < 4;++i){
        for(int j = 0;j < 13;++j){
            cards[i][j] = false;
        }
    }
    
    cin >> num;
    
    for(int i = 0;i < num;++i){
        cin >> c >> cardNum;
        
        switch(c){
            case 'S':
                cards[0][cardNum - 1] = true;
                break;
            case 'H':
                cards[1][cardNum - 1] = true;
                break;
            case 'C':
                cards[2][cardNum - 1] = true;
                break;
            case 'D':
                cards[3][cardNum - 1] = true;
                break;
        }
    }
    
    for(int i = 0;i < 4;++i){
        for(int j = 0;j < 13;++j){
            if(!cards[i][j]){
                switch (i) {
                    case 0:
                        cout << "S" << " " << j + 1 << endl;
                        break;
                    case 1:
                        cout << "H" << " " << j + 1 << endl;
                        break;
                    case 2:
                        cout << "C" << " " << j + 1 << endl;
                        break;
                    case 3:
                        cout << "D" << " " << j + 1 << endl;
                        break;
                    default:
                        break;
                }
            }
        }
    }
    return 0;
}
