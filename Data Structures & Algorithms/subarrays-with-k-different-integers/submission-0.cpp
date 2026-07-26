class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int n = nums.size(), ans = 0;
        int l_far = 0, l_near = 0;

        for(int i=0; i<n; i++) {
            mp[nums[i]]++;

            while(mp.size() > k) {
                mp[nums[l_near]]--;
                if(mp[nums[l_near]] == 0) {
                    mp.erase(nums[l_near]);
                }
                l_near++;
                l_far = l_near;
            }

            while(mp[nums[l_near]] > 1) {
                mp[nums[l_near]]--;
                l_near++;
            }

            if(mp.size() == k) ans += l_near - l_far + 1;  
        }

        return ans;
    }
};