class Solution {
public:
    unordered_map<char, string> mp = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };

    vector<string> ans;

    vector<string> letterCombinations(string digits) {
        if(digits == "") return {};

        vector<string> curr;
        for(auto c : digits) curr.push_back(mp[c]);
        dfs(curr, 0, "");
        return ans;
    }

    void dfs(vector<string>& curr, int idx, string str) {
        if(idx == curr.size()) {
            ans.push_back(str);
            return;
        }

        for (auto c : curr[idx]) {
            str.push_back(c);
            dfs(curr, idx + 1, str);
            str.pop_back();
        }
    }
};
