#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
		sort(g.begin(), g.end());
		sort(s.begin(), s.end());

        int fulfilled = 0;
        for(int i = 0; i < g.size(); i++){
			// cout<<"greed "<<i<<" "<<endl;
			for(int j = 0; j < s.size(); j++){
				// cout<<"cookie "<<j<<" "<<endl;
				if(s[j] >= g[i]){
					// cout<<"cookie given"<<endl;
					fulfilled++;
					g.at(i)=INT_MAX;
					s.at(j)=-1;
				}
			}
		}
		return fulfilled;
    }
};

int main(){
    Solution s1;

	// vector<int> g {1, 2};
    // vector<int> s {1, 2, 3};

    vector<int> g {10, 9, 8, 7};
    vector<int> s {5, 6, 7, 8};

	cout<<s1.findContentChildren(g, s);
    
    return 0;
}