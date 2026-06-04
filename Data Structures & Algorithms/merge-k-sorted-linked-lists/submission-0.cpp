/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        typedef pair<ListNode*, ListNode*> P;
        map<int, P> mp;
        for(ListNode* list: lists) {
            ListNode* node = list;
            while(node) {
                int val = node->val;
                if(mp.count(val)) {
                    ListNode* &tail = mp[val].second;
                    tail->next = node;
                    tail = tail->next;
                } else {
                    mp[val] = make_pair(node, node);
                }
                node = node->next;
            }
        }
        ListNode dummy;
        ListNode* node = &dummy;
        for (auto& [val, p]: mp) {
            ListNode *head = p.first, *tail = p.second;
            node->next = head;
            node = tail;
        }
        return dummy.next;
    }
};