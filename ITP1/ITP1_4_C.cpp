//
//  ITP1_4_C.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/09/30.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <iomanip>

using namespace std;

int main(void){
    int a,b,answer;
    string op;
    while(1){
        cin >> a >> op >> b;
        if(op == "/"){
            answer = a / b;
        }
        else if(op == "*"){
            answer = a * b;
        }
        else if(op == "+"){
            answer = a + b;
        }
        else if(op == "-"){
            answer = a - b;
        }
        else{
            break;
        }
        cout << answer << endl;
    }
    return 0;
}
