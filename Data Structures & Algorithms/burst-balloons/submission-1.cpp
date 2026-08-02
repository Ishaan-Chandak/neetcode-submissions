class Solution {
public:
    int f(int l, int r, vector<int>& nums, vector<vector<int>>& dp) {
        if(l > r) return 0;

        if(dp[l][r] != -1) return dp[l][r];

        int maxi = INT_MIN;
        for(int i = l; i<=r; i++) {
            int temp = nums[l-1] * nums[i] * nums[r + 1];
            temp += f(l, i - 1, nums, dp) + f(i +1, r, nums, dp);
            maxi = max(temp, maxi);
        }

        return dp[l][r] = maxi;
    }

    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));
        return f(1, nums.size() - 2, nums, dp);
    }
};
