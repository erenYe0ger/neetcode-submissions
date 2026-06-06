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
        int cnt = 0;
        ListNode *cur = head, *tail;
        auto reverse = [&]() {
            ListNode *prv = nullptr, *cur2 = head;
            while(cur2 != cur) {
                ListNode* nxt = cur2->next;
                cur2->next = prv;
                prv = cur2;
                cur2 = nxt;
            }
            cur2->next = prv;
            tail = head, head = cur;
        };
        while(cur) {
            if(cnt == k-1) {
                ListNode* curNext = cur->next;
                reverse();
                tail->next = reverseKGroup(curNext, k);
                break;
            }
            cur = cur->next;
            ++cnt;
        }
        return head;
    }
};
