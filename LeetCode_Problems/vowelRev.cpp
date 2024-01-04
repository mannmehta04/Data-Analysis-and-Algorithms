#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include<string.h>
using namespace std;

class Solution {
public:

	string reverseVowels(string s) {
		int v[5] = {'a','e','i','o','u'};
		string ans="";
		
		for(int i=0; i<s.length(); i++){
			if(s.at(v[i]))
				ans += s[i];
		}

		return ans;
    }
};

int main(){
    Solution s1;

	cout<<s1.reverseVowels("tinu");

    return 0;
}