#include <bits/stdc++.h>
class Solution {
    int dp[101][101][3][3];
    bool solve(string& s1, string& s2, string& s3, int last, int cnt, int i, int j) {
        if(i+j >= s3.size()) return abs(cnt) <= 1;
        int& memo = dp[i][j][cnt+1][last];
        if(memo != -1) return memo;
        bool res = false;
        // take from s1
        if(s1[i] == s3[i+j]) {
            res |= solve(s1, s2, s3, 1, cnt + (last != 1), i+1, j);
        }
        // take from s2
        if(s2[j] == s3[i+j]) {
            res |= solve(s1, s2, s3, 2, cnt - (last != 2), i, j+1);
        }
        return memo = res;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        if(s3.size() != s1.size() + s2.size()) return false;
        memset(dp, -1, sizeof(dp));
        return solve(s1, s2, s3, 0, 0, 0, 0);
    }
};
