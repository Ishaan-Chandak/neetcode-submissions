class Solution {
public:

    void backtrack(set<vector<int>>& ans, vector<int> curr, int index, vector<int>& nums){
        if(index == nums.size()) {
            ans.insert(curr);
            return;
        }

        curr.push_back(nums[index]);
        backtrack(ans, curr, index + 1, nums);
        curr.pop_back();

        while(index + 1 < nums.size() && nums[index] == nums[index+1]) index++;

        backtrack(ans, curr, index + 1, nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>> ans;
        vector<int> curr;
        int index = 0;
        sort(nums.begin(), nums.end());
        
        backtrack(ans, curr, index, nums);

        return vector<vector<int>>(ans.begin(), ans.end());
    }
};