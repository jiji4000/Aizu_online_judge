//
//  ALDS1_14_B.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/01.
//  Copyright © 2019 jiji4000. All rights reserved.
//


#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char t[1000001], p[10001];
    int jt[10001];
    cin.getline(t, 1000001);
    unsigned long tl= cin.gcount() - 1;
    cin.getline(p, 10001);
    unsigned long pl = cin.gcount() - 1;
    if(pl > tl) return 0;

    jt[0] = -1;
    jt[1] = 0;
    int i=2, j=0;
    while(i <= pl){
        if(p[i - 1] == p[j]){
            jt[i] = j + 1;
            ++i;
            ++j;
        } else if(j > 0){
          j = jt[j];
        }
        else {
            jt[i++] = 0;
        }
    }
    i = j = 0;
    while(i < tl){
        if(t[i] == p[j]){
            ++i;
            ++j;
            if(j == pl){
                cout << i - pl << endl;
                j = jt[j];
            }
        }else if(j==0){
          ++i;
        }
        else {
            j = jt[j];
        }
    }
}
