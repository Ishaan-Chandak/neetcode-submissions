class Solution {
public:
    int f(int i, int j, vector<int>& piles, vector<vector<int>>& dp) {
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int left = (j - i) % 2 == 1 ? piles[i] : 0;
        int right = (j - i) % 2 == 1 ? piles[j] : 0;


        return dp[i][j] = max(left  + f(i + 1, j, piles, dp), right + f(i, j-1, piles, dp));

    }
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        int tot = accumulate(piles.begin(), piles.end(), 0);
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        int alice = f(0, n-1, piles, dp);
        return alice > tot - alice;
    }
};