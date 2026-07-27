class Solution {
public:
    int f(int n, vector<int>& dp, int& origN) {
        if(n == 0) return 1;
        if(n < 0) return -1;

        if(dp[n] != -1) return dp[n];

        int maxi = INT_MIN;
        for(int i=1; i<origN; i++) {
            int temp = i * f(n - i, dp, origN);
            maxi = max(maxi, temp);
        }
        return dp[n] = maxi;
    }
    int integerBreak(int n) {
        vector<int> dp(n+1, -1);
        return f(n, dp, n);
    }
};