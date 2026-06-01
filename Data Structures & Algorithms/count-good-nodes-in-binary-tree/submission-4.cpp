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
    int goodNodes(TreeNode* root) {
        int max = INT_MIN, ans = 0;
        dfs(root, max, ans);

        return ans;
    }

    void dfs(TreeNode* root, int maxi, int& cnt) {
        if(root == nullptr) return;

        if(maxi <= root->val) {
            cnt++;
            cout << root->val << endl;
        }

        maxi = max(maxi, root->val);
        dfs(root->left, maxi, cnt);
        dfs(root->right, maxi, cnt);
    }
};
