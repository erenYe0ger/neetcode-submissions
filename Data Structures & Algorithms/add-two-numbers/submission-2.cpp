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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head1 = l1, *head2 = l2;
        bool valid1 = true, valid2 = true;

        ListNode *prev1, *prev2;
        int carry = 0;
        while(l1 || l2) {
            int sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
            carry = sum / 10;
            sum %= 10;
            
            if(l1) {
                l1->val = sum; prev1 = l1;
            } else valid1 = false;

            if(l2) {
                l2->val = sum; prev2 = l2;
            } else valid2 = false;

            if(l1) l1 = l1->next; if(l2) l2 = l2->next;
        }

        if(carry) {
            if(valid1) prev1->next = new ListNode(carry); 
            if(valid2) prev2->next = new ListNode(carry); 
        }

        if(valid1) return head1;
        return head2;
    }
};
