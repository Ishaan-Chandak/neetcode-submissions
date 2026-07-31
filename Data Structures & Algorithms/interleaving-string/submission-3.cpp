class Solution {
public:
    bool f(int i, int j, string& s1, string& s2, string& s3, vector<vector<int>>& dp) {
        if(i + j + 1 < 0) return i < 0 && j < 0;

        if(dp[i + 1][j + 1] != -1) return dp[i + 1][j + 1];

        bool ans = false;

        if(i >= 0 && s3[i + j + 1] == s1[i]) {
           ans = f(i - 1, j, s1, s2, s3, dp) || ans;
        } 

        if(j >= 0 && s3[i + j + 1] == s2[j]) {
            ans = f(i, j - 1, s1, s2, s3, dp) || ans;
        }

        return dp[i + 1][j + 1] = ans;
    } 

    bool isInterleave(string s1, string s2, string s3) {
        int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        if(n1 + n2 != n3) return false;
        vector<vector<int>> dp(n1 + 2, vector<int>(n2 + 2, -1));
        return f(n1 -1, n2 - 1, s1, s2, s3, dp);
    }
};
