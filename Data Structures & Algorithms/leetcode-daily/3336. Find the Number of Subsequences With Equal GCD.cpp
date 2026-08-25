class Solution {
public:
    int modulo = 1e9 + 7;
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a%b);
    }

    int f(int i, int gcd1, int gcd2, vector<int>& nums, vector<vector<vector<int>>>& dp) {
        if(i < 0) return gcd1 == gcd2 && gcd1 != 0;

        if(dp[i][gcd1][gcd2] != -1) return dp[i][gcd1][gcd2];

        int ans = 0;
        ans = f(i-1, gcd1, gcd2, nums, dp);

        int ng1 = gcd1 == 0 ? nums[i] : gcd(gcd1, nums[i]);
        ans = ans % modulo + f(i-1, ng1, gcd2, nums, dp) % modulo;

        int ng2 = gcd2 == 0 ? nums[i] : gcd(gcd2, nums[i]);
        ans = ans % modulo + f(i-1, gcd1, ng2, nums, dp) % modulo;

        return dp[i][gcd1][gcd2] = ans % modulo;
    }

    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        vector<vector<vector<int>>> dp(nums.size(), vector<vector<int>>(201, vector<int>(201, -1)));
        return f(n-1, 0, 0, nums, dp);
    }
};
