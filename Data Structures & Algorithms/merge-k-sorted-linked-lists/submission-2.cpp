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
    ListNode* merge(ListNode* h1, ListNode* h2) {
        ListNode* head = new ListNode();
        ListNode* curr = head;

        while(h1 && h2) {
            // cout << "merging " << h1->val << " " << h2->val << endl;
            if(h1->val < h2->val) {
                ListNode* temp = h1->next;
                curr->next = h1;
                h1 = temp;
            } else {
                ListNode* temp = h2->next;
                curr->next = h2;
                h2 = temp;
            }

            curr = curr->next;
        }

        while(h1) {
            ListNode* temp = h1->next;
            curr->next = h1;
            h1 = temp;
            curr = curr->next;
        }

        while(h2) {
            ListNode* temp = h2->next;
            curr->next = h2;
            h2 = temp;
            curr = curr->next;
        }

        return head->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {

        if(lists.size() == 0) return nullptr;

        int n = lists.size();

        for(int i=1; i<n; i++) {
            ListNode* temp = merge(lists[i], lists[i-1]);
            lists[i] = temp; 
        }

        return lists[n-1];
    }
};
