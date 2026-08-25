# good question for figurting out how to calculate the number of subsequences
# it tell us number of subsequencces is just picking 1 number or not picking it 
# so every number has 2 options (pick, not pick) (hence 2 ^ n)

class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = n-1;
        int mod = 1e9 + 7;
        int cnt = 0;

        vector<int> power(n, 1);
        for(int i = 1; i<n; i++) {
            power[i] = (power[i-1] * 2) % mod;
        }

        while(i <= j) {
                if((nums[i] + nums[j]) <= target) {
                    cnt = (cnt + power[j - i]) % mod;
                    i++;
                } else {
                    j--;
                }
        }

        return cnt;
    }
};
