class Solution {
public:
    int f(int index, int curr, int target, vector<int>& coins, vector<vector<int>>& dp) {
        if(curr == target) return 1;
        if(index < 0 || curr > target) return 0;

        if(dp[index][curr] != -1) return dp[index][curr];

        int pick = f(index, curr + coins[index], target, coins, dp);
        int notPick = f(index - 1, curr, target, coins, dp);

        return dp[index][curr] = pick + notPick;
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1, -1));
        return f(n-1, 0, amount, coins, dp);
    }
};
