class TimeMap {
    typedef pair<int,string> P;
    map<string, set<P>> mp;
public:
    TimeMap() {
        
    }
    
    void set(string key, string value, int time) {
        mp[key].insert(make_pair(time, value));
    }
    
    string get(string key, int time) {
        auto it = mp[key].upper_bound(make_pair(time+1, ""));
        if(it == mp[key].begin()) return "";
        return prev(it)->second;
    }
};
