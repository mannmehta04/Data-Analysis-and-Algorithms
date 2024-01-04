#include<iostream>
#include<vector>
using namespace std;

class lcs{
	string str1, str2;
	int dataSet[10][10];

	public:

	lcs(string str1, string str2){
		this->str1 = str1;
		this->str2 = str2;
		// dataSet[0][0]=1;
		for(int i=0;i<str1.length();i++){
			dataSet[i][0] = 0;
		}
		for(int j=0;j<str2.length();j++){
			dataSet[1][j] = 0;
        }
        display();
	}

	string max(string n1, string n2){
		return n1>n2 ? n1 : n2;
	}

	void calc(string str1, string str2){
		for(int i=0; i<str1.length(); i++){
			for(int j=0; j<str2.length(); j++){

				if(str1[i] == str2[j]){
					// dataSet[i][j] = 1+calc(str1[i-1], str2[j-1]);
				}

			}
		}
	}

	void display(){
		// cout<<"\t";
        for(int i=0;i<str1.length();i++){
            for(int j=0; j<str2.length();j++){
                cout<<dataSet[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
};

int main(){
	lcs l1("tinu","tini");
	// l1.calc();
	return 0;
}