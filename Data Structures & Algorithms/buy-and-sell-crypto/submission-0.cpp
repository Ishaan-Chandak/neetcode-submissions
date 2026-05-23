class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = INT_MAX;
        int ans = 0;
        int n = prices.size();
        for(int i =0; i<n; i++) {
            mini = min(prices[i], mini);
            ans = max(ans, prices[i] - mini);
        }

        return ans;
    }
};
