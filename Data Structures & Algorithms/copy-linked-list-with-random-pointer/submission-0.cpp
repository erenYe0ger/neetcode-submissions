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
        Node dummy(0);
        Node *node = &dummy, *node2 = head;
        map<Node*, Node*> mp;
        while(node2) {
            node->next = new Node(node2->val);
            node = node->next;
            mp[node2] = node; 
            node2 = node2->next;
        }
        node = dummy.next, node2 = head;
        while(node2) {
            if(node2->random) node->random = mp[node2->random];
            node = node->next;
            node2 = node2->next;
        }
        return dummy.next;
    }
};
