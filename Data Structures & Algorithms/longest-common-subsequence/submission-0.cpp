#include <bits/stdc++.h>
class Solution {
    int dp[1005][1005];
    int solve(string& text1, string& text2, int n1, int n2, int i, int j) {
        if(i >= n1 || j >= n2) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int res;
        // not take
        res = max(solve(text1, text2, n1, n2, i, j+1), solve(text1, text2, n1, n2, i+1, j));
        // take
        if(text1[i] == text2[j]) res = 1 + solve(text1, text2, n1, n2, i+1, j+1);
        return dp[i][j] = res;
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp, -1, sizeof(dp));
        return solve(text1, text2, text1.size(), text2.size(), 0, 0);
    }
};
