class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> mp;
        for(auto& s: strs) {
            string key (26, '0');
            for(auto& c: s) ++key[c-'a'];
            mp[key].push_back(s);
        }
        for(auto& [s,v]: mp) {
            res.push_back(v);
        }
        return res;
    }
};
