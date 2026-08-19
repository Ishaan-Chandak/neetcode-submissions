class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        for(int i = 0; i<n-3; i++) {
            for(int j = i + 1; j <n-2; j++) {
                int l = j + 1, r = n-1;
                while(l < r) {
                    long long curr = (long long)nums[i] + nums[j] + nums[l] + nums[r];
                    // cout << curr << endl;
                    if((long long)target == curr) {
                        ans.insert({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                        while(l < n && nums[l] == nums[l-1]) l++;
                        while(r >= 0 && nums[r] == nums[r+1]) r--;
                    } else if (target > curr) l++;
                    else r--;
                }
            }
        }
        vector<vector<int>> ret;
        for(auto i : ans) ret.push_back(i);
        return ret;
    }
};