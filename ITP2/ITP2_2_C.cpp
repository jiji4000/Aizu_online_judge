//
//  ITP2_2_C.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/10.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <queue>

using namespace std;
#define MAX 1000

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q,command,t,x;
    priority_queue<int>queue[MAX];
    cin >> n >> q;

    for (int i = 0;i < q;++i) {
        cin >> command >> t;
        switch(command){
                // insert
            case 0:
                cin >> x;
                queue[t].push(x);
                break;
                // get max
            case 1:
                if(!queue[t].empty()){
                    cout << queue[t].top() << endl;
                }
                break;
                // delete max
            case 2:
                if(!queue[t].empty()){
                    queue[t].pop();
                }
                break;
        }
    }
}
