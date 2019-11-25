//
//  ITP2_1_B.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/06.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <deque>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int n,a,b,c;
    n = 0;
    cin >> n;
    deque<long> que;
    for(int i = 0;i < n;++i){
        cin >> a;
        switch(a){
                // insert
            case 0:
                cin >> b >> c;
                if(b == 0){
                    que.insert(que.begin(), c);
                }else{
                    que.insert(que.end(), c);
                }
                break;
                // random access
            case 1:
                cin >> b;
                cout << que.at(b) << endl;
                break;
                // pop
            case 2:
                cin >> b;
                if(b == 0){
                    que.pop_front();
                }
                else{
                    que.pop_back();
                }
                break;
        }
    }
}
