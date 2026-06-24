class Solution {
public:
    int numDecodings(string s) {
        // dp[i] = no of ways to decode s[i...]
        int n = s.size();
        vector<int> dp(n, 0);
        dp[n-1] = s[n-1] != '0';
        for(int i=n-2; i>=0; --i) {
            if(s[i] != '0') {
                // take one char
                if(dp[i+1] != 0) dp[i] += dp[i+1];
                // take two chars
                if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')) {
                    if(i+2 < n) dp[i] += dp[i+2];
                    else dp[i] += 1;
                }
            }
        }
        return dp[0];
    }
};
