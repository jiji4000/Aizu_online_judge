//
//  ALDS1_14_D.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/05.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include<iostream>
#include<string>
#include<algorithm>

#define MAX_N 1000005

using namespace std;
int k;
unsigned long n;
int ranks[MAX_N + 1];
int tmp[MAX_N + 1];
int sa[MAX_N + 1];

bool compare_sa(int i, int j){
    if(ranks[i] != ranks[j]){
        return ranks[i] < ranks[j];
    } else {
        int ri =( i + k <= n )? ranks[i + k] : -1;
        int rj =( j + k <= n )? ranks[j + k] : -1;
        return ri < rj;
    }
    return true;
}

void construct_sa(string s,int* sa)
{
    n = s.length();
    
    for(int i = 0; i <= n;++i)
    {
        sa[i] = i;
        ranks[i] = i < n ? s[i] : -1;
    }
    
    for(k = 1;k <= n ; k *= 2)
    {
        sort(sa,sa + n + 1,compare_sa);
        
        tmp[sa[0]] = 0;
        for(int i = 1; i <= n; ++i)
        {
            tmp[sa[i]] = tmp[sa[i -1]] + (compare_sa(sa[i - 1],sa[i]) ? 1 : 0);
        }
        for(int i = 0;i <= n;++i)
        {
            ranks[i] = tmp[i];
        }
    }
}

bool contain(string s,int* sa, string t)
{
    unsigned long a = 0;
    unsigned long b = s.length();
    while(b - a > 1)
    {
        unsigned long c = (a + b) / 2;
        
        if(s.compare(sa[c],t.length(),t) < 0) a = c;
        else b = c;
    }
    
    return (s.compare(sa[b], t.length(),t) == 0);
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string S;
    int N;
    
    cin >> S;
    cin >> N;
    
    construct_sa(S,sa);
    
    for(int i = 0 ;i < N;++i)
    {
        string T;
        cin >> T;
        if(contain(S,sa,T)) cout << 1 << endl;
        else cout << 0 << endl;
    }
}
