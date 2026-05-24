class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i = 0, j = 0;
        int f[26] = {0};
        int res = 0;
        auto maxF = [&]() {
            int x = 0;
            for(int i=0; i<26; ++i) x = max(x, f[i]);
            return x;
        };
        while(j < n) {
            ++f[s[j]-'A'];
            while((j-i+1) - maxF() > k) {
                --f[s[i]-'A'];
                ++i;
            }
            res = max(res, j-i+1);
            ++j;
        }
        return res;
    }
};
