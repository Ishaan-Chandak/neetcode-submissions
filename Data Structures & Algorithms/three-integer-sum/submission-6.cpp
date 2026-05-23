class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        cout << "sorting done" << endl;
        for (int i=0; i<nums.size(); i++){
            cout << "inside for for " << i << endl;
            if(nums[i] > 0) break;
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i + 1;
            int k = nums.size() - 1;
            cout << j << " " << k << endl;
            while(j < k){
                if(nums[j] + nums[k] + nums[i] == 0){
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    k--;

                    while(j < k && nums[j] == nums[j-1]){
                        j++;
                    }
                } else if (nums[j] + nums[k] + nums[i] > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return ans;
    }
};
