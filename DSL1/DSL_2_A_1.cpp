//
//  DSL_2_A.cpp
//  AizuOnlineJudge
//
//  Created by jiji on 2019/11/27.
//  Copyright © 2019 jiji4000. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;
#define MAX 100000



// lookup[i][j] is going to store index of minimum value in
// arr[i..j]
int lookup[MAX][MAX];

void updateTable(int arr[],int n)
{
    // Initialize lookup[][] for the intervals with length 1
    for (int i = 0; i < n; i++)
        lookup[i][i] = i;
    
    // Fill rest of the entries in bottom up manner
    for (int i = 0;i < n;++i)
    {
        for(int j = i + 1;j < n;++j){
            
            // To find minimum of [0,4], we compare minimum of
            // arr[lookup[0][3]] with arr[4].
            if (arr[lookup[i][j - 1]] < arr[j])
                lookup[i][j] = lookup[i][j - 1];
            else
                lookup[i][j] = j;
        }
    }
}

int find(int arr[],int l,int r){
    return arr[lookup[l][r]];
}

int main()
{
    int n,q,x,y,c;
    cin >> n >> q;
    int nums[n];
    for(int i = 0;i < n;++i){
        nums[n] = pow(2,31) - 1;
    }
    for(int i = 0;i < q;++i){
        cin >> c >> x >> y;
        switch(c){
                // update
            case 0:
                nums[x] = y;
                updateTable(nums, n);
                break;
                // find
            case 1:
                cout << find(nums,x,y) << endl;
                break;
        }
    }
}
