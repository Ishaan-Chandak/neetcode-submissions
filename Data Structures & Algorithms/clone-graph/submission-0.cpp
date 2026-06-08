/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == nullptr) return nullptr;

        unordered_map<int, Node*> mp;
        Node* head = new Node(node->val);
        mp[head->val] = head;
        queue<Node*> q;
        q.push(node);

        while(!q.empty()) {
            auto tp = q.front();
            q.pop();

            auto curr = mp[tp->val];

            for(auto nei : tp->neighbors) {
                Node* temp;
                if(mp.find(nei->val) == mp.end()) {
                    temp = new Node(nei->val);
                    mp[nei->val] = temp;
                    q.push(nei);
                } else {
                    temp = mp[nei->val];
                }

                curr->neighbors.push_back(temp);
            }
        }


        return head;
    }
};
