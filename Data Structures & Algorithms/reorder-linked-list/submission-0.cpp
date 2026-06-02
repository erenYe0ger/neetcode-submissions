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
    ListNode* reverse(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* nextNode = head->next;
        ListNode* newHead = reverse(head->next);
        nextNode->next = head;
        head->next = nullptr;
        return newHead;
    }
public:
    void reorderList(ListNode* head) {
        if(!head) return;
        ListNode *slow = head, *fast = head;
        while(fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* list2 = reverse(slow->next);
        ListNode* list1 = head;
        slow->next = nullptr;
        while(list1 && list2) {
            ListNode *list1Next = list1->next, 
                    *list2Next = list2->next;
            list1->next = list2;
            list2->next = list1Next;
            list1 = list1Next;
            list2 = list2Next;
        }
        if(list1) list1->next = nullptr;
    }
};
