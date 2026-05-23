class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;

        sort(intervals.begin(), intervals.end());

        vector<int> curr = intervals[0];
        int n = intervals.size();

        for(int i=1; i<n; i++) {
            if(curr[1] >= intervals[i][0]) {
                curr[0] = min(intervals[i][0], curr[0]);
                curr[1] = max(intervals[i][1], curr[1]);
            } else {
                ans.push_back(curr);
                curr = intervals[i];
            }
        }

        ans.push_back(curr);

        return ans;
    }
};
