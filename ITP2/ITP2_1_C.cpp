//
//  ITP2_1_C.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/07.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <list>
#include <cmath>

using namespace  std;// namespace

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    list<int> A;
    list<int>::iterator cursor = A.end();
    int command,value;
    
    for (int i = 0;i < n;++i) {
        cin >> command;
        switch(command){
            case 0:
                cin >> value;
                cursor = A.insert(cursor,value);
                break;
            case 1:
                cin >> value;
                for (int j = 0; j < fabs(value); ++j) {
                    if(value > 0){
                        cursor++;
                    }
                    else{
                        cursor--;
                    }
                }
                break;
            case 2:
                cursor = A.erase(cursor);
                break;
        }
    }
    list<int>::iterator it = A.begin();
    for(;it!=A.end();++it){
        cout << *it << endl;
    }
}
