class Solution {
public:
    void backtrack(vector<vector<int>>& ans, vector<int> curr, int index, vector<int>& nums){
        if(index == nums.size()) {
            ans.push_back(curr);
            return;
        }

        curr.push_back(nums[index]);
        backtrack(ans, curr, index + 1, nums);
        curr.pop_back();
        backtrack(ans, curr, index + 1, nums);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;
        int index = 0;
        
        backtrack(ans, curr, index, nums);

        return ans;
    }
};
