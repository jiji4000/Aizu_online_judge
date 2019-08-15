//
//  Coins.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/08/14.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>

using namespace std;

int main(){
    int a,b,c,sum;
    int success = 0;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> sum;
    
    // 500
    for(int i = 0;i <= a;++i){
        if(i != 0){
            sum -= 500;
            if(sum == 0){
                success++;
                i = a;
            }
            if(sum < 0){
                break;
            }
        }
        // 100
        for(int j = 0;j <= b;++j){
            if(j != 0){
                sum -= 100;
                if(sum == 0){
                    success++;
                    sum += j * 100;
                    j = b;
                    break;
                }
                else if(sum < 0){
                    sum += j * 100;
                    break;
                }
            }
            // 50
            for(int k = 0;k < c;++k){
                sum -= 50;
                if(sum == 0){
                    success++;
                    sum += (k + 1) * 50;
                    k = c;
                    break;
                }
                else if(sum < 0){
                    break;
                }
                // 戻す
                if(k + 1 >= c){
                    sum += (k + 1) * 50;
                }
            }
            if(j + 1 > b){
                sum += j * 100;
            }
        }
    }
    
    cout << success << endl;
    return 0;
}
