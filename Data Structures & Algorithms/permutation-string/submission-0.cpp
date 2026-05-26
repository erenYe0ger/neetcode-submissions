class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int f1[26] = {0}, f2[26] = {0};
        for(auto& c: s1) ++f1[c-'a'];
        int n1 = s1.size(), n2 = s2.size();
        for(int i=0; i<n1-1; ++i) ++f2[s2[i]-'a'];
        for(int i=n1-1; i<n2; ++i) {
            ++f2[s2[i]-'a'];
            bool res = true;
            for(int j=0; j<26; ++j) res &= (f1[j] == f2[j]);
            if(res) return true;
            --f2[s2[i-n1+1]-'a'];
        }
        return false;
    }
};
