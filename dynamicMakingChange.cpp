#include<iostream>
#include<vector>
using namespace std;

class makingChange{

    vector<vector<int>> data;
    vector<int> denominator { 1,3,4 };
    int change;

    public:

    makingChange(int change){
        this->change = change;
        // for(int j=0;j<change;j++){
        //     data[0][j] = 0 ;
        // }
        // display();
    }

    int findMin(int n1, int n2){
        int min;
        min = n1<n2? n1 : n2;
        return min;
    }

    int findChange(int coinIndex, int currency){
        for(int i=0;i<denominator.size();i++){
            for(int j=0; j<change;j++){
                if(i==0){
                    data[i][j] = (1+findChange(i,j-denominator[i]));
                    // return (1+findChange(i,j-denominator[i]));
                }
                else{
                    data[i][j] = findMin(findChange(i-1,j),(1+findChange(i,j-denominator[i])));
                    // return findChange(i-1, j);
                }
            }
            cout<<endl;
        }
        return 0;
    }

    void display(){
        for(int i=0;i<denominator.size();i++){
            for(int j=0; j<change;j++){
                cout<<data[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){

    makingChange c1(6);
    // c1.display();
    c1.findChange(2,6);
    c1.display();

    return 0;
}