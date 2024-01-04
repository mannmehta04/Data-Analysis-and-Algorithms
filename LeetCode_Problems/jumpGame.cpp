#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
		int jump = 0;

		//check for initial conditions and special cases
		if(nums[0]==0 && nums.size()>1) return false;

		for(int i=0; i<nums.size()-1; i++){

			//check for out of bounds
			if(i>jump) return false;

			//check for best jump cases
			jump = max(jump, nums[i]+i);
		}

		//return possiblity of jump if exists
		return jump >= nums.size()-1;
    }
};

int main(){
    Solution s1;

	// vector<int> v1 { 2, 3, 1, 1, 4 };
	vector<int> v1 { 0 };

	cout<<s1.canJump(v1);

    return 0;
}