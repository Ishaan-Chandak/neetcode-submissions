class Solution {
public:
    int distance(vector<int>& x) {
        return x[0] * x[0] + x[1] * x[1];
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> pq; 
        for(int i = 0; i<points.size(); i++) {
            pq.push({distance(points[i]), i});
        }

        vector<vector<int>> ans;

        for(int i=0; i<k; i++) {
            ans.push_back(points[pq.top().second]);
            pq.pop();
        }

        return ans;
    }
};
