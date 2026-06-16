class Solution {
    typedef priority_queue<string, vector<string>, greater<string>> minHeap;
    unordered_map<string, minHeap> adj;
    vector<string> res;
    void dfs(string city) {
        while(!adj[city].empty()) {
            string nextCity = adj[city].top();
            adj[city].pop();
            dfs(nextCity);
        }
        res.push_back(city);
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto& ticket: tickets) {
            adj[ticket[0]].push(ticket[1]);
        }
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};
