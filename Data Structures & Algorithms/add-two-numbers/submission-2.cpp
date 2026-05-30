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
    ListNode* reverse(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = nullptr;

        while(curr) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        // l1 = reverse(l1);  
        // l2 = reverse(l2); 
        int cnt = 0;
        int ans = 0;

        ListNode* ret = new ListNode();

        ListNode* cpy = ret;

        while(l1 and l2) {
            int temp = l1->val + l2->val + carry;
            if(temp >= 10) carry = 1;
            else carry = 0;

            ListNode* temp1 = new ListNode(temp % 10);
            cpy->next = temp1;
            cpy = cpy->next;
            
            l1 = l1->next;
            l2 = l2->next;
        }

        while(l1) {
            int temp =  l1->val + carry;
            if(temp >= 10) carry = 1;
            else carry = 0;

            ListNode* temp1 = new ListNode(temp % 10);
            cpy->next = temp1;
            cpy = cpy->next;
            
            l1 = l1->next;
        }

        while(l2) {
            int temp =  l2->val + carry;
            if(temp >= 10) carry = 1;
            else carry = 0;

            ListNode* temp1 = new ListNode(temp % 10);
            cpy->next = temp1;
            cpy = cpy->next;

            l2 = l2->next;
        }

        if (carry == 1) {
            ListNode* temp1 = new ListNode(1);
            cpy->next = temp1;
            cpy = cpy->next;
        }


        return ret->next;       
    }
};
