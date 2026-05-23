class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        vector<vector<int>> ans2;
        sort(nums.begin(), nums.end());
        cout << "sorting done" << endl;
        for (int i=0; i<nums.size(); i++){
            cout << "inside for for " << i << endl;
            int j = i + 1;
            int k = nums.size() - 1;
            cout << j << " " << k << endl;
            while(j < k){
                if(nums[j] + nums[k] == -1 * nums[i]){
                    ans.insert({nums[i], nums[j], nums[k]});
                    j++;
                } else if (nums[j] + nums[k] < -1 * nums[i]) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        copy(ans.begin(), ans.end(), back_inserter(ans2));
        return ans2;
    }
};
