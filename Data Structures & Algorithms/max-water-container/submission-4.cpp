class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0;
        int n = heights.size();
        int r = n-1;
        int cmp = 0, ans = 0;

        while (l < r) {
            cmp = abs(r - l) * min(heights[l], heights[r]);

            if (cmp > ans) ans = cmp;

            if(heights[l] < heights[r]) l++;
            else r--;
        }

        return ans;
    }
};
