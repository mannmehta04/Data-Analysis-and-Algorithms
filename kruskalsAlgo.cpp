#include<iostream>
using namespace std;

class kruskalsNode{

    int nodeId;
    int nextDistance;
    kruskalsNode *next;

    public:

    kruskalsNode(){
        nodeId = 0;
        nextDistance = 0;
        next = NULL;
    }

    kruskalsNode(int nodeId, int nextDistance){
        this->nodeId = nodeId;
        this->nextDistance = nextDistance;
        next = NULL;
    }

    void appendNode(kruskalsNode *k1){
        kruskalsNode *tp;
        for(kruskalsNode *tp = this; tp-> next!=NULL; tp=tp->next){}
        tp -> next = k1;
    }

    
};