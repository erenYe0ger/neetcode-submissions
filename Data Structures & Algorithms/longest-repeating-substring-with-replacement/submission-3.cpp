class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i = 0;
        int res = 0;
        int freq[26] = {0};
        for(int j=0; j<n; ++j) {
            ++freq[s[j]-'A'];
            int maxF = 0;
            for(int k=0; k<26; ++k) maxF = max(maxF, freq[k]);
            if((j-i+1) - maxF > k) {
                --freq[s[i]-'A'];
                ++i;
            }
            res = max(res, j-i+1);
        }
        return res;
    }
};
