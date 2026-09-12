
/*
We need pairs (a, b) such that gcd(a,b) = x and lcm(a,b) = y.

Since a*b = gcd(a,b) * lcm(a,b),
let a = x*i and b = x*j.

Then:
    i*j = y/x

Hence y must be divisible by x.
Now find all factor pairs (i,j) of n = y/x.
A pair is valid only if gcd(i*x, j*x) == x
(equivalently gcd(i,j) == 1).

For every i != j, (i,j) and (j,i) give two ordered pairs,
so add 2.

If n == 1, the only pair is (x,x).
*/



class Solution {
  public:
    int pairCount(int x, int y) {
        // code here
        if(y % x != 0) return 0;
        
        int n = 0, ans = 0;
        n = y / x;
        
        if(n == 1) return 1;
        
        for(int i = 1; i <= sqrt(n); i++) {
            if(n % i == 0) {
                int j = n / i;
                if(i != j && gcd(i*x, j*x) == x) ans += 2;
            }
        }
        
        return ans;
    }
};
