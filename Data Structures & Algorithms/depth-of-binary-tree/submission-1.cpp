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
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        int ans = 0;

        while(!q.empty()) {
            pair<TreeNode*, int> temp = q.front();
            q.pop();

            ans = max(ans, temp.second);
            if(temp.first->right) q.push({temp.first->right, temp.second+1}); 
            if(temp.first->left) q.push({temp.first->left, temp.second+1}); 
        }

        return ans;
    }
};
