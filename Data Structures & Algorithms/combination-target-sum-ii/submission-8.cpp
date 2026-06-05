class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> ans;
        vector<int> curr;

        backtrack(s, curr, 0, 0, target, nums);

        for(auto i : s) {
            ans.push_back(i);
        }

        return ans;
    }

    void backtrack(set<vector<int>>& ans, vector<int> curr, int curSum, int index, int& target, vector<int>& nums){
        if(curSum == target) {
            sort(curr.begin(), curr.end());
            ans.insert(curr);
            return;
        } 

        if(curSum > target or index >= nums.size()) return;

        curr.push_back(nums[index]);
        curSum += nums[index];
        backtrack(ans, curr, curSum, index + 1, target, nums);
        curr.pop_back();
        curSum -= nums[index];

        while(index + 1 < nums.size() && nums[index] == nums[index+1]) index++; // very imp part becuase this helps to skip the duplicates by a lot
        backtrack(ans, curr, curSum, index + 1, target, nums);
    }
};
