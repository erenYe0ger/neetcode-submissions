class Solution {
public:
    int numDecodings(string s) {
        // dp[i] = no of ways to decode s[i...]
        int n = s.size();
        int nxt2, nxt = s[n-1] != '0';
        for(int i=n-2; i>=0; --i) {
            int cur = 0;
            if(s[i] != '0') {
                // take one char
                if(nxt != 0) cur += nxt;
                // take two chars
                if(s[i] == '1' || (s[i] == '2' && s[i+1] <= '6')) {
                    if(i+2 < n) cur += nxt2;
                    else cur += 1;
                }
            }
            nxt2 = nxt; nxt = cur;
        }
        return nxt;
    }
};
