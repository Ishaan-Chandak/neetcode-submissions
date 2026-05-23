class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        // for (auto i : nums) cout << i << " ";
        cout << endl;
        vector<vector<int>> ans;
        for(int i=0; i<n-2; i++) {
            if(i > 0 and nums[i] == nums[i-1]) continue;
            int j = i+1;
            int k = n-1;
            while(j < k) {
                // cout << i << " " << j << " " << k << endl; 
                if (nums[i] + nums[j] + nums[k] == 0) {
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while (nums[j] == nums[j-1] && j < n - 1) j++;
                    k--;
                    while(nums[k] == nums[k+1] && k > 0) k--;
                } else if (nums[i] + nums[j] + nums[k] > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }

        return ans;
    }
};
