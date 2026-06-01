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
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_MIN, LONG_MAX);
    }

    bool dfs(TreeNode* root, long maxi, long mini) {
        if(root == nullptr) return true;

        if(!(maxi < root->val and root->val < mini)) {
            return false;
        }
 
        bool left = dfs(root->left, maxi, root->val);
        bool right = dfs(root->right, root->val, mini);

        return left and right;
    }
};
