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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};
        vector<vector<int>> ans;

        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int curr = 0;
        vector<int> level;
        while(!q.empty()) {
            auto temp = q.front();
            q.pop();

            if(temp.second == curr) {
                level.push_back(temp.first->val);
            } else {
                ans.push_back(level);
                level.clear();
                level.push_back(temp.first->val);
                curr++;
            }

            if(temp.first->left) q.push({temp.first->left, temp.second + 1}); 
            if(temp.first->right) q.push({temp.first->right, temp.second + 1}); 
        }

        ans.push_back(level);


        return ans;
    }

    vector<int> rightSideView(TreeNode* root) {
        vector<vector<int>> bfs = levelOrder(root);
        vector<int> ans;
        for(auto v: bfs) ans.push_back(v.back());

        return ans; 
    }
};
