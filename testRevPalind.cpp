#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Lps{
	string s1,s2;
	int l1,l2;
	
	public:
		Lps(string s){
			s1 = s;
			s2 = s;
			reverse(s2.begin(), s2.end());
			
			l1=s1.size();
			l2=s2.size();
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
			
//			for(int i=1;i<=l1;i++){
//				
//				cout<<s1[i-1]<<" ";
//				for(int j=1;j<=l2;j++){
//					cout<<temp[i][j]<<" ";
//				}	
//				cout<<endl;
//			}

			return temp[l1][l2];	
		}
};

int main(){
	string s = "babad";
	
	Lps lps(s);
	cout<<"Longest Palindromic Subsequnce: "<<lps.LongSeq();
}
