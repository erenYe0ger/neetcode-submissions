class Solution {
public:
    bool isPalindrome(string s) {
        string s2;
        for(char& c: s) {
            if(c >= '0' && c <= '9') s2 += c;
            if(c >= 'a' && c <= 'z') s2 += c;
            if(c >= 'A' && c <= 'Z') s2 += (c + 32);
        }
        int n = s2.size();
        for(int i=0; i<n/2; ++i) {
            if(s2[i] != s2[n-i-1]) return false;
        }
        return true;
    }
};
