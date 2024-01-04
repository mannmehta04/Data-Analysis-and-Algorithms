#include<iostream>
#include<vector>
using namespace std;

class countingSort{

	vector<int> v1;
	vector<int> counterArr;
	vector<int> sortedArr;

	public:

	countingSort(){

	}

	countingSort(vector<int>& v1){
		this->v1 = v1;
	}

	int findArrSize(vector<int>& v1){
		int max = 0;
		for(int i=0; i<v1.size(); i++)
			if(v1[i]>max)
				max=v1[i];

		return max;
	}

	void findOccurence(){
		counterArr.resize(findArrSize(v1)+1);

		for(int i=0; i<findArrSize(v1); i++){
			counterArr[v1[i]]++;
		}
	}

	void sort(){
		findOccurence();
		sortedArr.resize(v1.size()+1);
		vector<int> tempArr = counterArr;

		for(int i=0; tempArr.size(); i++){
			if(tempArr[i]!=0){
				sortedArr.push_back(i);
				tempArr[i]--;
				cout<<sortedArr[i]<<" ";
			}
		}
	}

	void display(){
		for(int i=0; i<sortedArr.size(); i++)
			cout<<sortedArr[i]<<" ";
	}
};

int main(){

	vector<int> v1 { 2, 4, 5, 3, 1 };

	countingSort c1(v1);
	c1.sort();
	// c1.display();
	
	return 0;
}

/*
for(int i=0; i<v1.size(); i++)
			while(tempArr[i]!=0){
				sortedArr[i] = tempArr[i];
				tempArr[i]--;
				if(tempArr[i] != 0)
					continue;
			}
*/