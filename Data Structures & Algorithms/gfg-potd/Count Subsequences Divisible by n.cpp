// learnt that whenever we have questions regarding divisibility it is always important to think in terms of remainders
// hrer I was intially calculating values completely
// after seeing the solution I realized divisibility question ==== remainder usage

class Solution {
  public:
    int mod = 1e9 + 7;
    int f(int index, int val, int& k, string& s, vector<vector<int>>& dp) {
        if(index == s.size()) {
            return val == 0 ? 1 : 0;
        }
        
        if(dp[index][val + 1] != -1) return dp[index][val + 1];
        
        int notTake = f(index + 1, val, k, s, dp);
        int newValue = val == -1 ? (s[index] - '0') : val * 10 + (s[index] - '0');
        int take = f(index + 1, newValue % k, k, s, dp);
        
        return dp[index][val + 1] = (notTake % mod + take % mod) % mod;
    }
    int countSubsequences(string& s, int k) {
        // code here
        // vector<vector<int>> dp(s.size() + 1, vector<int>(n + 1, -1));
        vector<vector<int>> dp(s.size() + 1, vector<int>(k + 1, 0));
        
        int n = s.size();
        
        dp[n][1] = 1;
        for(int i = n - 1; i >= 0; i--) {
            for(int j = -1; j<k; j++) {
                int notTake = dp[i + 1][j + 1];
                int newValue = j == -1 ? (s[i] - '0') : j * 10 + (s[i] - '0');
                int take = dp[i + 1][(newValue % k) + 1];
                
                dp[i][j + 1] = (notTake % mod + take % mod) % mod;
            }
        }
        
        return dp[0][0];
        // return f(0, -1, n, s, dp);
    }
};
