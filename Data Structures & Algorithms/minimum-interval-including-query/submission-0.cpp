class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        sort(intervals.begin(), intervals.end());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<pair<int, int>> pairs;
        int i = 0;
        for(auto query : queries) {
            pairs.push_back({query, i});
            i++;
        }
        int idx = 0;
        vector<int> res(queries.size());
        sort(pairs.begin(), pairs.end());
        for(auto q : pairs) {
            while(idx < intervals.size() && intervals[idx][0] <= q.first) {
                pq.push({intervals[idx][1] - intervals[idx][0] + 1, intervals[idx][1]});
                idx++;
            }

            while(!pq.empty() && pq.top().second < q.first) {
                pq.pop();
            }

            if(pq.empty()) res[q.second] = -1;
            else res[q.second] = pq.top().first;
        }

        return res;
    }
};
