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
        ListNode *left = head, *right = head;
        for(int i=0; i<n; ++i) right = right->next;
        if(!right) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        } 
        while(right->next) left = left->next, right = right->next;
        ListNode* node = left->next;
        left->next = left->next->next;
        delete node;
        return head;
    }
};
