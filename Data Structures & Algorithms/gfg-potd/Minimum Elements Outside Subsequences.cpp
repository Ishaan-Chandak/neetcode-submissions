class Solution {
  public:
    int f(int index, int prevSmall, int prevLarge, int &n, vector<int> &arr, vector<vector<vector<int>>> &dp) {
        if(index == n) return 0;
        
        if(dp[index][prevSmall + 1][prevLarge + 1] != -1) return dp[index][prevSmall + 1][prevLarge + 1];
        
        int takeLarge = INT_MAX, takeSmall = INT_MAX, notTake = INT_MAX;
        
        notTake = 1 + f(index + 1, prevSmall, prevLarge, n, arr, dp);
        
        if(prevSmall == -1 or arr[prevSmall] < arr[index]) takeSmall = f(index + 1, index, prevLarge, n, arr, dp);
        if(prevLarge == -1 or arr[prevLarge] > arr[index]) takeLarge = f(index + 1, prevSmall, index, n, arr, dp);
        
        return dp[index][prevSmall + 1][prevLarge + 1] = min(notTake, min(takeSmall, takeLarge));
    }
  
    int minCount(vector<int>& arr) {
        // code here
        int n = arr.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 2, vector<int>(n + 2, -1)));
        return f(0, -1, -1, n, arr, dp);
    }
};
