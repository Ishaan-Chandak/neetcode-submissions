class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int l = 0, r = n - 1;
        int ans = 0;

        while(l < r){

            int cmp = min(heights[l], heights[r]) * (r - l);

            cout << l << " " << r << " " << cmp << " " << heights[l] << " " << heights[r] << endl;

            if(cmp > ans) {
                ans = cmp;
            } 

            if(heights[l] < heights[r]) l++;
            else r--;
        }

        return ans;
    }
};
