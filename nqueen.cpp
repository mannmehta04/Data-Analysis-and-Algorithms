#include<iostream>
#include<vector>
#define n 4
using namespace std;

vector<vector<int>> board(n, vector<int>(n, 0));

bool checkRow(int row, int col){
    for(int i = 0; i < board.size(); i++){
        if(i == col){
            continue;
        } 
        if(board[row][i] == 1){
            return false;
        }
    }
    return true;
}
bool checkCol(int row, int col){
    for(int i = 0; i < board.size(); i++){
        if(i == row){
            continue;
        } 
        if(board[i][col] == 1){
            return false;
        }
    }
    return true;
}
bool checkDia(int row, int col){
    int flag = 0;
    for(int i = 1;(row - i) >= 0 && (col + i) < n; i++){
        if(board[row-i][col+i] == 1){
            flag = 1;
            break;
        }
    }
    for(int i = 1;(row + i) < n && (col - i) >=0 ; i++){
        if(board[row+i][col-i] == 1){
            flag = 1;
            break;
        }
    }
    for(int i = 1;(row - i) >= 0 && (col - i) >= 0; i++){
        if(board[row-i][col-i] == 1){
            flag = 1;
            break;
        }
    }
     for(int i = 1;(row + i) < n && (col + i) < n; i++){
        if(board[row+i][col+i] == 1){
            flag = 1;
            break;
        }
    }
    if(flag == 1){
        return false;
    } else{
        return true;
    }
    
}
void print(){
 for(int j =0; j< n; j++){
        for(int i =0; i < n; i++){
            if(board[j][i] == 1){
                cout<<"1";
            } else{
                cout<<"0";
            }
        }
        cout<<endl;
    }
}
bool n_queens(int row, int col){
    if(row == n){
        return true;
    }
    for(int i =0; i < n; i++){
        if(checkCol(row, i) && checkRow(row, i) && checkDia(row, i)){
            board[row][i] = 1;
            if(n_queens(row+1, i)){
                return true;
            }
        }
        board[row][i] = 0;
    }
    return false;
}
 int main()
{
   n_queens(0,0);
    print();
}