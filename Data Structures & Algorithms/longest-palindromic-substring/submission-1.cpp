class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size(), resSize = 0, resSt;

        auto expand = [&](int i, int j) {
            while(i >= 0 && j < n && s[i] == s[j]) --i, ++j;
            if(j-i-1 > resSize) {
                resSize = j-i-1; resSt = i+1;
            }
        };

        for(int i=0; i<n; ++i) {
            expand(i, i);
            expand(i, i+1);
        }
        return s.substr(resSt, resSize);
    }
};
