// Count Prefix-Balanced Binary Strings - 25/08/2026

// catalan number
// this sovles it in O(n^2) time and O(n^2) space

// some mathematical formula exists but I could not understand it, hence stuck to this solution

class Solution {
    public:
      int mod = 1e9 + 7;
      int f(int ones, int zeros, int n, vector<vector<int>>& dp) {
          if(ones < zeros) return 0;
          if(ones > n || zeros > n) return 0;
          if(ones + zeros == 2 * n) return 1;
          
          if(dp[ones][zeros] != -1) return dp[ones][zeros];
          
          return dp[ones][zeros] = (f(ones +1, zeros, n, dp) % mod + f(ones, zeros + 1, n, dp) % mod) % mod;
      }
    
      int prefixStrings(int n) {
          // code here
          // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
          // return f(0, 0, n, dp);
          vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
          
          for(int i =0; i<=n; i++) {
              dp[n][i] = 1;
          }
          
          for(int i = n-1; i >= 0; i--) {
              for(int j = i; j >= 0; j--) {
                  dp[i][j] = (dp[i + 1][j] % mod + dp[i][j+1] % mod) % mod; 
              }
          }
          
          return dp[0][0];
      }
  };