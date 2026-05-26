class Solution {
public:
    int characterReplacement(string s, int k) {
        // O(n) TC and O(1) SC
        int n = s.size();
        int i = 0;
        int res = 0;
        int freq[26] = {0};
        int maxF = 0;
        for(int j=0; j<n; ++j) {
            ++freq[s[j]-'A'];
            maxF = max(maxF, freq[s[j]-'A']);
            if((j-i+1) - maxF > k) {
                --freq[s[i]-'A'];
                ++i;
            }
            res = max(res, j-i+1);
        }
        return res;
    }
};
