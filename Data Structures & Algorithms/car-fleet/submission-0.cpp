class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<double, double>> pairs;
        for(int i=0; i<n; i++){
            pairs.push_back({position[i], speed[i]});
        }
        sort(pairs.begin(), pairs.end(), [](const pair<double, double>& a, const pair<double, double>& b) {
            return b.first < a.first;
        });

        int fleetcount = 0;
        vector<double> time(n);
        for(int i=0; i<n; i++) {
            time[i] = (target - pairs[i].first) / pairs[i].second;
            if(i >= 1 && time[i] <= time[i-1]){
                time[i] = time[i - 1];
            } else {
                fleetcount++;
            }
        }

        return fleetcount;
    }
};
