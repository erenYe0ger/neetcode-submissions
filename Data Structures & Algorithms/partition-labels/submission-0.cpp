class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> last(26, 0), res;
        int n = s.size(), i = 0;
        for(int i=0; i<n; ++i) {
            last[s[i]-'a'] = i;
        }
        while(i < n) {
            int st = i;
            int end = last[s[i]-'a'];
            while(i < end) {
                end = max(end, last[s[i]-'a']);
                ++i;
            }
            res.push_back(end-st+1);
            ++i;
        }
        return res;
    }
};
