/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return node;
        unordered_map<Node*, Node*> mp;
        unordered_set<Node*> st;
        auto bfs = [&]() {
            queue<Node*> q;
            q.push(node);
            st.insert(node);
            while(!q.empty()) {
                auto u = q.front(); q.pop();
                mp[u] = new Node(u->val);
                for(auto v: u->neighbors) {
                    if(st.count(v)) continue;
                    st.insert(v);
                    q.push(v);
                }
            }
        };
        bfs();
        st.clear();
        auto bfs2 = [&]() {
            queue<Node*> q;
            q.push(node);
            st.insert(node);
            while(!q.empty()) {
                auto u = q.front(); q.pop();
                for(auto v: u->neighbors) {
                    mp[u]->neighbors.push_back(mp[v]);
                    if(st.count(v)) continue;
                    st.insert(v);
                    q.push(v);
                }
            }
        };
        bfs2();
        return mp[node];
    }
};
