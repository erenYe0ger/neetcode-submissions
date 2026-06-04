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
            if(list) heap.push(make_pair(list->val, list));
        }
        ListNode dummy;
        ListNode* node = &dummy;
        while(!heap.empty()) {
            ListNode* minNode = heap.top().second; heap.pop();
            if(minNode->next) heap.push(make_pair(minNode->next->val, minNode->next));
            node->next = minNode;
            node = node->next;
        }
        node->next = nullptr;
        return dummy.next;
    }
};
