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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int cnt = 0; // no of nodes
        ListNode* node = head;
        while(node) {
            ++cnt; node = node->next;
        }
        if(n == cnt) return head->next;
        int cnt2 = 1;
        node = head;
        while(cnt2 < cnt-n) {
            node = node->next;
            ++cnt2;
        }
        node->next = node->next->next;
        return head;
    }
};
