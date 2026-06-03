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

using namespace std;

class Codec {
public:
    string res = "";

    void dfs(TreeNode* root) {
        if(root == nullptr) {
             res += "N,";
            return;
        }

        res += to_string(root->val) + ",";
        dfs(root->left);
        dfs(root->right);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        dfs(root);
        cout << res << endl;
        return res;
    }

    vector<string> split(const string& s, char delim) {
        vector<string> res;
        string cur;

        for (char c : s) {
            if (c == delim) {
                res.push_back(cur);
                cur.clear();
            } else {
                cur += c;
            }
        }

        res.push_back(cur);

        return res;
    }

    TreeNode* dfs(vector<string>& data, int& i) {
        if(data[i] == "N") {
            i++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(data[i]));
        i++;
        node->left = dfs(data, i);
        node->right = dfs(data, i);

        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int i = 0;
        vector<string> res = split(data, ',');
        return dfs(res, i);
    }
};
