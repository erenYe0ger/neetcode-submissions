class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size(), cnt = 0;

        auto expand = [&](int i, int j) {
            while(i >= 0 && j < n && s[i] == s[j]) --i, ++j, ++cnt;
        };

        for(int i=0; i<n; ++i) {
            expand(i, i);
            expand(i, i+1);
        }
        return cnt;
    }
};
