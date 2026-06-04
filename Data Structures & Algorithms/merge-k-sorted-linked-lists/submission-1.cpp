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
        typedef pair<int, ListNode*> P;
        priority_queue<P, vector<P>, greater<P>> heap;
        for(ListNode* list: lists) {
            ListNode* node = list;
            while(node) {
                heap.push(make_pair(node->val, node));
                node = node->next;
            }
        }
        ListNode dummy;
        ListNode* node = &dummy;
        while(!heap.empty()) {
            node->next = heap.top().second;
            heap.pop();
            node = node->next;
        }
        node->next = nullptr;
        return dummy.next;
    }
};
