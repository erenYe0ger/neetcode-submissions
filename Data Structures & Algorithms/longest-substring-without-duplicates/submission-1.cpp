class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0) return 0;
        int res = 1;
        int i = 0, j = 1;
        unordered_set<char> st;
        st.insert(s[0]);
        while(j < n) {
            while(st.count(s[j])) {
                st.erase(s[i]);
                ++i;
            }
            st.insert(s[j]);
            res = max(res, j-i+1);
            ++j;
        }
        return res;
    }
};
