//
//  ITP2_2_D.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/10.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <list>

using namespace std;
#define MAX 1000

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q,command,t,x,s;
    list<int>myList[MAX];
    cin >> n >> q;
    
    for (int i = 0;i < q;++i) {
        cin >> command;
        switch(command){
                // insert
            case 0:
                cin >> t >> x;
                myList[t].insert(myList[t].end(), x);
                break;
                // get max
            case 1:
                cin >> t;
                if(!myList[t].empty()){
                    for(auto it = myList[t].begin();it != myList[t].end();++it){
                        cout << *it;
                        
                        if(++it != myList[t].end()){
                            cout << " ";
                        }
                        it--;
                    }
                }
                cout << endl;                
                break;
                // splice
            case 2:
                cin >> s >> t;
                if(!myList[s].empty()){
                    myList[t].splice(myList[t].end(), myList[s]);
                }
                break;
        }
    }
}
