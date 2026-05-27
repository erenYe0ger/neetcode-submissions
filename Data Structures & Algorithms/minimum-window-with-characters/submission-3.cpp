class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> have, need;
        for(auto& c: t) ++need[c];
        int n = s.size();
        int m = need.size();
        int i = 0;
        int st = -1, len = 1e5;
        int cnt = 0;
        for(int j=0; j<n; ++j) {
            ++have[s[j]];
            cnt += have[s[j]] == need[s[j]];
            while (cnt == m) {
                if(j-i+1 < len) st = i, len = j-i+1;
                --have[s[i]];
                cnt -= have[s[i]]+1 == need[s[i]];
                ++i;
            }
        }
        if(st == -1) return "";
        return s.substr(st, len);
    }
};
