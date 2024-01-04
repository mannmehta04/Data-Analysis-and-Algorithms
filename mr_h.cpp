#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class MaxRect{
	vector<vector<int>> vec;
	public:
		MaxRect(vector<vector<int>> v){
			vec = v;
		}
		
		int longArea(){
			vector<int> curRow = vec[0];
			int maxRes = maxArea(curRow);
		//	cout<<"Output :"<<endl;
		//	display(curRow);
			for(int i=1;i<vec.size();i++){
				for(int j=0;j<vec[i].size();j++){
				 	if(vec[i][j]==1)
				 		curRow[j] +=1;
				 	else if(vec[i][j]==0)
				 		curRow[j] =0;
				}
		//	display(curRow);
				maxRes = max(maxRes,maxArea(curRow));
			}
			return maxRes;
		}
		
	
		int maxArea(vector<int> v){
			int cou=0;
			int maxEle = *max_element(v.begin(), v.end());
		    for(auto i:v){
		    	if(maxEle == i)
		    		cou++;
			}
			return (cou*maxEle);
		}
		
		void display(vector<int> v){
			for(auto j:v){
				cout<<j<<" ";
			}
			cout<<endl;
		}
		
//		void display(){
//			for(int i=0;vec.size();i++){
//				for(auto j:vec[i]){
//					cout<<j<<" ";
//				}
//				cout<<endl;	
//			}
//		}
};


int main(){
	vector<vector<int>> vec{
		{1,0,1,0,0},
		{1,0,1,1,1},
		{1,1,1,1,1},
		{1,0,0,1,0}
	};
	
	MaxRect mr(vec);

	cout<<"Maximal Rectangle is "<< mr.longArea()<<endl<<endl;
	//cout<<"Input :"<<endl;
	//mr.display();
	
	return 0;
}
