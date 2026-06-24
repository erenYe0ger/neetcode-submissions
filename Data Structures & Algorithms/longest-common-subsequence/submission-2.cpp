class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<int> nxt(n2+1, 0);
        for(int i=n1-1; i>=0; --i) {
            vector<int> cur(n2+1, 0);
            for(int j=n2-1; j>=0; --j) {
                int res;
                // not take
                res = max(cur[j+1], nxt[j]);
                // take
                if(text1[i] == text2[j]) res = 1 + nxt[j+1];
                cur[j] = res;
            }
            nxt = cur;
        }
        return nxt[0];
    }
};
