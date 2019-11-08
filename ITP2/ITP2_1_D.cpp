//
//  ITP2_1_D.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/08.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
#define MAX 10000

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n,q,command,t,x;
    vector<int> vec[MAX];
    cin >> n >> q;
    
    for (int i = 0;i < q;++i) {
        cin >> command >> t;
        switch(command){
                // push back
            case 0:
                cin >> x;
                vec[t].push_back(x);
                break;
                // dump
            case 1:
                for(int i = 0;i < vec[t].size();++i){
                    cout << vec[t].at(i);
                    if(i + 1 < vec[t].size()){
                        cout << " ";
                    }
                }
                cout << endl;
                break;
                // clear
            case 2:
                vec[t].clear();
                break;
        }
    }
}
