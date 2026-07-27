class Solution {
public:
    vector<int> squares;

    int solve(int n, vector<int>& dp) {
        if(n == 0) return 1;
        if(n < 0) return 1e9;

        if(dp[n] != -1) return dp[n];

        int ans = INT_MAX;
        for(auto i : squares) {
            int temp = 1 + solve(n - i, dp);
            ans = min(ans, temp);
        } 

        return dp[n] = ans;
    }

    int numSquares(int n) {
        int i = 1;
        while(i*i <= n) {
            squares.push_back(i*i);
            i++;
        }

        vector<int> dp(n + 1, -1);

        return solve(n, dp) - 1;
    }
};