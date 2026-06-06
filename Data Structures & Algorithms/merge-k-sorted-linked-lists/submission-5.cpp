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
        int k = lists.size();
        if(k == 0) return nullptr;
        while(k > 1) {
            vector<ListNode*> newLists;
            for(int i=0; i<k; i+=2) {
                if(i+1 < k) newLists.push_back(merge(lists[i], lists[i+1]));
                else newLists.push_back(lists[i]);
            }
            lists = newLists;
            k = (k+1)/2;
        }
        return lists[0];
    }
};
