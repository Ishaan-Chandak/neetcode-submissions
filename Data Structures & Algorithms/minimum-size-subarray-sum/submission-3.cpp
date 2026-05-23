class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int curr = 0;

        int l = 0, r = 0;
        int n = nums.size();
        int ans = INT_MAX;

        while(r < n){
            curr += nums[r];

            if(curr >= target) {
                // cout << "inside if " << l << " " << r << " " << curr << endl;
                ans = min(ans, r - l + 1);

                while(curr >= target) {
                    curr -= nums[l];
                    l++;
                    if (curr >= target) ans = min(ans, r - l + 1);
                    // cout << "inside if + isnide while " << l << " " << r << " " << curr << " " << ans << endl;
                }
            }
            
            r++;
            
            // cout << l << " " << r << " " << curr << endl;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};