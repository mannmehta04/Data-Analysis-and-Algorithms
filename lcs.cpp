#include<iostream>
#include<string>
using namespace std;

class Lcs{
	string s1,s2;
	int l1,l2;
	
	public:
		Lcs(string s,string d){
			s1 = s;
			s2 = d;
			l1=s.size();
			l2=d.size();
		}
		
		int LongSeq(){
			int temp[l1+1][l2+1];
			
			for(int i=0;i<=l1;i++)
				temp[i][0] = 0;
			for(int i=0;i<=l2;i++)
				temp[0][i] = 0;
			
			for(int i=1;i<=l1;i++)
				for(int j=1;j<=l2;j++)
					if(s1[i-1] == s2[j-1])
						temp[i][j]=1+temp[i-1][j-1];
					else
						temp[i][j]=max(temp[i-1][j],temp[i][j-1]);
			cout<<endl;
			for(int i=1;i<=l1;i++){
				
				cout<<s1[i-1]<<" ";
				for(int j=1;j<=l2;j++){
					cout<<temp[i][j]<<" ";
				}	
				cout<<endl;
			}
					
			return temp[l1][l2];
			
		}
};

int main(){
	string s1 = "tinu";
	string s2 = "tini";
	
	Lcs lcs(s1,s2);
	cout<<"Longest Common Subsequnce: "<<lcs.LongSeq();
}
