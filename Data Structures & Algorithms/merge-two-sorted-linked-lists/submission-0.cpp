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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;

        ListNode* start;

        if(list1->val < list2->val) {
            start = list1;
            list1 = list1->next;
        } else {
            start = list2;
            list2 = list2->next;
        }
        
        ListNode* ans = start;

        while(list1 != nullptr && list2 != nullptr) {
            if(list1->val < list2->val) {
                start-> next = list1;
                start = start->next;
                list1 = list1->next;
            } else {
                start-> next = list2;
                start = start->next;
                list2 = list2->next;
            }
        }

        while(list1 != nullptr) {
            start->next = list1;
            start = start->next;
            list1 = list1->next;
        }

        while(list2 != nullptr) {
            start-> next = list2;
            start = start->next;
            list2 = list2->next;
        }

        return ans;
    }
};
