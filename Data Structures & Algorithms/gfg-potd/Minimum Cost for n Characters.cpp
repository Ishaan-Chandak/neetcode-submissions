/*
This question got me irritated, was ending in infinite loop

trick

ans = i * curr (take into account scenarios when the best way is to just keep on adding one at a time and not mulitplying by 2)
this is necessary because we assume that when (n) will be evem the best way possible is dividing by 2

keeping this the start value ensures, if muliplying by 2 is not the best way we are using it

and for the odd part it is generic 

this does not end up on infinite loop
*/


class Solution {
  public:
    int f(int curr, int &n, int &i, int &d, int &c, vector<int>& dp) {
        if(curr == 0) return 0;
        
        if(curr == 1) return i;
        
        if(dp[curr] != -1) return dp[curr];
        
        int ans = i * curr;
        if(curr % 2 == 0) {
            int temp = c + f(curr / 2, n, i, d, c, dp);
            ans = min(ans, temp);
        } else {
            int add = i + f(curr - 1, n, i, d, c, dp);
            int del = d + f(curr + 1, n, i, d, c, dp);
            
            ans = min(ans, min(add, del));
        }
        
        
        return dp[curr] = ans;
    }
    
    int minCost(int n, int i, int d, int c) {
        // code here
        vector<int> dp(2 * n + 1, -1);
        
        return f(n, n, i, d, c, dp);
    }
};
