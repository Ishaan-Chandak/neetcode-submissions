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
    int kthSmallest(TreeNode* root, int k) {
        int ans = -1, n = 0;
        dfs(root, k, n, ans);
        return ans ;
    }
    
    void dfs(TreeNode* root, int& k, int& n, int& ans) {
        if (root == nullptr || ans != -1) {
            return;
        }

        dfs(root->left, k, n, ans);

        n++;                    // current node is visited

        if (n == k) {
            ans = root->val;    // kth smallest found
            return;
        }

        dfs(root->right, k, n, ans);
    }
};
