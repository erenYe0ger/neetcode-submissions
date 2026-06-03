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
        ListNode dummy;
        ListNode* node = &dummy;
        int carry = 0, sum;
        while(l1 && l2) {
            sum = carry + l1->val + l2->val;
            carry = sum / 10;
            sum %= 10;
            node->next = new ListNode(sum);
            node = node->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1) {
            sum = carry + l1->val;
            carry = sum / 10;
            sum %= 10;
            node->next = new ListNode(sum);
            node = node->next;
            l1 = l1->next;
        }
        while(l2) {
            sum = carry + l2->val;
            carry = sum / 10;
            sum %= 10;
            node->next = new ListNode(sum);
            node = node->next;
            l2 = l2->next;
        }
        if(carry) node->next = new ListNode(carry);
        return dummy.next;
    }
};
