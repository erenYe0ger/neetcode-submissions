class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> mp, mp2;
        for(auto& c: t) ++mp[c];
        int i = 0, j = 0;
        int st = -1, end = 1e5+5;
        ++mp2[s[0]];
        int cnt = 0;
        if(mp.count(s[0])) cnt = mp[s[0]] == mp2[s[0]];
        int n = s.size(), m = mp.size();
        while(j < n) {
            if(cnt == m) {
                if(j-i+1 < end-st+1) st = i, end = j;
                --mp2[s[i]];
                if(mp.count(s[i])) cnt -= mp[s[i]] == mp2[s[i]]+1;
                ++i;
            } else {
                ++j;
                if(j<n) {
                    ++mp2[s[j]];
                    if(mp.count(s[j])) cnt += mp[s[j]] == mp2[s[j]];
                }
            }
        }
        if(end-st+1 > 1e5) return "";
        return s.substr(st, end-st+1);
    }
};
