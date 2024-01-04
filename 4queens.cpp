#include<iostream>
#include<vector>
#include<stack>
using namespace std;

stack<int> s1;

class queens{
	
	vector<vector<int>> v1 = {
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	};

	public:

	queens(){
		// for(int i = 0; i < 4; i++){
		// 	for(int j=0; j < 4; j++){
		// 		// v1[i][j]=1;
		// 	}
		// }
		placeQueen();
	}

	void placeQueen(int x=0, int y=0){
		for(int i=0; i < 4; i++){
			for(int j=0; j < 4; j++){
				if(v1[i][j]==0){
					v1[i][j]==1;
					fillVoid(i,j);
					placeQueen(i,j);
				}
			}
		}
		v1[x][y]=1;
	}

	void fillVoid(int x, int y){

		// this works
		for(int i = 0; i < 4; i++){
			for(int j=0; j < 4; j++){
				// fill rows
				v1[i][y]=4;

				// fill cols
				v1[x][j]=4;
			}
		}

		// fills \ diagonal, works
		for(int i=x;i<4;i++){
			for(int j=0;j<4;j++){
				v1[i][i]=4;
			}
		}

		// Upper left, works
		// for(int i=x;i>=0;i--){
		// 	for(int j=y;j>0;j--){
		// 		v1[i][j]=4;
		// 	}
		// }

		// upper right, works
		// for(int i=x;i>=0;i--){
		// 	for(int j=y;j<4;j++){
		// 		v1[i][j]=4;
		// 	}
		// }

		// for(int i=x;i<4;i++){
		// 	for(int j=y;j>=0;j--){
		// 		v1[i][j]=4;
		// 	}
		// }

		v1[x][y]=1;

		display();
	}

	bool checkRow(){
		for(int i=0; i<4; i++){
			for(int j=0; j<4; j++){
				if(v1[i+1][j] == 0){
					return false;
					exit(0);
				}
			}
		}
		return true;
	}

	void checkPlace(){

		// check for rows
		for(int i = 0; i < 4; i++){
			for(int j=0; j < 4; j++){
				if(v1[i][0]==1){
					
				}
			}
		}

		// this is test field
		// for(int i = 0; i < 4; i++){
		// 	for(int j=0; j < 4; j++){
		// 		// placeQueen(i,j);
		// 		if(v1[i][j]==1)
		// 			cout<<"hello";	exit(0);
		// 	}
		// }
		// display();
	}

	void display(){
		for(int i = 0; i < 4; i++){
			for(int j=0; j < 4; j++){
				cout<<v1[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<endl;
	}
};

int main(){
	queens q1;
	q1.fillVoid(1,2);
	// q1.checkPlace();
	// q1.display();
}