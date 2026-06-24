class Solution {
public:
    string longestPalindrome(string s) {
        // dp[i][j] = is s[i...j] palindrome?
        // dp[i][j] = true; if s[i] = s[j] and dp[i+1][j-1] = true
        int n = s.size(), resSt, resSize = 0;
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        for(int i=n-1; i>=0; --i) {
            for(int j=i; j<n; ++j) {
                if(s[i] == s[j] && 
                    (i+1 >= j-1 || dp[i+1][j-1])) {
                        dp[i][j] = true;
                        if(j-i+1 > resSize) {
                            resSt = i;
                            resSize = j-i+1;
                        }
                    }
            }
        }
        return s.substr(resSt, resSize);
    }
};
