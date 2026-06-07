class Solution {
    vector<vector<int>> ans;
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> pick (n, false);
        vector<int> perm;
        backtrack(perm, nums, pick);
        return ans;
    }


    void backtrack(vector<int>& perm, vector<int>& nums, vector<bool>& pick) {
        if(perm.size() == nums.size()) {
            ans.push_back(perm);
            return;
        }

        for(int i=0; i<nums.size(); i++) {
            if(!pick[i]) {
                perm.push_back(nums[i]);
                pick[i] = true;
                backtrack(perm, nums, pick);
                perm.pop_back();
                pick[i] = false;
            }
        }
    }
};
