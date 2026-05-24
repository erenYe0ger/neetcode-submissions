class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int i = 0, j = 1;
        int res = 1;
        unordered_map<char,int> mp;
        set<pair<int,char>> st;
        ++mp[s[0]];
        st.insert({1,s[0]});
        while(j < n) {
            st.erase({mp[s[j]], s[j]});
            st.insert({mp[s[j]]+1, s[j]});
            ++mp[s[j]];
            while((j-i+1) - st.rbegin()->first > k) {
                st.erase({mp[s[i]], s[i]});
                st.insert({mp[s[i]]-1, s[i]});
                --mp[s[i]];
                ++i;
            }
            res = max(res, j-i+1);
            ++j;
        }
        return res;
    }
};
