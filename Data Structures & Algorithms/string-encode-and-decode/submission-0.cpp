class Solution {
public:

    string encode(vector<string>& strs) {
        string res;
        for(auto& s: strs) {
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s) {
        vector<string> res;
        int i = 0, n = s.size();
        int len = 0;
        while(i < n) {
            while(s[i] != '#') {
                len *= 10;
                len += s[i]-'0';
                ++i;
            }
            res.push_back(s.substr(i+1, len));
            i += len + 1;
            len = 0;
        }
        return res;
    }
};
