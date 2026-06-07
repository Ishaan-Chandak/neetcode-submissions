class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> partition(string s) {
        vector<string> part;
        dfs(s, part, 0);
        return ans;
    }

    bool isPalindrome(string& s, int i, int j) {
        while(i < j) {
            if(s[i] != s[j]) return false;
            i++;
            j--;
        }

        return true;
    }

    void dfs(string& s, vector<string> part, int idx) {
        if(idx >= s.size()) {
            ans.push_back(part);
            return;
        }

        for(int i=idx; i < s.size(); i++) {
            if(isPalindrome(s, idx, i)){
                part.push_back(s.substr(idx, i-idx+1));
                dfs(s, part, i+1);
                part.pop_back();
            }
        } 
    }
};
