#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        int currentSum = 0;

        if(n==1) return nums[0];

        for(int i = 0; i < n; i++){
            currentSum = max(nums[i], currentSum + nums[i]);
            maxSum = max(currentSum,maxSum);
        }
        return maxSum;
    }
};

int main(){
    Solution s1;

	vector<int> v1 { -2,-1 };
	// vector<int> v1 {-2,1,-3,4,-1,2,1,-5,4};

	cout<<s1.maxSubArray(v1);

    return 0;
}

/*
	O(n2) Solution:

	int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = INT_MIN;
        int currentSum = 0;

        if(n==1) return nums[0];

        for(int i = 0; i < n; i++){
            for(int j = i; j < n ; j++){
                currentSum += nums[j];
                maxSum = max(currentSum,maxSum);
				// cout<<maxSum;
            }
            currentSum = 0;
        }
        return maxSum;
    }
*/