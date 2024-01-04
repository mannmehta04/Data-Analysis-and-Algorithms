#include<iostream>
#include<vector>
using namespace std;

class knap{

	vector<int> v1, v2;

	knap(vector<int> v1, vector<int> v2){
		this.v1 = v1;
		this.v2 = v2;
	}

	
};

int main(){

	knap k1;

	vector<int> cost {1,3,5};
	vector<int> happiness {1,2,3};

	k1(cost, happiness);

	return 0;
}