#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
		int candies = 0;
		int n = ratings.size();	// n is total number of childrens

        vector<int> leftData(n, 1);
		vector<int> rightData(n, 1);

		// new child doing better than previous but from left to right
		for(int i=1; i<n; i++)
			if(ratings[i] > ratings[i-1])
				leftData[i] = leftData[i-1] + 1;	// give more candy than previous

		// new child doing better than previous but from right to left
		for(int i=n-2; i>=0; i--)
			if(ratings[i] > ratings[i+1])
				rightData[i] = rightData[i+1] + 1;	// give more candy than previous

		// get the max out of both senerios
		for(int i = 0; i<n; i++)
			candies += max(leftData[i],rightData[i]);
		
		// for(int i = 0; i<n; i++)
		// 	cout<<"left "<<leftData[i]<<" right "<<rightData[i]<<endl;

		return candies;
    }
};

int main(){
    Solution s1;
	
	vector<int> v1 { 1,2,2 };
	cout<<s1.candy(v1);

    return 0;
}