class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = speed.size();
        vector<pair<int, int>> temp;
        for(int i = 0; i<n; i++) temp.push_back({position[i], speed[i]});

        sort(temp.rbegin(), temp.rend());

        int ans = 1;
        double prev = (double) (target - temp[0].first) / temp[0].second;
        for(int i = 1; i < n; i++) {
            double curr = (double) (target - temp[i].first) / temp[i].second;
            if(curr > prev) {
                ans++;
                prev = curr;
            }
        }

        return ans;
    }
};
