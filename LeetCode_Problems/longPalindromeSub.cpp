#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:

	string strrev(string str){
		return reverse(str);
	}

    string longestPalindrome(string s) {
        int n = s.length();
        string currStr, finalStr;

        if(n==1) return s[0];

        for(int i = 0; i < n; i++){
			for(int j = i+1; j<n; j++){
				if(strrev(currStr).length() < finalStr.length()){
					currStr=finalStr;
				}
			}
        }

        return finalStr;
    }
};

int main(){
    Solution s1;

	cout<<s1.longestPalindrome("babad");

    return 0;
}