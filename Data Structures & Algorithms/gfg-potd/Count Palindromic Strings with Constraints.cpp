class Solution {
  public:
    int mod = 1e9 + 7;
    
    int f(int& n, int& k) {
        long long ret = k;
        
        // cout << n << " " << k << " " << n / 2 << endl;
        
        if(n % 2 == 1) {
            for(int i = 1; i <= n/2; i++) {
                ret = (ret * (k - i)) % mod;
            }
        } else {
            for(int i = 1; i <= (n/2) - 1; i++) {
                ret = (ret * (k - i)) % mod;
            }
        }
        
        return ret;
    }
    
    int palindromicStrings(int n, int k) {
        // code here
        int ans = 0;
        
        if(n >= 1) ans += k;
        
        if(n >= 2) ans += k;
        
        vector<long long> dp(n + 1);
        dp[1] = k;
        dp[2] = k;
        
        for(int i = 3; i <= n; i++) {
            // int temp = f(i, k);
            int temp = (i + 1) / 2;
            int prev = i / 2;
            
            // cout << temp << " " << prev << " " << i << endl;
            long long curr;
            if(temp != prev) {
                curr = (dp[i - 1] * (k - i/2)) % mod;
            } else {
                curr = dp[i - 1];
            }
            ans = (ans%mod + curr%mod) % mod;
            dp[i] = curr;
        }
        
        return ans;
    }
};
