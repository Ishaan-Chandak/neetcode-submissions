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
    ListNode* getKth(ListNode* curr, int k) {
        while(k-- && curr) {
            curr = curr->next;
        }

        return curr;
    }

    ListNode* reverseKGroup(ListNode* head, int k1) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* gp = dummy;

        while(true) {
            ListNode* k = getKth(gp, k1);
            if(!k) break;

            ListNode* gn = k->next;

            ListNode* prev = k->next;
            ListNode* curr = gp->next;

            while(curr != gn) {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            ListNode* temp = gp->next;
            gp->next = k;
            gp = temp; 
        }

        return dummy->next;
    }
};
