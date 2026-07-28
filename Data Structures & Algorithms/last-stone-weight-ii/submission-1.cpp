class Solution {
public:
    int f(int index, int curr, int target, int total, vector<int>& stones, vector<vector<int>>& dp) {
        if(index == 0 or curr >= target) return abs(curr - (total - curr));

        if(dp[index][curr] != -1) return dp[index][curr];

        return dp[index][curr] = min(f(index - 1, curr, target, total, stones, dp), f(index - 1, curr + stones[index], target, total, stones, dp));
    }

    int lastStoneWeightII(vector<int>& stones) {
        int tot = accumulate(stones.begin(), stones.end(), 0);
        int n = stones.size();
        vector<vector<int>> dp(n+1, vector<int>(tot, -1));

        return f(n-1, 0, tot/2, tot, stones, dp);
    }
};