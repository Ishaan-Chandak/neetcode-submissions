class Solution {
public:
    unordered_map<string, char> mp;
    int f(int i, int& n, string& s, vector<int>& dp) {
        if(i == n) {
            // cout << "n" << endl;
            return 1;    
        }

        if(dp[i] != -1) return dp[i];
        
        int ans = 0;
        for(int j = i; j<min(n, (i+2)); j++) {
            // if(j == n-1) cout << "n-1" << endl;
            if(mp.find(s.substr(i, j - i + 1)) != mp.end()) {
                // cout << s.substr(i, j) << endl;
                // cout << "inside loop " << i << " " << j << endl;
                ans += f(j+1, n, s, dp);
            }
        }

        return dp[i] = ans;
    }

    int numDecodings(string s) {
        int n = s.size();

        char c = 'A';
        for(int i=0; i<26; i++) {
            // cout << i << " " << c << endl;
            mp[to_string(i+1)] = c++;
        }

        vector<int> dp(n+1, -1);

        return f(0, n, s, dp);
        // return 0;
    }
};
