class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> res;
        unordered_map<int,int> mp;
        for(auto& i: nums) ++mp[i];
        typedef pair<int,int> P;
        priority_queue<P, vector<P>, greater<P>> pq; // min-heap
        for(auto& [i,f] : mp) {
            pq.push(make_pair(f,i));
            if(pq.size() > k) pq.pop();
        }
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};
