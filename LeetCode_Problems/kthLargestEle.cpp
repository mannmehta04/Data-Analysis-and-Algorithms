#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue <int, vector<int>, greater<int> > pq;
            
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
            if(pq.size()>k){
                pq.pop();
            }
        }
        return pq.top();
    }
};

int main(){
    Solution s1;

	vector<int> v1 {3,2,1,5,6,4};

	cout<<s1.findKthLargest(v1,2);

    return 0;
}