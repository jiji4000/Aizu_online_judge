//
//  ALDS1_15_D.cpp
//  AizuOnlineJudge
//
//  Created by 佐藤俊一朗 on 2019/10/21.
//  Copyright © 2019年 jiji4000. All rights reserved.
//

#include<iostream>
#include<stdio.h>
#include<string>
#include<queue>

using namespace std;

#define CHAR_SIZE 256
#define NODE_SIZE 512
#define TOLEFT '0'
#define TORIGHT '1'

long length = 0;


class Node{
public:
    // char番号も兼ねる
    int id;
    int weight;
    int left;
    int right;
    Node(){ weight = 0; }
    Node( int id, int w, int l, int r ): id(id), weight(w), left(l), right(r){}
    
    bool operator < ( const Node &n ) const{
        return weight > n.weight;
    }
};

Node nodes[NODE_SIZE];
int newRootId;

void recursive( int id, string code){
    if ( id < CHAR_SIZE ){
        length += code.size() * nodes[id].weight;
        return;
    }
    recursive( nodes[id].left, code + TOLEFT );
    recursive( nodes[id].right, code + TORIGHT );
}

void encoding( string text ){
    // それぞれの文字の出現回数を加算する
    int w[CHAR_SIZE] = {};
    // 出現回数を代入する
    for ( int i = 0; i < text.size(); i++ ) w[text[i]]++;
    
    // 優先度付きqueを使う
    priority_queue<Node> PQ;
    for ( int i = 0; i < CHAR_SIZE; i++ ) {
        // 重みが入っていた場合
        if ( w[i] > 0 ){
            // ノード作成
            Node node = Node( i, w[i], -1, -1 );
            PQ.push( node );
            // global配列にも入れる
            nodes[ node.id ] = node;
        }
    }
    
    if(PQ.size() == 1){
        length = text.size();
    }
    // Construct the binary tree
    newRootId = CHAR_SIZE;
    // 木を構築しているのか
    while ( PQ.size() > 1 ){
        Node left = PQ.top();
        PQ.pop();
        
        Node right = PQ.top();
        PQ.pop();
        
        int weight = left.weight + right.weight;
        // 新しくrootを作成する
        Node newRoot = Node( newRootId, weight, left.id, right.id );
        PQ.push( newRoot );
        nodes[ newRootId++ ] = newRoot;
    }
}

void decoding(){
    recursive( newRootId - 1, "");
}

int main(){
    string text;
    cin >> text;
    encoding( text );
    if(length == 0){
        decoding();
    }
    cout << length << endl;
}

