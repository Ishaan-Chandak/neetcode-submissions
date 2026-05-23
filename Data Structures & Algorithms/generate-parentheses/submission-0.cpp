class Solution {
public:
    void solve(int n, int openN, int closedN, string curr, vector<string>& res) {
        if(openN == closedN && openN == n) {
            res.push_back(curr);
            return;
        }

        if(openN < n) {
            solve(n, openN + 1, closedN, curr + "(", res);
        }

        if(closedN < openN) {
            solve(n, openN, closedN + 1, curr + ")", res);
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        solve(n, 0, 0, "", res);
        return res;
    }
};
