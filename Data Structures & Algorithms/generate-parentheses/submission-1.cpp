class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        backtrack(0, 0, "", n);
        return ans;
    }

    void backtrack(int open, int close, string s, int& n) {
        if(open == close && open == n) {
            ans.push_back(s);
            return;
        }

        if(open > n) return;
        
        if(open > close) {
            backtrack(open +1, close, s + "(", n);
            backtrack(open, close + 1, s + ")", n);
        } else {
            backtrack(open +1, close, s + "(", n);
        }
    }
};
