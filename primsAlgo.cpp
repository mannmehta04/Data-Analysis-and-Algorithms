#include<iostream>
#include<vector>
#include<queue>
#include<bits/stdc++.h>
using namespace std;

void addVertex(vector<vector<pair<int,int>>> &graph){
    int noV;
    cout<<"Enter the number of vertex:";
    cin>>noV;
    vector<pair<int,int>> temp;
    for(int i=1;i<=noV;i++){
        int noE;
        cout<<"\nEnter the number of edges associate with vertex ["<<i<<"]:";
        cin>>noE;
        for(int j=1;j<=noE;j++){
            int edge,weight;
            cout<<"\nEnter the edge destination:";
            cin>>edge;
            cout<<"\nEnter the edge weight:";
            cin>>weight;
            temp.push_back(make_pair(edge,weight));
        }
        graph.push_back(temp);
        temp.clear();
    }
}

void print(vector<vector<pair<int,int>>> graph){
    for(int i=0;i<graph.size();i++){
            cout<<endl<<i+1<<"->";
        for(int j=0;j<graph[i].size();j++){
            cout<<graph[i][j].first<<","<<graph[i][j].second<<endl;
        }
    }
}

void primsMST(vector<vector<pair<int,int>>> &graph,int sNode){
    vector<int> visited;
    vector<pair<int,int>> wStore;
    visited.push_back(sNode);
    int sum = 0;

    while(visited.size() != graph.size()){
        for(int k=0;k<visited.size();k++){
            for(int i=0;i<graph[visited[k]-1].size();i++){
                wStore.push_back(graph[visited[k]-1][i]);
            }
        }
        int miniVal = INFINITY;
        int miniNode;
        for(int i=0;i<wStore.size();i++){
            if(wStore[i].second<miniVal && !count(visited.begin(),visited.end(),wStore[i].first)){
                miniVal = wStore[i].second;
                miniNode = wStore[i].first;
            }
        }
        sum += miniVal;
        visited.push_back(miniNode);
        wStore.clear();
    }
    cout<<endl<<"sum:="<<sum;
}
int main(){
    vector<vector<pair<int,int>>> graph;

    addVertex(graph);
    primsMST(graph,1);
    //print(graph);
}