#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#include<stack>
using namespace std;

stack<int> s;
void fillSpace(int board[4][4],int i,int j){
    int a=i+1;
    int b=j+1;
    int da1=i+1;
    int db1=j-1;
    int da2=i+1;
    int db2=j+1;

    while(a < 4){
        board[a][j] = 1;
        a++;
    }
    while(b < 4){
        board[i][b] = 1;
        b++;
    }
    while(da1 < 4 && db1 >= 0){
        board[da1][db1] = 1;
        da1++;
        db1--;
    }
    while(da2 < 4 && db2 < 4){
        board[da2][db2] = 1;
        da2++;
        db2++;
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<board[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
}
bool rowCheck(int board[4][4],int i){
    int count=0;
    for(int k=0;k<4;k++){
        if(board[i+1][k] == 0){
            s.push(k);
            count++;
        }
    }
    if(count != 0){
        return false;
    }
    else{
        return true;
    }
}

void queens(int board[4][4],int x){
    int y;
    for(int i=0;i<4;i++){
        for(int j=x;j<4;j++){
            if(rowCheck(board,i)){
                    if(!s.empty()){
                        y = s.top();
                        s.pop();
                        board[i][j] = 1;
                        board[i][y] = 0;
                        j=y;
                    }
            }
            if(board[i][j] == 0){
                board[i][j] = 2;
                fillSpace(board,i,j);
            }
        }
    }

    for(int i=0;i<4;i++){
        for(int j=0;j<4;j++){
            cout<<board[i][j]<<"  ";
        }
        cout<<endl;
    }
}

int main(){
    int board[4][4] = {{0,0,0,0},
                       {0,0,0,0},
                       {0,0,0,0},
                       {0,0,0,0}
                      };
    queens(board,0);

}
