#include <bits/stdc++.h>
class Solution {
    int dp[100][100];
    int solve(string& word1, string& word2, int i, int j) {
        if(i >= word1.size() && j >= word2.size()) return 0;
        if(i >= word1.size()) return word2.size()-j;
        if(j >= word2.size()) return word1.size()-i;
        if(dp[i][j] != -1) return dp[i][j];
        int res = 1e9;
        // equal
        if(word1[i] == word2[j]) {
            res = min(res, solve(word1, word2, i+1, j+1));
        }
        // not equal
        // insert
        res = min(res, 1 + solve(word1, word2, i, j+1));
        // delete
        res = min(res, 1 + solve(word1, word2, i+1, j));
        // replace
        res = min(res, 1 + solve(word1, word2, i+1, j+1));
        return dp[i][j] = res;
    }
public:
    int minDistance(string word1, string word2) {
        memset(dp, -1, sizeof(dp));
        return solve(word1, word2, 0, 0);
    }
};