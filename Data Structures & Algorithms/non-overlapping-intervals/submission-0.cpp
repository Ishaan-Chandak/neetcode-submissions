class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end());

        int n = intervals.size();
        int cnt = 0;
        vector<int> curr = intervals[0];
        for(int i=1; i<n; i++) {
            if(curr[1] > intervals[i][0]) {
                cnt++;
                curr[1] = min(curr[1], intervals[i][1]);
            } else {
                curr = intervals[i];
            }
        }

        return cnt;
    }
};
