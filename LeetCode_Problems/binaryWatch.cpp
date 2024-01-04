#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
        for(int h=0;h<12;h++){
            for(int m=0;m<60;m++){
                int x=countBits(h);
                int y=countBits(m);
                if(x+y==turnedOn){
                    ans.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
                }
            }
        }
        return ans;
    }
    
    int countBits(int num) {
        int count = 0;
        while (num) {
            count += num & 1;
            num >>= 1;
        }
        return count;
    }
};

int main(){
    Solution s1;

	vector<string> v1 = s1.readBinaryWatch(1);

	for(int i=0;i<v1.size();i++)
		cout<<v1[i]<<" ";

    return 0;
}