#include <bits/stdc++.h>
class Solution {
    int dp[1000][1000];
    int solve(string& s, string& t, int i, int j) {
        if(j >= t.size()) return 1;
        if(i >= s.size()) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int res = 0;
        // take s[i]
        if(s[i] == t[j]) res += solve(s, t, i+1, j+1);
        // not take s[i]
        res += solve(s, t, i+1, j);
        return dp[i][j] = res;
    }
public:
    int numDistinct(string s, string t) {
        if(t.size() > s.size()) return 0;
        memset(dp, -1, sizeof(dp));
        return solve(s, t, 0, 0);
    }
};
