class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        map<string, vector<int>> mp;
        int n = strs.size();
        for(int i=0; i<n; ++i) {
            string s = strs[i];
            sort(s.begin(), s.end());
            mp[s].push_back(i);
        }
        for(auto& [s,v]: mp) {
            vector<string> v2;
            for(auto& i: v) v2.push_back(strs[i]);
            res.push_back(v2);
        }
        return res;
    }
};
