class Solution {
public:
    int trap(vector<int>& heights) {
        int n = heights.size();
        // vector<int> right_max(n);
        // right_max[0] = 0;
        // for(int i=1; i<n; i++) {
        //     if(heights[i] >= heights[right_max[i-1]]) right_max[i] = i;
        //     else right_max[i] = right_max[i-1];
        // }

        // vector<int> left_max(n);
        // left_max[n-1] = n-1;
        // for(int i=n-2; i>=0; i--) {
        //     if(heights[i] >= heights[left_max[i+1]]) left_max[i] = i;
        //     else left_max[i] = left_max[i+1];
        // }

        // int ans = 0;

        // for (int i=0; i<n; i++) {
        //     if(right_max[i] == i || left_max[i] == i) continue;
        //     else {
        //         ans += (min(heights[right_max[i]], heights[left_max[i]]) - heights[i]);
        //     }
        // }

        int maxl = 0, maxr = 0, ans = 0;
        int l = 0, r = n-1;
        while(l < r) {
            if(heights[l] > maxl) maxl = heights[l];
            ans += maxl - heights[l];
            if(heights[r] > maxr) maxr = heights[r];
            ans += maxr - heights[r];

            if(maxl < maxr) l++;
            else r--;
        }

        return ans;
    }
};
