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
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode dummy;
        ListNode* list = &dummy;
        while(list1 || list2) {
            if(!list2) {
                list->next = list1;
                list1 = list1->next;
            } 
            else if(!list1) {
                list->next = list2;
                list2 = list2->next;
            }
            else {
                if(list1->val < list2->val) {
                    list->next = list1;
                    list1 = list1->next;
                } else {
                    list->next = list2;
                    list2 = list2->next;
                }
            }
            list = list->next;
        }
        return dummy.next;
    }
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* finalList = nullptr;
        for(auto& list: lists) finalList = merge(finalList, list);
        return finalList;
    }
};
