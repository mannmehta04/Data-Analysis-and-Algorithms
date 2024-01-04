#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        int steps[2] { 1, 2 };
		int currentStep = 1;
        int currentClimb;

		for(int i=0; i<n; i++){
			if(currentClimb>=n){
				return currentClimb;
			}
			currentClimb += steps[currentStep];
		}
		return 0;
    }
};

int main(){
    Solution s1;

	cout<<s1.climbStairs(5);

    return 0;
}


/*
	int steps[2] { 1, 2 };
    int currentStep = 1;
    int totalSteps = 0;

    for(int i=currentStep; i>=0; i--){
        if(n>=steps[i]){
			firstStep=n/steps[i];
			currentStep=i;
			n -= (steps[i]*firstStep);
			totalSteps++;
        }
    }
*/