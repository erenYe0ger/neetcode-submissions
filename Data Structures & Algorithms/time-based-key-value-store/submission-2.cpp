class TimeMap {
    typedef pair<int,string> P;
    unordered_map<string, vector<P>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int time) {
        mp[key].push_back(make_pair(time, value));
    }
    
    string get(string key, int time) {
        auto v = mp[key];
        auto it = upper_bound(v.begin(), v.end(),
                         make_pair(time+1, ""));
        if(it == v.begin()) return "";
        return prev(it)->second;
    }
};
