#include<iostream>
#include<vector>
#include<iterator>
#include<map>
#include<algorithm>
using namespace std;

class adjecencyMatrix{

    
    vector<int> vertex = {'A','B','C','D'};
    map<string,int> v;
    vector<int> undSrc = {'A','A','A','B','B','C','D','D'};
    vector<int> undDes = {'A','B','C','B','C','C','C','D'};
    vector<int> undweight = {0, 1, 2, 0, 4, 0, 7, 0};

    vector<int> dirSrc = {'A','A','B','A','C','B','B','C','D','D'};
    vector<int> dirDes = {'A','B','A','C','A','B','C','C','D','A'};
    vector<int> dirweight = {0,2,2,4,4,0,3,0,0,1};

    vector<vector<int>> edges;

    public:
    adjecencyMatrix(){
        for(int i=0;i<vertex.size();i++){
            // v[vertex[i]] = i;
        }
    }
    
    void addEdge(){
        
        for(int i=0;i<undSrc.size();i++){
            
            // cout<<x<<" "<<y;
            edges[0][0] = 0;
        }
        // edges[vertex[0],0];
    }

    void displayMatrix(){
        for(int i=0; i<undSrc.size(); i++){
            for(int j=0; j<undDes.size(); j++){
                cout<<edges[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){

    adjecencyMatrix m1;
    m1.addEdge();
    m1.displayMatrix();

    return 0;
}