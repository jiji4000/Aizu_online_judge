////
////  ALDS_1_5_B.cpp
////  AizuOnlineJudge
////
////  Created by jiji on 2018/12/13.
////  Copyright © 2018年 jiji4000. All rights reserved.
////
//
#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX 500000
#define SENTINEL 2000000000

int LEFT[MAX / 2 + 2];
int RIGHT[MAX / 2 + 2];

int cnt = 0;

void merge(int A[],int left,int mid,int right){
    int n1 = mid - left;
    int n2 = right - mid;
    
    for(int i = 0;i < n1;++i){
        LEFT[i] = A[left + i];
    }
    
    for(int i = 0;i < n2;++i){
        RIGHT[i] = A[mid + i];
    }
    
    LEFT[n1] = RIGHT[n2] = SENTINEL;
    int i = 0;
    int j = 0;
    
    for(int k = left;k < right;++k){
        cnt++;
        if(LEFT[i] <= RIGHT[j]){
            A[k] = LEFT[i++];
        }
        else{
            A[k] = RIGHT[j++];
        }
    }
}

void mergeSort(int A[],int n,int left,int right){
    if(left + 1 < right){
        int mid = (left + right) / 2;
        mergeSort(A,n,left,mid);
        mergeSort(A,n,mid,right);
        merge(A,left,mid,right);
    }
}

int main(){
    int A[MAX],n;
    
    cin >> n;
    for(int i = 0;i < n;++i){
        cin >> A[i];
    }
    
    mergeSort(A,n,0,n);
    
    for(int i = 0;i < n;++i){
        if(i){
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;
    
    cout << cnt << endl;
}
