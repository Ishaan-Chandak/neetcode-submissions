/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    bool isSubtree(TreeNode* p, TreeNode* q) {
        if(q == nullptr) return true;

        if(p == nullptr) return false;

        if(isSameTree(p, q)) {
            return true;
        } 

        return isSubtree(p->left, q) or isSubtree(p->right, q);
       
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == nullptr and q == nullptr) return true;

        if(p == nullptr or q == nullptr) return false;

        bool left = isSameTree(p->left, q->left); 
        bool right = isSameTree(p->right, q->right);

        return left and right and (p->val == q->val); 
    }
    
};
