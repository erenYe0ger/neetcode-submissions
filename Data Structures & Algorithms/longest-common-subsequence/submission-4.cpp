class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<int> dp(n2+1, 0);
        for(int i=n1-1; i>=0; --i) {
            int nxt = 0;
            for(int j=n2-1; j>=0; --j) {
                int prev = dp[j];
                int res;
                // not take
                res = max(dp[j+1], dp[j]);
                // take
                if(text1[i] == text2[j]) res = max(res, 1 + nxt);
                dp[j] = res; 
                nxt = prev;
            }
        }
        return dp[0];
    }
};
