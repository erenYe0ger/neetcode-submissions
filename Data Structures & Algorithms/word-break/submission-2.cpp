#include <bits/stdc++.h>
class Solution {
    unordered_set<string> dict;
    int dp[200];
    bool solve(string& s, int i) {
        if(i >= s.size()) return true;
        int& memo = dp[i];
        if(memo != -1) return memo; 
        bool res = false;
        for(int j=i; j<s.size(); ++j) {
            if(dict.count(s.substr(i, j-i+1))) {
                res |= solve(s, j+1);
            }
        }
        return memo = res;
    }
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp, -1, sizeof(dp));
        dict = unordered_set<string> (wordDict.begin(), wordDict.end());
        return solve(s, 0);
    }
};
