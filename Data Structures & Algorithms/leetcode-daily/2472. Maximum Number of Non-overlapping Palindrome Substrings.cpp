/*

I tried to solve this problem using DP, but was not able to - TLE

there is a DP solution which i was unable to understand, and hence used the greedy approach

GREEDY - simply says choose the smaller possible values equal to or greater than k
if anything bigger than k + 2, we can easily cut characters from the sides and choose the palindrome of length k

  */


class Solution {
public:
    bool isPalindrome(int i, int j, string &s, int &k) {
        int tempi = i, tempj = j;

        while (i < j) {
            if (s[i] != s[j]) return false;
            i++;
            j--;
        }

        return (tempj - tempi + 1) >= k ? true : false;
    }

    // int f(int i, int j, int &n, string &s, int &k, vector<vector<int>> &dp) {
    //     if(i == n) return isPalindrome(j, i - 1, s, k);

    //     int ans = INT_MIN;

    //     if(dp[i][j] != -1) return dp[i][j];

    //     int take = f(i + 1, i + 1, n, s, k, dp);
    //     if(isPalindrome(j, i, s, k)) {
    //         ans = max(ans, 1 + take);
    //     }
    //     int notTake = f(i + 1, j, n, s, k, dp);
    //     ans = max(ans, max(notTake, take));
    //     return dp[i][j] = ans;
    // }

    // int f(int i, int &n, string &s, int &k, vector<int> &dp) {
    //     if(i == n) return 0;

    //     if(dp[i] != -1) return dp[i];

    //     int ans = f(i + 1, n, s, k, dp);

    //     for(int j = i + k -1; j < n; j++) {
    //         if(isPalindrome(i, j, s, k)){
    //             int take = 1 + f(j + 1, n, s, k, dp);
    //             ans = max(ans, take);
    //         }
    //     }

    //     return dp[i] = ans;
    // }

    int maxPalindromes(string s, int k) {
        int n = s.size();
        // vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        // vector<int> dp(n + 1, -1);
        // return f(0, n, s, k, dp);

        // GREEDY solution

        int ans = 0, start = 0;
        for(int r = k -1; r < n; r++) {
            int l = r - k + 1;
            if(l >= start && isPalindrome(l, r, s, k)) {
                ans++;
                start = r + 1;
                continue;
            }

            l = r - k;
            if(l >= start && isPalindrome(l, r, s, k)) {
                ans++;
                start = r + 1;
            }
        }

        return ans;
    }
};
