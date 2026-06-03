/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        Node *node = head;
        while(node) {
            mp[node] = new Node(node->val);
            node = node->next;
        }
        node = head;
        while(node) {
            if(node->next) mp[node]->next = mp[node->next];
            if(node->random) mp[node]->random = mp[node->random];
            node = node->next;
        }
        return mp[head];
    }
};
