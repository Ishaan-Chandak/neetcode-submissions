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
        queue<pair<TreeNode*, int>> q;
        if(root) q.push({root, 1});
        int ret = INT_MIN;

        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            TreeNode* p = curr.first;
            int currHeight = curr.second;
            ret = max(ret, currHeight);
            if(p->left) q.push({p->left, currHeight+1});
            if(p->right) q.push({p->right, currHeight+1});
        }

        return ret == INT_MIN ? 0 : ret;
    }
};
