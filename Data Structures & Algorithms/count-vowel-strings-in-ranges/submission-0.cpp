class Solution {
public:
    bool check(string s) {
        int n = s.size();
        if(s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u') {
            if(s[n-1] == 'a' || s[n-1] == 'e' || s[n-1] == 'i' || s[n-1] == 'o' || s[n-1] == 'u') {
                return true;
            }
        }

        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int tot = 0;
        int n = words.size();
        vector<int> pre(n);
        for(int i=0; i<n; i++) {
            if(check(words[i])) tot++;
            pre[i] = tot;
        }

        vector<int> ans;
        for(auto i : queries) {
            if(i[0] == 0) ans.push_back(pre[i[1]]);
            else ans.push_back(pre[i[1]] - pre[i[0] - 1]);
        }

        return ans;
    }
};