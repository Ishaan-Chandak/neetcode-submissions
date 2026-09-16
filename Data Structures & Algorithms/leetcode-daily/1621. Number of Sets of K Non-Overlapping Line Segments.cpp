/*

Classic DP solution 

I wrote the intial commented code with help but the actual code is way simpler like mentioned, it is very important to see these patterns

Optimal Solution - using mathematics

  */

class Solution {
public:
    int mod = 1e9 + 7;

    // int f(int curr, int start, int cnt, int &n, int &k, vector<vector<vector<int>>> &dp) {
    //     if(curr >= n) {
    //         return cnt == k;
    //     }

    //     if(cnt == k) {
    //         return 1;
    //     }

    //     if(dp[curr][start + 1][cnt] != -1) return dp[curr][start + 1][cnt];

    //     int include, newstart;
    //     if(start == -1) {
    //         include = f(curr + 1, start, cnt, n, k, dp);
    //         newstart = f(curr + 1, curr, cnt, n, k, dp);
    //     } else {
    //         include = f(curr + 1, start, cnt, n, k, dp);

    //         bool isPossible = curr > start ? true : false;

    //         newstart = 0;
    //         if(isPossible) {
    //             if(cnt + 1 == k) newstart = 1;
    //             else {
    //                 newstart = (newstart % mod + f(curr + 1, curr, cnt + 1, n, k, dp) % mod) % mod;
    //                 newstart = (newstart % mod + f(curr + 1, -1, cnt + 1, n, k, dp)) % mod;
    //             }
                
    //         }
    //     }

    //     return dp[curr][start + 1][cnt] = (include % mod + newstart % mod) % mod;
    // }


    int f(int index, int k, int &n, bool start, vector<vector<vector<int>>> &dp) {
        if(k == 0) return 1;
        if(index == n) return 0;

        if(dp[index][k][start] != -1) return dp[index][k][start];

        int ans = f(index + 1, k, n, start, dp) % mod;
        if(start) {
            ans = (ans % mod + f(index + 1, k, n, false, dp) % mod) % mod;
        } else {
            ans = (ans % mod + f(index, k - 1, n, true, dp) % mod) % mod;
        }

        return dp[index][k][start] = ans;
    }

    int numberOfSets(int n, int k) {
        // vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 2, vector<int>(k + 1, -1)));
        // int ret = f(0, -1, 0, n, k, dp);
        // return ret;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2, -1)));
        return f(0, k, n, true, dp);
    }
};
