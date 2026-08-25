// marked as EASY but is not easy
// slight modification of LIS, but here we need to understand that the current number is just one greater than the previous one.
// Makes this valid for the map approach
// was not able to optimize this to O(n) time
// this optimizzation cannot be done for normal LIS but the +1 condition helps it here


class Solution {
    public:
      int lcs(int i, int prev, int n, vector<int>& arr, vector<vector<int>>& dp) {
          if(i == n) return 0;
          
          if(dp[i][prev + 1] != -1) return dp[i][prev + 1];
          
          int take = INT_MIN, notTake = INT_MIN;
          if(prev != -1 && arr[i] == arr[prev] + 1) take = 1 + lcs(i + 1, i, n, arr, dp);
          else if (prev == -1) take = lcs(i + 1, i, n , arr, dp);
          notTake = lcs(i + 1, prev, n, arr, dp);
          
          return dp[i][prev + 1] = max(take, notTake);
      }
    
      int minMoves(vector<int>& arr) {
          // code here
          int n = arr.size();
          // vector<vector<int>> dp(n + 1, vector<int>(n+2, -1));
          // return n - lcs(0, -1, n, arr, dp) - 1;
          
          // vector<vector<int>> dp(n + 1, vector<int>(n+2, 0));
          
          
          // for(int i = n -1; i >= 0; i--) {
          //     for(int prev = 0; prev<=i; prev++) {
          //         int take = INT_MIN, notTake = INT_MIN;
          //         if(prev != 0 && arr[i] == arr[prev - 1] + 1) take = 1 + dp[i + 1][i + 1];
          //         else if (prev == 0) take = dp[i + 1][i + 1];
          //         notTake = dp[i + 1][prev];
                  
          //         dp[i][prev] = max(take, notTake);
          //     }
          // }
          
          
          // return n - dp[0][0] - 1;
          
          unordered_map<int, int> dp;
          int ans = INT_MIN;
          
          for(int i = 0; i<n; i++) {
              int curr = 1;
              if(dp.find(arr[i-1]) != dp.end()) curr = 1 + dp[arr[i] - 1];
              
              dp[arr[i]] = max(dp[arr[i]], curr);
              
              ans = max(ans, dp[arr[i]]);
          }
          
          return n - ans;
      }
  };