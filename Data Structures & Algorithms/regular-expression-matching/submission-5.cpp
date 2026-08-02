class Solution {
public:
    int f(int i, int j, int n, int m, string& s, string& p, vector<vector<int>>& dp) {
        if(j == m) return i == n;

        if(dp[i][j] != -1) return dp[i][j];
        
        bool match = (i < n && (s[i] == p[j] || p[j] == '.'));
        if(j + 1 < m && p[j+1] == '*') {
            return dp[i][j] = (f(i, j + 2, n, m, s, p, dp) || (match && f(i + 1, j, n, m, s, p, dp)));
        } 

        if(match) return dp[i][j] = f(i + 1, j + 1, n, m, s, p, dp);

        return dp[i][j] = false;
    } 

    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        // return f(0, 0, n, m, s, p, dp);

        dp[n][m] = true;

        for(int i = n; i >= 0; i--) {
            for(int j = m - 1; j >= 0; j--) {
                bool match = (i < n && (s[i] == p[j] || p[j] == '.'));
                if(j + 1 < m && p[j+1] == '*') {
                    dp[i][j] = dp[i][j + 2] || (match && dp[i + 1][j]);
                } else if(match) {
                    dp[i][j] = dp[i + 1][j + 1];
                }
            }
        }


        return dp[0][0];
    }
};
