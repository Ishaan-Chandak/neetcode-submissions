/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> mp;
        mp[nullptr] = nullptr;

        Node* curr = head;
        while(curr) {
            if(mp.find(curr) == mp.end()) {
                mp[curr] = new Node(0);
            }
            mp[curr]->val = curr->val;
            
            if(mp.find(curr->next) == mp.end()) {
                mp[curr->next] = new Node(0);
            }
            mp[curr]->next = mp[curr->next];

            if(mp.find(curr->random) == mp.end()) {
                mp[curr->random] = new Node(0);
            }
            mp[curr]->random = mp[curr->random];

            curr = curr->next;
        }

        return mp[head];
    }
};
