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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head) return head;
        ListNode* cur = head;
        for(int i=0; i<k-1; ++i) {
            if(!cur) return head;
            cur = cur->next;
        }   
        if(!cur) return head;
        cur->next = reverseKGroup(cur->next, k);
        ListNode* prev = cur->next;
        cur = head;
        for(int i=0; i<k; ++i) {
            ListNode* nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
        }
        return prev;
    }
};
