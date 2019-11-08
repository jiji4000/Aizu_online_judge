//
//  ITP2_2_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/08.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <stack>

using namespace std;
#define MAX 1000

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q,command,t,x;
    stack<int> myStack[MAX];
    cin >> n >> q;
    
    for (int i = 0;i < q;++i) {
        cin >> command >> t;
        switch(command){
                // push
            case 0:
                cin >> x;
                myStack[t].push(x);
                break;
                // dump
            case 1:
                if(!myStack[t].empty()){
                    cout << myStack[t].top() << endl;
                }
                break;
                // clear
            case 2:
                if(!myStack[t].empty()){
                    myStack[t].pop();
                }
                break;
        }
    }
}
