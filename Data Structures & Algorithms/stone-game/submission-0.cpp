class Solution {
public:
    bool f(int i, int j, int turn, int curr, vector<int>& piles, vector<vector<vector<int>>>& dp) {
        if(i > j) return curr > 0;

        if(dp[i][j][turn] != -1) return dp[i][j][turn];

        if(turn == 0) {
            return dp[i][j][turn] = f(i + 1, j, 1, curr + piles[i], piles, dp) || f(i, j-1, 1, curr + piles[j], piles, dp);
        } else {
            return dp[i][j][turn] = f(i + 1, j, 0, curr - piles[i], piles, dp) || f(i, j-1, 0, curr - piles[j], piles, dp);
        }
    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
        return f(0, n-1, 0, 0, piles, dp);
    }
};