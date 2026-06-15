class Solution {
    typedef pair<string, int> P; // {city, used}
    map<string, vector<P>> adj;
    vector<string> res;
    int ticketCount;
    bool dfs(string city) {
        res.push_back(city);
        if(res.size() == ticketCount + 1) return true;
        for(auto& [nextCity, used]: adj[city]) {
            if(used) continue;
            used = 1;
            if(dfs(nextCity)) return true;
            used = 0;
        }
        res.pop_back();
        return false;
    }
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        ticketCount = tickets.size();
        for(auto& ticket: tickets) {
            adj[ticket[0]].push_back({ticket[1], 0}); // 0 means ticket not used
        }
        for(auto& [city, edges]: adj) sort(edges.begin(), edges.end());
        dfs("JFK");
        return res;
    }
};
