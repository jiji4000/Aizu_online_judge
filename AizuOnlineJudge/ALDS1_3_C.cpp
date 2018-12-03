////
////  ALDS1_3_C.cpp
////  AizuOnlineJudge
////
////  Created by jiji on 2018/11/28.
////  Copyright © 2018年 jiji4000. All rights reserved.
////
//
//#include <stdio.h>
//#include <cstdlib>
//#include <cstring>
//
//struct Node{
//    int key;
//    Node *next,*prev;
//};
//
//// 番兵
//Node* nil;
//
//Node* searchList(int key){
//    Node* cur = nil->next;
//    while(cur != nil && cur->key != key){
//        cur = cur->next;
//    }
//    return cur;
//}
//
//void init(){
//    nil = (Node*)malloc(sizeof(Node));
//    nil->next = nil;
//    nil->prev = nil;
//}
//
//void printList(){
//    Node* cur = nil->next;
//    int isf = 0;
//    while(1){
//        if(cur == nil) break;
//        if(isf++ > 0){
//            printf(" ");
//        }
//        printf("%d",cur->key);
//        cur = cur->next;
//    }
//    printf("\n");
//}
//
//void deleteNode(Node* n){
//    if(n == nil) return;
//    n->prev->next = n->next;
//    n->next->prev = n->prev;
//    free(n);
//}
//
//void deleteFirst(){
//    deleteNode(nil->next);
//}
//
//void deleteLast(){
//    deleteNode(nil->prev);
//}
//
//void deleteKey(int key){
//    deleteNode(searchList(key));
//}
//
//void insert(int key){
//    Node* node = (Node*)malloc(sizeof(Node));
//    node->key = key;
//    // 番兵の次に要素を追加
//    node->next = nil->next;
//    nil->next->prev = node;
//    nil->next = node;
//    node->prev = nil;
//}
//
//int main(){
//    int key,n;
//    int size = 0;
//    char com[20];
//    int np = 0,nd = 0;
//    scanf("%d",&n);
//    init();
//    
//    for(int i = 0;i < n;++i){
//        scanf("%s%d",com,&key);
//        
//        if(com[0] == 'i'){
//            insert(key);
//            np++;
//            size++;
//        }else if(com[0] == 'd'){
//            if(strlen(com) > 6){
//                if(com[6] == 'F'){
//                    deleteFirst();
//                }
//                else if(com[6] == 'L'){
//                    deleteLast();
//                }
//            }
//            else{
//                deleteKey(key);
//                nd++;
//            }
//            size--;
//        }
//    }
//    printList();
//    return 0;
//}
