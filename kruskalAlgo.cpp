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

vector<pair<int,pair<int,int>>> edges;
vector<int> num_of_vertex;
bool find_vertex(int var){
    for(int i =0;i<num_of_vertex.size();i++){
        if(num_of_vertex[i]== var){
            return true;
        }
    }
    return false;
}
int sum=0;
void kruskelMST(vector<vector<pair<int,int>>> &graph){
    int v = graph.size();
    vector<vector<int>> result;
    int totalWeight = 0;
     int j = 1;
    for(int i = 0;i<v;i++){
        for(auto neighbour : graph[i]){
            int v = neighbour.first;
            int w = neighbour.second;
            edges.push_back({w,{j,v}});
        }
        j++;
    }
    sort(edges.begin(),edges.end());



    num_of_vertex.push_back(edges[0].second.first);
    num_of_vertex.push_back(edges[0].second.second);
    cout<<edges[0].second.first<<endl<<edges[0].second.second;
    sum += edges[0].first;
    for(const auto& edge : edges){

        int firstElement = edge.first;
        int secondElementFirst = edge.second.first;
        int secondElementSecond = edge.second.second;

        cout<<"Weight : "<<firstElement<<endl;
        cout<<"Source : "<<secondElementFirst<<endl;
        cout<<"Destination : "<<secondElementSecond<<endl;

        if(find_vertex(secondElementFirst) && find_vertex(secondElementSecond)){
            continue;
        }
        else{
           if(!find_vertex(secondElementFirst)){
             num_of_vertex.push_back(secondElementFirst);
             sum+= firstElement;
           }
           if(!find_vertex(secondElementSecond)){
             sum+= firstElement;
             num_of_vertex.push_back(secondElementSecond);
           }
           else{
            num_of_vertex.push_back(secondElementFirst);
             num_of_vertex.push_back(secondElementSecond);
             sum+= firstElement;

           }
     }
    if(num_of_vertex.size() == edges.size()){
        cout<<"Sum = "<<sum;
        break;
     }
  }
}
int main(){
    vector<vector<pair<int,int>>> graph;

    addVertex(graph);
    kruskelMST(graph);
    //print(graph);
    cout<<"Sum = "<<sum;
    cout<<"Size = "<<num_of_vertex.size();

}