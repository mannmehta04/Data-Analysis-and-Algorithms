#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<unordered_set>
using namespace std;

class Solution {
public:
	vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<vector<string>> dp(n + 1, vector<string>());

        dp[0].push_back("");

        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < i; ++j) {
                string word = "";
                for (int k = j; k < i; k++) {
                    word += s[k];
                }
                if (wordSet.find(word) != wordSet.end()) {
                    for (string prev : dp[j]) {
                        dp[i].push_back(prev + (prev == "" ? "" : " ") + word);
                    }
                }
            }
        }

        return dp[n];
    }
};

int main(){
    Solution s1;

	vector<string> wordDict = {"cake", "bread", "pizza", "cheese"};

	vector<string> v1 = s1.wordBreak("cheesecake", wordDict);

	for(int i=0;i<v1.size();i++)
		cout<<v1[i]<<" ";

    return 0;
}