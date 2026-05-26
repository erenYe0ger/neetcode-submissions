class Solution {
public:
    string minWindow(string s, string t) {
        int ft[52] = {0};
        for(auto& c: t) {
            if(c < 'a') ++ft[c-'A'+26];
            else ++ft[c-'a'];
        }
        int n = s.size();
        int fs[52] = {0};
        int j = 0;
        for(j=0; j<n; ++j) {
            char& c = s[j];
            if(c < 'a') ++fs[c-'A'+26];
            else ++fs[c-'a'];
            bool flag = true;
            for(int t=0; t<52; ++t) {
                flag &= (ft[t] <= fs[t]);
            }
            if(flag) break;
        }
        if(j == n) return "";
        string res = s.substr(0,j+1);
        int i = 1;
        if(s[0] < 'a') --fs[s[0]-'A'+26];
        else --fs[s[0]-'a'];
        while(true) {
            bool flag = true;
            for(int t=0; t<52; ++t) {
                flag &= (ft[t] <= fs[t]);
            }
            if(flag) {
                res = s.substr(i, j-i+1);
                char& c = s[i];
                if(c < 'a') --fs[c-'A'+26];
                else --fs[c-'a'];
                ++i;
            } else {
                char& c = s[i];
                if(c < 'a') --fs[c-'A'+26];
                else --fs[c-'a'];
                ++i;
                ++j;
                if(j >= n) break;
                char& c2 = s[j];
                if(c2 < 'a') ++fs[c2-'A'+26];
                else ++fs[c2-'a'];
            }
        }
        return res;
    }
};
