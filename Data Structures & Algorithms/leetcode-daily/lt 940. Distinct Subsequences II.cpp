
/*

Completely new for me but great question
  */

class Solution {
public:
    int mod = 1e9 + 7;
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<long long> dp(n + 1, 1);
        dp[0] = 1;
        unordered_map<char, int> mp;
        
        for(int i = 1; i <= n; i++) {
            if(mp.find(s[i - 1]) == mp.end()) {
                dp[i] = (2 * dp[i - 1]) % mod;
            } else {
                int temp = mp[s[i - 1]];
                dp[i] = (2 * dp[i - 1] - dp[temp] + mod) % mod;
            }
            mp[s[i - 1]] = i - 1;
        }

        return (dp[n] - 1 + mod) % mod;
    }
};
