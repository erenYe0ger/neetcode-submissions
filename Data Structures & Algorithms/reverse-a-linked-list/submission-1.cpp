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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr) return nullptr;
        ListNode* n1 = head;
        ListNode* n2 = head->next;
        n1->next = nullptr;
        while(n2) {
            ListNode* n3 = n2->next;
            n2->next = n1;
            n1 = n2;
            n2 = n3;
        }
        return n1;
    }
};
